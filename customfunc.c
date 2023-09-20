#include "main.h"


/**
 * str_tok - This function splits string according to delimeter
 * into individul tokens
 * @string: The string
 * @del: Delimeter
 *
 * Return: The individual tokens
 */


char *str_tok(char *string, const char *del)
{
	static char *point;/* tokeniztion has not started*/
	char *token = point;

	if (string)
	{/* The tarting point for tokenization*/
		point = string;
	}
	else
	{
		if (!point)
			return (NULL);
	}

	while (*point && chr_str(del, *point))
		point++;

	if (!*point)
	{
		point = NULL; /* Reset for next call*/
		return (NULL);
	}

	token = point;

	while (*point && !chr_str(del, *point))
		point++;

	if (*point)
		*point++ = '\0'; /* Null-terminate the token*/

	return (token);
}

