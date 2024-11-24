#include <stdio.h>
#include <string.h>
#include "voter.h"

void getPass(char *pwd) {
    // TODO: implement security
    scanf("%s", pwd);
}

void auth(user *users, user *active_user) {
    user usr;
    int flag = 0;
    while (!flag) {
        int ul = len_users(users);
        printf("Are you existing user? ");
        char u;
        scanf("%c", &u);

        if (u == 'Y') {
            printf("Enter your userid: ");
            char userid[50];
            scanf("%s", userid);
            char password[50];
            getPass(password);

            // authenticate the user and check

        } else if (u == 'N'){
            // register the user

            printf("Enter name:");
            scanf(" %[^\n]", usr.name);

            printf("Email:");
            scanf("%s", usr.email);

            printf("Password:");
            scanf("%s", usr.password);

            printf("Sex:");
            scanf(" %[^\n]", usr.sex);

            printf("Age:");
            scanf("%d", &usr.age);
            if (usr.age < 18) {
                printf("You can't register. Please try again after you turn 18.");
            }
            usr.uid = ul + 1;

            if (signup(usr.name, usr.email, usr.password, usr.sex, usr.age, users)) {
                printf("Signup failed. Please try later.");
            } else {
                printf("Signup Successful. Logging you in...");
                // TODO: sign in successful. What next? login?
                flag = 1;
            }

        } else if (u == 'D') {
            break;
        } else {
            printf("Wrong Input, please try again.\n");
        }
    }
}

void user_menu(user active_user) {
    while (active_user.uid) {
        printf("Enter access code: ");
        int access_code;
        scanf("%d", &access_code);
        // TODO: Check if valid access code
        if (access_code) {
            printf("Options:\n");
            printf("1. Cast Vote\n2. View Results\n3. Logout\n> ");
            int op;
            scanf("%d", &op);
        } else {
            printf("Invalid access code.\n");
        }
    }
}

void admin_menu(user active_user) {
    while (active_user.uid) {

    }
}

int main(void) {

    user users[1000];
    vote votes[1000];

    init_data(users, votes);

    user curr;

    printf("INIT: %d", len_users(users) );

    auth(users, &curr);



    // debug code
    struct x {
        int z;
        int a;
    }lmao[10];


    printf("%lu", sizeof(lmao)/sizeof(lmao[0]));

    return 0;
}
