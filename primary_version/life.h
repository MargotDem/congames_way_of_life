#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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

#endif                                      