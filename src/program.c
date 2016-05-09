/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:55:38 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/09 19:33:01 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "libft.h"
#include "env.h"
#include "SDL.h"
#include "map.h"
#include "game.h"
#include "parse.h"
#include "helpers.h"

int		print_usage(char **argv)
{
	ft_putstr("Usage:\n\t");
	ft_putstr(argv[0]);
	ft_putendl(" <map_file> <tiles_file>");
	return (0);
}

int		init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		return (-1);
	env->img = NULL;
	if ((env->win = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, env->width, env->height, SDL_WINDOW_SHOWN))
		== NULL || (env->img =
		SDL_CreateRGBSurface(0, env->width, env->height, 32, 0, 0, 0, 0))
		== NULL || (env->texturesmap = load_texture("res/texturemap")) == NULL
		|| (env->numbersmap = load_texture("res/numbers")) == NULL)
	{
		if (env->img != NULL && env->texturesmap == NULL)
			ft_putendl("Error during texture map loading.");
		else if (env->numbersmap == NULL)
			ft_putendl("Error during numbers map loading.");
		else
		{
			ft_putstr("error during SDL init : ");
			ft_putendl(SDL_GetError());
		}
		destroy_env(&env);
		SDL_Quit();
		return (-1);
	}
	return (0);
}

t_env	*init_env(int width, int height)
{
	t_env	*env;

	if ((env = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		return (NULL);
	set_vector2(&env->player.pos, -1, -1);
	env->player.speed = 0.1;
	set_vector2(&env->player.dir, 0, -1);
	env->width = width;
	env->height = height;
	env->player.cam_dist = (env->width / 2) * tan(40 * M_PI / 180.);
	env->last_millis = 0;
	return (env);
}

void	destroy_env(t_env **env)
{
	if ((*env)->img != NULL)
		SDL_FreeSurface((*env)->img);
	(*env)->img = NULL;
	if ((*env)->numbersmap != NULL)
		SDL_FreeSurface((*env)->numbersmap);
	(*env)->numbersmap = NULL;
	if ((*env)->map != NULL)
		destroy_map((*env)->map);
	(*env)->map = NULL;
	if ((*env)->texturesmap != NULL)
		SDL_FreeSurface((*env)->texturesmap);
	(*env)->texturesmap = NULL;
	free(*env);
	*env = NULL;
}

int		main(int argc, char **av)
{
	t_env	*env;

	if ((env = init_env(800, 800)) == NULL)
		return (ft_return_int_print("error during env init.\nexiting...\n", 1));
	if (get_files(env, argc, av) == 0)
		return (0);
	if (init_sdl(env) == -1)
		return (ft_return_int_print("exiting...\n", 1));
	if (parse_map(env->mf, env) == -1 ||
		parse_tiles(env, env->tf, env->map) == -1)
	{
		destroy_env(&env);
		return (ft_return_int_print("error during parsing.\nexiting...\n", 1));
	}
	print_infos();
	game_start(env);
	SDL_DestroyWindow(env->win);
	destroy_env(&env);
	SDL_Quit();
	return (0);
}
