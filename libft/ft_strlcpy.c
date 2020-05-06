/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:31:44 by rgilles           #+#    #+#             */
/*   Updated: 2020/02/09 18:31:47 by rgilles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	char	*osrc;
	size_t	nleft;

	osrc = src;
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			if ((*dest++ = *src++) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
