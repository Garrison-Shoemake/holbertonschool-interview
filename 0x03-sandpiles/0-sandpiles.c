#include "sandpiles.h"
/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first grid to add
 * @grid2: second grid to add
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;


	/* the following will be adding the two original piles together */
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	
	topple(grid1);
}


/**
 * topple - topples all necessary cells to neighbours
 * @grid: grid to topple and stabilize 
 * 
 */
void topple(int grid[3][3])
{
	int x, y;

	while(!stable(grid))
	{
		printf("=\n");
		print_grid(grid);
		
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				/* the following is to topple the piles on to neighbours */			
				if (grid[x][y] > 3)
				{
					grid[x][y] -= 4;
					if (x < 2)
						grid[x+1][y]++;
					if (x > 0)
						grid[x-1][y]++;
					if (y < 2)
						grid[x][y+1]++;
					if (y > 0)
						grid[x][y-1]++;
				}			
			}
		}
	}
}

/**
 * stable - boolean helper function for stability
 * @grid - grid to check for stability
 * Return: returns either true or false
 */
bool stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				return false;

	return true;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}