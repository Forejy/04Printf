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

int			handle_conversions(char conversion, va_list *ap, t_flag flag)
{
	int		total_len;
	int		lenght_conv;

	total_len = 0;
	lenght_conv = flag.lenght_conv;
	if (conversion == '%')
		total_len = my_putchar_printf('%', flag);
	else if (conversion == 'C' || (conversion == 'c' && lenght_conv == L))
		total_len = my_put_wint_t(va_arg(*ap, wint_t), flag);
	else if (conversion == 'c')
		total_len = my_putchar_printf((char)(va_arg(*ap, int)), flag);
	else if (conversion == 'S' || (conversion == 's' && lenght_conv == L))
		total_len = my_put_wchar_t(va_arg(*ap, wchar_t *), flag);
	else if (conversion == 's')
		total_len = my_putstr_printf(va_arg(*ap, char *), flag);
	else if (conversion == 'd' || conversion == 'i')
	{
		if (lenght_conv == H)
			total_len = my_putnbr_long_long((short)(va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_putnbr_long_long((char)(va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_putnbr_long_long(va_arg(*ap, long), flag);
		else if (lenght_conv == LL)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else if (lenght_conv == J)
			total_len = my_putnbr_long_long(va_arg(*ap, intmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_putnbr_long_long(va_arg(*ap, ssize_t), flag);
		else
			total_len = my_putnbr_long_long(va_arg(*ap, int), flag);
	}
	else 	if (conversion == 'D')
	{
		if (lenght_conv == L)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else if (lenght_conv == H)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else
			total_len = my_putnbr_long_long(va_arg(*ap, long), flag);
	}
	else 	if (conversion == 'u')
	{
		if (lenght_conv == H)
			total_len = my_put_unsigned_long_long((unsigned short)(va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_put_unsigned_long_long((unsigned char)(va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_put_unsigned_long_long(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_put_unsigned_long_long(va_arg(*ap, size_t), flag);
		else
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned int), flag);
	}
	else 	if (conversion == 'U')
	{
		if (lenght_conv == L)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == H)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long), flag);
	}
	else if (conversion == 'o')
	{
		if (lenght_conv == H)
			total_len = my_put_octal((unsigned short)(va_arg(*ap,  unsigned int)), flag);
		else if (lenght_conv == HH)
			total_len = my_put_octal((unsigned char)(va_arg(*ap,  unsigned int)), flag);
		else if (lenght_conv == L)
			total_len = my_put_octal(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_put_octal(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_put_octal(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_put_octal(va_arg(*ap, unsigned long), flag);
		else
			total_len = my_put_octal(va_arg(*ap, unsigned int), flag);
	}
	else if (conversion == 'O' && lenght_conv == L)
		total_len = my_put_octal(va_arg(*ap, unsigned long long), flag);
	else if (conversion == 'O')
		total_len = my_put_octal(va_arg(*ap, unsigned long), flag);
	else if (conversion == 'x')
	{
		if (lenght_conv == H)
			total_len = my_putnbr_hexa((unsigned short)(va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_putnbr_hexa((unsigned char)(va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_putnbr_hexa(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_putnbr_hexa(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_putnbr_hexa(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_putnbr_hexa(va_arg(*ap, unsigned long), flag);
		else
			total_len = my_putnbr_hexa(va_arg(*ap, unsigned int), flag);
	}
	else if (conversion == 'X')
	{
		if (lenght_conv == H)
			total_len = my_putnbr_HEXA((unsigned short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_putnbr_HEXA((unsigned char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_putnbr_HEXA(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned long), flag);
		else
			total_len = my_putnbr_HEXA(va_arg(*ap, unsigned int), flag);
	}
	else if (conversion == 'b')
	{
		if (lenght_conv == H)
			total_len = convert_dec_to_binary((unsigned short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = convert_dec_to_binary((unsigned char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = convert_dec_to_binary(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned long), flag);
		else
			total_len = convert_dec_to_binary(va_arg(*ap, unsigned int), flag);
	}
	else if (conversion == 'p')
		total_len = my_putaddress(va_arg(*ap, uintmax_t), flag);
	else if (conversion == 'n')
		assigns_to_n(ap, lenght_conv, flag);
	return (total_len);
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
			/*if (temp_star < 0)
			{
				flag->less = 1;
				temp_star *= -1;
			}*/
			if (temp_star >= 0)
				flag->precision = temp_star;
			i++;
		}
	//	if (nb < 0)
	//		flag->precision = 0;
		else if (nb >= 0)
			flag->precision = nb;

	}
	return (i);
}
/*HANDLE_FORMAT V1 (FONCTIONNAL)
size_t			handle_format(const char *format, va_list ap)
{
	int				i;
	int				lenght_conv;
	size_t			lenght_print;
	t_flag			flag;

	i = 0;
	initialize_t_flag(&flag);
	lenght_print = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;

			while((test_flag(format[i], &flag)) != 0)
				i++;
			i = i + test_champs(&format[i], &flag);
			if (format[i] == '.')
			{
				i++;
				i = i + test_precision(&format[i], &flag);
			}
			if (format[i] == '%')
				lenght_print = lenght_print + my_putchar_printf('%', flag);
			else
			{
				if ((lenght_conv = define_lenght_conv(&format[i])) != 0)
					i += lenght_conv % 3;
				lenght_print = lenght_print + handle_conversions(format[i], ap, lenght_conv, flag);
			}
		}
		else
		{
			write(1, &format[i], 1);
			lenght_print++;
		}
		i++;
	}
	return(lenght_print);
}
*/
/* OLD HANDLER_FORMAT
size_t		handle_format(const char *format, va_list ap)
{
	int				i;
	int				lenght_conv;
	t_flag			flag;
	size_t			total_len;

	i = 0;
	total_len = 0;
	initialize_t_flag(&flag);
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while((test_flag(format[i], &flag)) != 0)
				i++;
			i = i + test_champs(&format[i], &flag);
			if (format[i] == '.')
			{
				i++;
				i = i + test_precision(&format[i], &flag);
			}
			else
			{
				if ((lenght_conv = define_lenght_conv(&format[i])) != 0)
					i += lenght_conv % 3;
				total_len += handle_conversions(format[i], ap, lenght_conv, flag);
			}
		}
		else
		{
			write(1, &format[i], 1);
			total_len += 1;
		}
		i++;
	}
	return (total_len);
}
*/

/*HANDLE_FORMAT V2
int 			test_if_conversion(char conv)
{
	if (conv == 'd' || conv == 'D' || conv == 'i' || conv == 'o' || 
		conv == 'O' || conv == 'u' || conv == 'x' || conv == 'X' || 
		conv == 'p' || conv == 'c' || conv == 'C' || conv == 's' || 
		conv == 'S')
		return (1);
	return (0);
}

int				pre_analyze(const char *format)
{
	int			i;
	
	i = 0;
	while (format[i] != '%' || format[i] != '\0')
		i++;
	if (i == 0 && format [i] == '%')
		return (-1);
	if (test_if_conversion(format[i - 1]) == 1)
		return (i);
	return (-2);
}

size_t			handle_format(const char *format, va_list ap)
{
	int			i;
	int			len_format;
	
	i = 0;
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
				len_format = pre_analyze(&format[i + 1]); //==> utiliser i pour renvoyer le nombre de parametres
			if (len_format == -2)
				
		}
	}
}
*/
//HANDLE_FORMAT V3 (ACTUAL)

/*
int			handle_special_no_conv(const char *format, int i, va_list ap, t_flag *flag)
{
	if (format [i + 1] == '\0')
		return (-1);
	return (0);
}
*/
 
int			analyze_and_printf(const char *format, va_list *ap, t_flag *flag)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = -1;
	ret = 0;
	if (*format == '\0')
	{
//		flag->lenght_print = -1;
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
		&& format[i] != 'b')
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

int			handle_format(const char *format, va_list *ap)
{
	int		i;
	int			ret;
	t_flag		flag;
	unsigned short 		j;
	
	i = 0;
	ret = 0;
	flag.lenght_print = 0;
	flag.len_buffer = 0;
	flag.color = 0;
	j = 0;
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
			if (flag.color == 1 && format[i] == '{' && format[i + 1] == 'e' && format[i + 2] == 'o' 
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
			if (format[i] == '{')
				i += handle_colors(&format[i + 1], &flag, &j);
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


