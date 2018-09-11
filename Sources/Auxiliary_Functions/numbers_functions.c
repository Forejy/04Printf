#include <unistd.h>
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

size_t		my_putnbr_long_long(intmax_t nb, t_flag flag)
{
	char			stock_number[20];
	int				i;
	uintmax_t		nbr;
	size_t				total_len;

	i = 19;
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	if (nbr == 0 && flag.precision != 0)
	{
		stock_number[i] = '0';
		i--;
	}
	while (nbr > 0)
	{
		stock_number[i] = (char) ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	if (nb < 0)
	{
		stock_number[i] = '-';
		i--;
	}
	if (nb >= 0 && flag.more)
		stock_number[i--]= '+';
	if (nb >= 0 && flag.champs == 0 && flag.blank && !flag.more)
	{
		stock_number[i] = ' ';
		i--;	
	}
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i, 19 - i);
	return (total_len);

}
