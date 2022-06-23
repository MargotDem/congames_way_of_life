#include "life.h"

void	*ft_memset(void *s, int c, size_t n);
char    **calculate_new_cells(t_board *init_state);

int	handle_key(int key, void *param)
{
	t_mlx_win	*mlx_win;

	mlx_win = (t_mlx_win *)param;
	if (key == 53)
	{
		mlx_destroy_window(mlx_win->mlx_ptr, mlx_win->window);
		exit(0);
	}
	return (0);
}

void	draw_cells(t_mlx_win *mlx_win, t_board *board, int scale)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	width;
	int	length;

	width = board->x_dimension;
	length = board->y_dimension;

	j = 0;
	while (j < length)
	{
		i = 0;
		while (i < width)
		{
			
				mlx_pixel_put(mlx_win->mlx_ptr, mlx_win->window, i * scale, j * scale, 0x03fca1);
				k = 0;
				l = 0;
				while (k < scale)
				{
					mlx_pixel_put(mlx_win->mlx_ptr, mlx_win->window, i * scale + l, j * scale + k, 0x03fca1);
					k++;
				}
				while (l < scale)
				{
					mlx_pixel_put(mlx_win->mlx_ptr, mlx_win->window, i * scale + l, j * scale + k, 0x03fca1);
					l++;
				}
				if (board->array[j][i] == 'X')
				{
					k = 1;
					while (k < scale)
					{
						l = 1;
						while (l < scale)
						{
							mlx_pixel_put(mlx_win->mlx_ptr, mlx_win->window, i * scale + l, j * scale + k, 0xd4446a);
							l++;
						}
						k++;
					}
				}
				else
				{
					k = 1;
					while (k < scale)
					{
						l = 1;
						while (l < scale)
						{
							mlx_pixel_put(mlx_win->mlx_ptr, mlx_win->window, i * scale + l, j * scale + k, 0x556b63);
							l++;
						}
						k++;
					}
				}
			
			i++;
		}
		j++;
	}
}

void	visualize(t_board *board, int rounds)
{
	t_mlx_win	*mlx_win;
	int	width;
	int	length;
	int	scale;

	width = board->x_dimension;
	length = board->y_dimension;
	scale = 10;
	mlx_win = (t_mlx_win *)malloc(sizeof(t_mlx_win));
	if (!mlx_win)
		exit(0);
	mlx_win->mlx_ptr = mlx_init();
	if (!(mlx_win->mlx_ptr))
		exit(0);
	mlx_win->window_width = width * scale;
	mlx_win->window_length = length * scale;
	mlx_win->window = mlx_new_window(mlx_win->mlx_ptr, mlx_win->window_width, \
		mlx_win->window_length, "Lem in");
	mlx_win->board = board;
	mlx_win->scale = scale;
	mlx_win->total_rounds = rounds;
	if (!(mlx_win->window))
		exit(0);
	draw_cells(mlx_win, board, scale);
	mlx_key_hook(mlx_win->window, handle_key, (void *)mlx_win);
	mlx_loop(mlx_win->mlx_ptr);
}
