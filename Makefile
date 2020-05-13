# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 15:46:44 by rgilles           #+#    #+#              #
#    Updated: 2020/05/02 15:46:46 by rgilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBDIR	=	libft/
LIBFT	=	libft.a
SRCSF	=	ft_printf.c
SRCS_BF	=	
SRCDIR	=	srcs/
INDIR	=	includes/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(SRCDIR),$(SRCSF))
SRCS_B	=	$(addprefix $(SRCDIR),$(SRCS_BF))
OBJS	=	$(SRCS:.c=.o)
OBJS_B	=	$(SRCS_B:.c=.o)

.c.o	:
			$(CC) $(CFLAGS) -I$(LIBDIR) -I$(INDIR) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C $(LIBDIR)
			cp $(LIBDIR)$(LIBFT) $(NAME)
			ar -vrs $(NAME) $(OBJS)

bonus	:	$(NAME) $(OBJS_B)
			ar -vrs $(NAME) $(OBJS_B)

libft	:
			make -C $(LIBDIR)
			cp $(LIBDIR)$(LIBFT) $(LIBFT)

clean	:
			make clean -C $(LIBDIR)
			rm -f $(OBJS) $(OBJS_B) $(LIBFT)

fclean	:	clean
			make fclean -C $(LIBDIR)
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	re clean fclean libft
