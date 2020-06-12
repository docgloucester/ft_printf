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

int	actual_printing(t_printf *myptf, unsigned long long nb, char *chset, int nbd)
{
	if (myptf->precision >= 0 && myptf->precision > nbd)
	{
		while (nbd++ < myptf->precision)
			write(1, "0", 1);
		ft_putnbr_uns_base(nb, chset);
		return (myptf->precision);
	}
	ft_putnbr_uns_base(nb, chset);
	return (nbd);
}

int	print_nb_base(t_printf *myprintf, char *charset, int is_signed, int is_l)
{
	unsigned long long int	nb;
	int						is_neg;
	long long int			temp;
	int						nb_digits;

	is_neg = 0;
	if (is_signed)
	{
		if (is_l == 1)
			temp = va_arg(myprintf->args, long);
		else if (is_l == 2)
			temp = va_arg(myprintf->args, long long);
		else if (is_l == -1)
			temp = (short)va_arg(myprintf->args, int);
		else if (is_l == -2)
			temp = (char)va_arg(myprintf->args, int);
		else
			temp = va_arg(myprintf->args, int);
		nb = temp < 0 ? -temp : temp;
		is_neg = temp < 0 ? 1 : 0;
	}
	else
		if (is_l == 1)
			nb = va_arg(myprintf->args, unsigned long);
		else if (is_l == 2)
			nb = va_arg(myprintf->args, unsigned long long);
		else if (is_l == -1)
			nb = (unsigned short)va_arg(myprintf->args, int);
		else if (is_l == -2)
			nb = (unsigned char)va_arg(myprintf->args, int);
		else
			nb = va_arg(myprintf->args, unsigned int);
	nb_digits = ft_nbdigits_base(nb, ft_strlen(charset));
	write(1, "-", is_neg ? 1 : 0 );
	return (actual_printing(myprintf, nb, charset, nb_digits) + is_neg);
}
