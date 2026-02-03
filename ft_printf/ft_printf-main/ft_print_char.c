
#include "ft_printf.h"

int	ft_putchar(char c)
{
	int r;

	r = write(1, &c, 1);
	if (r == -1)
		return (-1);
	return (1);
}
