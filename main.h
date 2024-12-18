#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

//shared functions
int process_handler(char *cmd);

#endif
