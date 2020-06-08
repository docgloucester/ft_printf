/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:46:43 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/09 17:46:45 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	init(t_printf *myprintf)
{
	myprintf->minus = 0;
	myprintf->zero = 0;
	myprintf->field_len = -1;
	myprintf->precision = -1;
	myprintf->conv = 0;
}

void	get_parsing_params(const char *to_parse, t_printf *myprintf)
{
	if (to_parse[myprintf->i] == '-')
		myprintf->minus = to_parse[(myprintf->i)++];
	if (to_parse[myprintf->i] == '0')
		myprintf->zero = to_parse[(myprintf->i)++];
	if (ft_strchr("123456789*", to_parse[myprintf->i]))
	{
		if (to_parse[(myprintf->i)] == '*')
			myprintf->field_len = va_arg(myprintf->args, int);
		else
			myprintf->field_len = ft_atoi(to_parse + myprintf->i);
		while (ft_strchr("123456789*", to_parse[myprintf->i]))
			(myprintf->i)++;
		if (myprintf->field_len < 0)
		{
			myprintf->precision = -(myprintf->precision);
			myprintf->minus = '-';
		}
	}
	if (to_parse[myprintf->i] == '.')
	{
		if (to_parse[++(myprintf->i)] == '*')
			myprintf->precision = va_arg(myprintf->args, int);
		else
			myprintf->precision = ft_atoi(to_parse + myprintf->i);
		while (ft_strchr("0123456789*", to_parse[myprintf->i]))
			(myprintf->i)++;
		if (myprintf->precision < 0)
			myprintf->precision = 0;
	}
	if (ft_strchr("cspdiuxX", to_parse[myprintf->i]))
		myprintf->conv = to_parse[(myprintf->i)++];
}

int		display(t_printf *myprintf)
{
	if (myprintf->conv == 'c')
		return (print_c(myprintf));
	else if (myprintf->conv == 's')
		return (print_s(myprintf));
	else if (myprintf->conv == 'p')
		return (print_p(myprintf));
	else if ((myprintf->conv == 'd') || (myprintf->conv == 'i'))
		return (print_d(myprintf, 0));
	else if (myprintf->conv == 'u')
		return (print_d(myprintf, 1));
	else if (myprintf->conv == 'x')
		return (print_x(myprintf, "0123456789abcdef"));
	else if (myprintf->conv == 'X')
		return (print_x(myprintf, "0123456789ABCDEF"));
	return (0);
}
