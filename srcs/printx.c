/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:09:05 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 18:09:06 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_x(t_printf *myprintf, char *charset)
{
	unsigned int	nb;
	int				nb_digits;

	nb = va_arg(myprintf->args, unsigned int);
	nb_digits = ft_nbdigits_base(nb, 16);
	if (myprintf->precision >= 0 && myprintf->precision > nb_digits)
	{
		while (nb_digits++ < myprintf->precision)
			write(1, "0", 1);
		ft_putnbr_uns_base(nb, charset);
		return (myprintf->precision);
	}
	ft_putnbr_uns_base(nb, charset);
	return (nb_digits);
}
