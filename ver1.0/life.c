int	main(int ac, char av)
{
	if (ac == 3)
		life(av[1], atoi(av[2]));
	else
		printf("usage: ./life <initial state file> <number of iterations>");
}