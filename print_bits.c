#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	print;

	i = 7;
	while (i >= 0)
	{
		print = ((octet >> i) & 1) + '0';
		write(1, &print, 1);
		i--;
	}
}

/*
int	main(int argc, char **argv)
{
	unsigned char	input;

	if (argc == 2)
	{
		input = argv[1][0];
		print_bits(input);
	}
	write(1, "\n", 1);
}
*/

/*
<NOTE>
In the exam, it was a little confusing because I did not see the same
result as what's given in the subject when I gave 2 as the parameter.
I tried my function with other inputs like 'H' or 'a' and saw that
everything was working except for numbers.

The function above will give 00110010 when 2 is given. I found out that
this calculates to 50, which is the ascii code of "2". I added a few more
lines to handle this (where a number is recognized and is made sure the
actual number is going through the bit operation, not its ascii number).

I got a KO with this additional lines. As I could not see anything else 
that could potentially be a problem, I deleted these lines assuming that 
this would be handled in another function of the marking system (because
we were told to write a function, not a program, in the subject). This 
guess was right and my file passed successfully after deleting these 
additional lines. 
*/