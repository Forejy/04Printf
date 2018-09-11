#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"
#include <unistd.h>

size_t			my_putnbr_hexa(uintmax_t nb, t_flag flag)
{
	char		stock_number[20];
	int			i;
	char		*base_hexa;
	size_t				total_len;

	base_hexa = "0123456789abcdef";
	i = 19;
	total_len = 0;
	flag.hexa = 2;
	if (nb == 0 && flag.precision != 0)
	{
		stock_number[i] = '0';
		i--;
	}
	else if(nb != 0)
	{
		while (nb > 0)
		{
			stock_number[i] = base_hexa[(nb % 16)];
			nb = (nb / 16);
			i--;
		}
		if (flag.hash == 2)
		{
			stock_number[i--] = 'x';
			stock_number[i--] = '0';
		}
	}
	total_len = total_len + print_final_result(flag, &stock_number[i + 1], 19 - i, 19 - i);
	return (total_len);

}

size_t			my_putnbr_HEXA(uintmax_t nb, t_flag flag)
{
	char		stock_number[20];
	int			i;
	char		*base_hexa;
	size_t			total_len;
	base_hexa = "0123456789ABCDEF";
	i = 19;
	total_len = 0;
	flag.hexa = 2;
	if (nb == 0 && flag.precision != 0)
	{
		stock_number[i] = '0';
		i--;
	}
	else
	{
		while (nb > 0)
		{
			stock_number[i] = base_hexa[(nb % 16)];
			nb = (nb / 16);
			i--;
		}
		if (flag.hash == 2)
		{
			stock_number[i--] = 'X';
			stock_number[i--] = '0';
		}
	}
	total_len = total_len + print_final_result(flag, &stock_number[i + 1], 19 - i, 19 - i);
	return (total_len);

}
