#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	x;

	(void)argc;
	x = atoi(argv[1]);
	while (x > 0)
	{
		printf("%d ", x);
		x--;
	}
	return (0);
}
