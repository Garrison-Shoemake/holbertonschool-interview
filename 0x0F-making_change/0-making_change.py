#!/usr/bin/python3
""" determines fewest number of coins needed to reach a total """

from re import sub
import sys


def makeChange(coins, total):
    """
    coins is a list of values in possession
    total is the amount needed to reach
    if total is 0, return 0
    if total cannot be met, return -1
    """

    """ initaiting table for storing answers """
    table = [0 for i in range(total + 1)]

    """ base case for 0 total """
    table[0] = 0

    """ initialize table values as infinite """
    for i in range(1, total + 1):
        table[i] = sys.maxsize

    """ find minimum coins required from 1 to total """
    for i in range(1, total + 1):
        for j in range(len(coins)):
            if (coins[j] <= i):
                sub_res = table[i - coins[j]]
                if (sub_res != sys.maxsize and sub_res + 1 < table[i]):
                    table[i] = sub_res + 1

    if table[total] == sys.maxsize:
        return -1

    return table[total]
