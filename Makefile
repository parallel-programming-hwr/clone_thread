main: main.c
	gcc -Wall -Wextra -pedantic -o main main.c -pthread
main_simple: main_simple.c
	gcc -Wall -Wextra -pedantic -o main_simple main_simple.c -pthread
	
