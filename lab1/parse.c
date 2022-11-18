#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/stat.h>
#include "parse.h"
int parse(char *buf, char **args)

{
int num=0;


while (*buf != '\0') {
    while ((*buf == ' ') || (*buf == '\t' || (*buf == '\n')))
        *buf++ = '\0';
    *args++ = buf;
    ++num;

    while ((*buf != '\0') && (*buf != '\t') && (*buf != '\n'))
        buf++; 
    }
*args = '\0';
return num;
}
