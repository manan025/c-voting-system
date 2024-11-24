#ifndef VOTER_H
#define VOTER_H

typedef struct Users {
    int uid;
    char name[100];
    char email[50];
    char password[15];
    char access;
    char role[5];
    char sex[5];
    int age;
} user;

typedef struct Votes {
    char uid;
    char email[50];
    char access_code[10];
    char vote[5];
} vote;

typedef struct questions {
    char uid;
    int access_code;
    char q;
    struct qns {
        char option_id;
        char option[100];
    } option;
} options;


int init_data(user*, vote*);
int cast_vote(char*, char*, char*);
int login(char*, char*, user*, user*);
int signup(char *, char *, char *, char *, int , user *);
int logout();
int len_users(user*);
int len_votes(vote*);
int save_votes(vote*);


#endif //VOTER_H
