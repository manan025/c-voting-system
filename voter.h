#ifndef VOTER_H
#define VOTER_H

typedef struct Users {
    int uid;
    char name[100];
    char email[50];
    char password[15];
    char access;
    char role;
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
    struct options {
        char option_id;
        char option[100];
    } option;
} agenda;

// voter functions
int init_data(user*, vote*);
int cast_vote(char*, char*, char*, vote *);
int signup(char *, char *, char *, char *, int , user *);
int len_users(user*);
int len_votes(vote*);
int save_votes(vote*);

int login(char*, char*, user*, user*);
int logout();

// admin functions
int listUsers(user*);
int add_question(char *, char *, char *, agenda *);
int adminProgress(vote *);
int len_questions(agenda *);


#endif //VOTER_H
