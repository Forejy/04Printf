#include "../../Includes/Handlers/handlers.h"
#include <unistd.h>

int		print_sign(char c, t_flag flag)
{
	if (c == '-' && !flag.blank)
	{
		write(1, "-", 1);
		return (1);
	}
	if (c == '+' && !flag.blank)
	{
		write(1, "+", 1);
		return (1);
	}
	return (0);
}

int		print_padding(t_flag flag, const char **stock, int len_padding)
{
	int		retenue;
	int		flag_pointer;

	retenue = 0;
	flag_pointer = flag.pointer;

	if (!flag.less && *stock && (**stock == '-' || **stock == '+') && !(len_padding > 0 && !flag.zero)  && flag.precision < 0)
	{
		write(1, *stock, 1);
		(*stock)++;
		retenue++;
	}
	 //Cas si on a pas de precision, et pas de padding ou un flag '0'
	if (len_padding > 0)
		//&& !flag.unicode_s
	{
		if (flag.zero && flag.blank && flag.conv_d)
		{
			len_padding -= 1;
			write(1, " ", 1);
		}
		if (flag.precision >= 0 && !flag.character_or_string && !flag.unicode_s)
			while (len_padding-- > 0)
				write(1, " ", 1);
		else if (!flag.zero || flag.zero && flag.less)
			while (len_padding-- > 0)
				write(1, " ", 1);
		else if ((flag.zero || flag.precision >= 0) && (flag_pointer == 2 ||
				 flag.hexa == 2 )  && !flag.less && ((flag.hexa && flag.hash == 2) || !flag.hexa))
			//Dans le cas des pointeurs :
				//Si on a champs et precision en meme temps 
				// le 0x doit etre imprime avant l'appel de la precision :'    0x''000000000000ffffcb84' 'padding''precision'
				//Si on a flag.zero 
				// le 0x doit etre imprime avant le rembourrage par 0 : 0x000000000000ffffcb84
		{
				write(1, *stock, 2);
				*stock = *stock + 2;
				retenue = 2;
			if (flag.precision <= 0)
				while (len_padding-- > 0)
					write(1, "0", 1);
		}
		else if (flag.zero && !flag.less)
			while (len_padding-- > 0)
				write(1, "0", 1);
	}
	return (retenue);
}

int		print_result_w_precision(t_flag flag, const char *stock, int len_argument, int len_padding)
{
	int		i;
	int		temp;
	int		ret;
	int 	sign;
	int 	len_precision;
	int		Ox;

	i = 0;
	ret = 0;
	sign = 0;	
	Ox = 0;
	len_precision = flag.precision;
	if (len_precision >= len_argument && stock && (*stock == '-' || *stock == '+') && flag.character_or_string == 0)
		//&&(len_padding < len_precision || len_padding > len_precision ) && 
	//len_padding > len_precision
	{
		write(1, stock, 1);
		stock++;
		len_argument--;
		sign = 1;
	}
	if (len_precision > 0 && flag.character_or_string == 0 && flag.unicode_c == 0 && flag.unicode_s == 0)
	{
		if (len_precision > len_argument && flag.pointer == 2 || (flag.hexa == 2 && flag.hash))
			//&& flag.champs < len_precision))
			//&& flag.champs == 0)
		{
			write(1, stock, 2);
			stock = stock + 2;
			len_argument -= 2;
			Ox += 2;
		}
		temp = len_precision - len_argument + ret;
		if (len_padding < len_argument && len_padding < len_precision && flag.blank && !sign 
			&& stock && *stock != '-' && *stock != '+')
		//&& len_argument >= len_precision
		{
			write(1, " ", 1);
			ret += 1;
		}
		while (temp-- > 0)
			write(1, "0", 1);
	}
	if (stock && (flag.character_or_string == 2 || flag.unicode_c || flag.unicode_s) && len_precision >= 0
		&& len_precision < len_argument)
		write(1, stock, (size_t) (len_precision));
	else if (flag.unicode_c == 1)
		while (len_argument > 0)
			write(1, &stock[len_argument-- - 1], 1);
	else if (flag.unicode_s == 1)
		while(i < len_argument)
			write(1, &stock[i++], 1);
	else if (stock)
			write(1, stock, (size_t) (len_argument));
	return(ret + sign + Ox);
}


