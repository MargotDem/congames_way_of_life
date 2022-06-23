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

void	*ft_memset(void *s, int c, size_t n)
{
	char	*content;
	size_t	index;

	content = (char *)s;
	index = 0;
	while (index < n)
	{
		content[index] = (char)c;
		index++;
	}
	return (s);
}

int get_neighbors(t_board *init_state, int y, int x)
{
    int counter;

    counter = 0;
    if (y == 0)
    {
        if (x == 0)
        {
            if(init_state->array[y][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x+1] == 'X')
                counter++;
            if(init_state->array[y+1][x] == 'X')
                counter++;
            return (counter);
        }
        else if (x == init_state->x_dimension - 1)
        {
            if(init_state->array[y+1][x] == 'X')
                counter++;
            if(init_state->array[y+1][x-1] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
        else
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
    }
    else if (y == init_state->y_dimension - 1)
    {
        if (x == 0)
        {
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y-1][x+1] == 'X')
                counter++;
            if(init_state->array[y][x+1] == 'X')
                counter++;
            return (counter);
        }
        else if (x == init_state->x_dimension - 1)
        {
            if(init_state->array[y-1][x-1] == 'X')
                counter++;
            if(init_state->array[y-1][x] == 'X')
                counter++;
            if(init_state->array[y][x-1] == 'X')
                counter++;
            return (counter);
        }
        else
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
    }
    else
    {
        if (x == 0)
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
        else if (x == init_state->x_dimension - 1)
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
        else
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
    }
}

char    calculate_cell(t_board *init_state, int y, int x)
{
    if (init_state->array[y][x] == 'X')
    {
        if (get_neighbors(init_state, y, x) < 2 || get_neighbors(init_state, y, x) > 3)
            return ('.');
        else
            return ('X');
    }
    else
    {
        if (get_neighbors(init_state, y, x) == 3)
            return ('X');
        else
            return ('.');
    }
}

char    **calculate_new_cells(t_board *init_state)
{
    char    **array;
    int     x;
    int     y;

    y = 0;
    array = (char**)malloc(sizeof(*array) * init_state->y_dimension);
    while (y < init_state->y_dimension)
    {
        x = 0;
        array[y] = (char*)malloc(sizeof(char) * init_state->x_dimension);
        while (x < init_state->x_dimension)
        {
            array[y][x] = calculate_cell(init_state, y, x);
            x++;
        }
        y++;
    }
    return (array);
}

t_board *play_game(t_board *init_state, int rounds)
{
    t_board *new_state;
    int     round;

    round = 1;
    while (round <= rounds)
    {
        new_state = (t_board*)malloc(sizeof(t_board));
        ft_memset(new_state, '\0', sizeof(t_board));
        new_state->x_dimension = init_state->x_dimension;
        new_state->y_dimension = init_state->y_dimension;
        new_state->array = calculate_new_cells(init_state);
        init_state->array = new_state->array;
        free(new_state);
        round++;
    }
    return (init_state);
}

int get_y_dimension(char *initial_state)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (initial_state[i] != '\0')
    {
        if (initial_state[i] == '\n')
            counter++;
        i++;
    }
    
    return (counter - 1);
}

int get_x_dimension(char *initial_state)
{
    int i;

    i = 0;
    while (initial_state[i] != '\n' && initial_state[i] != '\0')
        i++;
    return (i);
}

t_board *make_board(char *initial_state)
{
    t_board *board;
    char    **array;
    char    *row;
    int     x;
    int     y;
    int     i;

    board = (t_board*)malloc(sizeof(t_board));
    ft_memset(board, '\0', sizeof(t_board));
    board->x_dimension = get_x_dimension(initial_state);
    board->y_dimension = get_y_dimension(initial_state);
    y = 0;
    i = 0;
    array = (char**)malloc(sizeof(*array) * board->y_dimension);
    while (y < board->y_dimension)
    {
        x = 0;
        row = (char*)malloc(sizeof(row) * board->x_dimension);
        while (x < board->x_dimension)
        {
            row[x] = initial_state[i];
            x++;
            i++;
        }
        array[y] = row;
        y++;
        i++;
    }
    board->array = array;
    return (board);
}

char    *read_file(char *file)
{
    FILE    *fp;
    char    c;
    char    *str;
    int     i;

    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Error opening file");
        return (NULL);
    }
    c = fgetc(fp);
    if (c != '.' && c != 'X')
    {
        printf("Empty file");
        return (NULL);
    }
    str = (char*)malloc(sizeof(*str));
    str[0] = c;
    i = 1;
    while (1)
    {
        c = fgetc(fp);
        if (feof(fp))
            break;
        str = (char*)realloc(str, sizeof(*str) * i + 1);
        str[i] = c;
        i++;
    }
    str = (char*)realloc(str, sizeof(*str) * i + 2);
    str[i] = '\n';
    str[i + 1] = '\0';
    return (str);
}

void    life(char *file, int iterations)
{
    t_board *board;
    char    *initial_state;

    initial_state = read_file(file);
    board = make_board(initial_state);
    board = play_game(board, iterations);
    print_board(board);
}

int main(int ac, char **av)
{
    if (ac == 3)
        life(av[1], atoi(av[2]));
    else
        printf("usage: ./life <initial state file> <iterations>");
    return (0);
}