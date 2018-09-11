#include <unistd.h>
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

size_t		my_putaddress(unsigned long long nb, t_flag flag)
{
	char		stock_number[12];
	int			i;
	char		*base_hexa;
	size_t			total_len;

	base_hexa = "0123456789abcdef";
	i = 11;
	flag.pointer = 2;
	if (nb == 0)
		stock_number[i--] = '0';
	while (nb > 0)
	{
		stock_number[i] = base_hexa[(nb % 16)];
		nb = (nb / 16);
		i--;
 	}
	stock_number[i--] = 'x';
	stock_number[i--] = '0';
	total_len = print_final_result(flag, &stock_number[i + 1],
								   11 - i, 11 - i );
	return (total_len);
}