/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:48:15 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/25 16:25:07 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "env.h"
# include "SDL.h"

void	pixel_put_img(SDL_Surface *img, int x, int y, unsigned int color);
void	render_number(SDL_Surface *numbersmap, SDL_Surface *img, int pos,
						int n);
void	render_digit(SDL_Surface *numbersmap, SDL_Surface *img, int pos, int n);

#endif
