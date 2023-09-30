#include "main.h"

/**
 * env_dis - This function prnts environment to user
 *
 */

void env_dis(void)
{
	int k;

	for (k = 0; environ[k] != NULL; k++)
	{
		write(STDOUT_FILENO, environ[k], len_str(environ[k]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * cd - This function changes directories
 * @comnd: users input
 *
 * Return: 0 on succes
 */

void cd(char **comnd)
{
	if (comnd == NULL)
		return (NULL);

	if (comnd[1] == '\0')
	{
		if (chdir(find_env("HOME")) != 0)
		{
			return (NULL);
		}
	}
	else if (cmp_str(&comnd[1], "~") == 0)
	{
		if (chdir(find_env("OLDPWD")) != 0)
			return (NULL);
	}
	else
	{
		if (chdir(&comnd[1]) != 0)
			return (NULL);
	}
}


/**
 * ex_it - This function exits the shell it a status
 * @comnd: The argument compared
 *
 */


void ex_it(char *comnd)
{
	int status;
	char *msg = "Invalid status\n";

	/*Check if there is a command ie cmd[0] == smthing*/
	/*I need to check 1st if there is an argument...I think*/

	if (comnd[0] == '\0' || comnd[1] == '\0')
		exit(EXIT_FAILURE);
	else
		status = a_toi(&comnd[1]);
	if (status == 0 && comnd[1] != '0')
	{
		write(STDERR_FILENO, msg, len_str(msg));
		exit(EXIT_FAILURE);
	}
	exit(status);
}

/**
 * built_in - This command checks if a command is built in
 * @comnd: The command to be checked
 *
 * Return: 0 if successful
 */

int built_in(char *comnd)
{
	if (cmp_str(comnd, "exit") == 0)
		ex_it(comnd);
	if (cmp_str(comnd, "env") == 0)
	{
		env_dis();
		return (1);
	}
	if (cmp_str(comnd, "cd") == 0)
	{
		cd(comnd);
		return (1);
	}
	return (0);
}

