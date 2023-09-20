#include "main.h"


/**
 * dup_str - This function return a pointer to a newly allocated
 * space in memory
 * @str: This is a character
 * Return: Null if unseccesful otherwise string
 */

char *dup_str(char *str)
{
	int k = 0;
	char *t;

	if (str == NULL)
	{
		return (NULL);
	}
	/* +1 becuse the length ends with '\0'*/
	t = (char *) malloc(sizeof(char) * (len_str(str) + 1));

	if (t == NULL)
	{
		return (NULL);/*if memorry llocation is not successful return NULL*/
	}

	/* should copy the tring*/
	while (str[k - 1] != '\0')
	{
		t[k] = str[k];
		k++;
	}
	return (t);
}

/**
 * re_alloc - This function reallocates a memory
 * @ptr: This is a pointer
 * @old_size: This is the old size
 * @new_size: This is the new size
 * Return:  pointer
 */

void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
		return (ptr);
	free(ptr);
	ptr = malloc(new_size);
	return (ptr);

}

/**
 * mem_set - This fill memory with a constant byte
 * @s: char
 * @b: char
 * @n: unsigned int
 *
 * Return: char
 */


char *mem_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

