#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include "io.h"
#include "parse.h"
#define MAX 4096

void io() {
	while (1)
	{
		char* rt;
		char buf[MAX];
		char* args[64];
		int argnum = 0;
		pid_t pid;
		int status;
		printf("%%");
		rt = fgets(buf, MAX, stdin);
		if (rt == NULL)
		{
			printf("fgets error\n");
			exit(1);
		}
		if (!strcmp(buf, "\n"))
		{
			printf("%%");
			continue;
		}
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		argnum = parse(buf, args);
		if((strcmp(args[0],"logout")==0)||(strcmp(args[0],"exit")==0))
		  exit(0);
		else {
			if ((pid = fork()) < 0)//fork
			{
				printf("fork error,please reput command\n");
				continue;//结束这次循环 
			}
			else if (pid == 0)//子进�? 
			{
				execvp(*args, args);
				printf("coulde't execute :%s\n", buf);
				exit(127);
			}
			if ((pid = waitpid(pid, &status, 0)) < 0)//父进�? 
				printf("waitpid error\n");
		}
	}
}