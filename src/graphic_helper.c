/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:40:35 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/25 16:26:18 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "SDL.h"

void	pixel_put_img(SDL_Surface *img, int x, int y, unsigned int color)
{
	*((unsigned int *)(img->pixels + y * img->pitch + x *
		img->format->BytesPerPixel)) = color;
}

void	render_digit(SDL_Surface *numbersmap, SDL_Surface *img, int pos, int n)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	while (++i < numbersmap->w / 10)
	{
		j = -1;
		while (++j < numbersmap->h)
		{
			color = *((unsigned int *)
				(numbersmap->pixels + j * numbersmap->pitch + (i + n *
				numbersmap->w / 10) * numbersmap->format->BytesPerPixel));
			pixel_put_img(img, pos % img->w + i, pos / img->w + j, color);
		}
	}
}

int		nbr_length(int n)
{
	int				length;

	length = n <= 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

void	render_number(SDL_Surface *numbersmap, SDL_Surface *img, int pos, int n)
{
	int				a;
	int				length;

	a = -1;
	length = nbr_length(n);
	while (n)
	{
		a++;
		render_digit(numbersmap, img, pos + ((length - a) * numbersmap->w / 10)
			+ (length - a), n % 10);
		n /= 10;
	}
}
