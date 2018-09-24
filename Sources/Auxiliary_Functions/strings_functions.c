#include <unistd.h>
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

size_t		my_strlen(const char *str)
{
	size_t		i;

	i = 3;
	while (1)
	{
		if (str[i - 3] == '\0')
			return (i - 3);
		else if (str[i - 2] == '\0')
			return (i - 2);
		else if (str[i - 1] == '\0')
			return (i - 1);
		else if (str[i] == '\0')
			return (i);
		i += 4;
	}
}

int			my_putchar_printf(char c, t_flag flag)
{
	int			total_len;

	flag.character_or_string = 1;
	if (flag.champs == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	else
		total_len = print_final_result(flag, &c, 1);
	return(total_len);
}

size_t		my_putstr_printf(const char *str, t_flag flag)
{
	size_t		len_str;
	int			flag_precision;
	size_t		total_len;

	if (str == NULL && flag.champs == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (str == NULL)
		return(print_final_result(flag, "(null)", 6));
	len_str = 0;
	if (str != NULL)
		len_str = my_strlen(str);
	flag.character_or_string = 2;
	flag_precision = flag.precision;
//	if (flag_precision > -1 && flag_precision < len_str)
//		len_str = (size_t)flag_precision;
	if (flag.champs == 0)
	{
		if (flag_precision > -1 && flag_precision < (int)len_str)
			len_str = (size_t)flag_precision;
		write(1, str, len_str);
		total_len = len_str;
	}
	else
		total_len = print_final_result(flag, str, len_str);
	return (total_len);
}

size_t			my_putstr(const char *str)
{
	size_t				total_len;

	total_len = my_strlen(str);
		write(1, str, total_len);
	return(total_len);
}
