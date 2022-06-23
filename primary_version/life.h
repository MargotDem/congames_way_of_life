#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <stdio.h>

typedef struct  s_board
{
    char        **array;
    int         x_dimension;
    int         y_dimension;
}               t_board;


#endif                                      