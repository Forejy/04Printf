#include <stdlib.h>
#include <unistd.h>
#include "../Includes/Auxiliary_Functions/strings_functions.h"

void		exit_with_msg(const char *message)
{
	my_putstr(message);
	exit(1);
}
