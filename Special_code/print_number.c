#include <unistd.h>
/**
 * main - check the code
 *
 * Return: Always 0.
 */

int _putchar(char c);
void print_number(int n);

int main(void)
{
    print_number(98);
    _putchar('\n');
    print_number(402);
    _putchar('\n');
    print_number(1024);
    _putchar('\n');
    print_number(0);
    _putchar('\n');
    print_number(-98);
    _putchar('\n');
    return (0);
}

/**
 * print_number - this function prints an integer
 * @n: the integer
 * Return: return void
 */

void print_number(int n)
{
        unsigned int m = n;

        if (n < 0)
        {
                _putchar('-');
                m = -n;
        }

        if  (m / 10) /** this function works like infinite loop **/
                print_number(m / 10);

        _putchar(m % 10 + '0');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
