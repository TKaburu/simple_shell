#ifndef MAIN_H
#define MAIN_H

/* standard header files */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;
#define MAX_PROMPT 1024

/* Prompt prototypes */

int main(void);
void prompt(void);
void read_cmnd(char *comnd);
void exec_cmnd(char *comnd);
char **split(char *comnd, char **store);

/* string helpers */

char *cpy_str(char *src, char *dest);
int len_str(char *k);
int cmp_str(char *str1, char *str2);
char *cat_str(char *dest, char *src);
const char *chr_str(const char *t, char k);
int a_toi(char *t);
int cmpn_str(const char *str1, const char *str2, size_t n);



#endif