int			compute_padding(const char *stock, t_flag flag, int len_arg, int wtf)
{
	int			len_padding;
	int			len_champs;
	int 		len_precision;

	len_champs = flag.champs;
	len_precision = flag.precision;
	if (len_champs > 0 && len_precision >= (len_arg - flag.pointer) && flag.character_or_string == 0
		&& flag.unicode_c == 0 && flag.unicode_s == 0)//Si l'argument est un pointeur, je supprimne le '0x' de sa longueur
	{
		len_padding = len_champs - len_precision;
		if (*stock == '-' || (*stock == '+'))
			len_padding -= 1;
	}
	else if (len_precision >= 0 && len_precision <= len_arg && (flag.character_or_string == 2
			 || flag.unicode_c || flag.unicode_s))
		len_padding = len_champs - len_precision;
	else if (flag.hash == 2 && flag.zero && !flag.less && len_precision == -1 && !flag.hexa)
		len_padding = len_champs - len_arg + flag.pointer + flag.hash;
	else if (!flag.unicode_s || (flag.unicode_s && len_champs > len_arg))
		len_padding = len_champs - len_arg + flag.pointer; //J'ajoute flag.pointer pour annuler la soustraction finale
	return (len_padding - flag.pointer);
}

int			print_result_with_no_precision(t_flag flag,char *stock, int len_argument, int len_padding)
{
	int		i;
	int 	ret;

	i = 0;
	ret = 0;

	if (len_padding <= -1 && flag.conv_d && flag.blank && *stock != '-' && *stock != '+')
	{
		write(1, " ", 1);
		ret++;
	}
	/*
	if (stock && (*stock == '-' || *stock == '+') && flag.character_or_string == 0)
	{
		write(1, stock, 1);
		stock++;
		len_argument--;
		ret++;
	}
	 */
	if (flag.unicode_c == 1)
		while (len_argument > 0)
			write(1, &stock[len_argument-- - 1], 1);
	else if (flag.unicode_s == 1)
		while(i < len_argument)
			write(1, &stock[i++], 1);
	else if (stock)
		write(1, stock, len_argument);
	return(ret);
}


size_t		print_final_result(t_flag flag, const char *stock, int len_argument)
{
	int						len_precision;
	int						len_padding;
	unsigned long long		total_len;
	int						sign;

	len_padding = -1;
	len_precision = flag.precision;
	len_padding = compute_padding(stock, flag, len_argument, 42);
	total_len = 0;
	sign = 0;

	if (len_padding > 0 && flag.less == 0)
	{
		sign = print_padding(flag, &stock, len_padding);
		len_argument = len_argument - sign;
	}
	if (len_precision != -1)
		total_len += print_result_w_precision(flag, stock, len_argument, len_padding);
	else
		total_len += print_result_with_no_precision(flag, stock, len_argument, len_padding);
	if (len_padding >= 0 && flag.less == 1)
		print_padding(flag, &stock, len_padding);
	if (len_padding < 0)
		len_padding = 0;
	if ((flag.hexa  && (len_precision > (len_argument - flag.hash) 
		|| len_precision > len_argument )) //&& flag.character_or_string == 0
		|| (((flag.character_or_string == 2 || flag.unicode_s) && len_precision != -1 
		|| (flag.unicode_c && len_precision > 0)) 
		//&& len_precision < len_arg)
		&& len_precision < len_argument)

		   || (!flag.hexa && !flag.unicode_s && !flag.unicode_c && !flag.character_or_string
		//&& ((len_precision > len_padding) && len_precision >= len_argument 
		&& len_precision > len_argument))
		total_len += (size_t)len_padding + (size_t)len_precision;
	else if (flag.character_or_string == 2 && len_precision == 0) 
		total_len += len_padding;
	else
		total_len += (size_t)len_padding + (size_t)len_argument;
	return (total_len + sign);
}
