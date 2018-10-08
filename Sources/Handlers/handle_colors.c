#include "../../Includes/Handlers/handlers.h"

void		fill_buffer(char *flag_buffer, char b, char c)
{
	flag_buffer[0] = '\033';
	flag_buffer[1] = '[';
	flag_buffer[2] = b;
	flag_buffer[3] = ';';
	flag_buffer[4] = '3';
	flag_buffer[5] = c;
	flag_buffer[6] = 'm';
}

short		handle_bold_colors(char *color, char *flag_buffer)
{
	short		i;

	i = 0;
	if (color[0] == 'r' && color[1] == 'e' && color[2] == 'd'  && (i = 9))
		fill_buffer(&flag_buffer[0], '1', '1');
	else if (color[0] == 'g' && color[1] == 'r' && color[2] == 'e' && color[3] == 'e' && color[4] == 'n' 
		&& color[5] == '}' && (i = 11))
		fill_buffer(&flag_buffer[0], '1', '2');
	else if (color[0] == 'y' && color[1] == 'e' && color[2] == 'l' && color[3] == 'l' && color[4] == 'o' 
			 && color[5] == 'w' && color[6] == '}' && (i = 12))
		fill_buffer(&flag_buffer[0], '1', '3');
	else if (color[0] == 'b' && color[1] == 'l' && color[2] == 'u' && color[3] == 'e' && color[4] == '}' && (i = 10))
		fill_buffer(&flag_buffer[0], '1', '4');
	else if (color[0] == 'm' && color[1] == 'a' && color[2] == 'g' && color[3] == 'e' && color[4] == 'n'
		&& color[5] == 't' && color[6] == 'a' && color[7] == '}' && (i = 13))
		fill_buffer(&flag_buffer[0], '1', '5');
	else if (color[0] == 'c' && color[1] == 'y' && color[2] == 'a' && color[3] == 'n' && color[4] == '}' && (i = 10))
		fill_buffer(&flag_buffer[0], '1', '6');
	return (i);
}

short		handle_colors(char *color, t_flag *flag, unsigned short *j)
{
	short		i;
	short		temp;
	
	i = 0;
	temp = *j;
	if (color[0] == 'b' && color[1] == 'o' && color[2] == 'l' && color[3] == 'd')
		i += handle_bold_colors(color + 4, &flag->buffer[temp]);
	else if (color[0] == 'r' && color[1] == 'e' && color[2] == 'd' && color[3] == '}' && (i = 5))
		fill_buffer(&flag->buffer[temp], '0', '1');
	else if (color[0] == 'g' && color[1] == 'r' && color[2] == 'e' && color[3] == 'e' && color[4] == 'n'
		&& color[5] == '}' && (i = 7))
		fill_buffer(&flag->buffer[temp], '0', '2');
	else if (color[0] == 'y' && color[1] == 'e' && color[2] == 'l' && color[3] == 'l' && color[4] == 'o'
			 && color[5] == 'w' && color[6] == '}' && (i = 8))
		fill_buffer(&flag->buffer[temp], '0', '3');
	else if (color[0] == 'b' && color[1] == 'l' && color[2] == 'u' && color[3] == 'e' && color[4] == '}' && (i = 6))
		fill_buffer(&flag->buffer[temp], '0', '4');
	else if (color[0] == 'm' && color[1] == 'a' && color[2] == 'g' && color[3] == 'e' && color[4] == 'n'
		&& color[5] == 't' && color[6] == 'a' && color[7] == '}' && (i = 9))
		fill_buffer(&flag->buffer[temp], '0', '5');
	else if (color[0] == 'c' && color[1] == 'y' && color[2] == 'a' && color[3] == 'n' && color[4] == '}' && (i = 6))
		fill_buffer(&flag->buffer[temp], '0', '6');
	if (i > 0)
	{
		flag->color = 1;
		flag->lenght_print += i;
		*j += 7;
	}
	return (i);
}