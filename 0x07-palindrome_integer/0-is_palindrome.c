#include "palindrome.h"
/**
 * is_palindrome - checks a lu int for palindrome-ness
 * @n: integer to check
 * Return: returns 1 if is and 0 if not
 */
int is_palindrome(unsigned long n)
{

	unsigned long rev = 0, remainder, original;

	original = n;
	/* divs and mods n to reverse it */
	while (n != 0)
	{
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n /= 10;
	}
	/* compares reversed to original */
	return (original == rev);
}
