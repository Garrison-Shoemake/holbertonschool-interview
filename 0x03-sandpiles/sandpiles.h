#ifndef SANDPILES_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool stable(int grid[3][3]);
void topple(int grid[3][3]);
static void print_grid(int grid[3][3]);

#endif