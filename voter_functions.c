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


// HANDLING DATA
int len_users(user *users) {
    int n = 0;
    while (users[n].uid>0) ++n;
    return n;
}

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

int login(char *userid, char *pwd, struct Users *users) {

}

int signup(char *name, char *userid, char *pwd, char *sex, int *age, user *users) {

}

int logout() {
}

// --- Authentication ENDS
