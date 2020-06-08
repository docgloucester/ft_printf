/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:52:47 by rgilles           #+#    #+#             */
/*   Updated: 2020/04/08 19:52:49 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns_base_fd(unsigned int u_n, int fd, char *charset)
{
	unsigned int	base;

	base = ft_strlen(charset);
	if (u_n >= base)
	{
		ft_putnbr_uns_base_fd(u_n / base, fd, charset);
		ft_putchar_fd(charset[u_n % base], fd);
	}
	else
		ft_putchar_fd(charset[u_n], fd);
}
