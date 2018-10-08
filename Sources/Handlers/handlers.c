#include "../../Includes/Auxiliary_Functions/strings_functions.h"
#include "../../Includes/Print_Unicode/print_unicode.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_unsigned.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_octal.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_hexa.h"
#include "../../Includes/Auxiliary_Functions/print_pointer_address.h"
#include "../../Includes/errors.h"
#include "../../Includes/Auxiliary_Functions/bonus.h"
#include "../../Includes/Handlers/handle_colors.h"


static int			define_lenght_conv(const char *length, t_flag *flag)
{
	int lenght_conv;

	lenght_conv = 0;
	if (*length == 'l')
	{
		if (*(length + 1) == 'l')
			lenght_conv = LL;
		else
			lenght_conv = L;
	}
	else if (*length == 'h')
	{
		if (*(length + 1) == 'h')
			lenght_conv = HH;
		else
			lenght_conv = H;
	}
	else if (*length == 'j')
		lenght_conv = J;
	else if (*length == 'z')
		lenght_conv = Z;
	if (lenght_conv > flag->lenght_conv)
		flag->lenght_conv = lenght_conv;
	return (lenght_conv % 3);
}




void			initialize_t_flag(t_flag	*flag)
{
	flag->more = 0;
	flag->less = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->blank = 0;
	flag->champs = 0;
	flag->precision = -1;
	flag->pointer = 0;
	flag->hexa = 0;
	flag->binary = 0;
	flag->octal = 0;
	flag->character_or_string = 0;
	flag->unicode_c = 0;
	flag->unicode_s = 0;
	flag->conv_d = 0;
	flag->conv_f = 0;
	flag->conv_f_intpart = 0;
	flag->lenght_conv = 0;
}

int			test_flag(char format_flag, t_flag	*flag)
{
	if (format_flag == '+')
	{
		flag->more = 1;
		return (1);
	}
	if (format_flag == '-')
	{
		flag->less = 1;
		return (1);
	}
	if (format_flag == '0')
	{
		flag->zero = 1;
		return (1);
	}
	if (format_flag == '#')
	{
		flag->hash = 2;
		return (1);
	}
	if (format_flag == ' ')
	{
		flag->blank = 1;
		return (1);
	}
	else
		return (0);
}

int			test_champs(const char *format, t_flag *flag, va_list *ap)
{
	int		i;
	int		nb;
	int		temp_star;

	i = 0;
	nb = 0;
	
	if (format[0] == '*')
	{
		temp_star = va_arg(*ap, int);
		if (temp_star < 0)
		{
			flag->less = 1;
			temp_star *= -1;
		}
		flag->champs = temp_star;
		return (1);
	}
	if (format[0] == '0')//Si on a un 0 et pas de '.' derriere, on doit traiter le 0 dans la fonction test_flags
	{
		while (format[i] == '0')
			i++;
		if (format[i] != '.')
			return (i - 1);
		else
			return (i);
	}
	while (format[i] >= '0' && format[i] <= '9')
	{
		nb = nb * 10 + (format[i] - '0');
		i++;
	}
	if (nb > 0)
		flag->champs = nb;
	if (i > 0)
		return (i);
	return (0);
}

int				test_precision(const char *format, t_flag *flag, va_list *ap)
{
	int		i;
	int		nb;
	int		temp_star;

	i = 0;
	nb = 0;
	if (format[0] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
		{
			nb = nb * 10 + (format[i] - '0');
			i++;
		}
		if (format[i] == '*')
		{
			temp_star = va_arg(*ap, int);
			if (temp_star >= 0)
				flag->precision = temp_star;
			i++;
		}
		else if (nb >= 0)
			flag->precision = nb;

	}
	return (i);
}

 
int			analyze_and_printf(const char *format, va_list *ap, t_flag *flag)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = -1;
	if (*format == '\0')
	{
		write(1, flag->buffer, flag->len_buffer);
		return (0);
	}
	initialize_t_flag(flag);
	while (i > j)
	{
		j = i;
		i += test_flag(format[i], flag);
		i += define_lenght_conv(&format[i], flag);
		i += test_champs(&format[i], flag, ap);
		if (format[i] == '.')
			i += test_precision(&format[i], flag, ap);
	}
	if (format[i] != 'd' && format[i] != 'D' && format[i] != 'i' && format[i] != 'o' 
		&& format[i] != 'O' && format[i] != 'u' && format[i] != 'U'&& format[i] != 'x'
		&& format[i] != 'X' && format[i] != 'c' && format[i] != 'C' && format[i] != '%' 
		&& format[i] != 's' && format[i] != 'S' && format[i] != 'p' && format[i] != 'n'
		&& format[i] != 'b'&& format[i] != 'f' && format[i] != 'F')
	{
		if (format[i] >= 'a' && format[i] <= 'z')
			return (-1);
		else if (format[i] == '\0')
			return (i);
		else
		{
			flag->lenght_print += my_putchar_printf(format[i], *flag);
			return (i + 1);
		}
	}
	else if ((ret = handle_conversions(format[i], ap, *flag)) == -1)
		return (-1);
	else
		flag->lenght_print += ret;
	return (i + 1);
}

void			initialize_handle_format(int *i, int *j, int *ret, t_flag *flag)
{
	*i = 0;
	*ret = 0;
	flag->lenght_print = 0;
	flag->len_buffer = 0;
	flag->color = 0;
	*j = 0;
}

int			handle_format(const char *format, va_list *ap)
{
	int				i;
	int				ret;
	t_flag			flag;
	unsigned short	j;

	initialize_handle_format(&i, &j, &ret, &flag);
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (ret >= 0 && format[i] == '%')
			{
				flag.len_buffer = j;
				if ((ret = analyze_and_printf(&format[i + 1], ap, &flag)) > -1)
					i = i + ret + 1;
				else if (ret == -1)
					return (-1);
				j = 0;
			}
			else if (flag.color == 1 && format[i] == '{' && format[i + 1] == 'e' && format[i + 2] == 'o'
					 && format[i + 3] == 'f' && format[i + 4] == '}')
			{
				flag.buffer[j++] = '\033';
				flag.buffer[j++] = '[';
				flag.buffer[j++] = '0';
				flag.buffer[j++] = 'm';
				//write(1, "\033[0m", 4);
				i += 5;
				flag.color = 0;
			}
			else if (format[i] == '{' && (ret = handle_colors(&format[i + 1], &flag, &j)) > 0)
				i += ret;
			else
			{
				flag.buffer[j] = format[i];
				//	write(1, &format[i], 1);
				flag.lenght_print++;
				i++;
				j++;
			}
		}
	}
	write(1, flag.buffer, j);
	return(flag.lenght_print);
}


