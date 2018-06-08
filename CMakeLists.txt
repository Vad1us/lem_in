cmake_minimum_required(VERSION 3.9)
project(lemin_C)
set(CMAKE_C_STANDARD 99)
include_directories(${PROJECT_SOURCE_DIR}/libft)
link_directories(${PROJECT_SOURCE_DIR}/libft)

set(SOURCE_FILES ft_valid_room.c ft_links.c ft_myway.c main.c lemin.h lemin2.h ft_initial_room.c ft_depth.c ft_find_path.c
        ft_print_path.c)

add_executable(lemin_C ${SOURCE_FILES})

target_link_libraries(lemin_C ${PROJECT_SOURCE_DIR}/libft/libft.a ${PROJECT_SOURCE_DIR}/libft/libftprintf.a)