/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:40:41 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/02 12:19:07 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "helpers.h"
#include "vector2.h"

#include <math.h>

void	test_other_sides(t_inter *in, int y, int *tex, t_env *env)
{
	if ((in->side & 4) == 4)
	{
		tex[1] = (((y << 1) - env->height + in->wall_height * 2) * 16)
			/ in->wall_height + env->map->map[in->tx][in->ty].north[1];
		tex[0] = ((1 + in->tx - (in->pos.x)) * 64
			+ env->map->map[in->tx][in->ty].north[0]);
	}
	else if ((in->side & 8) == 8)
	{
		tex[1] = (((y << 1) - env->height + in->wall_height * 2) * 16)
			/ in->wall_height + env->map->map[in->tx][in->ty].south[1];
		tex[0] = (-(in->tx * 64 - (in->pos.x * 64))
			+ env->map->map[in->tx][in->ty].south[0]);
	}
}

void	render_pixel(t_inter *in, int x, int y, t_env *env)
{
	int		tex[2];

	env->cf = 0x606060;
	tex[0] = 0;
	tex[1] = 0;
	if ((in->side & 1) == 1)
	{
		tex[1] = (((y << 1) - env->height + in->wall_height * 2) * 16)
			/ in->wall_height + env->map->map[in->tx][in->ty].east[1];
		tex[0] = ((1 + in->ty - (in->pos.y)) * 64
			+ env->map->map[in->tx][in->ty].east[0]);
	}
	else if ((in->side & 2) == 2)
	{
		tex[1] = (((y << 1) - env->height + in->wall_height * 2) * 16)
			/ in->wall_height + env->map->map[in->tx][in->ty].west[1];
		tex[0] = (-(in->ty * 64 - (in->pos.y * 64))
			+ env->map->map[in->tx][in->ty].west[0]);
	}
	else
		test_other_sides(in, y, tex, env);
	pixel_put_img(env->img, x, y, *((unsigned int *)(env->texturesmap->pixels +
		tex[1] * env->texturesmap->pitch + tex[0]
		* env->texturesmap->format->BytesPerPixel)));
}

void	set_up_v(t_env *env, float angle, t_vector2 *v)
{
	set_vector2(v, env->player.dir.x, env->player.dir.y);
	rotate_vector2(v, angle);
	set_vector2(&v[1], floor(env->player.pos.x), floor(env->player.pos.y));
	set_vector2(&v[2], sqrt(1 + (v->y * v->y) / (v->x * v->x)),
			sqrt(1 + (v->x * v->x) / (v->y * v->y)));
	set_vector2(&v[3], v->x < 0 ? -1 : 1, v->y < 0 ? -1 : 1);
	set_vector2(&v[4], v->x < 0 ? (env->player.pos.x - v[1].x) * v[2].x :
			(v[1].x + 1 - env->player.pos.x) * v[2].x, v->y < 0 ?
			(env->player.pos.y - v[1].y) * v[2].y :
			(v[1].y + 1 - env->player.pos.y) * v[2].y);
}

void	render_minimap(t_env *env)
{
	int		x;
	int		y;

	if (env->width < 20 || env->height < 20)
		return ;
	x = -10;
	while (++x < 10)
	{
		y = -10;
		while (++y < 10)
		{
			if (x + (int)env->player.pos.x >= 0
				&& x + (int)env->player.pos.x < env->map->width
				&& y + (int)env->player.pos.y >= 0
				&& y + (int)env->player.pos.y < env->map->height)
			{
				pixel_put_img(env->img, x + env->width - 15, y + 15,
					env->map->map[x + (int)env->player.pos.x][y +
					(int)env->player.pos.y].id != 0 ? 0xFFFFFF : 0);
			}
		}
	}
}
