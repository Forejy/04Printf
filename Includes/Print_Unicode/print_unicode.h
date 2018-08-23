#ifndef PRINT_UNICODE_H
# define PRINT_UNICODE_H

#include <wchar.h>
#include "create_and_print_t_bin_list.h"

size_t			my_put_wint_t(int dec);
size_t			my_put_wchar_t(wchar_t *string);
t_bin_list			*call_functions_to_convert_dec_to_bin(int dec, int number_of_bytes[1]);

#endif