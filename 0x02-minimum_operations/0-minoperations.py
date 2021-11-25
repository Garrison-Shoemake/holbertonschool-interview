#!/usr/bin/python3
""" finds the minimum number of operations with copy and paste"""


def minOperations(n):
    """ defines minimum operations through infinite mod loop
    adds results if mod equals zero
    divides n by results until done
    """
    total = 0
    i = 2
    """ """

    
    if (n <= 0):
        """ if n is impossible return 0"""

        return 0

    
    while (i <= n ):
        """ while i less than or equal to n - mod i into n"""

        while (n % i == 0):
            """ reduces n while adding i steps to total until done """
            total += i
            n = n / i
        i += 1

    return total
    