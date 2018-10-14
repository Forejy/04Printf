#include <limits.h>
#include <locale.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "../Includes/printf.h"
#include "../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../Includes/Print_Unicode/print_unicode.h"
#include "../Includes/Auxiliary_Functions/strings_functions.h"
#include "../Includes/Auxiliary_Functions/print_pointer_address.h"
#include "../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../Includes/Auxiliary_Functions/bonus.h"

void		pourcent_n(char *str, int *n)
{
	int total_len;
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);

	*n = i;
}


int main(void)
{

	//SOMMAIRE :
	//TEST %hhd
	//TEST FLAGS BLANK
	//TEST FLAG +
	//TEST FLAG + et blank
	//TEST FLAG blank et +

	//setlocale(LC_ALL, "");
/*
	int i                = 1;
	unsigned char	x   = 255;
	long				lg = LONG_MAX;
	long long			llg = LLONG_MAX;
	ssize_t ss_t         = SSIZE_MAX;
	size_t s_t			 = SIZE_MAX;
	//suite_nombre(4, 1, 2, 3, 4);
	//\ft_printf("%zhd\n", -50);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("INT_MAX : %d\n", INT_MIN);
	printf("UINT_MAX : %u\n", UINT_MAX);
	printf("SHRT_MAX : %hd\n", SHRT_MAX);
	printf("SHRT_MIN : %hd\n", SHRT_MIN);
	printf("USHRT_MAX :%hu\n", USHRT_MAX);
	printf("LONG_MAX : %ld\n", LONG_MAX); // Si hld ou lhd le l surcharge le h
	printf("LONG_MIN : %ld\n", LONG_MIN); // Si hld ou lhd le l surcharge le h
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);
	printf("ULONG_MAX : %lu\n", ULONG_MAX);
	printf("ULLONG MAX : %llu\n", ULLONG_MAX);
	printf("SIZE_T MAX : %llu\n", SIZE_MAX);
	printf("SSIZE_T_MAX : %llu\n", SSIZE_MAX);
	printf("UNSIGNED CHAR MAX : %d\n", UCHAR_MAX);
	printf("INTMAX_T MAX : %jd\n", INTMAX_MAX);
	printf("INTMAX_T MIN : %jd\n", INTMAX_MIN);
	printf("UINTMAX_T MAX : %ju\n", UINTMAX_MAX);
	
	ft_printf("INT_MAX : %d\n", INT_MAX);
	ft_printf("INT_MAX : %d\n", INT_MIN);
	ft_printf("UINT_MAX : %u\n", UINT_MAX);
	ft_printf("SHRT_MAX : %hd\n", SHRT_MAX);
	ft_printf("SHRT_MIN : %hd\n", SHRT_MIN);
	ft_printf("USHRT_MAX :%hu\n", USHRT_MAX);
	ft_printf("LONG_MAX : %ld\n", LONG_MAX); // Si hld ou lhd le l surcharge le h
	ft_printf("LONG_MIN : %ld\n", LONG_MIN); // Si hld ou lhd le l surcharge le h
	ft_printf("LLONG_MAX : %lld\n", LLONG_MAX);
	ft_printf("LLONG_MIN : %lld\n" LLONG_MIN);
	ft_printf("ULONG_MAX : %lu\n", ULONG_MAX);
	ft_printf("ULLONG MAX : %llu\n", ULLONG_MAX);
	ft_printf("SIZE_T MAX : %llu\n", SIZE_MAX);
	ft_printf("SSIZE_T_MAX : %llu\n", SSIZE_MAX);
	ft_printf("UNSIGNED CHAR MAX : %d\n", UCHAR_MAX);
	ft_printf("INTMAX_T MAX : %jd\n", INTMAX_MAX);
	ft_printf("INTMAX_T MIN : %jd\n", INTMAX_MIN);
	ft_printf("UINTMAX_T MAX : %ju\n", UINTMAX_MAX);
	ft_printf("Short : %zu\n", sizeof(short));
	ft_printf("Long : %zu\n", sizeof(long));
	ft_printf("Long Long : %zu\n", 8);
	ft_printf("Unsigned Long : %zu\n", sizeof(unsigned long));
	ft_printf("Unsigned Long Long : %zu\n", sizeof(unsigned long long));
	ft_printf("Unsigned char : %zu\n", sizeof(unsigned char));
	ft_printf("Size_t : %zu\n", sizeof(size_t));
	ft_printf("Ssize_t : %zd");
	ft_printf("INTPTR_MAX : %zu\n", INTPTR_MAX);
	ft_printf("wint_t : %zu\n", sizeof(wint_t));
	/


	long		neglg = -648;
	ft_printf("%li\n", neglg);
	//ft_printf("\nli\n", -5);
	//ft_printf("|%-010.5d|\n", -12);
	//ft_printf("%0100llu\n", 555555555555);
	//ft_printf("%+010.4d\n", +12);
	//wint_t C = '®'; //Ne marche pas car on dit a l'ordinateur de loger un caractere de plusieurs octets sur un octet
//	wint_t C = L'ᴟ';
//	wint_t K = L'\xE1\xB4\x9F';
//	wchar_t *wchar = L"\xE1\xB4\x9F";
//	write(1, L"ᴟ", 15);
//	int D = 0b010101001;
//	ft_printf("%d\n", C);
//	ft_printf("%C\n", K);
//	ft_printf("%s", "\xE2\x98\xA0");
	unsigned char a = 0xE1;
	ft_printf("%d\n", a);

	unsigned char b = 0xB4;
	ft_printf("%d\n", b);

	unsigned char l = 0x9F;
	ft_printf("%d\n", l);

	unsigned char d = 0x0a;
	ft_printf("%d\n", d);

	ft_printf("Utilisation de write : \n");
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &l, 1);
	write(1, &d, 1);
	unsigned char c;
	c = 225;
	write(1, &c, 1);
	c = 180;
	write(1, &c, 1);
	c = 159;
	write(1, &c, 1);
	c = 10;
	write(1, &c, 1);


	ft_printf("Test unicode avec printf : %C\n",  L'ᴟ');

	
	t_bin_list	*binary;
	ft_printf("AFFICHAGE DE LA LISTE\n");
	write(1, "|", 1);
	wint_t  test_wint_t = L'⛄';
	my_put_wint_t(test_wint_t);
	write(1, "|", 1);
	write(1,"\n", 1);
	write(1, "/", 1);
	wchar_t *test_wchar_t = L"⛄☻☔";
	my_put_wchar_t(test_wchar_t);
	write(1, "/", 1);
	write(1,"\n", 1);







	//ft_printf("%d\n", '10');
	//TEST D'AFFICHAGE DE LA LISTE
	print_list(binary, BINARY);
	convert_bin_to_dec(binary);
	print_list(binary, DECIMAL);*/

	/*int titi = 12592;
	while (titi > 0)
	{
		ft_printf("%d\n", (titi % 16));
		titi = titi / 16;
	}
	//Resultat attendu :
	// 11110000
	// 10000000
	// 10000000
	// 10111001
//10000110 10111010
//	ft_printf("%d\n", c);
	c = 0xe1;
	ft_printf("%d\n", c);
	write(1, &c, 1);
	c = 0xe1;
	write(1, &c, 1);
	c = 0x88;
	write(1, &c, 1);
	c = 0xb4;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	//3 BITS SUR 3 BITS OK
	c = 0xe1;
	write(1, &c, 1);
	c = 0xb4	;
	write(1, &c, 1);
	c = 0x9f;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);

	//3 BITS SUR 4 BITS PAS OK
	c = 0xf0;
	write(1, &c, 1);
	c = 0x81;
	write(1, &c, 1);
	c = 0xb4	;
	write(1, &c, 1);
	c = 0x9f;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);


	unsigned char test[3];
	test[2] = binary->binary[0];
	binary = binary->next;
	test[1] = binary->binary[0];
	binary = binary->next;
	test[0] = binary->binary[0];
	 write(1, &(test[0]), 1);
	write(1, &(test[1]), 1);
	write(1, &(test[2]), 1);
	c = 0b11100001;
	write(1, &c, 1);
	c = 0b10110100;
	write(1, &c, 1);
	c = 0b10011111;
	write(1, &test[0], 1);
	c = 0x0a;
	write(1, &c, 1);

	ft_printf("test putchar avec unicode : ");
	my_putchar(48);
	unsigned char lk = 255;
	write(1, &c, 1);

	ft_printf("%d\n", L'ᴟ');*/

	//ft_printf("Sizeof wint_t : %d, Caractere Unicode affiche : %C%S\n", sizeof(wint_t), C, wchar);*/

	//TEST FLAGS HEXADECIMAL %x %X
	/*
	write(1, "\n", 1);
	char *test;

	test = malloc(sizeof(char) * 4);
	test[0] = '0';
	test[1] = '1';
	test[2] = '2';
	//print_pointers(test);
//	my_putnbr_hexa(&test);

	int		lpl;
	int		*ptr_int;
	int		**ptr_ptr;

	lpl = 7;
	ptr_int = &lpl;
	ptr_ptr = &ptr_int;
	ft_printf("\n");
	ft_printf("printf %%p : %p\n", &lpl);
	ft_printf("PUTADDRESS : \n");
	ft_printf("TAiLLE DE POINTER : %d\n", (int) sizeof(&lpl));
	//TEST %hhd

	ft_printf("%hhd\n", 300);
	write(1, "FT_PRINT TEST OVERFLOW CHAR\n", 28);
	ft_printf("abc", 300);
	ft_printf("\n%x%X\n", 9223372036854775807, 9223372036854775807);
	ft_printf("%+s\n", "25");
	ft_printf("%o\n", 0);


	int *testa;
	int testb;

	testb = 4;
	testa = &testb;
	//TEST FLAGS BLANK
	ft_printf("TEST FLAG BLANK\n");
	ft_printf("BLANK d : |% d| \n", 0);
	ft_printf("BLANK d : |%d| \n", 0);

	ft_printf("BLANK d : |% d| \n", 1);
	ft_printf("BLANK d : |%d| \n", 1);

	ft_printf("BLANK d : |% d| \n", -1);
	ft_printf("BLANK d : |%d| \n", -1);

	ft_printf("BLANK o : |% o| \n", 8);
	ft_printf("BLANK o : |%o| \n", 8);


	ft_printf("BLANK u : |% u| \n", 1);
	ft_printf("BLANK u : |%u| \n", 1);

	ft_printf("BLANK u : |% u| \n", -1);
	ft_printf("BLANK u : |%u| \n", -1);

	ft_printf("BLANK x : |% x| \n", 1);
	ft_printf("BLANK x : |%x| \n", 1);


	ft_printf("BLANK p : |% p| \n", testa);
	ft_printf("BLANK p : |%p| \n", testa);


	ft_printf("BLANK c : |% c| \n", 48);
	ft_printf("BLANK c : |%c| \n", 48);

	ft_printf("BLANK s : |% s| \n", "1");
	ft_printf("BLANK s : |% s| \n", "-1");


	//TEST FLAG +
	ft_printf("\nTEST FLAG '+'\n");\
ft_printf("+ d : %+d \n", 0);
	ft_printf("  d : %d \n", 0);

	ft_printf("+ d : %+d \n", 1);
	ft_printf("  d : %d \n", 1);

	ft_printf("+ d : %+d \n", -1);
	ft_printf("  d : %d \n", -1);

	ft_printf("+ o : %+o \n", 8);
	ft_printf("  o : %o \n", 8);


	ft_printf("+ u : %+u \n", 1);
	ft_printf("  u : %u \n", 1);

	ft_printf("+ u : %+u \n", -1);
	ft_printf("  u : %u \n", -1);

	ft_printf("+ x : %+x \n", 1);
	ft_printf("  x : %x \n", 1);

	ft_printf("+ p : %+p \n", testa);
	ft_printf("  p : %p \n", testa);

	ft_printf("+ c : %+c \n", 48);
	ft_printf("  c : %c \n", 48);

	ft_printf("+ s : %+s \n", "1");
	ft_printf("  s : %+s \n", "-1");

	//TEST FLAG + et blank
	ft_printf("\nTEST FLAG '+' et blank\n");\
ft_printf("+ d : %+ d \n", 0);
	ft_printf("  d : %d \n", 0);

	ft_printf("+ d : %+ d \n", 1);
	ft_printf("  d : %d \n", 1);

	ft_printf("+ d : %+ d \n", -1);
	ft_printf("  d : %d \n", -1);

	ft_printf("+ o : %+ o \n", 8);
	ft_printf("  o : %o \n", 8);


	ft_printf("+ u : %+ u \n", 1);
	ft_printf("  u : %u \n", 1);

	ft_printf("+ u : %+ u \n", -1);
	ft_printf("  u : %u \n", -1);

	ft_printf("+ x : %+ x \n", 1);
	ft_printf("  x : %x \n", 1);

	ft_printf("+ p : %+ p \n", testa);
	ft_printf("  p : %p \n", testa);

	ft_printf("+ c : %+ c \n", 48);
	ft_printf("  c : %c \n", 48);

	ft_printf("+ s : %+ s \n", "1");
	ft_printf("  s : %+s \n", "-1");

	//TEST FLAG blank et +
	ft_printf("\nTEST FLAG blank et +\n");\
ft_printf(" +d : % +d \n", 0);
	ft_printf("  d : %d \n", 0);

	ft_printf(" +d : % +d \n", 1);
	ft_printf("  d : %d \n", 1);

	ft_printf(" +d : % +d \n", -1);
	ft_printf("  d : %d \n", -1);

	ft_printf(" +o : % +o \n", 8);
	ft_printf("  o : %o \n", 8);


	ft_printf(" +u : % +u \n", 1);
	ft_printf("  u : %u \n", 1);

	ft_printf(" +u : % +u \n", -1);
	ft_printf("  u : %u \n", -1);

	ft_printf(" +x : % +x \n", 1);
	ft_printf("  x : %x \n", 1);

	ft_printf(" +p : % +p \n", testa);
	ft_printf("  p : %p \n", testa);

	ft_printf(" +c : % +c \n", 48);
	ft_printf("  c : %c \n", 48);

	ft_printf(" +s : % +s \n", "1");
	ft_printf("  s : %+s \n", "-1");

	//TEST FLAG '0' ET CHAMPS
	ft_printf("\nTEST FLAG '0' ET CHAMPS\n");
	ft_printf(" %%0d : |%0d| \n",0);
	ft_printf(" %%0d : |%0d| \n",2);

	ft_printf(" %%02d : |%02d| \n",0);
	ft_printf("  %%d : |%d| \n",0);

	ft_printf(" %%0d : |%0d| \n", 1);
	ft_printf(" %%02d : |%02d| \n", 1);
	ft_printf("  %%d : |%d| \n", 1);

	ft_printf(" %%0d : |%0d| \n", -1);
	ft_printf(" %%04d : |%04d| \n", -1);
	ft_printf("  %%d : |%d| \n", -1);

	ft_printf(" %%0o : |%0o| \n", 3);
	ft_printf(" %%02o : |%02o| \n", 3);
	ft_printf("  %%o : |%o| \n", 3);

	ft_printf(" %%0o : |%0o| \n", 8);
	ft_printf(" %%02o : |%02o| \n", 8);
	ft_printf("  %%o : |%o| \n", 8);


	ft_printf(" %%0u : |%0u| \n", 1);
	ft_printf(" %%02u : |%02u| \n", 1);
	ft_printf("  %%u : |%u| \n", 1);

	ft_printf(" %%0u : |%0u| \n", 4294967295);
	ft_printf(" %%020u : |%020u| \n", 4294967295);
	ft_printf("  %%u : |%u| \n", 4294967295);

	ft_printf(" %%0x : |%0x| \n", 1);
	ft_printf(" %%02x : |%02x| \n", 1);
	ft_printf("  %%x : |%x| \n", 1);

	ft_printf(" %%0p : |%0p| \n", testa);
	ft_printf(" %%020p : |%020p| \n", testa);
	ft_printf("  %%p : |%p| \n", testa);

	ft_printf(" %%0c : |%0c| \n", 48);
	ft_printf(" %%02c : |%02c| \n", 48);
	ft_printf("  %%c : |%c| \n", 48);

	ft_printf(" %%0s : |%0s| \n", "1");
	ft_printf(" %%020s : |%020s| \n", "1");
	ft_printf("  %%0s : |%0s| \n", "-1");

	//TEST CHAMPS SANS FLAG
	ft_printf("\nTEST CHAMPS SANS FLAG\n");
	ft_printf(" %%02d : |%02d| \n",0);
	ft_printf(" %%5d : |%5d| \n",0);
	ft_printf("  %%d : |%d| \n",0);

	ft_printf(" %%02d : |%02d| \n", 1);
	ft_printf(" %%2d : |%2d| \n", 1);
	ft_printf("  %%d : |%d| \n", 1);

	ft_printf("1 %%04d : |%04d| \n", -1);
	ft_printf("2 %% 4d : |% 4d| \n", -1);
	ft_printf("3 %% 04d : |% 04d| \n", -1);
	ft_printf("3bis %%0000. 5d : |%0000. 5d| \n", -1);
	ft_printf("4 %%0 4d : |%0 4d| \n", -1);
	ft_printf("5 %%4d : |%4d| \n", -1);
	ft_printf("6  %%d : |%d|\n", -1);
	ft_printf("7 %%04d avec -0 : |%04d| \n", -0);


	ft_printf(" %%02o : |%02o| \n", 3);
	ft_printf(" %%3o : |%3o| \n", 3);
	ft_printf("  %%o : |%o| \n", 3);

	ft_printf(" %%02o : |%02o| \n", 8);
	ft_printf(" %%3o : |%3o| \n", 8);
	ft_printf("  %%o : |%o| \n", 8);


	ft_printf(" %%02u : |%02u| \n", 1);
	ft_printf(" %%2u : |%2u| \n", 1);
	ft_printf("  %%u : |%u| \n", 1);

	ft_printf(" %%02u : |%020u| \n", 4294967295);
	ft_printf(" %%2u : |%2u| \n", 4294967295);
	ft_printf("  %%u : |%u| \n", 4294967295);

	ft_printf(" %%02x : |%02x| \n", 1);
	ft_printf(" %%2x : |%2x| \n", 1);
	ft_printf("  %%x : |%x| \n", 1);

	ft_printf(" %%020p : |%020p| \n", testa);
	ft_printf(" %%2p : |%2p| \n", testa);
	ft_printf("  %%p : |%p| \n", testa);

	ft_printf(" %%02c : |%02c| \n", 48);
	ft_printf(" %%2c : |%2c| \n", 48);
	ft_printf("  %%c : |%c| \n", 48);

	ft_printf(" %%020s : |%020s| \n", "1");
	ft_printf(" %%2s : |%2s| \n", "1");
	ft_printf("  %%s : |%0s| \n", "-1");


	//TEST CHAMPS BLANK ' ' ET CHAMPS
	ft_printf("\nTEST BLANK ' ' ET CHAMPS\n");
	ft_printf("|%% +2d| : |% +2d| \n",0);
	ft_printf("|%%+ 2d| : |%+ 2d| \n",0);
	ft_printf(" |%%2d  : |%2d| \n",0);
	ft_printf(" |%%d|  : |%d| \n",0);

	ft_printf(" |%% 2d| : |% 2d| \n", 1);
	ft_printf(" |%%2d|  : |%2d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);

	ft_printf("|%% 2d| : |% 2d| \n", -1);
	ft_printf(" |%%2d| : |%2d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf("|%% 3d| : |% 3d| \n", -1);
	ft_printf(" |%%3d| : |%3d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf(" |%% 2o| : |% 2o| \n", 3);
	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% 2o| : |% 2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);


	ft_printf(" |%% 2u| : |% 2u| \n", 1);
	ft_printf(" |%%2u|  : |%2u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);

	ft_printf(" |%% 2u| : |% 2u| \n", 4294967295);
	ft_printf(" |%%2u|  : |%2u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);

	ft_printf(" |%% 2x| : |% 2x| \n", 1);
	ft_printf(" |%%2x|   : |%2x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);

	ft_printf(" |%% 20p| : |% 20p| \n", testa);
	ft_printf(" |%% p| : |% p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);

	ft_printf(" |%% 2c| : |% 2c| \n", 48);
	ft_printf(" |%%2c|  : |%2c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);

	ft_printf(" |%% 2s| : |% 20s| \n", "1");
	ft_printf(" |%%2s|  : |%2s| \n", "1");
	ft_printf("  |%%s|  : |% s| \n", "-1");


	//TEST CHAMPS BLANK '+' ET ' ' ET CHAMPS
	ft_printf("\nTEST CHAMPS BLANK '+' ET ' ' ET CHAMPS\n");
	ft_printf("|%%+ 3d| : |%+ 3d| \n",0);
	ft_printf(" |%%2d  : |%2d| \n",0);
	ft_printf(" |%%d|  : |%d| \n",0);

	ft_printf(" |%%+ 2d| : |%+ 2d| \n", 1);
	ft_printf(" |%%2d|  : |%2d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);

	ft_printf("|%%+ 2d| : |%+ 2d| \n", -1);
	ft_printf(" |%%2d| : |%2d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf("|%%+ 3d| : |%+ 3d| \n", -1);
	ft_printf(" |%%3d| : |%3d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf(" |%%+ 2o| : |%+ 2o| \n", 3);
	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%%+ 2o| : |%+ 2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);

	ft_printf(" |%%+ 2u| : |%+ 2u| \n", 1);
	ft_printf(" |%%2u|  : |%2u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);

	ft_printf(" |%%+ 2u| : |%+ 2u| \n", 4294967295);
	ft_printf(" |%%2u|  : |%2u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);

	ft_printf(" |%%+ 2x| : |%+ 2x| \n", 1);
	ft_printf(" |%%2x|   : |%2x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);

	ft_printf(" |%%+ 20p| : |%+ 20p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);

	ft_printf(" |%%+ 2c| : |%+ 2c| \n", 48);
	ft_printf(" |%%2c|  : |%2c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);

	ft_printf(" |%%+ 2s| : |%+ 20s| \n", "1");
	ft_printf(" |%%2s|  : |%2s| \n", "1");
	ft_printf("  |%%s|  : |%+ s| \n", "-1");

	//TEST BLANK ' ' ET '+' ET CHAMPS
	ft_printf("\n\tTEST CHAMPS BLANK ' ' ET '+' ET CHAMPS\n");
	ft_printf("|%% +3d| : |% +3d| \n",0);
	ft_printf(" |%%2d  : |%2d| \n",0);
	ft_printf(" |%%d|  : |%d| \n",0);

	ft_printf(" |%% +2d| : |% +2d| \n", 1);
	ft_printf(" |%%2d|  : |%2d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);

	ft_printf("|%% +2d| : |% +2d| \n", -1);
	ft_printf(" |%%2d| : |%2d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf("|%% +3d| : |% +3d| \n", -1);
	ft_printf(" |%%3d| : |%3d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);

	ft_printf(" |%% +2o| : |% +2o| \n", 3);
	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +2o| : |% +2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);


	ft_printf(" |%% +2u| : |% +2u| \n", 1);
	ft_printf(" |%%2u|  : |%2u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);

	ft_printf(" |%% +2u| : |% +2u| \n", 4294967295);
	ft_printf(" |%%2u|  : |%2u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);

	ft_printf(" |%% +2x| : |% +2x| \n", 1);
	ft_printf(" |%%2x|   : |%2x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);

	ft_printf(" |%% +20p| : |% +20p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);

	ft_printf(" |%% +2c| : |% +2c| \n", 48);
	ft_printf(" |%%2c|  : |%2c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);

	ft_printf(" |%% +2s| : |% +20s| \n", "1");
	ft_printf(" |%%2s|  : |%2s| \n", "1");
	ft_printf("  |%% +s|  : |% +s| \n", "-1");

	//TEST PRECISION SEULE
	ft_printf("\n\tTEST PRECISION SEULE\n");
	ft_printf("|%% +.3d| avec ""0""  : |% +.3d| \n",0);
	ft_printf(" |%%.2d| avec ""0"" : |%.2d| \n",0);
	ft_printf(" |%%.2d| avec ""-2000"" : |%.2d| \n", -2000);
	ft_printf(" |%%.6d| avec ""-1234"" : |%.6d| \n", -1234);
	ft_printf(" |%%.d|  : |%d| \n",0);
	ft_printf(" |%%.0d| avec ""0""  : |%0d| \n",0);


	ft_printf(" |%% +.2d| : |% +.2d| \n", 1);
	ft_printf(" |%%.2d|  : |%.2d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);

	ft_printf("|%% +.2d| : |% +.2d| \n", -1);
	ft_printf(" |%%.2d| : |%.2d| \n", -1);
	ft_printf("  |%%.d| : |%d| \n", -1);

	ft_printf("|%% +.3d| : |% +.3d| \n", -1);
	ft_printf(" |%%.3d| : |%.3d| \n", -1);
	ft_printf("  |%%.d| : |%.d| \n", -1);

	ft_printf(" |%% +.2o| : |% +.2o| \n", 3);
	ft_printf(" |%%.3o|  : |%.3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +.2o| : |% +.2o| \n", 8);
	ft_printf(" |%%.3o|  : |%.3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);


	ft_printf(" |%% +.2u| : |% +.2u| \n", 1);
	ft_printf(" |%%.2u|  : |%.2u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);

	ft_printf(" |%% +.2u| : |% +.2u| \n", 4294967295);
	ft_printf(" |%%.2u|  : |%.2u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);

	ft_printf(" |%% +.2x| : |% +.2x| \n", 1);
	ft_printf(" |%%.2x|   : |%.2x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);

	ft_printf(" |%% +.20p| : |% +.20p| \n", testa);
	ft_printf(" |%% +.9p| : |% +.9p| \n", testa);
	ft_printf(" |%%0+.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+ .20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+0.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%.2p|  : |%.2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);

	ft_printf(" |%% +.2c| : |% +.2c| \n", 48);
	ft_printf(" |%%.2c|  : |%.2c| \n", 48);
	ft_printf("  |%%.0c|  : |%.0c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);

	ft_printf(" |%% +.20s| : |% +.20s| \n", "1");
	ft_printf(" |%%.2s| avec ""123""  : |%.2s| \n", "123");
	ft_printf(" |%%.2s| avec ""1""  : |%.2s| \n", "1");
	ft_printf(" |%%.0s| avec ""1""  : |%.0s| \n", "1");
	ft_printf(" |%%.1s| avec ""1""  : |%.1s| \n", "12");
	ft_printf("  |%%s|  : |% +s| \n", "-1");

	//TEST PRECISION a 0
	ft_printf("\n\tTEST PRECISION a 0\n");
	ft_printf("|%% +.0d| avec ""0""  : |% +.0d| \n",0);
	ft_printf(" |%%.0d| avec ""0"" : |%.0d| \n",0);
	ft_printf("|%% +.0d| avec ""0""  : |% +.0d| \n",1);
	ft_printf(" |%%.0d| avec ""0"" : |%.0d| \n",1);
	ft_printf(" |%%.0d| avec ""-2000"" : |%.0d| \n", -2000);
	ft_printf(" |%%.0d| avec ""-1234"" : |%.0d| \n", 1234);
	ft_printf(" |%%.d|  : |%d| \n",0);
	ft_printf(" |%%0d| avec ""0""  : |%0d| \n",0);


	ft_printf(" |%% +.0d| : |% +.0d| \n", 1);
	ft_printf(" |%%.0d|  : |%.0d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);

	ft_printf("|%% +.0d| : |% +.0d| \n", -1);
	ft_printf(" |%%.0d| : |%.0d| \n", -1);
	ft_printf("  |%%.d| : |%d| \n", -1);

	ft_printf(" |%% +.0o| : |% +.0o| \n", 3);
	ft_printf(" |%%.0o|  : |%.0o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +.0o| : |% +.0o| \n", 8);
	ft_printf(" |%%.0o|  : |%.0o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);
	ft_printf(" |%%.0o| avec ""0"" : |%.0o| \n", 0);




	ft_printf(" |%% +.0u| : |% +.0u| \n", 1);
	ft_printf(" |%%.0u|  : |%.0u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);
	ft_printf(" |%%.0u| avec ""0"" : |%.0u| \n", 0);


	ft_printf(" |%% +.0u| : |% +.0u| \n", 4294967295);
	ft_printf(" |%%.0u|  : |%.0u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);

	ft_printf(" |%% +.0x| : |% +.0x| \n", 1);
	ft_printf(" |%%.0x|   : |%.0x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);

	ft_printf(" |%% +.0p| : |% +.0p| \n", testa);
	ft_printf(" |%%.0p|  : |%.0p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);

	ft_printf(" |%% +.0c| : |% +.0c| \n", 48);
	ft_printf(" |%%.0c|  : |%.0c| \n", 48);
	ft_printf("  |%%.0c|  : |%.0c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);

	ft_printf(" |%% +.0s| : |% +.0s| \n", "1");
	ft_printf(" |%%.0s| avec ""123""  : |%.0s| \n", "123");
	ft_printf(" |%%.0s| avec ""1""  : |%.0s| \n", "1");
	ft_printf(" |%%.0s| avec ""1""  : |%.0s| \n", "1");
	ft_printf(" |%%.0s| avec ""1""  : |%.0s| \n", "12");
	ft_printf("  |%%s|  : |% +s| \n", "-1");

	//TEST CHAMPS ET PRECISION
	ft_printf("\n\tTEST CHAMPS ET PRECISION\n");
	ft_printf("|%% +10.5d| avec ""0""  : |% +10.5d| \n",0);
	ft_printf("|%%0+10.5d| avec ""0""  : |%0+10.5d| \n",0);
	ft_printf("|%%+010.5d| avec ""0""  : |%+010.5d| \n",0);
	ft_printf("|%%010.5d| avec ""0""  : |%010.5d| \n",0);
	ft_printf(" |%%10.5d| avec ""0"" : |%10.5d| \n",0);
	ft_printf("|%% +10.5d| avec ""0""  : |% +10.5d| \n",1);
	ft_printf(" |%%10.5d| avec ""0"" : |%10.5d| \n",1);
	ft_printf(" |%%10.5d| avec ""-2000"" : |%10.5d| \n", -2000);
	ft_printf(" |%%10.5d| avec ""-2000"" : |%10.5d| \n", -20000);
	ft_printf(" |%%10.5d| avec ""-2000"" : |%10.5d| \n", 20000);
	ft_printf(" |%%10.5d| avec ""-1234"" : |%10.5d| \n", 1234);
	ft_printf("|%% +5.10d| avec ""0""  : |% +5.10d| \n",0);
	ft_printf(" |%%5.10d| avec ""0"" : |%5.10d| \n",0);
	ft_printf("|%% +5.10d| avec ""0""  : |% +5.10d| \n",1);
	ft_printf(" |%%5.10d| avec ""0"" : |%5.10d| \n",1);
	ft_printf(" |%%5.10d| avec ""-2000"" : |%5.10d| \n", -2000);
	ft_printf(" |%%5.10d| avec ""-1234"" : |%5.10d| \n", 1234);
	ft_printf(" |%%d|  : |%.d| \n",0);
	ft_printf(" |%%.d|  : |%.d| \n",0);
	ft_printf(" |%%0.5d| avec ""0""  : |%0.5d| \n",0);
	ft_printf(" |%%5.0d| avec ""0""  : |%5.0d| \n",0);
	ft_printf(" |%%0.0d| avec ""0""  : |%0.0d| \n",0);


	ft_printf(" |%% +10.5d| : |% +10.5d| \n", 1);
	ft_printf(" |%%10.5d|  : |%10.5d| \n", 1);
	ft_printf(" |%% +5.10d| : |% +5.10d| \n", 1);
	ft_printf(" |%%5.10d|  : |%5.10d| \n", 1);
	ft_printf("  |%%d|  : |%d| \n", 1);
	ft_printf("  |%%.d|  : |%.d| \n", 1);
	ft_printf("  |%%0.5d|  : |%0.5d| \n", 1);
	ft_printf("  |%%5.0d|  : |%5.0d| \n", 1);
	ft_printf("  |%%0.0d|  : |%0.0d| \n", 1);


	ft_printf("|%% +10.5d| : |% +10.5d| \n", -1);
	ft_printf(" |%%10.5d| : |%10.5d| \n", -1);
	ft_printf("|%% +5.10d| : |% +5.10d| \n", -1);
	ft_printf(" |%%5.10d| : |%5.10d| \n", -1);
	ft_printf("  |%%d| : |%d| \n", -1);
	ft_printf("  |%%.d| : |%.d| \n", -1);
	ft_printf("  |%%0.0d| : |%0.0d| \n", -1);
	ft_printf("  |%%0.5d| : |%0.5d| \n", -1);
	ft_printf("  |%%5.0d| : |%5.0d| \n", -1);
	ft_printf("  |%%0.0d| : |%0.0d| \n", -1);

	ft_printf(" |%% +10.5o| : |% +10.5o| \n", 3);
	ft_printf(" |%%10.5o|  : |%10.5o| \n", 3);
	ft_printf(" |%% +5.10o| : |% +5.10o| \n", 3);
	ft_printf(" |%%5.10o|  : |%5.10o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);
	ft_printf("  |%%.o|  : |%.o| \n", 3);
	ft_printf("  |%%0.0o|  : |%0.0o| \n", 3);
	ft_printf(" |%%5.0o|  : |%5.0o| \n", 3);
	ft_printf(" |%%0.5o|  : |%0.5o| \n", 3);
	ft_printf(" |%%0.0o|  : |%0.0o| \n", 3);


	ft_printf(" |%% +10.5o| : |% +10.5o| \n", 8);
	ft_printf(" |%%10.5o|  : |%10.5o| \n", 8);
	ft_printf(" |%% +5.10o| : |% +5.10o| \n", 8);
	ft_printf(" |%%5.10o|  : |%5.10o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);
	ft_printf("  |%%.o|  : |%.o| \n", 8);
	ft_printf("  |%%0.0o|  : |%0.0o| \n", 8);

	ft_printf(" |%%0.5o| avec ""0"" : |%0.5o| \n", 0);
	ft_printf(" |%%5.0o| avec ""0"" : |%5.0o| \n", 0);
	ft_printf(" |%%0.0o| avec ""0"" : |%0.0o| \n", 0);


	ft_printf(" |%% +10.5u| : |% +10.5u| \n", 1);
	ft_printf(" |%%10.5u|  : |%10.5u| \n", 1);
	ft_printf(" |%% +5.10u| : |% +5.10u| \n", 1);
	ft_printf(" |%%5.10u|  : |%5.10u| \n", 1);
	ft_printf("  |%%u|  : |%u| \n", 1);
	ft_printf("  |%%.u|  : |%.u| \n", 1);
	ft_printf("  |%%0.0u|  : |%0.0u| \n", 1);
	ft_printf(" |%%5.0u| avec ""0"" : |%5.0u| \n", 0);
	ft_printf(" |%%0.5u| avec ""0"" : |%0.5u| \n", 0);
	ft_printf(" |%%0.0u| avec ""0"" : |%0.0u| \n", 0);


	ft_printf(" |%% +10.5u| : |% +10.5u| \n", 4294967295);
	ft_printf(" |%% 10.5u| : |% 10.5u| \n", 4294967295);
	ft_printf(" |%%+5.10u|  : |%+5.10u| \n", 4294967295);
	ft_printf(" |%%5.10u|  : |%5.10u| \n", 4294967295);
	ft_printf("  |%%u|  : |%u| \n", 4294967295);
	ft_printf("  |%%.u|  : |%.u| \n", 4294967295);
	ft_printf("  |%%0.0u|  : |%0.0u| \n", 4294967295);
	ft_printf(" |%%5.0u|  : |%5.0u| \n", 4294967295);
	ft_printf(" |%%0.5u|  : |%0.5u| \n", 4294967295);
	ft_printf(" |%%0.0u|  : |%0.0u| \n", 4294967295);


	ft_printf(" |%% +10.5x| : |% +10.5x| \n", 1);
	ft_printf(" |%% 10.5x| : |% 10.5x| \n", 1);
	ft_printf(" |%% +5.10x| : |% +5.10x| \n", 1);
	ft_printf(" |%% 5.10x| : |% 5.10x| \n", 1);
	ft_printf("  |%%x|   : |%x| \n", 1);
	ft_printf("  |%%.x|   : |%.x| \n", 1);
	ft_printf("  |%%0.0x|   : |%0.0x| \n", 1);
	ft_printf(" |%%5.0x|   : |%5.0x| \n", 1);
	ft_printf(" |%%0.5x|   : |%0.5x| \n", 1);
	ft_printf(" |%%0.0x|   : |%0.0x| \n", 1);


	ft_printf(" |%% +15.5p| : |% +15.5p| \n", testa);
	ft_printf(" |%% +15.9p| : |% +15.9p| \n", testa);
	ft_printf(" |%% 15.5p| : |% 15.5p| \n", testa);
	ft_printf(" |%%+15.5p| : |%+15.5p| \n", testa);
	ft_printf(" |%%15.5p| : |%15.5p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf("  |%%.p|  : |%.p| \n", testa);
	ft_printf("  |%%0.0p|  : |%0.0p| \n", testa);
	ft_printf(" |%%5.0p|  : |%5.0p| \n", testa);
	ft_printf(" |%%0.5p|  : |%0.5p| \n", testa);
	ft_printf(" |%%0.0p|  : |%0.0p| \n", testa);

	ft_printf(" |%% +10.5c| : |% +10.5c| \n", 48);
	ft_printf(" |%% 10.5c| : |% 10.5c| \n", 48);
	ft_printf(" |%% +5.10c| : |% +5.10c| \n", 48);
	ft_printf(" |%% 5.10c| : |% 5.10c| \n", 48);
	ft_printf("  |%%c|  : |%c| \n", 48);
	ft_printf("  |%%.c|  : |%.c| \n", 48);
	ft_printf("  |%%0.0c|  : |%0.0c| \n", 48);
	ft_printf(" |%%5.0c|  : |%5.0c| \n", 48);
	ft_printf("  |%%0.5c|  : |%0.5c| \n", 48);
	ft_printf("  |%%0.0c|  : |%0.0c| \n", 48);

	ft_printf(" |%% +10.5s| : |% +10.5s| \n", "1");
	ft_printf(" |%% 10.5s| : |% 10.5s| \n", "1");
	ft_printf(" |%% +5.10s| : |% +5.10s| \n", "1");
	ft_printf(" |%% 5.10s| : |% 5.10s| \n", "1");
	ft_printf("  |%% +s|  : |% +s| \n", "-1");
	ft_printf("  |%%s|  : |%s| \n", "-1");
	ft_printf("  |%%.s|  : |%.s| \n", "-1");
	ft_printf("  |%%0.0s|  : |%0.0s| \n", "-1");
	ft_printf(" |%% 5.0s| : |% +5.0s| \n", "1");
	ft_printf(" |%% 0.5s| : |% +0.5s| \n", "1");
	ft_printf(" |%% 0.0s| : |% +0.0s| \n", "1");

	ft_printf(" |%%+10.5s| avec ""123""  : |+%10.5s| \n", "123");
	ft_printf(" |%%10.5s| avec ""123""  : |%10.5s| \n", "123");
	ft_printf(" |%%+5.10s| avec ""123""  : |%+5.10s| \n", "123");
	ft_printf(" |%%5.10s| avec ""123""  : |%5.10s| \n", "123");
	ft_printf(" |%%s| avec ""123""  : |%s| \n", "123");
	ft_printf(" |%%.s| avec ""123""  : |%.s| \n", "123");
	ft_printf(" |%%0.0s| avec ""123""  : |%0.0s| \n", "123");
	ft_printf(" |%%.0s| avec ""123""  : |%.0s| \n", "123");
	ft_printf(" |%%0.0s| avec ""123""  : |%0.0s| \n", "123");

	ft_printf(" |%%5.0s| avec ""123""  : |%5.0s| \n", "123");
	ft_printf(" |%%0.5s| avec ""123""  : |%5.0s| \n", "123");
	ft_printf(" |%%0.0s| avec ""123""  : |%0.0s| \n", "123");

	ft_printf(" |%%+10.5s| avec ""12""  : |%+10.5s| \n", "12");
	ft_printf(" |%%10.5s| avec ""1""  : |%10.5s| \n", "12");
	ft_printf(" |%%+5.10s| avec ""1""  : |%+5.10s| \n", "12");
	ft_printf(" |%%5.10s| avec ""1""  : |%5.10s| \n", "12");
	ft_printf(" |%%s| avec ""1""  : |%s| \n", "12");
	ft_printf(" |%%.0s| avec ""1""  : |%.0s| \n", "12");
	ft_printf(" |%%0.0s| avec ""1""  : |%0.0s| \n", "12");

	ft_printf(" |%%5.0s| avec ""1""  : |%5.0s| \n", "12");
	ft_printf(" |%%0.5s| avec ""1""  : |%0.5s| \n", "12");
	ft_printf(" |%%0.0s| avec ""1""  : |%0.0s| \n", "12");


	//TEST D'AFFICHAGE DES POINTEURS
	ft_printf("\n\tTEST D'AFFICHAGE DES POINTEURS\n");
	ft_printf("BLANK p : |% p| \n", testa);
	ft_printf("BLANK p : |%p| \n", testa);
	ft_printf(" %%0p : |%0p| \n", testa);
	ft_printf(" %%020p : |%020p| \n", testa);
	ft_printf("  %%p : |%p| \n", testa);
	ft_printf(" %%20p : |%20p| \n", testa);
	ft_printf(" %%2p : |%2p| \n", testa);
	ft_printf("  %%p : |%p| \n", testa);
	ft_printf(" |%% 20p| : |% 20p| \n", testa);
	ft_printf(" |%% p| : |% p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf(" |%%+ 20p| : |%+ 20p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf(" |%% +20p| : |% +20p| \n", testa);
	ft_printf(" |%%2p|  : |%2p| \n", testa);
	ft_printf("  |%%p|  : %p \n", testa);
	ft_printf(" |%% +.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%0+.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+ .20p| : |% +.20p| \n", testa);
	ft_printf(" |%%+0.20p| : |% +.20p| \n", testa);
	ft_printf(" |%%.2p|  : |%.2p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf(" |%% +.0p| : |% +.0p| \n", testa);
	ft_printf(" |%%.0p|  : |%.0p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf(" |%% +20.15p| : |% +20.15p| \n", testa);

	ft_printf("Precision et padding avec flag '0'\n");
	ft_printf("     |%%0+20.15p| : |%0+20.15p| \n", testa);
	ft_printf("     |%%020.15p| : |%020.15p| \n", testa);
	ft_printf("     |%%020.15p| : |% 020.15p| \n", testa);

	ft_printf(" |%% 10.5p| : |% 10.5p| \n", testa);
	ft_printf(" |%%+10.5p| : |%+10.5p| \n", testa);
	ft_printf(" |%%10.5p| : |%10.5p| \n", testa);
	ft_printf("  |%%p|  : |%p| \n", testa);
	ft_printf("  |%%.p|  : |%.p| \n", testa);
	ft_printf("  |%%0.0p|  : |%0.0p| \n", testa);
	ft_printf(" |%%5.0p|  : |%5.0p| \n", testa);
	ft_printf(" |%%0.5p|  : |%0.5p| \n", testa);
	ft_printf(" |%%0.0p|  : |%0.0p| \n", testa);

	//TEST D'AFFICHAGE DES OCTAUX
	ft_printf("\n\tTEST D'AFFICHAGE DES OCTAUX\n");
	ft_printf(" |%% 2o| : |% 2o| \n", 3);
	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% 2o| : |% 2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);
	ft_printf(" %%02o : |%02o| \n", 3);
	ft_printf(" %%3o : |%3o| \n", 3);
	ft_printf("  %%o : |%o| \n", 3);

	ft_printf(" %%02o : |%02o| \n", 8);
	ft_printf(" %%3o : |%3o| \n", 8);
	ft_printf("  %%o : |%o| \n", 8);
	ft_printf(" %%0o : |%0o| \n", 3);
	ft_printf(" %%02o : |%02o| \n", 3);
	ft_printf("  %%o : |%o| \n", 3);

	ft_printf(" %%0o : |%0o| \n", 8);
	ft_printf(" %%02o : |%02o| \n", 8);
	ft_printf("  %%o : |%o| \n", 8);
	ft_printf("BLANK o : |% o| \n", 8);
	ft_printf("BLANK o : |%o| \n", 8);


	ft_printf(" |%%+ 2o| : |%+ 2o| \n", 3);
	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%%+ 2o| : |%+ 2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);

	ft_printf(" |%%3o|  : |%3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +2o| : |% +2o| \n", 8);
	ft_printf(" |%%3o|  : |%3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);

	ft_printf(" |%% +.2o| : |% +.2o| \n", 3);
	ft_printf(" |%%.3o|  : |%.3o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +.2o| : |% +.2o| \n", 8);
	ft_printf(" |%%.3o|  : |%.3o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);

	ft_printf(" |%% +.0o| : |% +.0o| \n", 3);
	ft_printf(" |%%.0o|  : |%.0o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);

	ft_printf(" |%% +.0o| : |% +.0o| \n", 8);
	ft_printf(" |%%.0o|  : |%.0o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);
	ft_printf(" |%%.0o| avec ""0"" : |%.0o| \n", 0);

	ft_printf(" |%% +10.5o| : |% +10.5o| \n", 3);
	ft_printf(" |%%10.5o|  : |%10.5o| \n", 3);
	ft_printf(" |%% +5.10o| : |% +5.10o| \n", 3);
	ft_printf(" |%%5.10o|  : |%5.10o| \n", 3);
	ft_printf("  |%%o|  : |%o| \n", 3);
	ft_printf("  |%%.o|  : |%.o| \n", 3);
	ft_printf("  |%%0.0o|  : |%0.0o| \n", 3);
	ft_printf(" |%%5.0o|  : |%5.0o| \n", 3);
	ft_printf(" |%%0.5o|  : |%0.5o| \n", 3);
	ft_printf(" |%%0.0o|  : |%0.0o| \n", 3);


	ft_printf(" |%% +10.5o| : |% +10.5o| \n", 8);
	ft_printf(" |%%10.5o|  : |%10.5o| \n", 8);
	ft_printf(" |%% +5.10o| : |% +5.10o| \n", 8);
	ft_printf(" |%%5.10o|  : |%5.10o| \n", 8);
	ft_printf("  |%%o|  : |%o| \n", 8);
	ft_printf("  |%%.o|  : |%.o| \n", 8);
	ft_printf("  |%%0.0o|  : |%0.0o| \n", 8);

	ft_printf(" |%%0.5o| avec ""0"" : |%0.5o| \n", 0);
	ft_printf(" |%%5.0o| avec ""0"" : |%5.0o| \n", 0);
	ft_printf(" |%%0.0o| avec ""0"" : |%0.0o| \n", 0);

	//		//TEST D'AFFICHAGE DES CARACTERES ET STRING
	ft_printf("\n\tTEST D'AFFICHAGE DES CARACTERES ET STRING\n");
	ft_printf(" |%% +.2c| : |% +.2c| \n", '+');
	ft_printf(" |%% +3.2c| : |% +3.2c| \n", '+');
	ft_printf(" |%% +.2s| : |% +.2s| \n", "+");
	ft_printf(" |%% +3.2s| : |% +3.2s| \n", "+");

	ft_printf(" |%% +.2s| : |% +.2s| \n", "123");
	ft_printf(" |%% +3.2s| : |% +3.2s| \n", "123");

	//TEST D'AFFICHAGE BASIC DE 42FILECHECKER
	

	ft_printf("\nBASIC TESTS DE 42FILECHECKER\n");
	int k = ft_printf("%5%");
	printf("\n%5%\n");
	ft_printf("\n%d\n", k);
	ft_printf("\n|%-5%|\n");
	printf("|%-5%|\n");
	ft_printf("|%5%|\n");
	ft_printf("|%-5d|\n", 5);

	k = ft_printf("%x", 0);
	printf("\n%d\n", k);

	k = ft_printf("#x : %#x", 42);
	printf("\n%d\n", k);

	k = ft_printf("%#08x", 42);
	printf("\n%d\n", k);

	k = ft_printf("%#x", 0);
	printf("\n%d\n", k);

	k = ft_printf("%#-08x", 42);
	printf("\n%d\n", k);
	
	ft_printf("|%.0x|\n", 0);
	ft_printf("|%.0d|\n", 1);
	printf("|%.0x|\n", 0);
	printf("|%.0d|\n", 1);

	k = ft_printf("%5.2s is a string", "");
	printf("\n%d\n", k);

	k = ft_printf("@moulitest: %s", NULL);
	printf("\n%d\n", k);
	
	ft_printf("|%#6o|\n", 2500);
	printf("|%#6o|\n", 2500);
	ft_printf("|%#6o|\n", 0);
	printf("|%#6o|\n", 0);
	
	ft_printf("|@moulitest: %.o %.0o|\n", 0, 0);
	printf("|@moulitest: %.o %.0o|\n", 0, 0);
	printf("|@moulitest: %.o %o|\n", 0, 0);

	k = ft_printf("%d\n", -1);
	printf("%d\n", k);

	k = ft_printf("% d\n", 42);
	printf("%d\n\n", k);

	k = ft_printf("% o\n", 42);
	printf("%d\n", k);
	k = printf("% x\n", 42);
	printf("%x\n\n", k);
	
	ft_printf("%d\n", 2147483647);
	ft_printf("%U\n", 4294967295);
	ft_printf("%lU\n", 4294967295);
	ft_printf("%hU\n", 4294967295);


	printf("%hld\n", 2147483647);
	*/
	
/*
	ft_printf("|%%| : |%%|\n");
	ft_printf("%%");
	ft_printf("|%%5%%| : |%5%|\n");
	ft_printf("|%%-5%%| : |%-5%|\n");
	ft_printf("|%%.0%%| : |%.0%|\n");
	ft_printf("|%%| : |%%|\n", "test");
	ft_printf("|%%  %%| : |%   %|\n", "test");
	ft_printf("|%%x| : |%x|\n", 0);
	ft_printf("|%%X| : |%X|\n", 0);
	ft_printf("|%%x| : |%x|\n", 4294967296);
	ft_printf("|%%X| : |%X|\n", 4294967296);
	ft_printf("|%%x| : |%x|\n", test);
	ft_printf("|%%-10x| : |%-10x|\n", 42);
	ft_printf("|%%hx| : |%hx|\n", 4294967296);
	ft_printf("|%%hhX| : |%hhX|\n", 4294967296);
	ft_printf("|%%-15x| : |%-15x|\n", 542);
	ft_printf("|%%#x| : |%#x|\n", 42);
	ft_printf("|%%#llx| : |%#llx|\n", 9223372036854775807);
	ft_printf("|%%#x| : |%#x|\n", 0);
	ft_printf("|%%#x| : |%#x|\n", 42);
	ft_printf("|%%#X| : |%#X|\n", 42);
	ft_printf("|%%#8x| : |%#8x|\n", 42);
	ft_printf("|%%#08x| : |%#08x|\n", 42);
	ft_printf("|%%#-08x| : |%#-08x|\n", 42);
	ft_printf("|@moulitest: %%#.x %%#.0x| : |@moulitest: %#.x %#.0x|\n", 0, 0);
	ft_printf("|@moulitest: %%.x %%.0x| : |@moulitest: %.x %.0x|\n", 0, 0);
	ft_printf("|@moulitest: %%5.x %%5.0x| : |@moulitest: %5.x %5.0x|\n", 0, 0);
	ft_printf("|%%5.2s is a string| : |%5.2s is a string|\n", "");
	ft_printf("|%%-10s is a string| : |%-10s is a string|\n", "this");
	ft_printf("|%%-5.2s is a string| : |%-5.2s is a string|\n", "this");
	ft_printf("|%%-5.2s is a string| : |%-5.2s is a string|\n", "");
	ft_printf("|@moulitest: %%s avec null| : |@moulitest: %s|\n", NULL);

	int		len_return;
	char *string = NULL;
	len_return = ft_printf("|%%s %%s avec null| |%s%s|\n", NULL, string);
	ft_printf("len_return = %d\n", len_return);
	ft_printf("|%%-5c| : |%-5c|\n", 42);
	ft_printf("|%%-5o| : |%-5o|\n", 2500);
	ft_printf("|%%#6o| : |%#6o|\n", 2500);
	ft_printf("|%%-#6o| : |%-#6o|\n", 2500);
	ft_printf("|%%-05o| : |%-05o|\n", 2500);
	ft_printf("|%%-10.5o| : |%-10.5o", 2500);
	ft_printf("|@moulitest: %%o| : |@moulitest: %o|\n", 0);
	ft_printf("|@moulitest: %%#.o %%#.0o| : |@moulitest: %#.o %#.0o|\n", 0, 0);
	ft_printf("|%%d| : | %d|\n", -1);
	ft_printf("|%%d| : | %d|\n", -4242);
	ft_printf("|%%d| : | %d|\n", 2147483648);
	ft_printf("|%%d| : |%d|\n", -2147483648);
	ft_printf("|%% d| : |% d|\n", 42);
	ft_printf("|%% d| : |% d|\n", -42);
	ft_printf("|%%+d| : |%+d|\n", 42);
	ft_printf("|%%+d| : |%+d|\n", -42);
	ft_printf("|%%+d| : |%+d|\n", 0);
	ft_printf("|%%+d| : |%+d|\n", 4242424242424242424242);
	ft_printf("|%% +d| : |% +d|\n", 42);
	ft_printf("|%% +d| : |% +d|\n", -42);
	ft_printf("|%% +d| : |%+ d|\n", 42);
	ft_printf("|%% +d| : |%+ d|\n", -42);
	ft_printf("|%% +d| : |%  +d|\n", 42);
	ft_printf("|%% +d| : |%  +d|\n", -42);
	ft_printf("|%% +d| : |%+  d|\n", 42);
	ft_printf("|%% +d| : |%+  d|\n", -42);
	ft_printf("|%% ++d| : |% ++d|\n", 42);
	ft_printf("|%% ++d| : |% ++d|\n", -42);
	ft_printf("|%%++ d| : |%++ d|\n", 42);
	ft_printf("|%%++ d| : |%++ d|\n", -42);
	ft_printf("|%%0d| : |%0d|\n", -42);
	ft_printf("|%%00d| : |%00d|\n", -42);
	ft_printf("|%%0+5d| : |%0+5d|\n", 42);
	ft_printf("|%%5d| : |%5d|\n", -42);
	ft_printf("|%%05d| : |%05d|\n", -42);
	ft_printf("|%%0+5d| : |%0+5d|\n", -42);
	ft_printf("|%%-5d| : |%-5d|\n", 42);
	ft_printf("|%%-05d| : |%-05d|\n", 42);
	ft_printf("|%%-5d| : |%-5d|\n", -42);
	ft_printf("|%%-05d| : |%-05d|\n", -42);
	ft_printf("|%%hd| : |%hd|\n", 32768);
	ft_printf("|%%hhd| : |%hhd|\n", 128);
	ft_printf("|%%hhd| : |%hhd|\n", -128);
	ft_printf("|%%ld| : |%ld|\n", -2147483648);
	ft_printf("|%%ld| : |%ld|\n", -2147483649);
	ft_printf("|%%lld| : |%lld|\n", -9223372036854775808);
	ft_printf("|%%jd| : |%jd|\n", -9223372036854775808);
	ft_printf("|%%zd| : |%zd|\n", -1);

	ft_printf("|%%-10.5d| : |%-10.5d|\n", 4242);
	ft_printf("|%%+10.5d| : |%+10.5d|\n", 4242);
	ft_printf("|%%-+10.5d| : |%-+10.5d|\n", 4242);
	ft_printf("|%%03.2d| : |%03.2d|\n", -1);
	ft_printf("|@moulitest: %%.10d| : |@moulitest: %.10d|\n", -42);
	ft_printf("|%%-15u| : |%-15u|\n", 4294967295);
	ft_printf("|%%U| : |%U|\n", 4294967295);
	ft_printf("|%%hU| : |%hU|\n", 4294967296);
	ft_printf("|%%U| : |%U|\n", 4294967296);
	
 //TEST FLAG '-'
	ft_printf("\nTEST FLAG '-'\n");
	ft_printf(" -d : %-d \n",0);
	ft_printf("  d : %d \n",0);

	ft_printf(" -d : %-d \n", 1);
	ft_printf("  d : %d \n", 1);

	ft_printf(" -d : %-d \n", -1);
	ft_printf("  d : %d \n", -1);

	ft_printf(" -o : %-o \n", 8);
	ft_printf("  o : %o \n", 8);

	ft_printf(" -u : %-u \n", 1);
	ft_printf("  u : %u \n", 1);

	ft_printf(" -u : %-u \n", -1);
	ft_printf("  u : %u \n", -1);

	ft_printf(" -x : %-x \n", 1);
	ft_printf("  x : %x \n", 1);

	ft_printf(" -x : %-x \n", -1);
	ft_printf("  x : %x \n", -1);

	ft_printf(" -p : %-p \n", testa);
	ft_printf("  p : %p \n", testa);

	ft_printf(" -c : %-c \n", 48);
	ft_printf("  c : %c \n", 48);

	ft_printf(" -s : %-s \n", "1");
	ft_printf("  s : %-s \n", "-1");
		 
	ft_printf("\n%hhd", 128);
	printf("\n%hhd\n", 128);
	
	
	printf("\n");
	printf("Test du cas %% : |");
	k = ft_printf("%");
	printf("|\n");
	printf("\nk = %d", k);
	printf("\n");
	k = printf("%");
	printf("\nk = %d", k);
	 
	int k;

	k = ft_printf("% ");
	printf("\n");
	printf("%d\n", k);

	k = ft_printf("%33.#0d", 256);
	printf("\n");
	printf("%d\n", k);
	k = printf("%33.#0d", 256);
	printf("\n");
	printf("%d\n", k);

	k = ft_printf("%#08x", 42);
	printf("\n");
	printf("%d\n", k);

	unsigned long ss;

	// test->debug = 1;
	k = ft_printf("%%p : %p", (void*)ss);
	printf("\n");
	printf("%d\n", k);

	k = printf("%%p : %p", (void*)ss);
	printf("\n");
	printf("%d\n", k);


	printf("\n");
	printf("1 : ft_printf %%ls :");
	k = ft_printf("%S", L"Á±≥");
	ft_printf("\n");
	printf("\nret : %d\n", k);
	
	printf("1 : printf %%S :");
	k = printf("%S", L"Á±≥");
	ft_printf("\n");
	printf("\nret : %d\n", k);

	printf("2 : ft_printf %%ls :");
	k = ft_printf("%S", L"ᚠᚠc");
	printf("\n");
	printf("ret : %d\n", k);

	printf("2 : Printf %%ls :");
	k = printf("%ls", L"ᚠc");
	printf("\n");
	printf("ret : %d\n", k);

	k = ft_printf("3 : %C", L'ᚠ');
	printf("\n");
	printf("ret ft : %d\n", k);

	k = printf("3 : %C", L'ᚠ');
	printf("\n");
	printf("ret : %d\n", k);

	k = printf("4 : %S", L"ᚠ");
	printf("\n");
	printf("ret : %d\n", k);

	k = ft_printf("test %%S : |%S|\n", L"ᚠc");
	ft_printf("ret = %d\n", k);

	k = ft_printf("test %%S : |%S|\n", L"Á±≥");
	ft_printf("ret = %d\n", k);
	
	ft_printf("\n");
//		printf("Sizeof wchar_t %zu\n", sizeof(wchar_t));
	
	k = ft_printf("%%C : %C\n", L'Á');
	k = ft_printf("%%C : %C\n", L'ᚠ');

	ft_printf("ft_printf : {%%030S} : ");
	k = ft_printf("{%030S}", L"我是一只猫。");
	//是一只猫。
	 printf("\n");
	ft_printf("printf : {%%030S} : ");
	k = printf("{%030S}", L"我是一只猫。");
	printf("\n");

	ft_printf("%O\n", LONG_MAX);
	printf("%O\n", LONG_MAX);

	ft_printf("% 03d\n", 0);
	printf("% 05d\n", -1);

	ft_printf("ft_printf : %%.0p, %%.p : ");
	k = ft_printf("%.0p, %.p", 0, 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.0p, %%.p : ");
	k = printf("%.0p, %.p", 0, 0);
	printf("\nret : %d\n", k);
	

	
	ft_printf("ft_printf : %%9.2p : ");
	k = ft_printf("%9.2p", 1234);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%9.2p : ");
	k = printf("%9.2p", 1234);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%2.9p : ");
	k = ft_printf("%2.9p", 1234);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%2.9p : ");
	k = printf("%2.9p", 1234);
	printf("\nret : %d\n", k);



	ft_printf("ft_printf : %%05.s : ");
	k = ft_printf("%05.s", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05.s : ");
	k = printf("%05.s", 0);
	printf("\nret : %d\n", k);
	ft_printf("ft_printf : %%Z,bc : ");
	k = ft_printf("%Z,bc");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%Z,bc : ");
	k = printf("%Z,bc");
	printf("\nret : %d\n", k);


	ft_printf("CAS 0\n");
	ft_printf("ft_printf : %% : ");
	k = ft_printf("%");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% : ");
	k = printf("%");
	printf("\nret : %d\n", k);

	ft_printf("CAS 1\n");
	ft_printf("ft_printf : {%%05.Z : ");
	k = ft_printf("{%05.Z}");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%05.Z : ");
	k = printf("{%05.Z}");
	printf("\nret : %d\n", k);

	ft_printf("CAS 2\n");
	ft_printf("ft_printf : {%%05.Z} : ");
	k = ft_printf("{%05.Z}");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%05.Z} : ");
	k = printf("{%05.Z}");
	printf("\nret : %d\n", k);

	ft_printf("CAS 3\n");
	ft_printf("ft_printf : %% Zoooo : ");
	k = ft_printf("% Zoooo");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% Zoooo : ");
	k = printf("% Zoooo");
	printf("\nret : %d\n", k);

	ft_printf("CAS 4\n");
	ft_printf("ft_printf : {%%} : ");
	k = ft_printf("{%5}");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%} : ");
	k = printf("{%5}");
	printf("\nret : %d\n", k);

	ft_printf("CAS 5\n");
	ft_printf("ft_printf : {% } : ");
	k = ft_printf("% ");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {% } : ");
	k = printf("% ");
	printf("\nret : %d\n", k);

	ft_printf("CAS 6\n");
	ft_printf("ft_printf : {%%#08x} : ");
	k = ft_printf("%#08x", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%#08x} : ");
	k = printf("%#08x", 1);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7\n");
	ft_printf("ft_printf : {%%#.5x} : ");
	k = ft_printf("%#.5x", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%#.5x} : ");
	k = printf("%#.5x", 1);
	printf("\nret : %d\n", k);

	ft_printf("CAS 8\n");
	ft_printf("ft_printf : {%%#.2x} : ");
	k = ft_printf("%#.2x", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%#.2x} : ");
	k = printf("%#.2x", 1);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : {%%.4x} : ");
	k = ft_printf("%.4x", 424242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%.4x} : ");
	k = printf("%.4x", 424242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 10\n");
	ft_printf("ft_printf : {%%o, %%ho, %%hho} : ");
	k = ft_printf("%o, %ho, %hho", -42, -42, -42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%o, %%ho, %%hho} : ");
	k = printf("%o, %ho, %hho", -42, -42, -42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 11\n");
	ft_printf("ft_printf : {%%hho} : ");
	k = ft_printf("%ho, %hho", 30, -25);
	ft_printf("\n%hho", -25);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%hho} : ");
	k = printf("%ho, %hho", 30, -25);
	printf("\nret : %d\n", k);

	ft_printf("CAS 12\n");
	ft_printf("%d%hho%o\n", -25, -42, 50);
	ft_printf("%15d%hho%o\n", -25, -42, 50);
	printf("%15d%hho%o\n", -25, -42, 50);

	ft_printf("CAS 13\n");
	ft_printf("ft_printf : {%%hhu %%hhu} : ");
	k = ft_printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%hhu, %%hhu} : ");
	k = printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 14\n");
	ft_printf("ft_printf : {%%05.3S} : ");
	k = ft_printf("{%5S}", L"");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%05.S} : ");
	k = printf("{%5S}", L"");
	printf("\nret : %d\n", k);

	ft_printf("CAS 15\n");
	ft_printf("ft_printf : {%%05.S} : ");
	k = ft_printf("{%5.3s}", "");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%05.S} : ");
	k = printf("{%5.3s}", "");
	printf("\nret : %d\n", k);

	ft_printf("CAS 16\n");
	ft_printf("ft_printf : {%% 10.5d} : ");
	k = ft_printf("{% 10.5d}", 4242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%% 10.5d} : ");
	k = printf("{% 10.5d}", 4242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 17\n");
	ft_printf("ft_printf : {%%.2d} : ");
	k = ft_printf("{%.3d}", 4242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%.2d} : ");
	k = printf("{%.3d}", 4242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 17\n");
	ft_printf("ft_printf : {%%.2s is a string} : ");
	k = ft_printf("{%.2s is a string}", "this");
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%.2s is a string} : ");
	k = printf("{%.2s is a string}", "this");
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : {%%.4x} : ");
	k = ft_printf("%.4x", 42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%.4x} : ");
	k = printf("%.4x", 42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : {%%.4x} : ");
	k = ft_printf("%.4x", 424242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%.4x} : ");
	k = printf("%.4x", 424242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : {%%15.4x} : ");
	k = ft_printf("%15.4x", 42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : {%%15.4x} : ");
	k = printf("%15.4x", 42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : %%05.c : ");
	k = ft_printf("%05.c", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05.c : ");
	k = printf("%05.c", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : %%05.s : ");
	k = ft_printf("%05.s", "5465");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05.s : ");
	k = printf("%05.s", "5465");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%5S : ");
	k = ft_printf("%5S", L"Ê c'est cool");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%5S : ");
	k = printf("%5S", L"Ê c'est cool");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%S : ");
	k = ft_printf("%S", L"Ê c'est cool");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S : ");
	k = printf("%S", L"Ê c'est cool");
	printf("\nret : %d\n", k);

	ft_printf("CAS 5100\n");
	ft_printf("ft_printf : %%30S : ");
	k = ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%30S : ");
	k = printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%25S : ");
	k = ft_printf("{%25S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%25S : ");
	k = printf("{%25S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);
	
	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%1S : ");
	k = ft_printf("{%1S}", L"ÊM");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%1S : ");
	k = printf("{%1S}", L"ÊM");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%2S : ");
	k = ft_printf("{%2S}", L"ÊM");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%2S : ");
	k = printf("{%2S}", L"ÊM");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%3S : ");
	k = ft_printf("{%3S}", L"ÊM");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%3S : ");
	k = printf("{%3S}", L"ÊM");
	printf("\nret : %d\n", k);

	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%4S : ");
	k = ft_printf("{%4S}", L"ÊM");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%4S : ");
	k = printf("{%4S}", L"ÊM");
	printf("\nret : %d\n", k);


	ft_printf("CAS 500\n");
	ft_printf("ft_printf : %%S : ");
	k = ft_printf("{%S}", L"ÊM");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S : ");
	k = printf("{%S}", L"ÊM");
	printf("\nret : %d\n", k);
	
	ft_printf("CAS 5100\n");
	ft_printf("ft_printf : %%S : ");
	k = ft_printf("{%S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S : ");
	k = printf("{%S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nret : %d\n", k);

	ft_printf("CAS 5100\n");
	ft_printf("ft_printf : %%30S : ");
	k = ft_printf("{%30S}", L"我是一只猫。");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%30S : ");
	k = printf("{%30S}", L"我是一只猫。");
	printf("\nret : %d\n", k);



	ft_printf("CAS 5100\n");
	ft_printf("ft_printf : %%0.5p : ");
	k = ft_printf("{%15.5p}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0.5p : ");
	k = printf("{%15.5p}", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5100\n");
	ft_printf("ft_printf : %%030x : ");
	k = ft_printf("{%030x}", 0xFFFF);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%030x : ");
	k = printf("{%030x}", 0xFFFF);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5200\n");
	ft_printf("ft_printf : %%05p : ");
	k = ft_printf("{%01p}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05p : ");
	k = printf("{%01p}", 0);
	printf("\nret : %d\n", k);

	
	int *kop;

	ft_printf("CAS 5300\n");
	ft_printf("ft_printf : %%05p : ");
	k = ft_printf("{%025p}", &kop);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05p : ");
	k = printf("{%025p}", &kop);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5400\n");
	ft_printf("ft_printf : %%.5C : ");
	k = ft_printf("{%.5C}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5C : ");
	k = printf("{%.5C}", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5500\n");
	ft_printf("ft_printf : %%.5C : ");
	k = ft_printf("{%.5C}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5C : ");
	k = printf("{%.5C}", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5500\n");
	ft_printf("ft_printf : %%.5C : ");
	k = ft_printf("{%.5C}", L'Ê');
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5C : ");
	k = printf("{%.5C}", L'Ê');
	printf("\nret : %d\n", k);

	ft_printf("CAS 5600\n");
	ft_printf("ft_printf : %%.5C : ");
	k = ft_printf("{%.C}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5C : ");
	k = printf("{%.C}", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5600\n");
	ft_printf("ft_printf : %%05s : ");
	k = ft_printf("{%05s}", "abc");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%05s : ");
	k = printf("{%05s}", "abc");
	printf("\nret : %d\n", k);

	ft_printf("CAS 5600\n");
	ft_printf("ft_printf : %%.4S : ");
	k = ft_printf("{%.4S}", L"我是一只猫。");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.4S : ");
	k = printf("{%.4S}", L"我是一只猫。");
	printf("\nret : %d\n", k);

	ft_printf("CAS 5700\n");
	ft_printf("ft_printf : %% 0.2d : ");
	k = ft_printf("{% 0.2d}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 0.2d : ");
	k = printf("{% 0.2d}", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5800\n");
	ft_printf("ft_printf : %%42.53zd : ");
	k = ft_printf("{% 34.50hhd}", -5);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%42.53zd : ");
	k = printf("{% 34.50hhd}", -5);
	printf("\nret : %d\n", k);



    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%42.53zd : ");
    k = ft_printf("{%60.10d}", -1044492945);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%42.53zd : ");
    k = printf("{%60.10d}", -1044492945);
    printf("\nret : %d\n", k);


    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%42.53zd : ");
    k = ft_printf("{% d}", -42);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%42.53zd : ");
    k = printf("{% d}", -42);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%42.53zd : ");
    k = ft_printf("%d", 42);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%42.53zd : ");
    k = printf("%d", 42);
    printf("\nret : %d\n", k);


    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k = ft_printf("{% 03d}", 0);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k = printf("{% 03d}", 0);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k = ft_printf("{% d}", 9999);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k = printf("{% d}", 9999);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k = ft_printf("{%.4d}", -424242);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k = printf("{%.4d}", -424242);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k =   ft_printf("%+10.3d", 4242);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k =   printf("%+10.3d", 4242);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k =   ft_printf("%15.4d", -424242);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k =   printf("%15.4d", -424242);
    printf("\nret : %d\n", k);

    ft_printf("CAS 5800\n");
    ft_printf("ft_printf : %%S : ");
    k =   ft_printf("%15.4d", -42);
    printf("\nret : %d\n", k);
    ft_printf("   printf : %%S : ");
    k =   printf("%15.4d", -42);
    printf("\nret : %d\n", k);

	ft_printf("CAS 5800\n");
	ft_printf("ft_printf : %4.15d 42 : ");
	k =   ft_printf("%4.15d", 42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %4.15d 42 : ");
	k =   printf("%4.15d", 42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 6500\n");
	ft_printf("ft_printf : %%4.15d 424242: ");
	k =   ft_printf("%4.15d", 424242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%4.15d 424242: ");
	k =   printf("%4.15d", 424242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 6600\n");
	ft_printf("ft_printf : %%4.8d 424242424: ");
	k =   ft_printf("%4.8d", 424242424);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%4.8d 424242424: ");
	k =   printf("%4.8d", 424242424);
	printf("\nret : %d\n", k);

	ft_printf("CAS 6700\n");
	ft_printf("ft_printf : %%4.15d -42: ");
	k =   ft_printf("%4.15d", -42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%4.15d -42: ");
	k =   printf("%4.15d", -42);
	printf("\nret : %d\n", k);

	ft_printf("CAS 6800\n");
	ft_printf("ft_printf : %%4.15d -424242: ");
	k =   ft_printf("%4.15d", -424242);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%4.15d -424242: ");
	k =   printf("%4.15d", -424242);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7100\n");
	ft_printf("ft_printf : %%.0p, %%.p, 0, 0 ");
	k =   ft_printf("%.0p, %.p", 0, 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.0p, %%.p, 0, 0: ");
	k =   printf("%.0p, %.p", 0, 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7200\n");
	ft_printf("ft_printf : %%.5p, 0 :");
	k =   ft_printf("%.5p", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5p, 0 : ");
	k =   printf("%.5p", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7300\n");
	ft_printf("ft_printf : %%9.2p, 1234 : ");
	k =   ft_printf("%9.2p", 1234);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%9.2p\", 1234: ");
	k =   printf("%9.2p", 1234);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7400\n");
	ft_printf("ft_printf : %%9.2p, 1234567 : ");
	k =   ft_printf("%9.2p", 1234567);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%9.2p, 1234567 : ");
	k =   printf("%9.2p", 1234567);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7500\n");
	ft_printf("ft_printf : %%2.9p, 1234: ");
	k =   ft_printf("%2.9p", 1234);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%2.9p, 1234: ");
	k =   printf("%2.9p", 1234);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7600\n");
	ft_printf("ft_printf : %%2.9p, 1234567 ");
	k =   ft_printf("%2.9p", 1234567);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%2.9p, 1234567 ");
	k =   printf("%2.9p", 1234567);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9000\n");
	ft_printf("ft_printf : ^.^%% 27.34zd^.^");
	k =   ft_printf("^.^% 27.34zd^.^", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : ^.^%% 27.34zd^.^");
	k =   printf("^.^% 27.34zd^.^", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9000\n");
	ft_printf("ft_printf : %%31.15hhd, 1004946852");
	k =   ft_printf("%31.15hhd", 1004946852);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%31.15hhd, 1004946852");
	k =   printf("%31.15hhd", 1004946852);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9000\n");
	ft_printf("ft_printf : %%31.15d, 1004946852");
	k =   ft_printf("%31.15d", -92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%31.15d, 1004946852");
	k =   printf("%31.15d", -92);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9000\n");
	ft_printf("ft_printf : %% 56.32zd42, 0");
	k =   ft_printf("42% 56.32zd42", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 56.32zd42, 0");
	k =   printf("42% 56.32zd42", 0);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9100\n");
	ft_printf("ft_printf : %% 24.22i, 2044020523 : ");
	k =   ft_printf("{% 24.22i}", 2044020523);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 24.22i, 2044020523 : ");
	k =   printf("{% 24.22i}", 2044020523);
	printf("\nret : %d\n", k);


	ft_printf("CAS 9100\n");
	ft_printf("ft_printf : %%.2hhi, -1096457820 : ");
	k =   ft_printf("{% .2hhi}", -1096457820);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, -1096457820 : ");
	k =   printf("{% .2hhi}", -1096457820);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9100\n");
	ft_printf("ft_printf : %%.3hhi, 92 : ");
	k =   ft_printf("{% 2.2hhi}", 92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.3hhi, 92 : ");
	k =   printf("{% 2.2hhi}", 92);
	printf("\nret : %d\n", k);
	
	ft_printf("CAS 9100\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% .2hhi}", 92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% .2hhi}", 92);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9100\n");
	ft_printf("ft_printf : %%.2hhi, 922 : ");
	k =   ft_printf("{% .2hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 922 : ");
	k =   printf("{% .2hhi}", 100);
	printf("\nret : %d\n", k);
	
	ft_printf("ft_printf : %%.5p : ");
	k = ft_printf("%.5p", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5p : ");
	k = printf("%.5p", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%.5p : ");
	k = ft_printf("%.0p", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.5p : ");
	k = printf("%.0p", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0 .2ji : ");
	k = ft_printf("% .4ji", 10);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0 .2ji : ");
	k = printf("% .4ji", 10);
	printf("\nret : %d\n", k);


	ft_printf("ft_printf : %% 045i, -2131582368 : ");
	k = ft_printf("{% 045i}", -2131582368);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 045i, -2131582368 : ");
	k = printf("{% 045i}", -2131582368);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% 045s, -2131582368 : ");
	k = ft_printf("{% 045s}", "-2131582368");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 045s, -2131582368 : ");
	k = printf("{% 045s}", "-2131582368");
	printf("\nret : %d\n", k);


	
	ft_printf("{%d}", 42);

	ft_printf("CAS 13\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 1.3hhi}", 92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 1.3hhi}", 92);
	printf("\nret : %d\n", k);

	ft_printf("CAS 12\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 2.4hhi}", 9);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 2.4hhi}", 9);
	printf("\nret : %d\n", k);
	
	ft_printf("CAS 11\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% .2hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% .2hhi}", 100);
	printf("\nret : %d\n", k);

	ft_printf("CAS 10\n");
	ft_printf("ft_printf : %% 2.1hhi, 92 : ");
	k =   ft_printf("{% 2.1hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 2.1hhi, 92 : ");
	k =   printf("{% 2.1hhi}", 100);
	printf("\nret : %d\n", k);

	ft_printf("CAS 9\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 4.3hhi}", 9);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 4.3hhi}", 9);
	printf("\nret : %d\n", k);

	ft_printf("CAS 8\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 4.1hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 4.1hhi}", 100);
	printf("\nret : %d\n", k);

	ft_printf("CAS 7\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 1.2hhi}", 92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 1.2hhi}", 92);
	printf("\nret : %d\n", k);

	ft_printf("CAS 6\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 2.4hhi}", 92);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 2.4hhi}", 92);
	printf("\nret : %d\n", k);

	ft_printf("CAS 5\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 2.2hhi}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 2.2hhi}", 1);
	printf("\nret : %d\n", k);
	
	ft_printf("CAS 4\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 2.2hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 2.2hhi}", 100);
	printf("\nret : %d\n", k);

	ft_printf("CAS 2\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 4.1hhi}", 9);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 4.1hhi}", 9);
	printf("\nret : %d\n", k);

	ft_printf("CAS 1\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{% 3.3hhi}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{% 3.3hhi}", 100);
	printf("\nret : %d\n", k);


	ft_printf("CAS UBH1\n");
	ft_printf("ft_printf : %%#0 33.1..d : ");
	k =   ft_printf("{%0 33.1d}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%#0 33.1..d : ");
	k =   printf("{%0 33.1d}", 100);
	printf("\nret : %d\n", k);

	ft_printf("CAS UBH1\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{%#0 33..1d}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{%#0 33..1d}", 100);
	printf("\nret : %d\n", k);


	ft_printf("CAS UBH1\n");
	ft_printf("ft_printf : %%.2hhi, 92 : ");
	k =   ft_printf("{%-0 33.12.d}", 100);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%.2hhi, 92 : ");
	k =   printf("{%-0 33.12.d}", 100);
	printf("\nret : %d\n", k);


	ft_printf("ft_printf : 42%% -2zi42, 0 : ");
	k = ft_printf("{42% -5zi42}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : 42%% -2zi42, 0 : ");
	k = printf("{42% -5zi42}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% 2hhi, -1595175326 : ");
	k = ft_printf("{% 2hhi}", -1595175326);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 2hhi, -1595175326 : ");
	k = printf("{% 2hhi}", -1595175326);
	printf("\nret : %d\n", k);



	ft_printf("ft_printf : %% 2hhi, -1595175326 : ");
	k = ft_printf("{%- 33.12#+d}", 256);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 2hhi, -1595175326 : ");
	k = printf("{%- 33.12#+d}", 256);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% 2hhi, -1595175326 : ");
	k = ft_printf("{%- 33d}", 256);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 2hhi, -1595175326 : ");
	k = printf("{%- 33d}", 256);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% 2hhi, -1595175326 : ");
	k = ft_printf("{%- 33d}", -256);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% 2hhi, -1595175326 : ");
	k = printf("{%- 33d}", -256);
	printf("\nret : %d\n", k);
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{% -4.2zi}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{% -4.2zi}", 0);
	printf("\nret : %d\n", k);
	
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#.0x}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#.0x}", 0);
	printf("\nret : %d\n", k);
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#.x }", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#.x }", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#.x %#.0x}", 0, 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#.x %#.0x}", 0, 0);
	printf("\nret : %d\n", k);
	//%#.x %#.0x}", 0, 0

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%# 9.2i}", 936655296);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%# 9.2i}", 936655296);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#0o}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#0o}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{% 2i}", -550081044);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{% 2i}", -550081044);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%52.2i}", 85257866);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%52.2i}", 85257866);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%52.2i}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%52.2i}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%.2i}", 129518426);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%.2i}", 129518426);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%.2i}", 2017630899);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%.2i}", 2017630899);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%5.zd}", 1183550320);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%5.zd}", 1183550320);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%05ho}", -288200916);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%05ho}", -288200916);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#02hho}", -2070287848);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#02hho}", -2070287848);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#02hho}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#02hho}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#02hho}", -1252916177);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#02hho}", -1252916177);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%32.2i", 15425432);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%32.2i", 15425432);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%34.14hhi", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%34.14hhi", 0);
	printf("\nret : %d\n", k);


	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%- 16i}", 1391592226);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%- 16i}", 1391592226);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#32.8hhx}", 1403649820);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#32.8hhx}", 1403649820);
	printf("\nret : %d\n", k);


	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%44.43x}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%44.43x}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%#44.43d, 0 : ");
	k = ft_printf("{%#44.43d}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%#44.43d, 0 : ");
	k = printf("{%#44.43d}", 0);
	printf("\nret : %d\n", k);
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#44.43x}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#44.43x}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#44.43x}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#44.43x}", 1);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#8x}", 42);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#8x}", 42);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%060zx}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%060zx}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2d, 0 : ");
	k = ft_printf("{%0#2d}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2d, 0 : ");
	k = printf("{%0#2d}", 1);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2x, 0 : ");
	k = ft_printf("{%0#2x}", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2x, 0 : ");
	k = printf("{%0#2x}", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2x, 0 : ");
	k = ft_printf("{%0#2x}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2x, 0 : ");
	k = printf("{%0#2x}", 1);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2x, 0 : ");
	k = ft_printf("{%-#2.2x}", 5);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2x, 0 : ");
	k = printf("{%-#2.2x}", 5);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2x, 0 : ");
	k = ft_printf("{%#62.2hhx}", 5);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2x, 0 : ");
	k = printf("{%#62.2hhx}", 5);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%0#2x, 0 : ");
	k = ft_printf("{%#62.4x}", 500);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%0#2x, 0 : ");
	k = printf("{%#62.4x}", 500);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%#44.43x}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%#44.43x}", 1);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{% 44.43d}", 114790132);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{% 44.43d}", 114790132);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%-#.53X}", 1);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%-#.53X}", 1);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%.12s}", NULL);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%.12s}", NULL);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%34.51s}", "(null)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%34.51s}", "(null)");
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%34.51s}", NULL);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%34.51s}", NULL);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%-60ls}", L"(null)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%-60ls}",  L"(null)");
	printf("\nret : %d\n", k);
/*
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("{%28.32ls}", L"(null)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("{%28.32ls}",  L"(null)");
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%28.32ls", L"┬─┬ ノ( ゜-゜ノ)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%28.32ls",  L"┬─┬ ノ( ゜-゜ノ)");
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%20ls", L"こんにちは、私は単体テストです");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%20ls",  L"こんにちは、私は単体テストです");
	printf("\nret : %d\n", k);
	

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%1S", L"こ");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%1S",  L"こ");
	printf("\nret : %d\n", k);
*/
/*
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%#.X%###.1x", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%.X", 0);
	printf("\nret : %d\n", k);
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%lc", 0);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%lc", 0);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("abc%lc", 0xbffe);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("abc%lc", 0xbffe);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%.1s", NULL);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%.1s", NULL);
	printf("\nret : %d\n", k);

	wchar_t		s[4];
	
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	
	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%5S", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%5S", s);
	printf("\nret : %d\n", k);

	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%S", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%S", s);
	printf("\nret : %d\n", k);
	
	s[0] = 'a';
	s[1] = 254;
	s[2] = 'b';
	s[3] = '\0';

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%C", 254);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%C", 254);
	printf("\nret : %d\n", k);
*/
/*
	int k ;
	
	wchar_t s[4];
	s[0] = 'a';
	s[1] = 'a';
	s[2] = 'b';
	s[3] = '\0';

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%S", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%S", s);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%C", L'Ѻ');
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%C", L'Ѻ');
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %% -3zi, 0 : ");
	k = ft_printf("%C", 129);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %% -3zi, 0 : ");
	k = printf("%C", 129);
	printf("\nret : %d\n", k);

/*	setlocale(LC_ALL, "");
	s[0] = 83;
	s[1] = 55296;
	s[2] = 528384;
	s[3] = '\0';

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%S", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%S", s);
	printf("\nret : %d\n", k);
*/
    wchar_t s[4];
    int k;
	/*
	s[0] = 'a';
	s[1] = 254;
	s[2] = 'b';
	s[3] = '\0';

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%S", s);
	printf("\nret : %d\n", k);




    ft_printf("   printf : %%S, s : ");
//	k = printf("%S", s);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%20.ld et %.4hhi !", 0x11ffaa147, -8);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%20.ld et %.4hhi !", 0x11ffaa147, -8);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("titi % +---12.5% et%%%0004% et %+1%");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("titi % +---12.5% et%%%0004% et %+1%");
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("Coucou %.0s%sabc%---12s", "hi", "coco", NULL);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("Coucou %.0s%sabc%---12s", "hi", "coco", NULL);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%lc titi", 256);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%lc titi", 256);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%lc", 256);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%lc", 256);
	printf("\nret : %d\n", k);

	//setlocale(LC_ALL, "");
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%lc", 200);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%lc", 200);
	printf("\nret : %d\n", k);

*/
	//setlocale(LC_ALL, "");

/*	s[0] = 'a';
	s[1] = 'u';
	s[2] = 256;
	s[3] = '\0';
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%.1ls", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%.1ls", s);
	printf("\nret : %d\n", k);
*/
	/*
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%-62.3ls", L"(null)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%-62.3ls", L"(null)");
	printf("\nret : %d\n", k);

	ft_printf("   printf : %%S, s : ");
	k = printf("42%35.54ls42", L"(null)");
	printf("\nret : %d\n", k);
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("42%35.54ls42", L"(null)");
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%2lc", 248);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%2lc", 248);
	printf("\nret : %d\n", k);


	//setlocale(LC_ALL, "");

	s[0] = 'a';
	s[1] = 254;
	s[2] = 'b';
	s[3] = '\0';
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%3ls", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%3ls", s);
	printf("\nret : %d\n", k);

	s[0] = 254;
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';
	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("%ls", s);
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("%ls", s);
	printf("\nret : %d\n", k);

	ft_printf("ft_printf : %%S, s : ");
	k = ft_printf("^.^/%s^.^/", "(null)");
	printf("\nret : %d\n", k);
	ft_printf("   printf : %%S, s : ");
	k = printf("^.^/%s^.^/", "(null)");
	printf("\nret : %d\n", k);
	
//	ft_printf("%lld", LLONG_MAX);
//	printf("%lld", LLONG_MAX);
	
	ft_printf("%.d, %.0d", 0, 0);
	printf("\n");
//	printf("%.d, %.0d", 0, 0);
	
//	ft_printf("{%*d}", -5, 42);
//	printf("\n");
//	printf("{%*d}", -5, 42);

	ft_printf("{%.5d}", 5, 42);
	printf("\n");
	printf("{%.5d}", 5, 42);

	printf("\n");
	
	ft_printf("{%.*d}", -5, 42);
	printf("\n");
	printf("{%.*d}", -5, 42);

	printf("\n");

	ft_printf("{%.*s}", 0, "42");
	printf("\n");
	printf("{%.*s}", 0, "42");

	printf("\n");
	
/*

//	printf("\n");
//	my_putnbr_double(5.610);
//	printf("%zu, %llu\n", sizeof(unsigned long long), ULLONG_MAX);
	printf("ULLONG MAX : %llu\n", ULLONG_MAX);
	printf("%D\n", MAX_INPUT);
	printf("%a\n", FLT_MAX);
	printf("Taille d'un float : %zu\n", sizeof(float));
	printf("Taille d'un double : %zu\n", sizeof(double));
	printf("Taille d'un long double : %zu\n", sizeof(long double));
	printf("Taille d'un intmax_t : %zu\n", sizeof(intmax_t));
	printf("Valeur maximum pour un float : %f\n", FLT_MAX);
	printf("Valeur maximum pour un double : %f\n", DBL_MAX);
	printf("Valeur maximum pour un long double : %Lf\n", LDBL_MAX);
	
//	printf("%f", FLT_MAX);
	printf("%a\n", 726.123456);
	printf("%a\n", 123.123);
	printf("1.123456 : %a\n", 1.123456);
	printf("2.0 : %a\n", 2.0);
	printf("3.0 : %a\n", 3.0);
	printf("3.5 : %a\n", 3.5);
	printf("%a\n", 4.0);
	printf("%a\n", 5.0);
	printf("%a\n", 9.0);
	printf("%a\n", 10.0);
	printf("%a\n", 100.0);
	printf("%a\n", 0.0);

	printf("2.0 : %f\n", 2.0);
	printf("3.0 : %f\n", 3.0);
	printf("3.5 : %f\n", 3.5);
	printf("%f\n", 4.0);
	printf("%f\n", 5.0);
	printf("%f\n", 9.0);
	printf("%f\n", 10.0);
	printf("%#0-10.18f\n", 100.0);
	printf("%f\n", 0);
	
	my_putnbr_double(123.4);
	
*/
	/*
	short b;
	printf("%%n : ");
	printf("abcd%hn\n", &b);
	printf("%d\n", b);
	
	//pourcent_n("12345678\n", &b);
	//printf("%d\n", b);
	ft_printf("abcdef%n\n", &b);
	printf("%d\n", b);
	
	printf("%2$d%d\n", 1, 5, 20);

	/*printf("\033[0;31m"); 
	write(1, "\033[32mnocolor", 7);
	printf("abc\n");
	write(1, "color?", 6);
	printf("Hello\n");
	printf("%d\n", 5);
	printf("\033[0m");
	printf("ABC");*/
//	k = ft_printf("%d\033[0;31m", 3);
//	printf("k : %d\n", k);
	
//	k = printf("%d\033[0;31m", 3);
//	printf("k : %d", k);
	/*
	ft_printf("nocolor {red}red{eof} nocoloragain\n");
	ft_printf("nocolor {boldred}boldred{eof} nocoloragain\n");
	ft_printf("nocolor {green}green{eof} nocoloragain\n");
	ft_printf("nocolor {boldgreen}boldgreen{eof} nocoloragain\n");
	ft_printf("nocolor {yellow}yellow{eof} nocoloragain\n");
	ft_printf("nocolor {boldyellow}boldyellow{eof} nocoloragain\n");
	ft_printf("nocolor {blue}blue{eof} nocoloragain\n");
	ft_printf("nocolor {boldblue}boldblue{eof} nocoloragain\n");
	ft_printf("nocolor {magenta}magenta{eof} nocoloragain\n");
	ft_printf("nocolor {boldmagenta}boldmagenta{eof} nocoloragain\n");
	ft_printf("nocolor {cyan}cyan{eof} nocoloragain\n");
	ft_printf("nocolor {boldcyan}boldcyan{eof} nocoloragain\n");

//	printf("%zu\n", sizeof(intmax_t));
//	printf("nocolor \033[0;31mcyan\033[0m nocolor");
	
//	write(1, "nocolor \033[0;31mcyan\033[0m nocolor", 31);
//	printf("%li\n", INTMAX_MIN);
	k =ft_printf("%.2b\n", 0);
	printf("k = %d\n", k);
	k =ft_printf("INTMAX_MIN : %b\n", INTMAX_MIN);
	printf("k = %d\n", k);
	k =ft_printf("INTMAX_MAX : %b\n", INTMAX_MAX);
	printf("k = %d\n", k);
	k = printf("%+.2x\n", 0);
	
//	ft_printf("%c", 'b');

	//printf("\n-11011001011001000111011011");

//	printf("color ?");

	
	k = printf("DOUBLE_MAX : %lf\n", DBL_MAX);
	printf("k = %d\n", k);
	
	ft_printf("{%s}\n", NULL);
	k = ft_printf("{%S}", NULL);
	printf("%d\n", k);

	k = ft_printf("{%030x}\n", 0xFFFF);
	printf("%d\n", k);

	k = printf("{%030x}\n", 0xFFFF);
	printf("%d\n", k);
	
	//printf("%F", 1444565444646.6465424242242);


	printf("\n%.50f\n",  17976931348623.17);
	printf("\n%.50d\n",  17976931348623);
	printf("\n%e\n",  17976931348623.6465424242242);
	printf("%e\n",  17976931348623.6465424242242);
	printf("\n%g\n",  159123.6465424242242);
	printf("%G\n",  159123.6465424242242);
	printf("\n%g\n",  1591234.6465424242242);
	printf("%G\n",  1591234.6465424242242);

	printf("%d\n", k);

	
	double test;
	
	test = 1/7;
	printf("%f\n", 45.0);

	printf("%.0f\n", 45.0);

	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%20.14f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%20.14f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%20.2f\n", 45.123456);
	printf("k = %d\n", k);
//	k = ft_printf("%20.2f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%1.1f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%1.1f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%1.3f\n", 45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%1.3f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%14.20f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%14.20f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%1.20f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%1.20f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%.14f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%.14f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%14f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%14f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%.0f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%.0f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%0f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%0f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%0.0f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%0.0f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	k = printf("%5.0f\n", 45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%5.0f\n", 45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	k = printf("%4.0f\n", 456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%4.0f\n", 456.123456);
	printf("k = %d\n", k);

	ft_printf("{red}AVEC SIGNE -{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%20.14f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%20.14f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%20.2f\n", -45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%20.2f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%1.1f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%1.1f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%1.3f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%1.3f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%14.20f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%14.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%1.20f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%1.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%.14f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%.14f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%14f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%14f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%0.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%0.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%5.0f{eof}\n");
	k = printf("%5.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%5.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%4.0f{eof}\n");
	k = printf("%4.0f\n", -456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%4.0f\n", -456.123456);
	printf("k = %d\n", k);

	ft_printf("{red}AVEC SIGNE +{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%+20.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+20.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%+20.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%+20.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%+1.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+1.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%+1.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+1.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%+14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%+1.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+1.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%+.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%+14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%+f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%+.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%+0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%+0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%+5.0f{eof}\n");
	k = printf("%+5.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+5.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%+4.0f{eof}\n");
	k = printf("%+4.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%+4.0f\n", +456.123456);
	printf("k = %d\n", k);

	ft_printf("{red}AVEC PADDING PAR LA DROITE {eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%-20.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-20.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%-20.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-20.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%-1.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-1.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%-1.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-1.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%-1.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-1.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%-.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%-14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%-f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%-.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%-0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-5.0f{eof}\n");
	k = printf("%-5.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-5.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-4.0f{eof}\n");
	k = printf("%-4.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-4.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{cyan}%.f{eof}\n", 45.0);
	ft_printf("{cyan}%f{eof}\n", 17976931348623.123456);
	printf("%f\n", 17976931348623.123456);

	ft_printf("{red}AVEC FLAG ' '{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("% 20.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 20.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("% 20.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("% 20.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("% 1.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 1.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("% 1.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 1.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("% 4.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 4.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("% 1.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 1.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("% .14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% .14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("% 14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("% f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("% .0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% .0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("% 0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("% 0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 5.0f{eof}\n");
	k = printf("% 5.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 5.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 4.0f{eof}\n");
	k = printf("% 4.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 4.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14.8f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("% 14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 14.8f\n", +45.123456);
	printf("k = %d\n", k);

	ft_printf("{red}AVEC FLAG ' ' et '-'{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("% -20.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -20.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("% -20.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("% -20.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("% -1.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -1.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("% -1.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -1.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("% -4.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -4.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("% -1.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -1.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("% -.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("% -14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("% -f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("% -.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("% -0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("% -0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% -5.0f{eof}\n");
	k = printf("% -5.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -5.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% -4.0f{eof}\n");
	k = printf("% -4.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -4.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% -14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14.8f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("% -14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% -14.8f\n", +45.123456);
	printf("k = %d\n", k);

	
	ft_printf("{red}AVEC FLAG ' ' et '0'{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("% 020.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 020.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("% 020.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("% 020.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("% 01.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 01.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("% 01.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 01.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("% 04.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 04.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("% 01.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 01.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("% 0.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("% 014f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 014f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("% 0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("% 0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("% 00f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 00f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("% 00.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 00.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 05.0f{eof}\n");
	k = printf("% 05.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 05.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 04.0f{eof}\n");
	k = printf("% 04.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 04.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 014.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("% 014.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 014.8f\n", +45.123456);
	printf("k = %d\n", k);

	
	ft_printf("{red}AVEC FLAG ' ' et '-' et '0'{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("% 0-20.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-20.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("% 0-20.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("% 0-20.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("% 0-1.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-1.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("% 0-1.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-1.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("% 0-4.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-4.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("% 0-1.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-1.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("% 0-.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("% 0-14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("% 0-f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("% 0-.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("% 0-0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("% 0-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 0-5.0f{eof}\n");
	k = printf("% 0-5.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-5.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%% 0-4.0f{eof}\n");
	k = printf("% 0-4.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-4.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 0-14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14.8f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("% 0-14.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("% 0-14.8f\n", +45.123456);
	printf("k = %d\n", k);
	 
	ft_printf("{red}AVEC FLAG '-' et '0'{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%-020.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-020.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%-020.2f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-020.2f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%-01.1f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.1f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%-01.3f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.3f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("%-04.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-04.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%-01.20f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%-0.14f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0.14f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%-014f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%-0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%-00f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-00f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%-00.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-00.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-05.0f{eof}\n");
	k = printf("%-05.0f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-05.0f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-04.0f{eof}\n");
	k = printf("%-04.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-04.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{cyan}%%#-04.0f{eof}\n");
	k = printf("%#-04.0f\n", +456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%#-04.0f\n", +456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.20f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-014.20f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.50f\n", +45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-014.50f\n", +45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("%-014.8f\n", +45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014.8f\n", +45.123456);
	printf("k = %d\n", k);

	ft_printf("{red}AVEC FLAG '-' et '0'{eof}\n");
	ft_printf("{red}Champs > Precision > Len_arg : {eof}\n");
	k = printf("%-020.14f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-020.14f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Len_arg > Precision : {eof}\n");
	k = printf("%-020.2f\n", -45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-020.2f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Champs > Precision : {eof}\n");
	k = printf("%-01.1f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.1f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Len_arg > Precision > Champs : {eof}\n");
	k = printf("%-01.3f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.3f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.20f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs = intpart: {eof}\n");
	k = printf("%-04.20f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-04.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Len_arg > Champs: {eof}\n");
	k = printf("%-01.20f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-01.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision seulement : {eof}\n");
	k = printf("%-0.14f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0.14f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs seulement : {eof}\n");
	k = printf("%-014f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Ni champs ni precision : {eof}\n");
	k = printf("%-0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision = 0 : {eof}\n");
	k = printf("%-0.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-0.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 : {eof}\n");
	k = printf("%-00f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-00f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs = 0 et Precision = 0 : {eof}\n");
	k = printf("%-00.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-00.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-05.0f{eof}\n");
	k = printf("%-05.0f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-05.0f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs < len_arg et Precision = 0 : {eof}\n");
	ft_printf("{cyan}%%-04.0f{eof}\n");
	k = printf("%-04.0f\n", -456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-04.0f\n", -456.123456);
	printf("k = %d\n", k);
	ft_printf("{cyan}%%#-04.0f{eof}\n");
	k = printf("%#-04.0f\n", -456.123456);
	printf("k = %d\n", k);
	k =ft_printf("%#-04.0f\n", -456.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.20f\n", -45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-014.20f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Precision > Champs > Len_arg: {eof}\n");
	k = printf("%-014.50f\n", -45.123456);
	printf("k = %d\n", k);
	k = ft_printf("%-014.50f\n", -45.123456);
	printf("k = %d\n", k);
	ft_printf("{red}Champs > Precision > Len_arg: {eof}\n");
	k = printf("%-014.8f\n", -45.123456);
	printf("k = %d\n", k);
	k =ft_printf("%-014.8f\n", -45.123456);
	printf("k = %d\n", k);

	setlocale(LC_ALL, "");

	k = printf("[%-36.2ls]\n", L"(null)");
	//printf("k = %d\n", k);
	ft_printf("[%-36.2ls]\n", L"(null)");
	//printf("k = %d\n", k);

	k = printf("[%36.20lf]\n", 0,000000);
	//printf("k = %d\n", k);
	ft_printf("[%36.20lf]\n", 0,000000);

	k = printf("%-014.8hX\n", +45256);
	printf("k = %d\n", k);
	k =ft_printf("%-014.8b\n", +45256);
	printf("k = %d\n\n", k);
	
	//printf("k = %d\n", k);
	k = printf("%o\n", 40);
	printf("k = %d\n", k);
	k =ft_printf("%o\n", 40);
	printf("k = %d\n", k);

	k =printf("%S", L"Á±≥");
	printf("k = %d\n", k);
	k = ft_printf("%S", L"Á±≥");
	printf("k = %d\n", k);

	printf("\n%%C, 0x11ffff\n");

    k =printf("%C\n", 0x11ffff);
    printf("k = %d\n", k);
    k = ft_printf("%C\n", 0x11ffff);
    printf("k = %d\n", k);

	setlocale(LC_ALL, "");

	k =printf("%hhS\n", L"Á±≥k");
	printf("k = %d\n", k);
	k = ft_printf("%hhS\n", L"Á±≥k");
	printf("k = %d\n", k);
	//tester .0
	//					  12345678912345 1926570851355791
	//					  22222222222222 8538157651200891

	//	ft_printf("%lli \n", -9223372036854775807);

	k =printf("%s\n", "abc");
	printf("k = %d\n", k);
	k = ft_printf("%s\n", "abc");
	printf("k = %d\n", k);

	k = printf("%ji\n", -9223372036854775808);
	printf("k = %d\n", k);

	k = ft_printf("%jb%jb\n", 9223372036854775807, -9223372036854775808);
	printf("k = %d\n", k);

	k =printf("%+10.5d", 4242);
	printf("k = %d\n", k);
	k = ft_printf("%+10.5d", 4242);
	printf("k = %d\n", k);


	k =printf("%.2x", 5427);
	printf("k = %d\n", k);
	k = ft_printf("%.2x", 5427);
	printf("k = %d\n", k);

    k =printf("42%47S42", L"(null)");
    printf("k = %d\n", k);
    k = ft_printf("42%47S42", L"(null)");
    printf("k = %d\n", k);

*/	//setlocale(LC_ALL, "");

/*    int test;

    test = 123;
    while (test++ <= 255)
    {
        printf("%d : ", test);
        k = printf("%C", test);
        printf("k = %d\n", k);
    }
    */
    //setlocale(LC_ALL, "");
//    printf("MBCURMAX : %d\n", MB_CUR_MAX);

  //  �%

  //  k = printf("%C", 254);
  //      printf("k = %d\n", k);
   // k = ft_printf("%C", 254);
    // printf("k = %d\n", k);
    int *test;
    int b;

    test = &b;

    k = printf("%.3p\n", (void*) 16);
          printf("k = %d\n", k);
    k = ft_printf("%.3p\n", (void*) 16);
          printf("k = %d\n", k);

    ft_printf("|%ld|\n", 18);
    ft_printf("|%ld|\n", -18);
    ft_printf("|%ld|\n", 2387);
    ft_printf("|%ld|\n", -2387);
    ft_printf("|%ld|\n", 2147483647);
    ft_printf("|%ld|\n", -2147483648);
    ft_printf("|%+ld|\n", -18);
    ft_printf("|%+ld|\n", 2387);
    ft_printf("|%+ld|\n", -2387);
    ft_printf("|%+ld|\n", 0);
    ft_printf("|%+ ld|\n", -18);
    ft_printf("|%+ ld|\n", 2387);
    ft_printf("|%+ ld|\n", -2387);
    ft_printf("|%+ ld|\n", 0);
    ft_printf("|%3ld|\n", -18);
    ft_printf("|%3ld|\n", 2387);
    ft_printf("|%3ld|\n", -2387);
    ft_printf("|%3ld|\n", 0);
    ft_printf("|%-3ld|\n", -18);
    ft_printf("|%-3ld|\n", 2387);
    ft_printf("|%-3ld|\n", -2387);
    ft_printf("|%-3ld|\n", 0);
    ft_printf("|%-ld|\n", 2147483647);
    ft_printf("|%-ld|\n", -2147483648);
    ft_printf("|%-15ld|\n", 2147483647);
    ft_printf("|%-15ld|\n", -2147483648);
    ft_printf("|%.3ld|\n", -18);
    ft_printf("|%.3ld|\n", 2387);
    ft_printf("|%.3ld|\n", -2387);
    ft_printf("|%.3ld|\n", 0);
    ft_printf("|%3*ld|\n", 0, 18);
    ft_printf("|%3*ld|\n", 2, 18);
    ft_printf("|%3*ld|\n", 3, 18);
    ft_printf("|%3*ld|\n", 6, 18);
    ft_printf("|%3*ld|\n", 0, -18);
    ft_printf("|%3*ld|\n", 2, -18);
    ft_printf("|%3*ld|\n", 6, -18);
    ft_printf("|%3*ld|\n", 2, 2387);
    ft_printf("|%2*ld|\n", 8, 2387);
    ft_printf("|%ld|\n", 1);
    ft_printf("|%ld|\n", 5);
    ft_printf("|%ld|\n", -5);
    ft_printf("|%.ld|\n", 0);
    ft_printf("|%.ld|\n", 5);
    ft_printf("|%.ld|\n", -5);
    ft_printf("|%.*ld|\n", 0, 5);
    ft_printf("|%.*ld|\n", 0, -5);
    ft_printf("|%.*ld|\n", 5, 0);
    ft_printf("|%.*ld|\n", 5, -5);
    ft_printf("|%.*ld|\n", -5, 0);
    ft_printf("|%.*ld|\n", -5, -5);
    ft_printf("|%2.2ld|\n", 5);
    ft_printf("|%2.1ld|\n", 5);
    ft_printf("|%2.3ld|\n", 5);
    ft_printf("|%3.2ld|\n", 5);
    ft_printf("|%5.0ld|\n", 5);
    ft_printf("|%0.2ld|\n", 5);
    ft_printf("|%3.7ld|\n", 5);
    ft_printf("|%7.3ld|\n", 5);
    ft_printf("|%2.2ld|\n", 0);
    ft_printf("|%2.1ld|\n", 0);
    ft_printf("|%2.3ld|\n", 0);
    ft_printf("|%3.2ld|\n", 0);
    ft_printf("|%5.0d$\n", 0);
    ft_printf("|%0.2ld|\n", 0);
    ft_printf("|%3.7ld|\n", 0);
    ft_printf("|%7.3ld|\n", 0);
    ft_printf("|%2.2ld|\n", -5);
    ft_printf("|%2.1ld|\n", -5);
    ft_printf("|%2.3ld|\n", -5);
    ft_printf("|%3.2ld|\n", -5);
    ft_printf("|%5.0ld|\n", -5);
    ft_printf("|%0.2ld|\n", -5);
    ft_printf("|%3.7ld|\n", -5);
    ft_printf("|%7.3ld|\n", -5);
    ft_printf("|%2.6ld|\n", -346);
    ft_printf("|%7.1ld|\n", -346);
    ft_printf("|%5.3ld|\n", -346);
    ft_printf("|%6.2ld|\n", -346);
    ft_printf("|%8.0ld|\n", -346);
    ft_printf("|%0.8ld|\n", -346);
    ft_printf("|%3.7ld|\n", -346);
    ft_printf("|%7.3ld|\n", -346);
    ft_printf("|%2.6ld|\n", 346);
    ft_printf("|%7.1ld|\n", 346);
    ft_printf("|%5.3ld|\n", 346);
    ft_printf("|%6.2ld|\n", 346);
    ft_printf("|%8.0ld|\n", 346);
    ft_printf("|%0.8ld|\n", 346);
    ft_printf("|%3.7ld|\n", 346);
    ft_printf("|%7.3ld|\n", 346);
    ft_printf("|%*d$\n", 6, -2356);
    ft_printf("|% *d$\n", 7, -3455);
    ft_printf("|%*d$\n", 0, 3455);
    ft_printf("|%*d$\n", -1, 3455);
    ft_printf("|%*d$\n", -10, 3455);
    ft_printf("|%06ld|\n", -2356);
    ft_printf("|% 6ld|\n", -3455);
    ft_printf("|%-6ld|\n", -3455);
    ft_printf("|%-+6ld|\n", -455);
    ft_printf("|%-+6ld|\n", 455);
    ft_printf("|%- 6d$\n", 455);
    ft_printf("|% -6d$\n", -455);
    ft_printf("|%*ld|\n", 0, 0);
    ft_printf("|%*ld|\n", 1, 10);
    ft_printf("|%*ld|\n", 10, 0);
    ft_printf("|%*ld|\n", 10, 10);
    ft_printf("|%*ld|\n", -10, 10);
    ft_printf("|%03*ld|\n", 0, 0);
    ft_printf("|%03*ld|\n", 1, 10);
    ft_printf("|%03*ld|\n", 10, 0);
    ft_printf("|%03*ld|\n", 10, 10);
    ft_printf("|%03*ld|\n", -10, 10);
    ft_printf("|%ld|\n", -18);
    ft_printf("|%ld|\n", -2387);
    ft_printf("|%+03ld|\n", 1);
    ft_printf("|% 03ld|\n", 1);
    ft_printf("|% 03ld|\n", 1);
    ft_printf("|%0-10ld|\n", 10);
    ft_printf("|% ld|\n", -18);
    ft_printf("|% ld|\n", 2387);
    ft_printf("|% ld|\n", -2387);
    ft_printf("|% ld|\n", 2147483647);
    ft_printf("|%03*ld|\n", 0, 0);
    ft_printf("|%03*ld|\n", 1, 8);
    ft_printf("|%03*ld|\n", 10, 0);
    ft_printf("|%03*ld|\n", 10, 8);
    ft_printf("|%03*ld|\n", -10, 8);
    ft_printf("|%03*ld|\n", 0, 'a');
    ft_printf("|%03*ld|\n", 1, 'a');
    ft_printf("|%03*ld|\n", 10, 'a');
    ft_printf("|%03*ld|\n", 10, 'a');
    ft_printf("|%03*ld|\n", -10, 'a');
    ft_printf("|%03*.ld|\n", 0, 8888);
    ft_printf("|%03*.ld|\n", 1, 8888);
    ft_printf("|%03*.ld|\n", 4, 8888);
    ft_printf("|%03*.ld|\n", 5, 8888);
    ft_printf("|%03*.ld|\n", 10, 8888);
    ft_printf("|%03*.ld|\n", 0, 8888);
    ft_printf("|%03*.ld|\n", -1, 8888);
    ft_printf("|%03*.ld|\n", -4, 8888);
    ft_printf("|%03*.ld|\n", -5, 8888);
    ft_printf("|%03*.ld|\n", -10, 8888);
    ft_printf("|%03ld|\n", 0);
    ft_printf("|%03ld|\n", 1);
    ft_printf("|%03ld|\n", 4);
    ft_printf("|%03ld|\n", 0);
    ft_printf("|%03ld|\n", 1);
    ft_printf("|%03ld|\n", 4);
    ft_printf("|%03ld|\n", -1);
    ft_printf("|%03ld|\n", -4);
    ft_printf("|%03.ld|\n", 0);
    ft_printf("|%03.ld|\n", 1);
    ft_printf("|%03.ld|\n", 4);
    ft_printf("|%03.ld|\n", 0);
    ft_printf("|%03.ld|\n", 1);
    ft_printf("|%03.ld|\n", 4);
    ft_printf("|%03.ld|\n", -1);
    ft_printf("|%03.ld|\n", -4);
    ft_printf("|%03.4ld|\n", 0);
    ft_printf("|%03.4ld|\n", 4);
    ft_printf("|%03.4ld|\n", 100);
    ft_printf("|%03.4ld|\n", 1000);
    ft_printf("|%03.4ld|\n", -4);
    ft_printf("|%03.4ld|\n", -100);
    ft_printf("|%03.4ld|\n", -1000);
    ft_printf("|%03*.3ld|\n", 0, 0);
    ft_printf("|%03*.3ld|\n", 0, 10);
    ft_printf("|%03*.3ld|\n", 0, 100);
    ft_printf("|%03*.3ld|\n", 1, 0);
    ft_printf("|%03*.3ld|\n", 1, 10);
    ft_printf("|%03*.3ld|\n", 1, 100);
    ft_printf("|%03*.3ld|\n", 3, 0);
    ft_printf("|%03*.3ld|\n", 3, 10);
    ft_printf("|%03*.3ld|\n", 3, 100);
    ft_printf("|%03*.3ld|\n", 5, 0);
    ft_printf("|%03*.3ld|\n", 5, 10);
    ft_printf("|%03*.3ld|\n", 5, 100);
    ft_printf("|%+03*.ld|\n", 84, 84);
    ft_printf("|%+03*.ld|\n", 8, 84);
    ft_printf("|%+03*.ld|\n", -8, 84);
    ft_printf("|%+03*.ld|\n", -8, -84);


    int n;

   // printf("LALALALALAL\n%n", &n);
    //printf("%d\n", n);
    ft_printf("LALALALALAL\n%n", &n);
    ft_printf("%d\n", n);
    return (0);
}
//9223372036854775807
//[(null)                  ]
//[(null)                  ]
/*12345599999999
 *123455999999997.34
 * 45.123455999999997
 * 123455999
 * 123455999999997
 * ^.^/%s^.^/" and arg: "(null)"k
expected: [^.^/(null)^.^/]
     got: [(null)^.^/\x00\x00\x81\x51]
 */