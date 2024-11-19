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
		
		strcpy(users[n-1].access, "no");;	
		
		printf("Enter name:");
		scanf(" %[^\n]", users[n-1].name);
		
		printf("Email:");
		scanf("%s", users[n-1].email);
		strcpy(voters[n-1].email, users[n-1].email);
		
		printf("Password:");
		scanf("%s", users[n-1].password);
		
		printf("Sex:");
		scanf(" %[^\n]", users[n-1].sex);
		
		printf("Age:");
		scanf("%d", &users[n-1].age);
		
		printf("Access code:");
		scanf("%s", voters[n-1].access_code);
		
		printf("Vote(yes/no):");
		scanf("%s", voters[n-1].vote);	
	}
}
		
		
