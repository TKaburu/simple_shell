#include "main.h"


/**
 * handle_comment - This function check if string has
 * comment (#) and voids it
 * @comnd: The string to be checked
 *
 */

void handle_comment(char *comnd)
{
	int k = 0;

	while (comnd[k])
	{
		if (comnd[k] == '#')
			comnd[k] = '\0';
		k++;
	}
}

