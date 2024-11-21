#include <stdio.h>
#include "voter.h"
#include <stdlib.h>
/*
* Functions for voters:
* - save voter data
* - vote
* - authenticate
* - get voting data based on access code
* - init data
 */


struct Users {
    char name[100];
    char email[50];
    char password[15];
    char access[5];
    char sex[10];
    int age;
};

struct Votes {
    char email[50];
    char access_code[10];
    char vote[5];
};

int init_data(struct Users *users, struct Votes *votes) {
}


int vote(char *userid, char *access_code, char *vote_code) {
    /*
   * Function to vote
   * Required Parameters: userid, access_code, vote_code
   * Returns: 0 if success, 1 if access code wrong, 2 if vote_code is invalid
     */
}

int save_votes(struct Votes *votes) {
    FILE *vote_file;

}

// --- Authentication STARTS

int login(char *userid, char *pwd) {
}

int signup(char *name, char *userid, char *pwd, char *sex, int *age) {
}

int logout() {
}

// --- Authentication ENDS
