/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:43:00 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/25 16:15:30 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <sys/time.h>

#include "env.h"
#include "map.h"
#include "SDL.h"
#include "game2.h"
#include "hooks.h"
#include "libft.h"
#include "helpers.h"
#include "vector2.h"

t_inter	get_dist(t_env *env, t_vector2 v[])
{
	t_inter			in;
	int				side;

	in.dist = -1;
	while (DIST_WHILE)
	{
		if (v[4].x < v[4].y)
		{
			v[4].x += v[2].x;
			v[1].x += v[3].x;
			side = 0;
		}
		else
		{
			v[4].y += v[2].y;
			v[1].y += v[3].y;
			side = 1;
		}
		if (TEST_TOUCH)
			in.dist = fabs(SET_DIST);
	}
	in.tx = (int)v[1].x;
	in.ty = (int)v[1].y;
	return (in);
}

void	render_column(int col, t_env *env)
{
	t_inter			in;
	t_vector2		v[5];
	int				i;
	float			angle;
	float			cdist;

	angle = ((col / (float)env->width) * 60. - 30.) * M_PI / 180.;
	set_up_v(env, angle, v);
	in = get_dist(env, v);
	set_vector2(&in.pos, SET_INPOS);
	cdist = in.dist * cos(angle);
	in.wall_height = 1 / cdist * env->player.cam_dist * 1.5;
	in.side = ft_isaround(in.pos.x, in.tx + 1, 0.000001) ? 1 : 0;
	in.side += ft_isaround(in.pos.x, in.tx, 0.000001) ? 2 : 0;
	in.side += ft_isaround(in.pos.y, in.ty, 0.000001) ? 4 : 0;
	in.side += ft_isaround(in.pos.y, in.ty + 1, 0.000001) ? 8 : 0;
	i = -1;
	while (++i < env->height)
	{
		if (cdist > 0 && i >= env->height / 2 - in.wall_height
			&& i <= env->height / 2 + in.wall_height)
			render_pixel(&in, col, i, env);
		else
			pixel_put_img(env->img, col, i, env->cf);
	}
}

void	render_screen(t_env *env)
{
	int				x;

	x = -1;
	while (++x < env->width)
	{
		env->cf = 0x2D2D2D;
		render_column(x, env);
	}
}

void	framerate(t_env *env)
{
	struct timeval	current;
	unsigned long	cur_millis;
	int				framerate;
	unsigned int	wait;

	gettimeofday(&current, NULL);
	cur_millis = current.tv_usec / 1000 + current.tv_sec * 1000;
	wait = cur_millis - env->last_millis;
	if (wait < 16 && wait > 0)
		SDL_Delay(16 - wait);
	gettimeofday(&current, NULL);
	cur_millis = current.tv_usec / 1000 + current.tv_sec * 1000;
	env->delta_t = cur_millis - env->last_millis;
	env->last_millis = cur_millis;
	framerate = 1000 / env->delta_t;
	render_number(env->numbersmap, env->img, 0, framerate);
}

void	game_start(t_env *env)
{
	SDL_Event	event;

	env->running = 1;
	while (env->running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				env->keys[event.key.keysym.scancode] = 1;
			else if (event.type == SDL_KEYUP)
				env->keys[event.key.keysym.scancode] = 0;
			else if (event.type == SDL_WINDOWEVENT
				&& event.window.event == SDL_WINDOWEVENT_EXPOSED)
			{
				SDL_BlitSurface(env->img, NULL,
					SDL_GetWindowSurface(env->win), NULL);
				SDL_UpdateWindowSurface(env->win);
			}
		}
		key_test(env);
		render_screen(env);
		framerate(env);
		SDL_BlitSurface(env->img, NULL, SDL_GetWindowSurface(env->win), NULL);
		SDL_UpdateWindowSurface(env->win);
	}
}
