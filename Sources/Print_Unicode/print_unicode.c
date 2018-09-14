#include <unistd.h>
#include <stdlib.h>
#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Print_Unicode/convert_dec_to_bin_utf8.h"
#include "../../Includes/errors.h"
#include "../../Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h"

t_bin_list		*call_functions_to_convert_dec_to_bin_in_utf8(int dec, int number_of_bytes)
{
	t_bin_list	*begin_list;

	begin_list = create_and_initialize_t_bin_list(number_of_bytes);
	convert_dec_to_bin_utf8(number_of_bytes, begin_list, dec);
	convert_bin_to_dec(begin_list);
	return (begin_list);
}

/*
 * Stocke le charactere sous forme binaire UTF8 (dans la liste chaine chaine t_bin_list)
 * Convertit chaque octet en decimal puis les combine pour affiche le caractere unicode
 */

size_t			my_put_wint_t(int dec, t_flag flag)
{
	t_bin_list			*temp;
	unsigned char		codeset[6];
	int					number_of_bytes;
	int					i;

	if (dec <= 128)
		return (print_final_result(flag, (char *)&dec, 1, 1));
	number_of_bytes = compute_minimum_number_of_bytes_in_utf8(dec);
	temp = call_functions_to_convert_dec_to_bin_in_utf8(dec, number_of_bytes);
	flag.unicode_c = 1;
	i = 0;
	while (i < number_of_bytes)
	{
		codeset[i] = temp->binary[0];
		i++;
		temp = temp->next;
	}
	return (print_final_result(flag, codeset, i, i ));
}

/*
 * Fonction d'affichage de charactere unicode (par combinaison si le charactere est multi-octet)
 */

int			count_char_per_wint_t(wchar_t *string_wchar, int **number_of_char_per_wint_t)
{
	int			i;
	size_t			number_of_bytes;
	
	i = 0;
	//i = string_wchar[0];
	while (string_wchar[i] != '\0')
		i++;
	if (!(number_of_char_per_wint_t[0] = malloc(sizeof(int) * i)))
		exit_with_msg(ERROR_MALLOC_FAILED);
	number_of_bytes = 0;
	while (--i >= 0)
		number_of_char_per_wint_t[0][i] = 1;
	i = 0;
	while (string_wchar[i] != '\0')
	{
		if (string_wchar[i] >= 128)
			number_of_char_per_wint_t[0][i] =
				compute_minimum_number_of_bytes_in_utf8(string_wchar[i]);
		number_of_bytes += number_of_char_per_wint_t[0][i++];
	}
	return (number_of_bytes);
}

size_t			my_put_wchar_t(wchar_t *string_wchar, t_flag flag)
{
	size_t		total_len;
	int			number_of_bytes;
	int			*number_of_char_per_wint_t;
	int			i;
	int			j;
	int			k;
	char		*string;
	t_bin_list	*temp;
	//char		string[5];

	i = 0;
	number_of_bytes = count_char_per_wint_t(string_wchar, &number_of_char_per_wint_t);
	if (!(string = malloc(sizeof(char) * (number_of_bytes + 1))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	string[number_of_bytes] = '\0';
	j = 0;
	while (string_wchar[i] != '\0')
	{
		if (string_wchar[i] >= 128)
		{
			temp = call_functions_to_convert_dec_to_bin_in_utf8(string_wchar[i], number_of_char_per_wint_t[i]);
			k = number_of_char_per_wint_t[i] + j - 1;
			while (temp)
			{
				string[k] = temp->binary[0];
				k--;
				j++;
				temp = temp->next;
			}
		}
		else
			string[j++] = string_wchar[i];
		i++;
	}
	total_len = 0;
	/*
	while (*string_wchar)
	{
		my_put_wint_t(*string_wchar, flag);
		string_wchar++;
		total_len++;
	}
	 */
	flag.unicode_s = 1;
	/*
	string[0] = '\264';
	string[1] = '\316';
	string[2] = 160;
	string[3] = 154;
	string[4] = 225;
	 \240\232\341
	 */
	
	
	total_len = print_final_result(flag, string, number_of_bytes, number_of_bytes);
	//total_len = print_final_result(flag, string, 19 - i, 19 - i );
	return (total_len);
}

/*
 * Utilise la fonction my_put_wint_t pour afficher une chaine de caractere d'unicode (wchar_t)
 */

//DONETODO Compter nombre de caracteres total
//TODO Creer la string qui va les contenir
//TODO Converti les unicodees en "char" un par un et je les stocke dans la string