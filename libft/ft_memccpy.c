/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:48:36 by lpilotto          #+#    #+#             */
/*   Updated: 2015/11/30 10:25:10 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*srce;
	unsigned char	*dest;

	i = 0;
	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (i < n)
	{
		dest[i] = srce[i];
		if (dest[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
