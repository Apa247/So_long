# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 12:38:29 by daparici          #+#    #+#              #
#    Updated: 2022/09/12 13:39:55 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = So_long
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -g3
AR = ar rcs

SRCS = main.c check_map_1.c check_map_2.c game.c Exit.c move_goku_ki.c move_goku.c key_select.c \
	move_supergoku.c move_goku_2.c enemies.c enemies_2.c map.c key_select_2.c move_supergoku_2.c
PRINTF = ft_print_adress_hex_nbr.c ft_printf.c
PRINTFPATH = $(addprefix ./printf/,$(PRINTF))
GNL = get_next_line.c get_next_line_utils.c
GNLPATH = $(addprefix ./GetNextLine/,$(GNL))
LIBFT = ./Libft/libft.a

OBJS = ${SRCS:.c=.o}
GNLOBJ = $(GNLPATH:.c=.o)
PRINTFOBJ = $(PRINTFPATH:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(GNLOBJ) $(PRINTFOBJ)
		make bonus -C ./Libft;
#		$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) $(LIBFT) -L ./Libft -l ft -o -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) $(PRINTFOBJ) $(LIBFT) -L mlx -l mlx -framework OpenGL -framework AppKit -o $(NAME)	
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME) 
re: clean all
.PHONY: bonus all clean fclean re
