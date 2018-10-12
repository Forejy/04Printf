#include "../../Includes/Handlers/handlers.h"
#include <unistd.h>

int		print_padding(t_flag flag, const char **stock, int len_padding)
{
	int		retenue;
	int		flag_pointer;

	retenue = 0;
	flag_pointer = flag.pointer;
	if (!flag.less && *stock && (**stock == '-' || **stock == '+') && flag.character_or_string == 0
		&& !(len_padding > 0 && !flag.zero) && flag.precision < 0)
	{
		write(1, *stock, 1);
		(*stock)++;
		retenue++;
	}
	if (len_padding > 0)
	{
		if ((flag.zero && flag.blank && (flag.conv_d || flag.conv_f) && !retenue )|| flag.less)
		{
			len_padding -= 1;
			write(1, " ", 1);
		}
		if (((flag.precision >= 0 && !flag.character_or_string && !flag.unicode_s && 
			(!flag.blank || (flag.blank && flag.zero))) //cas flag.blank && flag.zero : %0 33.1d, 100
			|| !flag.zero || (flag.zero && flag.less)) && !(flag.conv_f && flag.zero) || (flag.conv_f && flag.less))
			while (len_padding-- > 0)
				write(1, " ", 1);
		else if ((flag.zero || flag.precision >= 0) && (flag_pointer == 2 ||
				flag.hexa == 2 || flag.binary)  && !flag.less && (((flag.hexa  || flag.binary ) && flag.hash == 2) 
				|| (!flag.hexa && !flag.binary)))
		{
				write(1, *stock, 2);
				*stock = *stock + 2;
				retenue += 2;
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
/*
 * 			//Dans le cas des pointeurs :
				//Si on a champs et precision en meme temps 
				// le 0x doit etre imprime avant l'appel de la precision :'    0x''000000000000ffffcb84' 'padding''precision'
				//Si on a flag.zero 
				// le 0x doit etre imprime avant le rembourrage par 0 : 0x000000000000ffffcb84
 */

void		print_conv_f_w_prec(t_flag f, const char *s, int len_prec, int *sign)
{
	int		len_int_part;
	int		padding;

	padding = len_prec - 15;
	len_int_part = f.conv_f_intpart;
	if ((len_prec > 0 && (f.champs < (f.conv_f_intpart + 1 + len_prec) 
		&& f.blank)) || ((len_prec >= f.champs || f.conv_f_intpart >= f.champs  
		|| f.less) && f.blank && s && *s != '-' && *s != '+') && (*sign += 1))
		write(1, " ", 1);
	if (f.precision > 0)
	{
		write(1, s, len_int_part + 1);
		if (len_prec > 0 && len_prec <= 15)
			write(1, &s[len_int_part + 1], len_prec);
		else
		{
			write(1, &s[len_int_part + 1], 15);
			while (padding-- > 0)
				write(1, "0", 1);
		}
	}
	else if (f.precision == 0)
		write(1, s, len_int_part + f.hash/2);
}
 
int		print_result_w_precision(t_flag flag, const char *stock, int len_argument)
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
	if (flag.conv_f)
		print_conv_f_w_prec(flag, stock, len_precision, &sign);
	if (flag.character_or_string == 0 && stock && (*stock == '-' || *stock == '+')
		&& (len_precision >= len_argument && !flag.conv_f))
	{
		write(1, stock, 1);
		stock++;
		len_argument--;
		sign = 1;
	}
	if (flag.character_or_string == 0 && flag.unicode_c == 0 && flag.unicode_s == 0 && !flag.conv_f)
	{
		if (len_precision > 0 && (len_precision > len_argument - flag.hexa - flag.binary)
			&& (flag.pointer == 2 || ((flag.hexa == 2 || flag.binary) && flag.hash)))
		{
			write(1, stock, 2);
			stock = stock + 2;
			len_argument -= 2;
			Ox += 2;
		}
		temp = len_precision - len_argument + ret;
		if ((len_precision >= flag.champs || len_argument >= flag.champs  || flag.less) //|| (len_argument + len_precision) >= flag.champs 
			&& flag.blank //|| (stock && *stock == '0')) 
			&& !sign && stock && *stock != '-' && *stock != '+')
		{
			write(1, " ", 1);
			ret += 1;
		}
		while (temp-- > 0)
			write(1, "0", 1);
	}
	if (stock && (flag.character_or_string == 2 || flag.unicode_c || flag.unicode_s) && len_precision >= 0
		&& len_precision < len_argument && !flag.conv_f)
		write(1, stock, (size_t) (len_precision));
	else if (flag.unicode_c == 1)
		while (len_argument > 0)
			write(1, &stock[len_argument-- - 1], 1);
	else if (flag.unicode_s == 1)
		while(i < len_argument)
			write(1, &stock[i++], 1);
	else if (stock && len_argument > 0 && !flag.conv_f)
			write(1, stock, (size_t) (len_argument));
	return(ret + sign + Ox);
}

int		compute_padding_conv_f(const char *stock, t_flag flag, int len_arg)
{
	int		len_padding;
	int		len_champs;
	int		len_precision;
	
	len_padding = 0;
	len_champs = flag.champs;
	len_precision = flag.precision;
	if (len_precision == -1 && len_champs > 0)
		len_padding = len_champs - len_arg;
	else if (len_precision == 0 && len_champs == (flag.conv_f_intpart + 1))// Pourquoi cette ligne ?
		len_padding = 1;
	else if (len_precision == 0)
		len_padding = len_champs - flag.conv_f_intpart;
	else if (len_precision > 0 && flag.champs > flag.conv_f_intpart + 1 + len_precision)
		len_padding = len_champs - (flag.conv_f_intpart + 1) - len_precision ;
	return (len_padding);
}

int			compute_padding(const char *stock, t_flag flag, int len_precision, int len_arg)//, int wtf
{
	int			len_padding;
	int			len_champs;

	len_champs = flag.champs;
	len_padding = -1;
	if (flag.conv_f)
		len_padding = compute_padding_conv_f(stock, flag, len_arg);
	else if (flag.hash == 2 && (flag.hexa == 2 || flag.binary) && len_precision > len_arg - 2)
		len_padding = len_champs - len_precision - 2;
	else if (len_precision >= (len_arg - flag.pointer) && flag.character_or_string == 0
		&& flag.unicode_c == 0 && flag.unicode_s == 0)//Si l'argument est un pointeur, je supprimne le '0x' de sa longueur
	{
		len_padding = len_champs - len_precision;
		if (*stock == '-' || (*stock == '+'))
			len_padding -= 1;
	}
	else if (len_precision >= 0 && len_precision <= len_arg && (flag.character_or_string == 2
			 || flag.unicode_c || flag.unicode_s)) //Cas Unicode
		len_padding = len_champs - len_precision;
	else if (!flag.unicode_s || (flag.unicode_s && len_champs > len_arg))
		len_padding = len_champs - len_arg + flag.pointer; //J'ajoute flag.pointer pour annuler la soustraction finale
	if (stock && *stock != '+' && *stock != '-' && flag.less && flag.blank && (flag.conv_d || flag.conv_f_intpart))//Cas " -3zi" = { 0 } : blank a gauche par defaut, puis suite du padding a droite 
		len_padding -= 1;
	return (len_padding - flag.pointer);
}

int			print_result_with_no_precision(t_flag flag, const char *stock, int len_argument)//, int len_padding
{
	int		i;
	int 	ret;

	i = 0;
	ret = 0;
	if ((flag.conv_d || flag.conv_f) && flag.blank && *stock != '-' 
		&& *stock != '+' && (flag.champs <= len_argument || flag.less))
	{
		write(1, " ", 1);
		ret++;
	}
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


intmax_t		print_final_result(t_flag flag, const char *stock, int len_argument)
{
	int						len_precision;
	int						len_padding;
	unsigned long long		total_len;
	int						sign;

	len_padding = -1;
	len_precision = flag.precision;
	total_len = 0;
	sign = 0;
	write(1, flag.buffer, flag.len_buffer);
	if(flag.champs > 0)
		len_padding = compute_padding(stock, flag, len_precision, len_argument);
	if (len_padding > 0 && flag.less == 0)
	{
		sign = print_padding(flag, &stock, len_padding);
		len_argument = len_argument - sign;
	}
	if (len_precision != -1)
		total_len += print_result_w_precision(flag, stock, len_argument);			//, len_padding;
	else
		total_len += print_result_with_no_precision(flag, stock, len_argument);//, int len_padding
	if (len_padding >= 0 && flag.less == 1)
		print_padding(flag, &stock, len_padding);
	if (len_padding < 0)
		len_padding = 0;
	if (flag.conv_f)
	{
		if (len_padding > 0 && len_precision > 0)
			total_len += len_padding + flag.conv_f_intpart + 1 + flag.precision;
		else if (len_padding > 0 && len_precision == 0)
			total_len += len_padding + flag.conv_f_intpart;
		else if (len_padding <= 0 && len_precision > 0)
			total_len += flag.precision + flag.conv_f_intpart + 1;
		else if (len_precision == -1)
			total_len += len_argument + len_padding;
		else
			total_len += flag.conv_f_intpart;
	}
	else if (((flag.hexa || flag.binary) && (len_precision > (len_argument - flag.hash) 
		|| len_precision > len_argument )) //&& flag.character_or_string == 0
		|| (((flag.character_or_string == 2 || flag.unicode_s) && (len_precision != -1 
		|| (flag.unicode_c && len_precision > 0)))
		//&& len_precision < len_arg)
		&& len_precision < len_argument)

		   || ((!flag.hexa || !flag.binary) && !flag.unicode_s && !flag.unicode_c && !flag.character_or_string
		//&& ((len_precision > len_padding) && len_precision >= len_argument 
		&& len_precision > len_argument))
		total_len += (size_t)len_padding + (size_t)len_precision;
	else if (flag.character_or_string == 2 && len_precision == 0) 
		total_len += len_padding;
	else
		total_len += (size_t)len_padding + (size_t)len_argument;
	return (total_len + sign);
}
