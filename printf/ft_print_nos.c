#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (len > 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}

static void	ft_putnbr_buff(long nb, int *len)
{
	char	res[12];
	int		i;

	i = 0;
	if (nb == 0)
	{
		*len += write(1, "0", 1);
		return ;
	}
	while (nb > 0)
	{
		res[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (--i >= 0)
		*len += write(1, &res[i], 1);
}

int	ft_printnbr(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	ft_putnbr_buff(nb, &len);
	return (len);
}
