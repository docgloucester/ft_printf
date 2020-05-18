/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:16:32 by rgilles           #+#    #+#             */
/*   Updated: 2020/05/18 17:16:34 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	display(t_printf *myprintf)
{
	if (myprintf->conv == 'c')
		return (print_c(myprintf));
	else if (myprintf->conv == 's')
		return (print_s(myprintf));
	else if (myprintf->conv == 'p')
		return (print_p(myprintf));
	else if (myprintf->conv == 'd')
		return (print_d(myprintf));
	else if (myprintf->conv == 'i')
		return (print_i(myprintf));
	else if (myprintf->conv == 'u')
		return (print_u(myprintf));
	else if (myprintf->conv == 'x' || myprintf->conv == 'X')
		return (print_x(myprintf));
}
