# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 20:33:31 by vkostenk          #+#    #+#              #
#    Updated: 2018/12/05 17:33:01 by vkostenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = *.c
HEADERS = includes/fractol.h
LIBFT = Libft/libft.a
MINILIBX = minilibx_macos/liblmx.a
OBJ=$(SRC:.c=.o)
GREEN = \033[1;32m

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ)
		Make -C Libft
		Make -C minilibx_macos
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

		@echo "$(GREEN)Project successfully compiled"

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make Libft
$(MINILIBX):
		make minilibx_macos


clean :
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C Libft
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re: fclean all
