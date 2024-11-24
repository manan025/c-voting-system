#include <stdio.h>
#include "voter.h"
#include <stdlib.h>
#include <string.h>
/*
* Functions for voters:
* - save voter data
* - vote
* - authenticate
* - get voting data based on access code
* - init data
 */

user admin = {1000, "admin", "admin@mrkr.me", "admin", 'A', 'A', 'U'};


// HANDLING DATA
int len_users(user *users) {
    int n = 0;
    while (users[n].uid>0) ++n;
    return n;
}

int len_votes(vote *votes) {
    int n = 0;
    while (votes[n].uid>0) ++n;
    return n;
}

int len_questions(agenda *questions) {
    int n = 0;
    while (questions[n].uid > 0) ++n;
    return n;
}

int init_data(user *users, vote *votes) {
    FILE *vote_file, *user_file;
    int re = 0;
    if ((vote_file = fopen("votes.bin", "rb")) == NULL) {
        FILE *newfile;
        newfile = fopen("votes.bin", "wb");
        fclose(newfile);

        re++;
    }
    if ((user_file = fopen("users.bin", "rb")) == NULL) {
        // create users.bin
        FILE *newfile;
        newfile = fopen("users.bin", "wb");
        fclose(newfile);
        re += 2;
    }
    // read the data from the file and store it in the struct users and votes
    if (re == 0) {
        fread(&users, sizeof(struct Users), 0, user_file);
        fread(&votes, sizeof(struct Votes), 0, vote_file);
    }
    fclose(user_file);
    fclose(vote_file);
    return re;
}

int cast_vote(char *userid, char *access_code, char *vote_code, vote *votes) {
    /*
   * Function to vote
   * Required Parameters: userid, access_code, vote_code
     */
    int l = len_votes(votes) + 1;
    votes[l].uid = l+1;
    strcpy(votes[l].email, userid);
    strcpy(votes[l].access_code, access_code);
    strcpy(votes[l].vote, vote_code);

    if (save_votes(votes)) {
        return 1;
    }

    return 0;
}

int save_votes(vote *votes) {
    FILE *vote_file;
    if ((vote_file = fopen("temp.bin", "wb")) == NULL) {
        return 1;
    }
    fwrite(&votes, sizeof(struct Votes), len_votes(votes), vote_file);
    return 0;
}

int checkProgress(int *access_code, vote *votes) {

    return 1;
}

// --- Authentication STARTS

int login(char *userid, char *pwd, user *users, user *active_user) {
    int n =0;
    printf("%d", strcmp(admin.email, userid));
    if (strcmp(userid, admin.email) == 0 && strcmp(pwd, admin.password) == 0) {
        *active_user = admin;
        printf("Welcome admin\n");
        return 0;
    }

    while (users[n].uid) {
        if (strcmp(users[n].email, userid) == 0 && strcmp(users[n].password, pwd) == 0) {
            *active_user = users[n];
            printf("Welcome, %s\n", active_user->name);
            return 0;
        }
        ++n;
    }
    return 1;
}

int signup(char *name, char *userid, char *pwd, char *sex, int age, user *users) {
    int l = len_users(users) + 1;
    users[l].uid = l;
    strcpy(users[l].name, name);
    strcpy(users[l].email, userid);
    strcpy(users[l].password, pwd);
    users[l].role = 'U';
    strcpy(users[l].sex, sex);
    users[l].age = age;

    FILE *user_file;
    if ((user_file = fopen("users.bin", "wb")) == NULL) {
        return 1;
    }
    printf("USER: %d", l);
    fwrite(&users, sizeof(struct Users), len_users(users)+1, user_file);

    fclose(user_file);

    return 0;

}

int logout() {
    return 1;
}

// --- Authentication ENDS

// --- ADMIN section STARTS

int add_question(char *q, char *options, char *access_code, agenda *qns) {
    return 1;
}

int listUsers(user *users) {
    int l = len_users(users);
    for (int i = 0; i < l; i++) {
        printf("--------------------\n");
        printf("uid: %d", users[i].uid);
        printf("User: %s\n", users[i].name);
        printf("User Email: %s\n", users[i].email);
    }
    return 0;
}

int adminProgress(vote *votes) {

    return 1;
}
