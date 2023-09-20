#include "main.h"

/**
 * prompt - prints prompt to user
 *
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}


/**
 * read_cmd - This function reads the users input
 * @comnd: This is the input of the user
 *
 */

void read_cmd(char *comnd)
{
	ssize_t input;
	int k = 0;

	mem_set(comnd, 0, MAX_PROMPT);
	input = read(STDIN_FILENO, comnd, MAX_PROMPT);
	if (input == -1)
	{
		exit(errno);
	}
	while (comnd[k])
	{/* remove '\n' */
		if (comnd[k] == '\n')
			comnd[k] = '\0';
		k++;
	}
	if (input == '\0' || input == EOF)
		exit(EXIT_SUCCESS);
	if (input == 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	handle_comment(comnd);


}

/**
 * split - This function splits string according to delimeter
 * @comnd: The string
 * @store: Adress of individual token
 *
 * Return: individual tokens
 */


char **split(char *comnd, char **store)
{
	char *point = NULL;
	char *del = " \n\t\r";
	int k = 0;

	point = strtok(comnd, del);
	while (point)
	{
		store[k++] = point;
		point = strtok(NULL, del);
	}
	store[k] = NULL;
	return (store);
}


/**
 * exec_cmnd - This function executes commands
 * @comnd: uer command to be executed
 *
 */

void exec_cmnd(char *comnd)
{
	pid_t baby;
	char *arg[] = { NULL, NULL };
	int status;

	baby = fork();
	if (baby == -1)
	{
		perror("Error: Failed to create baby");
		exit(errno);
	}
	else if (baby == 0)
	{
		split(comnd, arg);
		arg[0] = comnd;
		if (execve(arg[0], arg, environ) == -1)
		{
			perror("./hsh");
			exit(errno);
		}
	}
	else
		wait(&status);
}
/**
 * main - Entry point of the shell program
 *
 * Return: (0) on succes
 */

int main(void)
{
	char comnd[MAX_PROMPT];

	for (;;)
	{
		prompt();
		read_cmd(comnd);
		built_in(comnd);
		exec_cmnd(comnd);

	}
	return (0);
}

