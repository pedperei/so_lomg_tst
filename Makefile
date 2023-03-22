# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 16:08:07 by abaiao-r          #+#    #+#              #
#    Updated: 2023/03/22 22:35:01 by pedperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	map_check.c  \
		map_check2.c \
		map_check_utils.c \
		free_memory.c \
		map_init.c \
		check_arguments.c \
		
#main.c\

#mlx_init.c \


#OBJS = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g

CC= cc 

RM = rm -rf 



LIBFT_DIR = libft/
LIBFT_INCLUDE = libft

MLX_LIB_DIR = minilibx-linux/
MLX_INCLUDE = -I mlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)
	
$(NAME): $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) bonus
			$(MAKE) -C $(MLX_LIB_DIR)
			$(CC) $(CFLAGS) $(MLX_INCLUDE) $(SRC) libft/libft.a $(MLX_FLAGS) -o $(NAME) -g -fsanitize=address
#-fsanitize=address
clean:	
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_LIB_DIR) clean

fclean:	clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(MAKE) -C $(MLX_LIB_DIR) clean

re: fclean all
				
.PHONY: all clean fclean re bonus run