#include <stdio.h>
#include <string.h>
#include "voter.h"


void getPass(char *pwd) {
    // TODO: implement security
    printf("Enter your password: ");
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

            int ret = login(userid, password, users, active_user);
            if (ret == 0) {
                flag = 1;
            } else {
                printf("Wrong credentials\n");
            }

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
                printf("Signup failed. Please try later.\n");
            } else {
                printf("Signup Successful. Logging you in...");
                // TODO: sign in successful. What next? login?
                flag = 1;
                active_user = &usr;
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
            if (op == 1) {
                // cast vote
            } else if (op == 2) {
                // view results
            } else if (op == 3) {
                // logout
            } else {
                printf("Invalid option.\n");
            }
        } else {
            printf("Invalid access code.\n");
        }
    }
}

void admin_menu(user active_user) {
    while (active_user.uid) {
        printf("Options:\n");
        printf("1. List Users\n2. List Votes\n3. Create Votes\n3. Logout\n> ");
        int op;
        scanf("%d", &op);
        if (op == 1) {
            // list users
        } else if (op == 2) {
            // list votes
        } else if (op == 3) {
            // logout
        } else {
            printf("Invalid option.\n");
        }
    }
}

int main(void) {

    user users[1000];
    vote votes[1000];

    int ret = init_data(users, votes);

    if (ret == 1) {
        printf("WARN: Error reading votes file. Ignore if running for the first time.\n");
    } else if (ret == 2) {
        printf("WARN: Error reading users file. Ignore if running for the first time.\n");
    } else if (ret == 3) {
        printf("WARN: Error reading users and votes files. Ignore if running for the first time\n");
    }

    user curr;

    printf("INIT: %d", len_users(users) );

    auth(users, &curr);

    if (curr.role == 'A') {
        admin_menu(curr);
    } else {
        user_menu(curr);
    }

    // debug code STARTS

    return 0;
}
