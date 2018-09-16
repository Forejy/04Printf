#include <unistd.h>
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

size_t		my_putnbr_long_long(intmax_t nbr, t_flag flag)
{
	char			stock_number[20];
	int				i;
	uintmax_t		nb;
	size_t				total_len;

	flag.conv_d = 1;
	i = 19;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb == 0 && flag.precision != 0)
	{
		stock_number[i] = '0';
		i--;
	}
	while (nb > 0)
	{
		stock_number[i] = (char) ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	if (nbr < 0)
	{
		stock_number[i] = '-';
		i--;
	}
	if (nbr >= 0 && flag.more)
		stock_number[i--]= '+';
	if (nbr >= 0 && flag.champs == 0 && flag.blank && !flag.more)
	{
		stock_number[i] = ' ';
		i--;	
	}
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i, 19 - i);
	return (total_len);

}
