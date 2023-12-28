# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 22:27:42 by amonier           #+#    #+#              #
#    Updated: 2022/11/28 21:18:46 by amonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c \
ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c \
ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c \

# GNL:

_SRC_GNL = get_next_line_utils.c get_next_line.c

SRC_GNL_DIR = ft_gnl

SRC_GNL = $(addprefix $(SRC_GNL_DIR)/, $(_SRC_GNL))

# FONCTION LST CHAINEES: 

_SRC_LST = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c

SRC_LST_DIR = ft_lst

SRC_LST = $(addprefix $(SRC_LST_DIR)/, $(_SRC_LST))

# FONCTION PRINT:

_SRC_PRINT = ft_print_ptr.c ft_printf.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr.c

SRC_PRINT_DIR = ft_printf

SRC_PRINT = $(addprefix $(SRC_PRINT_DIR)/, $(_SRC_PRINT))

HEADERFILES = Includes/libft.h

CC = gcc

OBJ = $(SRC:.c=.o) $(SRC_PRINT:.c=.o) $(SRC_LST:.c=.o) $(SRC_GNL:.c=.o)

#OBJ_BONUS = $(BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(FLAG) -o $@ $<

#clean:
#	@if [ "$(OS)" = "Windows_NT" ]; then \
#		del $(OBJ) $(OBJ_BONUS); \
#	else \
#		rm -f $(OBJ) $(OBJ_BONUS) \
#	fi

#fclean: clean
#	@if [ "$(OS)" = "Windows_NT" ]; then \
#		del $(NAME); \
#	else \
#		rm -f $(NAME) \
#	fi

clean:
	@if "%OS%" == "Windows_NT" (@del $(OBJ)) else (rm -f $(OBJ))

fclean: clean
	@if "%OS%" == "Windows_NT" (@del $(NAME)) else (rm -f $(NAME))

re: clean fclean all

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS)
#	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJ_BONUS)

.PHONY: clean fclean all re bonus
