#ifndef AUXILIARY_FUNCTIONS_FOR_UNICODE_H
# define AUXILIARY_FUNCTIONS_FOR_UNICODE_H

int				compute_power(int base, unsigned int exposant);
int				compute_minimum_number_of_bytes_in_utf8(int decimal);
unsigned int	compute_minimum_number_of_bits(unsigned int n);

#endif