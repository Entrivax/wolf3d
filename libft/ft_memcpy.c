/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:44:09 by lpilotto          #+#    #+#             */
/*   Updated: 2015/11/29 10:49:43 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	i = 0;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}
