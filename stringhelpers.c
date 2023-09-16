#include "main.h"

/**
 * cpy_str - This function copies a string
 * @src: the source
 * @dest: the detination
 *
 * Return: destination
 */

char *cpy_str(char *src, char *dest)
{

	char *p = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p);
}

/**
 * len_str - Finds the length of a string
 * @k: points to string
 *
 * Return: Sring length
 */

int len_str(char *k)
{
	int t = 0;

	while (*k++)
		t++;
	return (t);
}

/**
 * cmp_str - This function compares two strings
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0
 */

int cmp_str(char *str1, char *str2)
{
	int k;

	for (k = 0; str1[k] != '\0' && str2[k] != '\0'; k++)
	{
		if (str1[k] != str2[k])
			return (str1[k] - str2[k]);
	}
	return (0);
}

/**
 * cat_str - concats two strings
 * @dest: detination
 * @src: source
 * Return: destination
 */

char *cat_str(char *dest, char *src)
{
	char *k = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (k);
}


/**
 * chr_str - This function locates a character in a string
 * @k: This is a character
 * @t: This is a string
 *
 * Return: NULL
 */

const char *chr_str(const char *t, char k)
{
	while (*t)
	{
		if (*t == k)
			return (t);
		t++;
	}
	return (NULL);
}
