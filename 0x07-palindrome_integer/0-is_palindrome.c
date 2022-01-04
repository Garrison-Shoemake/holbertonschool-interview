#include "palindrome.h"
/**
 * is_palindrome - checks a lu inte for palindrome-ness
 * @n: integer to check
 * Return: returns 1 if is and 0 if not
 */
int is_palindrome(unsigned long n)
{

	unsigned long rev = 0, remainder, original;

	original = n;
	while (n != 0)
	{
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n /= 10;
	}
	if (original == rev)
		return (1);
	else
		return (0);

}
