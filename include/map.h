/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 12:40:14 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/20 23:00:08 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_tile
{
	int		id;
	int		north[2];
	int		west[2];
	int		east[2];
	int		south[2];
}					t_tile;

typedef struct		s_map
{
	t_tile	**map;
	int		width;
	int		height;
}					t_map;

t_map				*create_map(int width, int height);
t_map				*destroy_map(t_map *map);

#endif
