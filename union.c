#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	char temp[256] = {0};
	char *s1 = av[1], *s2 = av[2];
	while (*s1)
	{
		if (temp[(int)*s1] == 0)
		{
			ft_putchar(*s1);
			temp[(int)*s1] = 1;
		}
		s1++;
	}
	while (*s2)
	{
		if (temp[(int)*s2] == 0)
		{
			ft_putchar(*s2);
			temp[(int)*s2] = 1;
		}
		s2++;
	}
	ft_putchar('\n');
	return (0);
}
