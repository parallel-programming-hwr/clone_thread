#define _GNU_SOURCE
#include <sched.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <strings.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)

int child(void* buf){
	printf("print buf (addr=%p): %s\n",buf,(char *) buf);
	sleep(2);
	printf("print buf (addr=%p): %s\n",buf, (char *)buf);
	exit(EXIT_SUCCESS);
}

int main(){
	char * stack = malloc(STACK_SIZE * sizeof(char));
	char * buf = malloc(256 * sizeof(char));
	snprintf(buf,256,"inital"); 
	clone(child, stack + STACK_SIZE, SIGCHLD | CLONE_THREAD | CLONE_SIGHAND | CLONE_VM, buf);
	sleep(1);
	snprintf(buf,256,"changed");
	sleep(2);
	exit(EXIT_SUCCESS);
}
