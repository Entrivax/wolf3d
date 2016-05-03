/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:54:05 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/28 12:12:22 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "env.h"
#include "libft.h"

void	test_move2(t_env *env, float speed_mult)
{
	float	dx;
	float	dy;

	if (env->keys[SDL_SCANCODE_DOWN])
	{
		dx = env->player.dir.x * env->player.speed * speed_mult;
		if ((int)(env->player.pos.x - dx) > 0
			&& (int)(env->player.pos.x - dx) < env->map->width)
			env->player.pos.x -= env->map->map[(int)(env->player.pos.x - dx)]
				[((int)env->player.pos.y)].id == 0 ? dx : 0;
		dy = env->player.dir.y * env->player.speed * speed_mult;
		if ((int)(env->player.pos.y - dy) > 0
			&& (int)(env->player.pos.y - dy) < env->map->height)
			env->player.pos.y -= env->map->map[((int)env->player.pos.x)]
				[(int)(env->player.pos.y - dy)].id == 0 ? dy : 0;
	}
}

void	test_move(t_env *env)
{
	float	dx;
	float	dy;
	float	speed_mult;

	speed_mult = env->keys[SDL_SCANCODE_LSHIFT] ? 2 : 1;
	if (env->keys[SDL_SCANCODE_UP])
	{
		dx = env->player.dir.x * env->player.speed * speed_mult;
		if ((int)(env->player.pos.x + dx) > 0
			&& (int)(env->player.pos.x + dx) < env->map->width)
			env->player.pos.x += env->map->map[(int)(env->player.pos.x + dx)]
				[((int)env->player.pos.y)].id == 0 ? dx : 0;
		dy = env->player.dir.y * env->player.speed * speed_mult;
		if ((int)(env->player.pos.y + dy) > 0
			&& (int)(env->player.pos.y + dy) < env->map->height)
			env->player.pos.y += env->map->map[((int)env->player.pos.x)]
				[(int)(env->player.pos.y + dy)].id == 0 ? dy : 0;
	}
	test_move2(env, speed_mult);
}

void	key_test(t_env *env)
{
	if (env->keys[SDL_SCANCODE_RIGHT])
		rotate_vector2(&env->player.dir, 2 * M_PI / 180.);
	if (env->keys[SDL_SCANCODE_LEFT])
		rotate_vector2(&env->player.dir, -2 * M_PI / 180.);
	if (env->keys[SDL_SCANCODE_ESCAPE])
		env->running = 0;
	test_move(env);
}
