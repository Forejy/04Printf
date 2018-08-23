#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Print_Unicode/convert_dec_to_bin_utf8.h"
#include "../../Includes/errors.h"

t_bin_list		*call_functions_to_convert_dec_to_bin(int dec, int *number_of_bytes)
{
	t_bin_list	*begin_list;

	*number_of_bytes = compute_minimum_number_of_bytes(dec);
	begin_list = create_and_initialize_t_bin_list(*number_of_bytes);
	convert_dec_to_bin_utf8(*number_of_bytes, begin_list, dec);
	convert_bin_to_dec(begin_list);
	return (begin_list);
}

/*
 * Stocke le charactere sous forme binaire UTF8 (dans la liste chaine chaine t_bin_list)
 * Convertit chaque octet en decimal puis les combine pour affiche le caractere unicode
 */

size_t			my_put_wint_t(int dec)
{
	t_bin_list		*temp;
	unsigned char	codeset[6];
	int				*number_of_bytes;

	if (!(number_of_bytes = malloc(sizeof(int))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	temp = call_functions_to_convert_dec_to_bin(dec, number_of_bytes);
	int i = 0;
	while (i < *number_of_bytes)
	{
		codeset[i] = temp->binary[0];
		i++;
		temp = temp->next;
	}
	while (*number_of_bytes >= 0)
	{
		write(1, &codeset[*number_of_bytes - 1], 1);
		(*number_of_bytes)--;
	}
	return (1);
}

/*
 * Fonction d'affichage de charactere unicode (par combinaison si le charactere est multi-octet)
 */

size_t			my_put_wchar_t(wchar_t *string)
{
	size_t		total_len;
	
	total_len = 0;
	while (*string)
	{
		my_put_wint_t(*string);
		string++;
	}
	return (total_len);
}

/*
 * Utilise la fonction my_put_wint_t pour afficher une chaine de caractere d'unicode (wchar_t)
 */
