/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:09:05 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 18:09:06 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	prnt(t_printf *myptf, unsigned long long nb, char *chst, int nbd, int prl)
{
	int nbtofillfield;

	nbtofillfield = 0;
	if (prl == 1 && myptf->zero && myptf->precision == -1)
		write(1, "-", 1);
	if (myptf->conv == 'p' && myptf->zero && myptf->precision == -1)
		write(1, "0x", 2);
	if (myptf->precision >= 0 && myptf->precision > nbd)
	{
		if (myptf->field_len > (myptf->precision + prl) && !myptf->minus)
			nbtofillfield = complete_field_len(myptf, myptf->precision + prl);
		if (prl == 1 && (!myptf->zero || (myptf->zero && myptf->precision)))
			write(1, "-", 1);
		if (myptf->conv == 'p' && (!myptf->zero || (myptf->zero && myptf->precision)))
			write(1, "0x", 2);
		while (nbd++ < myptf->precision)
			write(1, "0", 1);
		ft_putnbr_uns_base(nb, chst);
		if (myptf->field_len > (myptf->precision + prl) && myptf->minus)
			nbtofillfield = complete_field_len(myptf, myptf->precision + prl);
		return (myptf->precision + prl + nbtofillfield);
	}
	if (myptf->field_len > (nbd + prl) && !myptf->minus)
		nbtofillfield = complete_field_len(myptf, nbd + prl);
	if (prl == 1 && (!myptf->zero || (myptf->zero && myptf->precision != -1)))
		write(1, "-", 1);
	if (myptf->conv == 'p' && (!myptf->zero || (myptf->zero && myptf->precision != -1)))
		write(1, "0x", 2);
	if (!(nb == 0 && !myptf->precision))
		ft_putnbr_uns_base(nb, chst);
	if (myptf->field_len > (nbd + prl) && myptf->minus)
		nbtofillfield = complete_field_len(myptf, nbd + prl);
	return (nbd + prl + nbtofillfield);
}

int	print_nb_base(t_printf *myprintf, char *charset, int is_signed, int is_l)
{
	unsigned long long int	nb;
	int						prefix_len;
	long long int			temp;
	int						nb_digits;

	prefix_len = 0;
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
		prefix_len = temp < 0 ? 1 : 0;
	}
	else
	{
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
	}
	if (myprintf->conv == 'p')
		prefix_len += 2;
	nb_digits = ft_nbdigits_base(nb, ft_strlen(charset));
	if (nb == 0 && !myprintf->precision)
		nb_digits--;
	return (prnt(myprintf, nb, charset, nb_digits, prefix_len));
}
