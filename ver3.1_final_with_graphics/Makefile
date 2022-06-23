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
SRCS	=	main.c	life.c	read.c	play.c	print.c visualizer.c
OBJS	=	$(SRCS:.c=.o)

LIBS = -L /usr/local/lib -lmlx

INCLUDES = -I/usr/local/include

FRAMEWORKS = -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME):
	gcc $(O_FLAGS) $(FLAGS) $(INCLUDES) -c $(addprefix $(SRC), $(SRCS))
	gcc $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORKS)

clean:
	rm -v -f $(OBJS)
	rm -v -f *~

fclean:	clean
	rm -v -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
