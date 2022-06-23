#include "life.h"

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

static int get_y_dimension(char *initial_state)
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

static int get_x_dimension(char *initial_state)
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