# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 15:01:45 by tponnusa          #+#    #+#              #
#    Updated: 2022/12/18 17:34:17 by tponnusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   libftprintf.a
LIBFT_DIR   =   libft
LIBFT 		=	$(LIBFT_DIR)/libft.a
CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror

SRC         =   ft_print_char.c ft_print_str.c ft_print_nbr.c ft_printf.c \
				ft_print_hex.c ft_print_ptr.c ft_print_percent.c ft_print_unsigned.c

OBJ         =   $(SRC:.c=.o)

all         :   $(NAME)

$(NAME)     :   $(LIBFT) $(OBJ)
				cp $(LIBFT) $(NAME)
				ar -rcs $(NAME) $(OBJ)

$(LIBFT)	:	
				make -C $(LIBFT_DIR) all

$(OBJ)      :   $(SRC)
				$(CC) $(CFLAGS) -c $(SRC)

clean       :	
				make clean -C ./libft
				rm -f $(OBJ)

fclean      :   clean
				make fclean -C ./libft
				rm -f $(NAME)

re          :   fclean all

norm        :   
				norminette $(SRC)

.PHONY		:	all clean fclean re