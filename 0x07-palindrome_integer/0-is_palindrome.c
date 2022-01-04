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
	/* edits n to reverse it through div and mod */
	while (n != 0)
	{
		remainder = n % 10;
		rev = rev * 10 + remainder;
		n /= 10;
	}
	/* returns if the reversed number matches the original */
	return (original == rev);
}
