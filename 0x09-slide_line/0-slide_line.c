#include "slide_line.h"
/**
 * slide_line - slides the line left or right
 * @line: line to slide
 * @size: size of the line
 * @direction: direction to shift line, 1 for left, 2 for right
 * these are defined in slide_line.h
 * Return: returns 1 on success and 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int *tmp = line;
	size_t i, j;

	if (line == NULL)
		return (0);
	/* parse line */
	for (i = 0; i < size; i++)
	{
		/* move on if the number is 0, do stuff if its not */
		if (line[i] != 0)
		{
			for (j = i + 1; j < size; j++)
			{
				/* parses and adds if consecutive match found */
				if (line[j] == 0)
					break;
				else if (line[j] == line[i])
				{
					tmp[i] = line[i] * 2;
					line[j] = 0;
					break;
				}
			}
		}
	}
	/* collapse the list so all 0s are on one side */
	collapse(tmp, size);

	/* reverse line if opposite direction */
	if (direction == 2)
		reversal(line, size);
	return (1);
}

/**
 * collapse - collapses the list
 * @list: list to collapse
 * @size: size of the list
 */
void collapse(int *list, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		if (list[i] == 0)
		{
			for (j = i + 1; j < size; j++)
			{
				/* looks for next non 0 to replace */
				if (list[j] > 0)
				{
					tmp = list[j];
					list[j] = list[i];
					list[i] = tmp;
					break;
				}
			}
		}
	}
}
/**
 * reversal - reverse the list
 * @list: list to reverse
 * @size: how big it is
 */
void reversal(int *list, size_t size)
{
	size_t i, j = size - 1;

	for (i = 0; i < j; i++)
	{
		list[i] ^= list[j];
		list[j] ^= list[i];
		list[i] ^= list[j];
		j--;
	}
}
