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

unsigned long long		power_of_10(int n)
{
	unsigned long long			power;
	
	power = 1;
	if (n <= 0)
		power = 1;
	while (n-- > 0)
		power = power * 10;
	return (power);
}

size_t		my_putnbr_double(double nbr, t_flag flag)
{
	unsigned long long		int_part;
	double		dec_part;
	unsigned long long dec_part_bis;
	char	stock_number[36];//20 chars pour ULLONG_MAX, 1 pour '.', et 6 pour la partie decimal
	int			i;
	int		total_len;
	double		nb;
	int			len_precision;
	
	i = 35;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	int_part = nb;
	dec_part = (nb - int_part) * 1000000000000000;
	dec_part_bis = dec_part;
	flag.conv_f = 1;
	len_precision = flag.precision <= 15 ? flag.precision : 15;
	len_precision = len_precision == -1 ? 6 : len_precision;
/*	if ((dec_part_bis % 10) >= 5)
	{
		if (dec_part_bis/10 == 999999999999999)
		{
			int_part += 1;
			dec_part_bis = 0;
		}
		else
			dec_part_bis = dec_part_bis / 10 + 1;
	}
 
	else
		dec_part_bis = dec_part_bis/10;
		*/
	if (len_precision > 0 && dec_part_bis != 0)
	{
		dec_part_bis = dec_part_bis/power_of_10(14 - len_precision);//Divise par longueur du nombre - 1
		if (dec_part_bis % 10 >= 5 && flag.precision <= 15)
			dec_part_bis = dec_part_bis/10 + 1;
		else if (flag.precision <= 15)
			dec_part_bis = dec_part_bis/10;
		i = 20 + len_precision;
	}
	else if (dec_part_bis == 0)
		while (i > 20)
			stock_number[i--] = '0';
	while (dec_part_bis > 0)
	{
		stock_number[i] = (char) ((dec_part_bis % 10) + '0');
		dec_part_bis = dec_part_bis / 10;
		i--;
	}
	if(!(len_precision == 0 && !flag.hash))
	{
		stock_number[i = 20] = '.';
		i--;
	}
	if (int_part == 0)
	{
		stock_number[i = 19] = '0';
		flag.conv_f_intpart++;
		i--;
	}
	while (int_part > 0)
	{
		stock_number[i] = (char) ((int_part % 10) + '0');
		int_part = int_part / 10;
		flag.conv_f_intpart++;
		i--;
	}
	if (nbr < 0)
		stock_number[i--] = '-';
	if (nbr >= 0 && flag.more)
		stock_number[i--]= '+';
	if (nbr < 0 || (nbr >= 0 && flag.more))
		flag.conv_f_intpart += 1;
	total_len = print_final_result(flag, &stock_number[i + 1], len_precision + flag.conv_f_intpart + 1);
	return (total_len);
}


