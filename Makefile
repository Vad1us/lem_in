# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vradchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 14:44:48 by vradchen          #+#    #+#              #
#    Updated: 2017/11/15 14:44:49 by vradchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	lem-in

FLAG =	-Wall -Wextra -Werror

SRCS =	main.c ft_data.c ft_depth.c ft_find_path.c ft_gnl.c ft_initial_room.c \
		ft_l.c ft_print_path.c ft_valid_room.c ft_del.c \

OBJ =	main.o ft_data.o ft_depth.o ft_find_path.o ft_gnl.o ft_initial_room.o \
		ft_l.o ft_print_path.o ft_valid_room.o ft_del.o \

all: $(NAME)

$(NAME): 
	@make -C libft/
	gcc $(FLAG) $(SRCS) libft/libft.a libft/printf/libftprintf.a -o $(NAME)

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
