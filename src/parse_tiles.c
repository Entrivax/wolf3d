/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:10:29 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/26 12:01:51 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "map.h"
#include "parse.h"

#include <fcntl.h>
#include <unistd.h>

void	check_tiles2(t_env *env, t_map *map, int x, int y)
{
	if (map->map[x][y].west[0] < 0 || map->map[x][y].west[1] < 0 ||
		map->map[x][y].west[0] > env->texturesmap->w - 64 ||
		map->map[x][y].west[1] > env->texturesmap->h - 64)
	{
		map->map[x][y].west[0] = 64;
		map->map[x][y].west[1] = 0;
		ft_putendl("Warning, texture out of bounds.");
	}
	if (map->map[x][y].east[0] < 0 || map->map[x][y].east[1] < 0 ||
		map->map[x][y].east[0] > env->texturesmap->w - 64 ||
		map->map[x][y].east[1] > env->texturesmap->h - 64)
	{
		map->map[x][y].east[0] = 64;
		map->map[x][y].east[1] = 0;
		ft_putendl("Warning, texture out of bounds.");
	}
	if (map->map[x][y].south[0] < 0 || map->map[x][y].south[1] < 0 ||
		map->map[x][y].south[0] > env->texturesmap->w - 64 ||
		map->map[x][y].south[1] > env->texturesmap->h - 64)
	{
		map->map[x][y].south[0] = 0;
		map->map[x][y].south[1] = 0;
		ft_putendl("Warning, texture out of bounds.");
	}
}

void	check_tiles(t_env *env, t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			if (map->map[x][y].north[0] < 0 || map->map[x][y].north[1] < 0 ||
				map->map[x][y].north[0] > env->texturesmap->w - 64 ||
				map->map[x][y].north[1] > env->texturesmap->h - 64)
			{
				map->map[x][y].north[0] = 0;
				map->map[x][y].north[1] = 0;
				ft_putendl("Warning, texture out of bound.");
			}
			check_tiles2(env, map, x, y);
		}
	}
}

void	set_tiles(t_map *map, int id, char **str)
{
	int		x;
	int		y;

	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			if (map->map[x][y].id != id)
				continue ;
			map->map[x][y].north[0] = (((ft_atoi(str[0]) - 1) % 3) << 7);
			map->map[x][y].north[1] = (((ft_atoi(str[0]) - 1) / 3) << 6);
			map->map[x][y].west[0] = (((ft_atoi(str[1]) - 1) % 3) << 7) + 64;
			map->map[x][y].west[1] = (((ft_atoi(str[1]) - 1) / 3) << 6);
			map->map[x][y].east[0] = (((ft_atoi(str[2]) - 1) % 3) << 7) + 64;
			map->map[x][y].east[1] = (((ft_atoi(str[2]) - 1) / 3) << 6);
			map->map[x][y].south[0] = (((ft_atoi(str[3]) - 1) % 3) << 7);
			map->map[x][y].south[1] = (((ft_atoi(str[3]) - 1) / 3) << 6);
		}
	}
}

int		parse_tiles(t_env *env, char *filename, t_map *map)
{
	int		fd;
	int		count;
	char	*line;
	char	**str;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ft_return_int_print("failed to open tiles file\n", -1));
	count = 0;
	while (++count && get_next_line(fd, &line) > 0)
	{
		if (line == NULL || (str = ft_strsplit(line, ' ')) == NULL
			|| split_length(str) != 4)
		{
			--count;
			free_split(str);
			break ;
		}
		if (ft_isnumber(str[0]) && ft_isnumber(str[1]) && ft_isnumber(str[2])
			&& ft_isnumber(str[3]))
			set_tiles(map, count, str);
		free_split(str);
		free(line);
	}
	check_tiles(env, map);
	return (0);
}
