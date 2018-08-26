#ifndef HANDLERS_H
# define HANDLERS_H
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>


# define L 4
# define H 7
# define J 10
# define Z 13
# define LL 5
# define HH 8
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
	int		character_or_string;
}					t_flag;

size_t			handle_format(const char *format, va_list ap);
size_t		handle_conversions(char conversion, va_list ap, int lenght_conv, t_flag flag);

#endif
