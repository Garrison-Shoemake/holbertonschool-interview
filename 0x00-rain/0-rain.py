#!/usr/bin/python3
""" 
walls is a list of non-negative integers
Return: returns total amount of rain stored
ends of list are not walls and do not store
if list is empty return 0
"""

def rain(walls):
    """ 
    define sizes of left and right arrays
    also define water for use later
    """
    size = len(walls)
    left = size * [0]
    right = size * [0]
    left[0] = walls[0]
    water = 0
    

    """
    define left array and define highest wall from left to right
    shows the maximum height each element could be
    """
    max_left = walls[0]
    for index in range(0, size):
        if (max_left < walls[index]):
            max_left = walls[index]
            left[index] = max_left
        else:
            left[index] = max_left

    """ 
    do the same, define right comparison list except go from
    right to left, which gives a different height in each 
    elements position
    """
    max_right = walls[-1]
    for index in range(size -1, -1, -1):
        if(max_right < walls[index]):
            max_right = walls[index]
            right[index] = max_right
        else:
            right[index] = max_right


    """
    water is filled based on the difference between the minimum
    of each element's potential height, minus the original height
    of that same element
    if the minimum is larger than the original wall, then remainder
    is filled with water
    """
    for index in range(0, size):
        water = water + min(left[index], right[index]) - walls[index]

    return water
