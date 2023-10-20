#include "shell.h"

/**
 * check_interactive - returns true if the shell is in interactive mode
 * @info: struct address
 *
 * Returns: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_separator - checks if a character is a separator
 * @c: the character to check
 * @delim: the separator string
 * Returns: 1 if it's a separator, 0 if not
 */
int is_separator(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _is_alphabetic - checks for an alphabetic character
 * @c: The character to check
 * Returns: 1 if c is an alphabetic character, 0 otherwise
 */
int _is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _custom_atoi - converts a string to an integer
 * @s: the string to be converted
 * Returns: 0 if no numbers in the string, the converted number otherwise
 */
int _custom_atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

