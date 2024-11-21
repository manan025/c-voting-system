#include <stdio.h>
#include <string.h>

	struct Users{
		char name[100];
		char email[50];
		char password[15];
		char access[5];
		char sex[10];
		int age;
	}users[100];

	struct Voters{
		char email[50];
		char access_code[10];
		char vote[5];
	}voters[100];
	
int main(){
	
	int n; //no. of entries to test code
	
	printf("no. of entries:");
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++){	//loop to take input of n users
		
		strcpy(users[i].access, "no");;	
		
		printf("Enter name:");
		scanf(" %[^\n]", users[i].name);
		
		printf("Email:");
		scanf("%s", users[i].email);
		strcpy(voters[i].email, users[i].email);
		
		printf("Password:");
		scanf("%s", users[i].password);
		
		printf("Sex:");
		scanf(" %[^\n]", users[i].sex);
		
		printf("Age:");
		scanf("%d", &users[i].age);
		
		printf("Access code:");
		scanf("%s", voters[i].access_code);
		
		printf("Vote(yes/no):");
		scanf("%s", voters[i].vote);
        signup(users[i].name, ...);
	}
}
		
		
