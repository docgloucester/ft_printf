/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:49:22 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 11:49:24 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_s(t_printf *myprintf)
{
	const char	*str;
	int			len;

	str = va_arg(myprintf->args, const char*);
	len = ft_strlen(str);
	if (myprintf->precision >= 0 && myprintf->precision < len)
	{
		write(1, str, myprintf->precision);
		return (myprintf->precision);
	}
	write(1, str, len);
	return (len);
}
