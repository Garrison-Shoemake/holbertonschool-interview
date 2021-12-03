#include "sandpiles.h"
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid to add
 * @grid2: second grid to add
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, num;

	/* the following will be adding the two original piles together */
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			/* the following is to topple the piles on to neighbours */
			num = grid1[x][y];
			if (num >= 4)
			{
				grid1[x][y] += (num - 4);
				if (x+1 < 3)
					grid1[x+1][y]++;
				if (x-1 >= 0)
					grid1[x-1][y]++;
				if (y+1 < 3)
					grid1[x][y+1]++;
				if (y-1 >= 0)
					grid1[x][y-1]++;
			}				
		}
	}

}
