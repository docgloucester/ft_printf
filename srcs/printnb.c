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

int	print_nb_base(t_printf *myprintf, char *charset, int is_signed)
{
	unsigned long long int	nb;
	int						is_neg;
	long long int			temp;
	int						nb_digits;

	is_neg = 0;
	if (is_signed)
	{
		temp = va_arg(myprintf->args, int);
		nb = temp < 0 ? -temp : temp;
		is_neg = temp < 0 ? 1 : 0;
	}
	else
		nb = va_arg(myprintf->args, unsigned int);
	nb_digits = ft_nbdigits_base(nb, ft_strlen(charset));
	write(1, "-", is_neg ? 1 : 0 );
	if (myprintf->precision >= 0 && myprintf->precision > nb_digits)
	{
		while (nb_digits++ < myprintf->precision)
			write(1, "0", 1);
		ft_putnbr_uns_base(nb, charset);
		return (myprintf->precision + is_neg);
	}
	ft_putnbr_uns_base(nb, charset);
	return (nb_digits + is_neg);
}
