#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>

//#define MAXLINE 4096

void io(char* rt,char* buf,int argnum,char* args)
	while (1)
	{
	    int MAXLINE = 4096;
	    printf("%%");
	    rt = fgets(buf, MSXLINE, stdin);
	    if(rt==NULL)
	    {
		printf("fgets error\n");
		exit(1);
	    }
	    if(!strcmp(buf,"\n"))
	    {
		printf("%%");
		continue;
	    }
	    if(buf[strlen(buf)-1]=='\n')
		buf[strlen(buf) - 1] = 0;
	    argnum = parse(buf, args);
	    //if((strcmp(args[0],"logout")==0)||(strcmp(args[0],"exit")==0))
		//exit(0);
	}