/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:24:04 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/19 11:24:06 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_c(t_printf *myprintf)
{
	ft_putchar((unsigned char)va_arg(myprintf->args, int));
	return (1);
}