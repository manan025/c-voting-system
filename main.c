#include <stdio.h>
#include <string.h>
#include "voter.h"

void getPass(char *pwd) {
    // TODO: implement security
    scanf("%s", pwd);
}



int main(void) {

    user usr;
    user users[1000];
    vote votes[1000];

    init_data(users, votes);

    while (1) {
        int ul = len_users(users);
        printf("Are you existing user? ");
        char u;
        scanf("%c", &u);

        if (u == 'Y') {
            printf("Enter your userid: ");
            char userid[];
            scanf("%s", userid);
            char password[];
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

            if (signup()) {
                printf("Signup failed. Please try later.");
            } else {
                printf("Signup Successful. Logging you in...");
                // TODO: sign in successful. What next? login?
            }
            
        } else if (u == 'D') {
            break;
        } else {
            printf("Wrong Input, please try again.");
        }
    }

    // debug code
    struct x {
        int z;
        int a;
    }lmao[10];


    printf("%lu", sizeof(lmao)/sizeof(lmao[0]));

    return 0;
}
