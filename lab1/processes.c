void processes(char *buf,char *args)
{
	pid_t pid;
	int status;
	if((pid=fork())<0)//fork
	{
		printf("fork error,please reput command\n");
		continue;//结束这次循环 
	}
	else if(pid==0)//子进程 
	{
		execvp(*args,args);
		printf("coulde't execute :%s\n",buf );
		exit(127); 
	}
	if((pid=waitpid(pid,&status,0))<0)//父进程 
		printf("waitpid error\n");
}
