/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:07:53 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 18:07:54 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	digits_nb(int nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	print_d(t_printf *myprintf)
{
	int	nb;
	int	nb_digits;
	int negat;

	nb = va_arg(myprintf->args, int);
	nb_digits = digits_nb(nb);
	negat = 0;
	if (myprintf->precision >= 0 && myprintf->precision > nb_digits)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
			negat = 1;
		}
		while (nb_digits++ < myprintf->precision)
			write(1, "0", 1);
		ft_putnbr(nb);
		return (negat == 1 ? 1 + myprintf->precision :myprintf->precision);
	}
	ft_putnbr(nb);
	return (nb < 0 ? 1 + nb_digits : nb_digits);
}
