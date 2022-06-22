#include "life.h"

char	*read_state(char *file)
{
	FILE	*fp;
	char	c;
	char	*temp;
	char	*state;
	int		i;
	int		j;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		return (NULL);
	}
	i = 0;
	while (1)
	{
		c = fgetc(fp);
		if (feof(fp))
			break;
		if (i != 0)
		{
			temp = (char*)malloc(sizeof(temp) * i);
			j = 0;
			while (j < i)
			{
				temp[j] = state[j];
				j++;
			}
		}
		state = (char*)malloc(sizeof(temp) * i + 1);
		if (i != 0)
		{
			j = 0;
			while (j < i)
			{
				state[j] = temp[j];
				j++;
			}
		}
		state[i] = c;
		i++;
	}
	temp = (char*)malloc(sizeof(temp) * i);
	temp = state;
	state = (char*)malloc(sizeof(temp) * i + 1);
	state = temp;
	state[i] = '\0';
	return (state);
}

char	*read(char *file)
{
	char	*state;

	state = read_state(file);
	printf("%s", state);
	return (state);
}