#include <stdio.h>

int main(void)
{
	int i;
	char buff[] = "Hello every one, my name is radouane abounouas.";

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (!(i % 10) && i)
			printf("\n");
		printf("%x ", buff[i]);
	}

	return (0);
}
