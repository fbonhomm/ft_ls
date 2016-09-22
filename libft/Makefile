# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 17:46:33 by fbonhomm          #+#    #+#              #
#    Updated: 2016/03/03 13:47:23 by fbonhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strndup.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strsplit.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstaddend.c \
	  ft_strlen_first_dim.c \
	  ft_strlen_second_dim.c \
	  ft_error.c \
	  get_next_line.c \
	  ft_putstr_color.c \
	  ft_free_array.c \
	  ft_strdup_array.c \
	  ft_put_array.c \
	  ft_split.c \
	  ft_free.c \
	  ft_realloc.c \
	  ft_in_read_line.c \
	  ft_split_mult.c \
	  ft_split_mult_other.c \
	  ft_print_str.c \
	  ft_print_nbr.c \
	  ft_print_err.c \
	  ft_eof.c \
	  ft_strch_eof.c \
	  ft_sleep.c \
	  ft_sort_str.c \
	  ft_sort_str_nocasse.c \
	  ft_strjoin_mult.c \
	  ft_print_str_endl.c \

OBJET = ft_atoi.o \
	ft_bzero.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putendl.o \
	ft_putendl_fd.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putstr.o \
	ft_putstr_fd.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_strdup.o \
	ft_strequ.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlen.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strncat.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnstr.o \
	ft_strndup.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_lstnew.o \
	ft_lstdelone.o \
	ft_lstdel.o \
	ft_lstadd.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstaddend.o \
	ft_strlen_first_dim.o \
	ft_strlen_second_dim.o \
	ft_error.o \
	get_next_line.o \
	ft_putstr_color.o \
	ft_free_array.o \
	ft_strdup_array.o \
	ft_put_array.o \
	ft_split.o \
	ft_free.o \
	ft_realloc.o \
	ft_in_read_line.o \
	ft_split_mult.o \
	ft_split_mult_other.o \
	ft_print_str.o \
	ft_print_nbr.o \
	ft_print_err.o \
	ft_eof.o \
	ft_strch_eof.o \
	ft_sleep.o \
	ft_sort_str.o \
	ft_sort_str_nocasse.o \
	ft_strjoin_mult.o \
	ft_print_str_endl.o \

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) $(HEADERS)
	ar rc $(NAME) $(OBJET)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJET)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
