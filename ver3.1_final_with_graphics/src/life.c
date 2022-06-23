#include "life.h"

void    life(char *file, int iterations)
{
    t_board *board;
    char    *initial_state;
    int     i;

    initial_state = read_file(file);
//    printf("file:\n%s\niterations: %i\n\n", initial_state, iterations);
    board = make_board(initial_state);
	free(initial_state);
    board = play_game(board, iterations);
    print_board(board);
	visualize(board, iterations);
	i = board->y_dimension;
    while (--i >= 0)
		free(board->array[i]);
	free(board->array);
    free(board);
}
