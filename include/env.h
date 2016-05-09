/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:45:33 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/09 14:58:15 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "SDL.h"
# include "map.h"
# include "vector2.h"

# define SET_INPOS2  in.dist + env->player.pos.y
# define SET_INPOS v[0].x * in.dist + env->player.pos.x, v[0].y * SET_INPOS2

# define DIST_WHILE3 (v[1].y >= 0 && v[1].y < env->map->height)
# define DIST_WHILE2 (v[1].x >= 0 && v[1].x < env->map->width) && DIST_WHILE3
# define DIST_WHILE in.dist == -1 && DIST_WHILE2

# define TEST_TOUCH3 env->map->map[(int)v[1].x][(int)v[1].y].id
# define TEST_TOUCH2 (v[1].y >= 0 && v[1].y < env->map->height) && TEST_TOUCH3
# define TEST_TOUCH (v[1].x >= 0 && v[1].x < env->map->width) && TEST_TOUCH2

# define SD3 (v[1].y - env->player.pos.y + (1 - v[3].y) / 2) / v->y
# define SET_DIST2 (v[1].x - env->player.pos.x + (1 - v[3].x) / 2) / v->x : SD3
# define SET_DIST side == 0 ? SET_DIST2

typedef struct		s_player
{
	t_vector2		pos;
	t_vector2		dir;
	float			cam_dist;
	float			speed;
}					t_player;

typedef struct		s_inter
{
	t_vector2		pos;
	int				tx;
	int				ty;
	float			dist;
	float			wall_height;
	int				side;
}					t_inter;

typedef struct		s_env
{
	SDL_Surface		*img;
	SDL_Surface		*texturesmap;
	SDL_Surface		*numbersmap;
	int				width;
	int				height;
	t_map			*map;
	SDL_Window		*win;
	t_player		player;
	char			running;
	char			keys[285];
	char			*mf;
	char			*tf;
	unsigned int	cf;
	unsigned long	last_millis;
	float			delta_t;
}					t_env;

int					print_usage(char **argv);
void				destroy_env(t_env **env);
int					get_files(t_env *env, int argc, char **av);
void				print_infos(void);

#endif
