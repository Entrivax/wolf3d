/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:27:30 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/21 16:30:06 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "env.h"
# include "map.h"
# include "SDL.h"

void		free_split(char **split);
int			split_length(char **split);
int			parse_map(char *map_file, t_env *env);
SDL_Surface	*load_texture(char *filename);
int			parse_tiles(t_env *env, char *filename, t_map *map);

#endif
