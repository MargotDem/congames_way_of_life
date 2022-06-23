#include "life.h"

void    print_board(t_board *board)
{
    int x;
    int y;

    y = 0;
    while (y < board->y_dimension)
    {
        x = 0;
        while (x < board->x_dimension)
        {
            printf("%c", board->array[y][x]);
            x++;
        }
        printf("\n");
        x = 0;
        y++;
    }
}