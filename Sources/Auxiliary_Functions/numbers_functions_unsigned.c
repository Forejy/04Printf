#include "../../Includes/Auxiliary_Functions/strings_functions.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

size_t			my_put_unsigned_long_long(uintmax_t nbr, t_flag flag)
{
	char			stock_number[20];
	int				i;
	size_t			total_len;

	i = 19;
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
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}
