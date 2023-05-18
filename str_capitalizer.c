#include <unistd.h>

char	*lower_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	str_capitalizer(char *str)
{
	int	i;

	str = lower_case(str);
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if (str[i - 1] == ' ' || str[i - 1] == '\t')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc > 1)
	{
		while (argv[index])
		{
			str_capitalizer(argv[index]);
			write(1, "\n", 1);
			index++;
		}
	}
	else
		write(1, "\n", 1);
}