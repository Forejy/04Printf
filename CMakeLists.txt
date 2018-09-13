cmake_minimum_required(VERSION 3.9)
project(my_printf_clean C)


file(GLOB SOURCES
        "Sources/*.c"
        "Sources/Print_Unicode/*.c"
        "Sources/Auxiliary_Functions/*.c"
        "Sources/Handlers/*.c")

file(GLOB HEADERS
        "Includes/*.h"
        "Includes/Auxiliary_Functions/*.h"
        "Includes/Handlers/*.h"
        "Includes/Print_Unicode/*h")

set(CMAKE_C_STANDARD 90)
add_executable(my_printf_clean ${SOURCES} ${HEADERS} Sources/Auxiliary_Functions/print_final_result_w_padding_and_conversion.c Includes/Auxiliary_Functions/print_final_result_w_padding_and_conversion.h Sources/main.c Sources/Print_Unicode/convert_dec_to_bin_utf16.c Includes/Print_Unicode/convert_dec_to_bin_utf16.h)