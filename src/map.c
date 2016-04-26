/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 13:07:50 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/21 15:24:28 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"
#include "libft.h"

t_map	*destroy_map(t_map *map)
{
	int		i;

	if (map != NULL)
	{
		if (map->map != NULL)
		{
			i = -1;
			while (++i < map->width && map->map[i] != NULL)
				free(map->map[i]);
			free(map->map);
		}
		free(map);
	}
	return (NULL);
}

t_map	*create_map(int width, int height)
{
	t_map	*map;

	if (width <= 3 && height <= 3)
		return (NULL);
	if ((map = (t_map *)ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((map->map = (t_tile **)ft_memalloc(sizeof(t_tile *) * width)) == NULL)
		return (NULL);
	map->width = -1;
	map->height = height;
	while (++map->width < width)
	{
		if ((map->map[map->width] =
			(t_tile *)ft_memalloc(sizeof(t_tile) * height)) == NULL)
			return (destroy_map(map));
	}
	return (map);
}
