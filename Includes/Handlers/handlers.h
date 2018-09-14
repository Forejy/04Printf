#ifndef HANDLERS_H
# define HANDLERS_H
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>

# define HH 5
# define H 7
# define L 10
# define LL 11
# define J 13
# define Z 16
# define HASH 3

typedef struct		s_flag
{
	int		more;
	int		less;
	int		zero;
	int		hash;
	int		blank;
	int		champs;
	int		precision;
	int		pointer;
	int		hexa;
	int		character_or_string;
	int		unicode_c;
	int		unicode_s;
	int		conv_d;
	int 	lenght_conv;
	size_t 	lenght_print;
}					t_flag;

size_t			handle_format(const char *format, va_list ap);
size_t			handle_conversions(char conversion, va_list ap, t_flag flag);

#endif
