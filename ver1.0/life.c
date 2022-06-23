#include "life.h"
#include <unistd.h>

void	print_grid(int grid_size_x, int grid_size_y, t_uint16 **grid);

t_uint16	set_bits(char *str, int x_dimension, int y, int x)
{
	t_uint16	result;
	t_uint16	one;
	int			i;
	int			end;

	i = (y * (x_dimension + 1)) + (x * 16);
	end = i + 15;
	result = 0;
	one = 1;
	while (i <= end)
	{
		if (str[i] == 'x')
		{
			printf("i: %d\nend: %d\n", i, end);
			result |= one << (end - i);
		}
		i++;
	}
	printf("result: %d\n", result);
	return (result);
}

void	set_bits2(char *str, int x_dimension, t_uint16 **grid, int y)
{
	int i;
	uint16_t	bitwise_nb;

	i = 0;
	bitwise_nb = 0b1000000000000000;
	while (i < x_dimension)
	{
		if (str[i] == 'x')
			grid[y][i / 16] |= bitwise_nb;
		bitwise_nb = bitwise_nb >> 1;
		if (bitwise_nb == 0b0000000000000000)
			bitwise_nb = 0b1000000000000000;
		i++;
	}
}

static int	get_y_dimension(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	return (counter + 1);
}

static int	get_x_dimension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	play(int grid_size_x, int grid_size_y, t_uint16 **grid,  t_uint16 **grid2, int uint16_nb, int iterations)
{
	int	i;
	int	y;
	int	x;
	int	turns;
	t_uint16	**init_grid;
	t_uint16	**rslt_grid;
	uint16_t	bitwise_nb;
	(void)uint16_nb;

	//printf("iterations are %d\n", iterations);
	init_grid = grid;
	rslt_grid = grid2;
	turns = 0;
	while (turns < iterations)
	{
		y = 0;
		while (y < grid_size_y)
		{
			i = 0;
			bitwise_nb = 0b1000000000000000;
			x = 0;
			while (i < grid_size_x)
			{
				if ((rslt_grid[y][i / 16] & bitwise_nb))
				{
					rslt_grid[y][i / 16] ^= bitwise_nb;
				}
				if ((init_grid[y][i / 16] & bitwise_nb) && turns == 0)
				{
					rslt_grid[y][i / 16] = rslt_grid[y][i / 16] | bitwise_nb;
				}
				bitwise_nb = bitwise_nb >> 1;
				if (bitwise_nb == 0b0000000000000000)
					bitwise_nb = 0b1000000000000000;
				i++;
			}
			printf("\n");
			y++;
		}
		printf("\n");
		printf("turn is %d, init grid:\n", turns);
		print_grid(grid_size_x, grid_size_y, init_grid);
		printf("\nrslt grid:\n");
		print_grid(grid_size_x, grid_size_y, rslt_grid);
		turns++;
	}
	init_grid = rslt_grid;
}

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

void	make_grid(char *initial_state, int iterations)
{
	int	grid_size_x;
	int	grid_size_y;
	int	uint16_nb;
	uint16_t	bitwise_nb;
	int	x;
	int	y;
	t_uint16	**grid;
	t_uint16	**grid2;

	bitwise_nb = 0b1000000000000000;
	grid_size_x = get_x_dimension(initial_state);
	grid_size_y = get_y_dimension(initial_state);
	y = 0;

	grid = (t_uint16 **)malloc(sizeof(t_uint16 *) * grid_size_y);
	grid2 = (t_uint16 **)malloc(sizeof(t_uint16 *) * grid_size_y);
	if (!grid || !grid2)
		exit(0);
	uint16_nb = grid_size_x / 16;
	if (grid_size_x % 16)
		uint16_nb++;
	//printf("size is %d\n", uint16_nb);
	while (y < grid_size_y)
	{
		grid[y] = (t_uint16 *)malloc(sizeof(t_uint16) * uint16_nb);
		grid2[y] = (t_uint16 *)malloc(sizeof(t_uint16) * uint16_nb);
		if (!(grid[y]) || !(grid2[y]))
		{
			// free the previous
			exit(0);
		}
		x = 0;
		while (x < uint16_nb)
		{
			//grid[y][x] = set_bits(initial_state, grid_size_x, y, x);
			grid[y][x] = 0b0000000000000000;
			grid2[y][x] = 0b0000000000000000;
			x++;
		}
		set_bits2(&initial_state[y * (grid_size_x + 1)], grid_size_x, grid, y);
		y++;
	}
	print_grid(grid_size_x, grid_size_y, grid);
	printf("\n\n");
	print_grid(grid_size_x, grid_size_y, grid2);
	printf("\n\nplay:");
	play(grid_size_x, grid_size_y, grid, grid2, uint16_nb, iterations);
	printf("\n\n");
}

int	main(int ac, char **av)
{
	char	*initial_state;
	if (ac == 3)
	{
		initial_state = life_read(av[1]);
		make_grid(initial_state, atoi(av[2]));
	}
	else
		printf("usage: ./life <initial state file> <number of iterations>");
}
