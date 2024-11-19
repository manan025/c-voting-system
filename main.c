#include <stdio.h>
#include <string.h>

int main(void) {
    struct Student {
        char name[50];
        int age;
    }s1,ws2;
    int t;
    s1.age = 0;
    strcpy(s1.name, "sad");
    ws2.age = 10;

    return 0;
}
