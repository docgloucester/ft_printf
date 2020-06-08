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

int	digits_nb(int nb, int base)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int	print_d(t_printf *myprintf, int is_unsigned)
{
	unsigned int	nb;
	int				temp;
	int				nb_digits;
	int 			negat;

	negat = 0;
	if (is_unsigned)
		nb = va_arg(myprintf->args, unsigned int);
	else
	{
		temp = va_arg(myprintf->args, int);
		nb = temp < 0 ? -temp : temp;
		negat = temp < 0 ? 1 : 0;
	}
	nb_digits = digits_nb(nb, 10);
	if (negat == 1)
		write(1, "-", 1);
	if (myprintf->precision >= 0 && myprintf->precision > nb_digits)
	{
		while (nb_digits++ < myprintf->precision)
			write(1, "0", 1);
		ft_putnbr_uns(nb);
		return (negat == 1 ? 1 + myprintf->precision :myprintf->precision);
	}
	ft_putnbr_uns(nb);
	return (nb < 0 ? 1 + nb_digits : nb_digits);
}
