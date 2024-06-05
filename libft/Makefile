# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 22:12:47 by cmakario          #+#    #+#              #
#    Updated: 2023/11/08 14:14:15 by cmakario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FUNCTIONS = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memset.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c  \
			ft_substr.c	\
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstlast.c \

BONUS_FUNCTIONS =	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c 
					

OBJ_FILES = $(FUNCTIONS:%.c=%.o)
OBJ_BONUS_FILES = $(BONUS_FUNCTIONS:%.c=%.o)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES) : $(FUNCTIONS)
	$(CC) $(CFLAGS) -c $(FUNCTIONS)

all: $(NAME)

bonus:
	gcc -c -Wall -Wextra -Werror $(BONUS_FUNCTIONS)
	ar rcs $(NAME) $(OBJ_BONUS_FILES)
	
clean: 
	rm -f $(OBJ_FILES) $(OBJ_BONUS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re