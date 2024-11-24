#include <stdio.h>
#include "voter.h"
#include <stdlib.h>
#include <secure/_string.h>
/*
* Functions for voters:
* - save voter data
* - vote
* - authenticate
* - get voting data based on access code
* - init data
 */


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

int init_data(user *users, struct vote *votes) {
    FILE *vote_file, *user_file;
    if ((vote_file = fopen("votes.bin", "rb")) == NULL) {
        return 1;
    }
    if ((user_file = fopen("users.bin", "rb")) == NULL) {
        return 1;
    }
    // read the data from the file and store it in the struct users and votes
    fread(&users, sizeof(struct Users), 100, user_file);
    fread(&votes, sizeof(struct Votes), 100, vote_file);
    return 0;
}


int cast_vote(char *userid, char *access_code, char *vote_code) {
    /*
   * Function to vote
   * Required Parameters: userid, access_code, vote_code
     */

}

int save_votes(vote *votes) {
    FILE *vote_file;
    if ((vote_file = fopen("temp.bin", "wb")) == NULL) {
        return 1;
    }
    fwrite(&votes, sizeof(struct Votes), len_votes(votes), vote_file);
    return 0;
}

// --- Authentication STARTS

int login(char *userid, char *pwd, user *users, user *active_user) {
    int n = 0;

    while (users[n].uid) {
        if (users[n].email == userid && users[n].password == pwd) {
            active_user = &users[n];
            return 0;
        }
        ++n;
    }
    return 1;
}

int signup(char *name, char *userid, char *pwd, char *sex, int age, user *users) {
    int l = len_users(users);
    strcpy(users[l].name, name);
    strcpy(users[l].email, userid);
    strcpy(users[l].password, pwd);
    strcpy(users[l].role, "U");
    strcpy(users[l].sex, sex);
    users[l].age = age;

    FILE *user_file;
    if ((user_file = fopen("users.bin", "wb")) == NULL) {
        return 1;
    }

    fwrite(&users, sizeof(struct Users), len_users(users), user_file);

    return 0;

}

int logout() {
    return 0;
}

// --- Authentication ENDS
