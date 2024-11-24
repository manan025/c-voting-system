gcc -c main.c -o main.o
gcc -c voter_functions.c -o voter_functions.o
gcc main.o voter_functions.o -o main
./main