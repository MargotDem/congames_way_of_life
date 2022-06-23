#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct  s_board
{
    char        **array;
    int         x_dimension;
    int         y_dimension;
}               t_board;

void    life(char *file, int iterations);
char    *read_file(char *file);
t_board *make_board(char *initial_state);
t_board *play_game(t_board *init_state, int rounds);
void    print_board(t_board *board);
void	*ft_memset(void *s, int c, size_t n);

#endif                                      