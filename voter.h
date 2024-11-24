//
// Created by Manan Raina Kumar on 19/11/24.
//

#ifndef VOTER_H
#define VOTER_H

typedef struct Users {
    int uid;
    char name[100];
    char email[50];
    char password[15];
    char access[5] = "no";
    char role;
    char sex[3];
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
    char q;
    char options[][];
};

int init_data(user*, vote*);
int cast_vote(char*, char*, char*);
int login(char*, char*);
int signup();
int logout();
int len_users(user*);
int signup(char*, char*, char*, int);


#endif //VOTER_H
