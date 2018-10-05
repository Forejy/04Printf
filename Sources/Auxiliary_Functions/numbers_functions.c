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
		stock_number[i--] = '-';
	if (nbr >= 0 && flag.more)
		stock_number[i--]= '+';
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}

size_t		my_putnbr_double(double nbr)
{
	long double	nb;
	long double int_part_test;
	long long		int_part;
	int		decimal_part;
	char	string[318];//20 chars pour ULLONG_MAX, 1 pour '.', et 6 pour la partie decimal
	int		total_len;
	t_flag 	flag;
	
	total_len = 0;
	initialize_t_flag(&flag);
	
	nb = nbr;
	
	string[0] = (char)nb;
	/*
	nb = nbr/10;
	int_part = nbr;
	decimal_part = (nbr - int_part) * 1000000;
	total_len += my_putnbr_long_long(int_part, flag);
	write(1, ".", 1);
	total_len += 1;
	total_len += my_putnbr_long_long(decimal_part, flag);
	 */
	
	return (0);
}


