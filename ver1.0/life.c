#include "life.h"

void	print_grid(int grid_size_x, int grid_size_y, t_uint16 **grid)
{
	int	i;
	int	y;
	uint16_t	bitwise_nb;

	y = 0;
	while (y < grid_size_y)
	{
		i = 0;
		bitwise_nb = 0b1000000000000000;
		while (i < grid_size_x)
		{
			if (grid[y][i / 16] & bitwise_nb)
			{
				printf("x");
			}
			else
			{
				printf(".");
			}
			bitwise_nb = bitwise_nb >> 1;
			if (bitwise_nb == 0b0000000000000000)
				bitwise_nb = 0b1000000000000000;
			i++;
		}
		printf("\n");
		y++;
	}
}

void	make_grid(void)
{
	int	grid_size_x;
	int	grid_size_y;
	int	uint16_nb;
	uint16_t	bitwise_nb;
	int	x;
	int	y;
	t_uint16	**grid;

	bitwise_nb = 0b1000000000000000;
	grid_size_x = 18;
	grid_size_y = 5;
	y = 0;

	grid = (t_uint16 **)malloc(sizeof(t_uint16 *) * grid_size_y);
	if (!grid)
		exit(0);
	uint16_nb = grid_size_x / 16;
	if (grid_size_x % 16)
		uint16_nb++;
	printf("size is %d\n", uint16_nb);
	while (y < grid_size_y)
	{
		grid[y] = (t_uint16 *)malloc(sizeof(t_uint16) * uint16_nb);
		if (!(grid[y]))
		{
			// free the precedents
			exit(0);
		}
		x = 0;
		while (x < uint16_nb)
		{
			grid[y][x] = 0b0000000000000000;
			x++;
		}
		y++;
	}

	/*
	..................
	.......x..x.....xx
	..................
	..................
	..................
	*/
	grid[1][0] = grid[1][0] | 0b0000000100100000;
	grid[1][1] = grid[1][1] | 0b1100000000000000;
	print_grid(grid_size_x, grid_size_y, grid);
}

int	main(int ac, char **av)
{
	char	*initial_state;
	if (ac == 3)
		initial_state = read(av[1]);
		make_grid();
	else
		printf("usage: ./life <initial state file> <number of iterations>");
}
