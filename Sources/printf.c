#include <stdarg.h>
#include "../Includes/printf.h"
#include "../Includes/Handlers/handlers.h"
#include <unistd.h>

int			count_ap(char const *str)
{
	int			count;

	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str - 1) != '%')
			count++;
		str++;
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	va_start(ap, format);
	handle_format(format, ap);
}