#include "main.h"

/**
 * a_toi - This function convert strings to integers
 * @t: tring to be converted
 *
 * Return: int
 */

int a_toi(char *t)
{
	int k = 0;
	unsigned int i = 0;
	int m = 1;
	int a = 0;

	while (t[k])
	{
		if (t[k] == 45)
		{
			m *= -1;
		}
		while (t[k] >= 48 && t[k] <= 57)
		{
			a = 1;
			i = (i * 10) + (t[k] - '0');
			k++;
		}

		if (a == 1)
		{
			break;
		}

		k++;
	}

	i *= m;
	return (i);
}

/**
 * cmpn_str - Thi function compares two string with the bytes
 * @str1: The first string
 * @str2: The second string
 * @n: The bytes
 *
 * Return: 0 on success
 */

int cmpn_str(const char *str1, const char *str2, size_t n)
{
	size_t k = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);
	while (k < n)
	{
		if (str1[k] != str2[k])
		{
			if (str1[k] < str2[k])
				return (-1);
			else
				return (1);
		}
		k++;
	}
	if (k == n || str1[k] == '\0')
		return (0);
	return (0);
}


