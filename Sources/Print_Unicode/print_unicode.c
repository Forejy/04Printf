#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
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
	t_bin_list *temp;
	char       codeset[6];
	int        number_of_bytes;
	int        i;
//	unsigned char		codeset[6];

	flag.unicode_c = 1;
	if (dec <= 128 && dec >= 0)
		return (print_final_result(flag, (char *) &dec, 1));
	else if (dec >= 129 && dec <= 255 && MB_CUR_MAX < 2 )
	{
		write(1,"�", 2);
		return (-1);
	}
	else if ((dec > 1114111 || dec < 0) || (dec >= 55296 && dec <= 57343))
		return (-1);
	else if (dec > 196608 && dec < 262143)
		return (0);
	if((number_of_bytes = compute_minimum_number_of_bytes_in_utf8(dec)) > MB_CUR_MAX)
		return (-1);
	temp = call_functions_to_convert_dec_to_bin_in_utf8(dec, number_of_bytes);
	i = 0;
	while (i < number_of_bytes)
	{
		codeset[i] = temp->binary[0];
		i++;
		temp = temp->next;
	}
	return (print_final_result(flag, codeset, i));
}

/*
 * Fonction d'affichage de charactere unicode (par combinaison si le charactere est multi-octet)
 */

int			count_char_per_wint_t(t_flag flag, wchar_t *string_wchar, int **number_of_char_per_wint_t)
{
	int			i;
	int 		len_precision;
	size_t			number_of_bytes;
	
	i = 0;
	len_precision = flag.precision;
	//i = string_wchar[0];
	while (string_wchar[i] != '\0')
		i++;
	if (!(number_of_char_per_wint_t[0] = (int *)malloc(sizeof(int) * i)))
		exit_with_msg(ERROR_MALLOC_FAILED);
	number_of_bytes = 0;
	while (--i >= 0)
		number_of_char_per_wint_t[0][i] = 1;
	i = 0;
	while (string_wchar[i] != '\0')
	{
		if (string_wchar[i] >= 128)
			if((number_of_char_per_wint_t[0][i] = compute_minimum_number_of_bytes_in_utf8(string_wchar[i])) > MB_CUR_MAX)
			{
				if (string_wchar[i] >= 129 && string_wchar[i] <= 255)
					number_of_char_per_wint_t[0][i] = 1;
				else if (len_precision > 0 || flag.precision == -1)
				{
				//	if (flag.precision > 0)

					//write(1,"�", 2);
					return (-1);
				}
			//	else if (flag.precision == -1)
            //        number_of_char_per_wint_t[0][i] = 1;
			}
		len_precision -= number_of_char_per_wint_t[0][i];
		number_of_bytes += number_of_char_per_wint_t[0][i++];
	}
	return (number_of_bytes);
}

int				adapts_precision_to_numbers_of_bytes(int presumed_precision, int *number_of_char_per_wint_t)
{
	int		i;
	int		temp_bytes;
	int		temp_precision;
	
	i = 0;
	temp_bytes = number_of_char_per_wint_t[0];
	temp_precision = presumed_precision;
	while (temp_precision > 0)
	{
		if (temp_bytes == 0)
		{
			i++;
			temp_bytes = number_of_char_per_wint_t[i];
		}
		temp_precision--;
		temp_bytes--;
	}
	if (temp_bytes > 0)
			return (presumed_precision - (number_of_char_per_wint_t[i] - temp_bytes));
	else
		return (presumed_precision);
}

int 	test_validity_of_characters(wchar_t *string_wchar)
{
	int i;
	wint_t temp;

	i = 0;
	while ((temp = string_wchar[i]) != '\0')
	{
	//	if (temp >= 129 && temp <= 255)
	//		string_wchar[i] = 65533;
		if ((temp > 1114111 || temp < 0) || (temp >= 55296 && temp <= 57343))
			return (-1);
		i++;
	}
	return (1);
}

int			annex_to_put_wchar_t(char *string_wchar, int *number_of_char_per_wint_t, char *string)
{
	short	i;
	short	j;
	short	k;
	t_bin_list	*temp;

	i = 0;
	j = 0;
	while (string_wchar[i] != '\0')
	{
		if (string_wchar[i] >= 128)
		{
			temp = call_functions_to_convert_dec_to_bin_in_utf8(string_wchar[i], number_of_char_per_wint_t[i]);
			k = number_of_char_per_wint_t[i] + j - 1;
			while (temp && (j++))
			{
				string[k--] = temp->binary[0];
				//j++;
				temp = temp->next;
			}
		}
		else if (string_wchar[i] > 1114111 || string_wchar[i] < 0
				 || (string_wchar[i] >= 55296 && string_wchar[i] <= 57343 ))
			return (-1);
		else if (temp >= 129 && temp <= 255)
			string[j++] = 65533;
		else
			string[j++] = string_wchar[i];
		i++;
	}
}

int			my_put_wchar_t(wchar_t *string_wchar, t_flag flag)
{
	size_t		total_len;
	int			number_of_bytes;
	int			*number_of_char_per_wint_t;
	char		*string;

	if (string_wchar == NULL)
	{
		write(1, flag.buffer, flag.len_buffer);
		write(1, "(null)", 6);
		return (6);
	}
	if((test_validity_of_characters(string_wchar) == -1) 
		||(number_of_bytes = count_char_per_wint_t(flag, string_wchar, &number_of_char_per_wint_t)) == -1)
		return (-1);
	if (!(string = (char *)malloc(sizeof(char) * (number_of_bytes + 1))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	string[number_of_bytes] = '\0';
	if ((annex_to_put_wchar_t(string_wchar, number_of_char_per_wint_t, string)) == -1)
		return (-1);
	flag.unicode_s = 1;
	if (flag.precision > -1 && flag.precision < number_of_bytes)
		flag.precision = adapts_precision_to_numbers_of_bytes(flag.precision, number_of_char_per_wint_t);
	total_len = print_final_result(flag, string, number_of_bytes);
	return (total_len);
}

/*
 * Utilise la fonction my_put_wint_t pour afficher une chaine de caractere d'unicode (wchar_t)
 */

//DONETODO Compter nombre de caracteres total
//DONETODO Creer la string qui va les contenir
//DONETODO Converti les unicodees en "char" un par un et je les stocke dans la string