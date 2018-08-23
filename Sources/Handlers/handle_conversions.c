#include "../../Includes/Print_Unicode/print_unicode.h"
#include "../../Includes/Auxiliary_Functions/strings_functions.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_unsigned.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_hexa.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions_octal.h"
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/print_pointer_address.h"
/*
void		handle_conversions(char conversion, va_list ap, int lenght_conv)
{

	if (conversion == 'C' || (conversion == 'c' && lenght_conv == L))
		my_put_wint_t(va_arg(ap, wint_t));
	else if (conversion == 'c')
		my_putchar((char)(va_arg(ap, int)));
	else if (conversion == 'S' || (conversion == 's' && lenght_conv == L))
		my_put_wchar_t(va_arg(ap, wchar_t *));
	else if (conversion == 's')
		my_putstr(va_arg(ap, char *));
	else if (conversion == 'd' || conversion == 'i')
	{
		if (lenght_conv == H)
			my_putnbr_long_long((short)(va_arg(ap, int)));
		else if (lenght_conv == HH)
			my_putnbr_long_long((char)(va_arg(ap, int)));
		else if (lenght_conv == L)
			my_putnbr_long_long(va_arg(ap, long));
		else if (lenght_conv == LL)
			my_putnbr_long_long(va_arg(ap, long long));
		else if (lenght_conv == J)
			my_putnbr_long_long(va_arg(ap, intmax_t));
		else if (lenght_conv == Z)
			my_putnbr_long_long(va_arg(ap, ssize_t));
		else
			my_putnbr_long_long(va_arg(ap, int));
	}
	else 	if (conversion == 'D' && lenght_conv == L)
		my_putnbr_long_long(va_arg(ap, long long));
	else 	if (conversion == 'D')
		my_putnbr_long_long(va_arg(ap, long));
	else 	if (conversion == 'u')
	{
		if (lenght_conv == H)
			my_put_unsigned_long_long((unsigned short)(va_arg(ap, int)));
		else if (lenght_conv == HH)
			my_put_unsigned_long_long((unsigned char)(va_arg(ap, int)));
		else if (lenght_conv == L)
			my_put_unsigned_long_long(va_arg(ap, unsigned long));
		else if (lenght_conv == LL)
			my_put_unsigned_long_long(va_arg(ap, unsigned long long));
		else if (lenght_conv == J)
			my_put_unsigned_long_long(va_arg(ap, uintmax_t));
		else if (lenght_conv == Z)
			my_put_unsigned_long_long(va_arg(ap, size_t));
		else
			my_put_unsigned_long_long(va_arg(ap, unsigned int));
	}
	else if (conversion == 'o')
	{
		if (lenght_conv == H)
			my_put_octal((unsigned short)(va_arg(ap, int)));
		else if (lenght_conv == HH)
			my_put_octal((unsigned char)(va_arg(ap, int)));
		else if (lenght_conv == L)
			my_put_octal(va_arg(ap, unsigned long));
		else if (lenght_conv == LL)
			my_put_octal(va_arg(ap, unsigned long long));
		else if (lenght_conv == J)
			my_put_octal(va_arg(ap, uintmax_t));
		else if (lenght_conv == Z)
			my_put_octal(va_arg(ap, unsigned long));
		else
		my_put_octal(va_arg(ap, unsigned int));
	}
	else if (conversion == 'O'&& lenght_conv == L)
		my_put_octal(va_arg(ap, unsigned long long));
	else if (conversion == 'O')
		my_put_octal(va_arg(ap, unsigned long));
	else if (conversion == 'x')
	{
		if (lenght_conv == H)
			my_putnbr_hexa((unsigned short)(va_arg(ap, int)));
		else if (lenght_conv == HH)
			my_putnbr_hexa((unsigned char)(va_arg(ap, int)));
		else if (lenght_conv == L)
			my_putnbr_hexa(va_arg(ap, unsigned long));
		else if (lenght_conv == LL)
			my_putnbr_hexa(va_arg(ap, unsigned long long));
		else if (lenght_conv == J)
			my_putnbr_hexa(va_arg(ap, uintmax_t));
		else if (lenght_conv == Z)
			my_putnbr_hexa(va_arg(ap, unsigned long));
		else
		my_putnbr_hexa(va_arg(ap, unsigned int));
	}
	else if (conversion == 'X')
	{
		if (lenght_conv == H)
			my_putnbr_HEXA((unsigned short) (va_arg(ap, int)));
		else if (lenght_conv == HH)
			my_putnbr_HEXA((unsigned char) (va_arg(ap, int)));
		else if (lenght_conv == L)
			my_putnbr_HEXA(va_arg(ap, unsigned long));
		else if (lenght_conv == LL)
			my_putnbr_HEXA(va_arg(ap, unsigned long long));
		else if (lenght_conv == J)
			my_putnbr_HEXA(va_arg(ap, uintmax_t));
		else if (lenght_conv == Z)
			my_putnbr_HEXA(va_arg(ap, unsigned long));
		else
		my_putnbr_HEXA(va_arg(ap, unsigned int));
	}
	else if (conversion == 'p')
		my_putaddress(va_arg(ap, unsigned int));
}

*/
