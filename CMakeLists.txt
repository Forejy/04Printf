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
#set(CMAKE_CPP_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#set(CMAKE_CPP_FLAGS "${CMAKE_C++_FLAGS} -Wall -Wextra -std=c++11")

add_executable(my_printf_clean ${SOURCES} ${HEADERS} Sources/main.c Sources/Auxiliary_Functions/bonus.c Includes/Auxiliary_Functions/bonus.h Sources/Handlers/handle_colors.c Includes/Handlers/handle_colors.h Includes/Handlers/handle_conversions.h Sources/Handlers/handle_conversions_2.c Includes/Handlers/handle_conversions_2.h Sources/Handlers/test_conv_champs_prec.c Includes/Handlers/test_conv_champs_prec.h Sources/Print_Unicode/auxiliary_functions_for_unicode.c Includes/Print_Unicode/auxiliary_functions_for_unicode.h Sources/Print_Unicode/print_wchar_t.c Sources/Auxiliary_Functions/numbers_functions_double.c Includes/Auxiliary_Functions/numbers_functions_double.h Sources/Print_Final_Result/print_and_compute_final_result.c Sources/Print_Final_Result/compute_functions.c Sources/Print_Final_Result/annex_functions.c Includes/Print_Final_Result/annex_functions.h Includes/Print_Final_Result/compute_functions.h Includes/Print_Final_Result/print_and_compute_final_result.h)