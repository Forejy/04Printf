NAME = libftprintf.a

SRCS += Sources/Auxiliary_Functions/numbers_functions.c
SRCS += Sources/Auxiliary_Functions/numbers_functions_hexa.c
SRCS += Sources/Auxiliary_Functions/numbers_functions_octal.c
SRCS += Sources/Auxiliary_Functions/numbers_functions_unsigned.c
SRCS += Sources/Auxiliary_Functions/print_final_result_w_padding_and_conversion.c
SRCS += Sources/Auxiliary_Functions/print_pointer_address.c
SRCS += Sources/Auxiliary_Functions/strings_functions.c
SRCS += Sources/Auxiliary_Functions/bonus.c
SRCS += Sources/Handlers/handlers.c
SRCS += Sources/Handlers/handle_colors.c
SRCS += Sources/Print_Unicode/convert_dec_to_bin_utf8.c
SRCS += Sources/Print_Unicode/create_and_print_t_bin_list.c
SRCS += Sources/Print_Unicode/print_unicode.c
SRCS += Sources/errors.c
SRCS += Sources/printf.c

INCLUDES += Includes/Auxiliary_Functions/numbers_functions.h
INCLUDES += Includes/Auxiliary_Functions/numbers_functions_hexa.h
INCLUDES += Includes/Auxiliary_Functions/numbers_functions_octal.h
INCLUDES += Includes/Auxiliary_Functions/numbers_functions_unsigned.h
INCLUDES += Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h
INCLUDES += Includes/Auxiliary_Functions/print_pointer_address.h
INCLUDES += Includes/Auxiliary_Functions/strings_functions.h
INCLUDES += Sources/Auxiliary_Functions/bonus.h
INCLUDES += Includes/Handlers/handlers.h
INCLUDES += Sources/Handlers/handle_colors.h
INCLUDES += Includes/Print_Unicode/convert_dec_to_bin_utf8.h
INCLUDES += Includes/Print_Unicode/create_and_print_t_bin_list.h
INCLUDES += Includes/Print_Unicode/print_unicode.h
INCLUDES += Includes/errors.h
INCLUDES += Includes/printf.h

OBJS += Sources/Auxiliary_Functions/numbers_functions.o
OBJS += Sources/Auxiliary_Functions/numbers_functions_hexa.o
OBJS += Sources/Auxiliary_Functions/numbers_functions_octal.o
OBJS += Sources/Auxiliary_Functions/numbers_functions_unsigned.o
OBJS += Sources/Auxiliary_Functions/print_final_result_w_padding_and_conversion.o
OBJS += Sources/Auxiliary_Functions/print_pointer_address.o
OBJS += Sources/Auxiliary_Functions/strings_functions.o
OBJS += Sources/Auxiliary_Functions/bonus.o
OBJS += Sources/Handlers/handlers.o
OBJS += Sources/Handlers/handle_colors.o
OBJS += Sources/Print_Unicode/convert_dec_to_bin_utf8.o
OBJS += Sources/Print_Unicode/create_and_print_t_bin_list.o
OBJS += Sources/Print_Unicode/print_unicode.o
OBJS += Sources/errors.o
OBJS += Sources/printf.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

objects :
	mkdir objects

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
