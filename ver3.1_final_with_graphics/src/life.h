#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct  s_board
{
    char        **array;
    int         x_dimension;
    int         y_dimension;
}               t_board;

typedef struct s_mlx_win {
	void		*mlx_ptr;
	void		*window;
	size_t		window_width;
	size_t		window_length;
	t_board	*board;
	int	scale;
	int	total_rounds;
	int	rounds;
}	t_mlx_win;

void    life(char *file, int iterations);
char    *read_file(char *file);
t_board *make_board(char *initial_state);
t_board *play_game(t_board *init_state, int rounds);
void    print_board(t_board *board);
void	*ft_memset(void *s, int c, size_t n);
void	visualize(t_board *board, int rounds);

#endif                                      