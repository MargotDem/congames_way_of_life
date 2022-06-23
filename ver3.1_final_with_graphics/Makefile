# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 16:30:08 by ijaaskel          #+#    #+#              #
#    Updated: 2022/06/23 16:30:17 by ijaaskel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	life

FLAGS	=	-Wall -Wextra -Werror
O_FLAGS	=	-O3

SRC		=	./src/
SRCS	=	main.c	life.c	read.c	play.c	print.c
OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
	gcc $(O_FLAGS) $(FLAGS) -c $(addprefix $(SRC), $(SRCS))
	gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -v -f $(OBJS)
	rm -v -f *~

fclean:	clean
	rm -v -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
