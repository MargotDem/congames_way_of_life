#include "life.h"

static int get_neighbors(t_board *init_state, int y, int x)
{
    int counter;

    counter = 0;
	if (y > 0 && y < init_state->y_dimension - 1)
    {
        if (x > 0 && x < init_state->x_dimension - 1)
        {
            if(init_state->array[y-1][x-1] == 'X')
                counter++;
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y-1][x+1] == 'X')
                counter++;
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x-1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);  
        }
        else if (x == 0)
        {
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y-1][x+1] == 'X')
                counter++;
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            return (counter);
        }
        else
        {
            if(init_state->array[y-1][x-1] == 'X')
                counter++;
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x-1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
	}
    else if (y == 0)
    {
        if (x > 0 && x < init_state->x_dimension - 1)
        {
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x-1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
        else if (x == 0)
        {
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            return (counter);
        }
        else
        {
            if(init_state->array[y+1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x-1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
    }
    else
    {
        if (x > 0 && x < init_state->x_dimension - 1)
        {
            if(init_state->array[y-1][x-1] == 'X')
                counter++;
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y-1][x+1] == 'X')
                counter++;
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
        else if (x == 0)
        {
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y-1][x+1] == 'X')
                counter++;
            if(init_state->array[y][x+1] == 'X')
                counter++;
            return (counter);
        }
        else
        {
            if(init_state->array[y-1][x-1] == 'X')
                counter++;
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
    }
}

static void    calculate_empty_neighbors(char **array, t_board *init_state, int y, int x)
{
    if(y > 0 && x > 0 && init_state->array[y-1][x-1] == '.')
    {
        if (get_neighbors(init_state, y-1, x-1) == 3)
            array[y-1][x-1] = 'X';
    }
    if(y > 0 && init_state->array[y-1][x] == '.')
    {
        if (get_neighbors(init_state, y-1, x) == 3)
            array[y-1][x] = 'X';
    }
    if(y > 0 && x < init_state->x_dimension - 1 && init_state->array[y-1][x+1] == '.')
    {
        if (get_neighbors(init_state, y-1, x+1) == 3)
            array[y-1][x+1] = 'X';
    }
    if(x < init_state->x_dimension - 1 && init_state->array[y][x+1] == '.')
    {
        if (get_neighbors(init_state, y, x+1) == 3)
            array[y][x+1] = 'X';
    }
    if(y < init_state->y_dimension - 1 && x < init_state->x_dimension - 1 && init_state->array[y+1][x+1] == '.')
    {
        if (get_neighbors(init_state, y+1, x+1) == 3)
            array[y+1][x+1] = 'X';
    }
    if(y < init_state->y_dimension - 1 && init_state->array[y+1][x] == '.')
    {
        if (get_neighbors(init_state, y+1, x) == 3)
            array[y+1][x] = 'X';
    }
    if(y < init_state->y_dimension - 1 && x > 0 && init_state->array[y+1][x-1] == '.')
    {
        if (get_neighbors(init_state, y+1, x-1) == 3)
            array[y+1][x-1] = 'X';
    }
    if(x > 0 && init_state->array[y][x-1] == '.')
    {
        if (get_neighbors(init_state, y, x-1) == 3)
            array[y][x-1] = 'X';
    }
}

static void    calculate_cell(char **array, t_board *init_state, int y, int x)
{
    if (init_state->array[y][x] == 'X')
    {
        if (get_neighbors(init_state, y, x) < 2 || get_neighbors(init_state, y, x) > 3)
            array[y][x] = '.';
        else
            array[y][x] = 'X';
        calculate_empty_neighbors(array, init_state, y, x);
    }
}

static char    **calculate_new_cells(t_board *init_state)
{
    char    **array;
    int     x;
    int     y;

    y = 0;
    array = (char**)malloc(sizeof(*array) * init_state->y_dimension);
    array[0] = (char*)malloc(sizeof(char) * init_state->x_dimension);
    x = 0;
    while (x < init_state->x_dimension)
    {
        array[0][x] = '.';
        x++;
    }
    while (y < init_state->y_dimension)
    {
        if (y < init_state->y_dimension - 1)
        {
            x = 0;
            array[y+1] = (char*)malloc(sizeof(char) * init_state->x_dimension);
            while (x < init_state->x_dimension)
            {
                array[y+1][x] = '.';
                x++;
            }
        }
        x = 0;
        while (x < init_state->x_dimension)
        {
            calculate_cell(array, init_state, y, x);
            x++;
        }
        y++;
    }
    return (array);
}

t_board *play_game(t_board *init_state, int rounds)
{
    char    **new_array;
    int     round;
	int		i;

    round = 1;
    while (round <= rounds)
    {
        new_array = calculate_new_cells(init_state);
		i = init_state->y_dimension;
        while (--i >= 0)
			free(init_state->array[i]);
		free(init_state->array);
        init_state->array = new_array;
        round++;
//        print_board(init_state);
    }
    return (init_state);
}