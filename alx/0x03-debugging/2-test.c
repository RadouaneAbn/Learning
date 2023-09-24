#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

/**
* main - prints the largest of 3 integers
* Return: 0
*/

int main(void)
{
	int a, b, c;
	int largest;

	srand(time(0));

	a = rand() - RAND_MAX / 2;
	b = rand() - RAND_MAX / 2;
	c = rand() - RAND_MAX / 2;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	largest = largest_number(a, b, c);

	printf("%d is the largest number\n", largest);

	return (0);
}
