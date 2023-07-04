# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/07/04 17:20:02 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
DBFLAGS		=	-g -fsanitize=address
LIBFT 		= 	libft/libft.a
SRCDIR		=	src/
SRCFILES	= 	push_swap.c output.c input.c stack.c moves.c sort.c convert.c \
				error_check.c stack_utils.c moves_output.c
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(SRCS)
	@echo "Compiling push_swap.."
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "Done!"

debug:
	make -C libft
	$(CC) $(CFLAGS) $(DBFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@echo "Deleting binaries.."
	@rm -f $(NAME)
	@echo "Binaries deleted!"

re: fclean all

.PHONY: all clean fclean re