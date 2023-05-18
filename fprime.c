#include <stdio.h>
#include <stdlib.h>

void	get_primes(int number)
{
	int	i;

	i = 2;
	while (number != 1)
	{
		if (number % i == 0)
		{
			if (number / i == 1)
				printf("%d", i);
			else
				printf("%d*", i);
			number = number / i;
			i = 2;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number == 1 || number == 2)
			printf("%d", number);
		else
			get_primes(number);
	}
	printf("\n");
}