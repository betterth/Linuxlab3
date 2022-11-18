#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/stat.h>
#include "ioprocesses.h"
int main(void){
    io();
    exit(0);
}