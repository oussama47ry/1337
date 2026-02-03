
#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count += ft_putchar('%');
	else
	{
    count += write(1, "%", 1);
    count += ft_putchar(c);
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    int     i;

    if (!format || write(1, "", 0) == -1)
        return (-1);
    va_start(args, format);
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (!format[++i])
            {
                va_end(args);
                return (-1);
            }
            count += ft_format(format[i++], args);
        }
        else
            count += ft_putchar(format[i++]);
    }
    va_end(args);
    return (count);
}
