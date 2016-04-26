/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:28:21 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/19 14:58:48 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_reader.h"
#include "helpers.h"
#include "SDL.h"
#include <fcntl.h>
#include <unistd.h>

SDL_Surface	*load_texture(char *filename)
{
	SDL_Surface	*surface;
	int			fd;
	int			size[2];
	int			pixel[2];
	int			color;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if (read_int(fd, &size[0]) <= 0 || read_int(fd, &size[1]) <= 0)
		return (NULL);
	if ((surface = SDL_CreateRGBSurface(0, size[0], size[1], 32, 0, 0, 0, 0))
		== NULL)
		return (NULL);
	pixel[1] = -1;
	while (++pixel[1] < size[1])
	{
		pixel[0] = -1;
		while (++pixel[0] < size[0])
		{
			read_int(fd, &color);
			pixel_put_img(surface, pixel[0], pixel[1], color);
		}
	}
	close(fd);
	return (surface);
}
