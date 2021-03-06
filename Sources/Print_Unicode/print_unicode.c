#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Print_Unicode/convert_dec_to_bin_utf8.h"
#include "../../Includes/errors.h"
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"
#include "../../Includes/Print_Unicode/auxiliary_functions_for_unicode.h"

/*
 * Annexe a Put_wint_t pour respecter la norme de ligne de 42.
 * */

intmax_t		annex_put_wint_t(t_flag flag, int number_of_bytes, char *codeset, t_bin_list *temp)
{	
	int			i;
	t_bin_list	*head;

	i = 0;
	while (i < number_of_bytes)
	{
		codeset[i++] = temp->binary[0];
		head = temp->next;
		free(temp);
		temp = head;
	}
	return (print_final_result(flag, codeset, i));
}

/*
 * Stocke le charactere sous forme binaire UTF8 (dans la liste chaine chaine t_bin_list)
 * Convertit chaque octet en decimal puis les combine pour affiche le caractere unicode
 */

intmax_t		my_put_wint_t(int dec, t_flag flag)
{
	t_bin_list	*temp;
	char		codeset[6];
	int			number_of_bytes;

	flag.unicode_c = 1;
	if (dec < 128 && dec >= 0)
		return (print_final_result(flag, (char *) &dec, 1));
	else if (dec >= 128 && dec <= 255 && MB_CUR_MAX < 2 )
	{
		write(1, "�", 2);
		return (1);
	}
	if ((dec >= 128 && dec <= 255 && MB_CUR_MAX < 2 )
		|| (dec > 1114111 || dec < 0) || (dec >= 55296 && dec <= 57343)
		||(number_of_bytes = compute_minimum_number_of_bytes_in_utf8(dec)) > MB_CUR_MAX)
		return (-1);
	else if (dec > 196608 && dec < 262143)
		return (0);
	temp = call_functions_to_convert_dec_to_bin_in_utf8(dec, number_of_bytes);
	return (annex_put_wint_t(flag, number_of_bytes, codeset, temp));
}

/*
 * Fonction d'affichage de charactere unicode (par combinaison si le charactere est multi-octet)
 */

int			annex_to_count_char(t_flag flag, wchar_t *string_wchar, int **number_of_char_per_wint_t)
{
	short	i;
	int		len_precision;
	size_t	number_of_bytes;

	i = 0;
	len_precision = flag.precision;
	number_of_bytes = 0;
	while (string_wchar[i] != '\0')
	{
		if (string_wchar[i] >= 128)
			if((number_of_char_per_wint_t[0][i] = compute_minimum_number_of_bytes_in_utf8(string_wchar[i])) > MB_CUR_MAX)
			{
				if (string_wchar[i] >= 129 && string_wchar[i] <= 255)
					number_of_char_per_wint_t[0][i] = 1;
				else if (len_precision > 0 || flag.precision == -1)
					return (-1);
			}
		len_precision -= number_of_char_per_wint_t[0][i];
		number_of_bytes += number_of_char_per_wint_t[0][i++];
	}
	return (number_of_bytes);
}

int			ct_char_per_wint_t(t_flag flag, wchar_t *string_wchar, int **number_of_char_per_wint_t)
{
	int			i;
	int         temp;

	i = 0;
	while (string_wchar[i] != '\0')
		i++;
	if (!(number_of_char_per_wint_t[0] = (int *)malloc(sizeof(int) * i)))
		exit_with_msg(ERROR_MALLOC_FAILED);
	while (--i >= 0)
		number_of_char_per_wint_t[0][i] = 1;
    temp =	annex_to_count_char(flag, string_wchar, number_of_char_per_wint_t);
	return (temp);
}

/*
 * Utilise la fonction my_put_wint_t pour afficher une chaine de caractere d'unicode (wchar_t)
 */

//DONETODO Compter nombre de caracteres total
//DONETODO Creer la string qui va les contenir
//DONETODO Converti les unicodees en "char" un par un et je les stocke dans la string