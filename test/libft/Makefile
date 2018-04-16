# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 14:37:39 by gmachena          #+#    #+#              #
#    Updated: 2018/03/19 12:56:43 by gmachena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_PATH = ./src/
SRC_NAME = ft_atoi.c \
					ft_uimin.c \
					ft_rgb_add.c \
					fclamp.c \
					ft_uiclamp.c \
					 ft_vectcpy.c \
					 ft_bzero.c \
					 ft_countcwords.c \
					 ft_isalnum.c \
					 ft_isalpha.c \
					 ft_isascii.c \
					 ft_isdigit.c \
					 ft_islower.c \
					 ft_iswp.c \
					 ft_isprint.c\
					 ft_memalloc.c \
					 ft_itoa.c \
					 ft_isupper.c \
					 ft_memccpy.c \
					 ft_memdel.c \
					 ft_memchr.c \
					 ft_toupper.c \
					 ft_tolower.c \
					 ft_strtrim.c \
					 ft_strstr.c\
					 ft_strsub.c \
					 ft_strsplit.c \
					 ft_strrchr.c \
					 ft_strnstr.c \
					 ft_strnew.c\
					 ft_strnequ.c \
					 ft_strncpy.c \
					 ft_strncmp.c \
					 ft_strncat.c \
					 ft_strmapi.c\
					 ft_strmap.c \
					 ft_strlen.c \
					 ft_strlcat.c \
					 ft_strjoin.c \
					 ft_striteri.c \
					 ft_striter.c \
					 ft_strequ.c \
					 ft_strdup.c \
					 ft_strdel.c \
					 ft_strctrim.c\
					 ft_strcpy.c \
					 ft_strcmp.c \
					 ft_strclr.c \
					 ft_strclen.c \
					 ft_strchr.c \
					 ft_strcat.c \
					 ft_putstr_fd.c \
					 ft_putstr.c \
					 ft_putnbr_fd.c \
					 ft_putnbr.c\
					 ft_putendl_fd.c \
					 ft_putendl.c \
					 ft_putchar_fd.c \
					 ft_putchar.c \
					 ft_atof.c \
					 ft_memset.c \
					 ft_memmove.c \
					 ft_memcpy.c \
					 ft_memcmp.c \
					 ft_lstmap.c \
					 ft_lstnew.c \
					 ft_lstiter.c \
					 ft_lstdelone.c \
					 ft_lstdel.c \
					 ft_lstadd.c \
					 ft_strrcpy.c \
					 ft_realloc.c \
					 ft_eq_second.c \
					 ft_normalize.c \
					 ft_vectadd.c \
					 ft_vectsub.c \
					 ft_vrotate.c \
					 ft_coord_v.c \
					 ft_dot.c \
					 ft_vmult.c \
					 get_next_line.c
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	-@ar -r $@ $^ 2> /dev/null || true
	@ranlib $@
	@echo "LIBFT compilée."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	-@rm -fv $(OBJ) 2> /dev/null || true
	-@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	-@rm -fv $(NAME) 2> /dev/null || true

re: fclean all
