/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:27:11 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/06 20:27:14 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_printf
{
	va_list			args;
	unsigned int	i;
	unsigned int	nbwritten;
	char			minus;
	char			zero;
	int				field_len;
	int				precision;
	char			conv;
}					t_printf;

void				init(t_printf *myprintf);
void				get_parsing_params(const char *to_parse, t_printf *myprintf);

int					print_c(t_printf *myprintf);
int					print_s(t_printf *myprintf);
int					print_p(t_printf *myprintf);
int					print_d(t_printf *myprintf);
int					print_u(t_printf *myprintf);
int					print_x(t_printf *myprintf);

int					display(t_printf *myprintf);
int					ft_printf(const char*, ...);

#endif
