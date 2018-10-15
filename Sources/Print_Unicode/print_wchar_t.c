#include <stdlib.h>
#include "../../Includes/errors.h"
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"
#include "../../Includes/Print_Unicode/convert_dec_to_bin_utf8.h"
#include "../../Includes/Print_Unicode/auxiliary_functions_for_unicode.h"
#include "../../Includes/Print_Unicode/print_unicode.h"


int				adapts_prec_to_n_of_bytes(int presumed_precision, int *number_of_char_per_wint_t)
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


void		annex_to_annex_put_wchart_t(t_bin_list *temp, int k, short *j, char *string)
{
	t_bin_list *head;
	while (temp)
	{
		string[k--] = temp->binary[0];
		(*j)++;
		head = temp->next;
		free(temp);
		temp = head;
	}
}

int			annex_to_put_wchar_t(wchar_t *s_wchar, int *number_of_char_per_wint_t, char *string)
{
	short	i;
	short	j;
	int		k;
	t_bin_list	*temp;

	i = 0;
	j = 0;
	while (s_wchar[i] != '\0')
	{
		if (s_wchar[i] >= 128)
		{
			temp = call_functions_to_convert_dec_to_bin_in_utf8(s_wchar[i], number_of_char_per_wint_t[i]);
			k = number_of_char_per_wint_t[i] + j - 1;
			annex_to_annex_put_wchart_t(temp, k, &j, string);
		}
		else if (s_wchar[i] > 1114111 || s_wchar[i] < 0
				 || (s_wchar[i] >= 55296 && s_wchar[i] <= 57343 ))
			return (-1);
		else if (temp >= 129 && temp <= 255)
			string[j++] = 65533;
		else
			string[j++] = s_wchar[i];
		i++;
	}
	return (0);
}

short			annex_to_wchart_t(t_flag flag)
{
	write(1, flag.buffer, flag.len_buffer);
	write(1, "(null)", 6);
	return (6);
}

intmax_t		my_put_wchar_t(wchar_t *s_wchar, t_flag flag)
{
	size_t		total_len;
	int			n_of_bytes;
	int			*char_per_wint_t;
	char		*string;

	if (s_wchar == NULL)
		return(annex_to_wchart_t(flag));
	if((test_validity_of_characters(s_wchar) == -1) 
		||(n_of_bytes = ct_char_per_wint_t(flag, s_wchar, &char_per_wint_t)) == -1)
	{
		free(char_per_wint_t);
		return (-1);
	}
	if (!(string = (char *)malloc(sizeof(char) * (n_of_bytes + 1))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	string[n_of_bytes] = '\0';
	if ((annex_to_put_wchar_t(s_wchar, char_per_wint_t, string)) == -1)
		return (-1);
	flag.unicode_s = 1;
	if (flag.precision > -1 && flag.precision < n_of_bytes)
		flag.precision = adapts_prec_to_n_of_bytes(flag.precision, char_per_wint_t);
	total_len = print_final_result(flag, string, n_of_bytes);
	free(string);
	free(char_per_wint_t);
	return (total_len);
}
