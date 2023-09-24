#include "main.h"

void _mul(char *a, char *b);
void print_array(char *s, int l);
void *_calloc(unsigned int nmemb, unsigned int size);
int check_digits(char *s);
int _strlen(char *s);
void error_exit(void);

int main(int argc, char *argv[])
{
	char *S1 = argv[1], *S2 = argv[2];

	if (argc != 3 || check_digits(S1) || check_digits(S2))
		error_exit();

	if (*S1 == '0' || *S2 == '0')
	{
		_putchar('0');
		_putchar('\n');
	}
	else
		_mul(S1, S2);
	return (0);
}

void _mul(char *a, char *b)
{
	int i, j, al, bl, x, y, Tl, mul0, tmp, M;
	char *A, *tmp_A;

	al = _strlen(a);
	bl = _strlen(b);
	tmp = bl;
	Tl = al + bl;
	A = _calloc(Tl, sizeof(int));

	tmp_A = A;

	for (i = al - 1; i >= 0; i--)
	{
		M = 0;
		x = a[i] - '0';
		mul0 = 0;
		bl = tmp;
		for (j = bl - 1; j >= 0; j--)
		{
			y = b[j] - '0';
			mul0 += A[i + j + 1] + (x * y) + M;
			A[i + j + 1] = mul0 % 10 + '0';
			M = mul0 / 10;
		}
		if (M)
			A[i + j + 1] = mul0 % 10 + '0';
	}

	print_array(A, Tl);
/**	
	start = 0;
	while (start < Tl && A[start] == 0)
		start++;

	if (start == Tl)
		printf("0");
	else
		for (i = start; i < Tl; i++)
			printf(A[i]);
	_putchar('\n');
	*/
	free(tmp_A);
}

void print_array(char *s, int l)
{
	int i = 0;

	while (s[i] == '0' && (i + 1) < l)
		i++;
	for (; i < l; i++)
		_putchar(s[i]);
	_putchar('\n');
}

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *A;
	unsigned int i;

	A = malloc(size * nmemb);

	if (A == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		A[i] = '0';

	return (A);
}

/**
 * _isdigit - this function will check if the input is digit
 *
 * @c: the input
 *
 * Return: return (1) if digit | (0) if not
 */

int check_digits(char *s)
{
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	return (0);
}

/**
 * _strlen - this function compute the lenght of a string
 * @s: pointer to the string
 * Return: return the lenght of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void error_exit(void)
{
	int i;
	const char *err;

	err = "Error";
	for (i = 0; err[i]; i++)
		_putchar(err[i]);
	_putchar('\n');
	exit(98);
}
