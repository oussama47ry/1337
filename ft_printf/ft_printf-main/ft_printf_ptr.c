
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(addr, 0);
	return (count);
}
