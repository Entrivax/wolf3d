/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:17:05 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/21 13:14:01 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			read_int(int fd, int *out)
{
	char			b[4];
	ssize_t			r;

	r = read(fd, b, 4);
	if (out == NULL)
		return (r);
	*out = *((int *)b);
	return (r);
}

int			read_short(int fd, short *out)
{
	char			b[2];
	ssize_t			r;

	r = read(fd, b, 2);
	if (out == NULL)
		return (r);
	*out = *((short *)b);
	return (r);
}

int			read_byte(int fd, unsigned char *out)
{
	char			b[1];
	ssize_t			r;

	r = read(fd, b, 1);
	if (out == NULL)
		return (r);
	if (r <= 0)
		return (r);
	*out = (unsigned char)b[0];
	return (r);
}
