#include "menger.h"
#include <math.h>
/**
 * menger - draws a 2D menger Sponge
 * @level: level that the menger sponge is to be drawn at
 */
void menger(int level)
{
	int i, j, k;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}

	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level); j++)
		{
			for (k = pow(3, level) / 3; k; k /= 3)
			{
				if ((i % (k * 3)) / k == 1 && (j % (k * 3)) / k == 1)
					break;
			}
			printf(k ? " " : "#");
		}
		printf("\n");
	}
}
