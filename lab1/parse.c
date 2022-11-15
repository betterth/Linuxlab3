#include <stdio.h>

int parse(char *buf, char **args)

{
int num=0;


while (*buf!='\0')
while((*buf=='')||(*buf=='\t'||(*buf=='\n')))


*buf++='\0';
 ++num;

            while ((*buf!='\0')&&(*buf!='\t')&&(*buf!='\n'))
         {

              buf++;


   }
}