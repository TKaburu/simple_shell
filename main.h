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

/* Memory helpers */
char *dup_str(char *str);
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *mem_set(char *s, char b, unsigned int n);

/*custom functions */

char *str_tok(char *string, const char *del);

/* handlers function*/
void handle_comment(char *comnd);

/* Location function */
char *find_env(char *name);
char *find_path(char *path, char *comnd);
char *locate_comnd(char *comnd);

/* Built in functions */

void env_dis(void);
int built_in(char *comnd);
void ex_it(char *comnd);
#endif

