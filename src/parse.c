/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:59:25 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/09 12:16:32 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "env.h"
#include "libft.h"
#include "map.h"
#include "parse.h"
#include "helpers.h"

void	check_borders(int line_n, int i, t_env *env)
{
	int id;

	id = env->map->map[i][line_n - 1].id;
	if ((line_n == 1 || line_n == env->map->height || i == 0
		|| i == env->map->width - 1) && (id == 0 || id == -1))
	{
		ft_putstr("Line ");
		ft_putnbr(line_n + 1);
		ft_putendl(": warning, border is not a wall, replacing.");
		env->map->map[i][line_n - 1].id = 1;
	}
}

int		parse_map_line2(int line_n, t_env *env, char **str)
{
	int		i;

	if (split_length(str) != env->map->width || line_n > env->map->height)
	{
		free_split(str);
		return (-1);
	}
	i = -1;
	while (str[++i])
	{
		if (!ft_isnumber(str[i]))
		{
			free_split(str);
			return (-1);
		}
		env->map->map[i][line_n - 1].id = ft_atoi(str[i]);
		check_borders(line_n, i, env);
		if (env->map->map[i][line_n - 1].id == -1)
		{
			set_vector2(&env->player.pos, i + 0.5, line_n - 0.5);
			env->map->map[i][line_n - 1].id = 0;
		}
	}
	free_split(str);
	return (0);
}

int		parse_map_line(int line_n, char *line, t_env *env)
{
	char	**str;
	int		a;

	str = ft_strsplit(line, ' ');
	a = -1;
	if (line_n == 0)
	{
		if (split_length(str) == 2
			&& ft_isnumber(str[0]) && ft_isnumber(str[1]))
		{
			if ((env->map = create_map(ft_atoi(str[0]), ft_atoi(str[1])))
				!= NULL)
				a = 0;
			free_split(str);
			return (a);
		}
		free_split(str);
		return (a);
	}
	else
		return (parse_map_line2(line_n, env, str));
	free_split(str);
	return (0);
}

int		final_check(t_env *env)
{
	if (env->player.pos.x < 0 || env->player.pos.y < 0 ||
		env->player.pos.x >= env->map->width ||
		env->player.pos.y >= env->map->height)
	{
		ft_putendl("Error: no spawn point found!");
		return (-1);
	}
	return (0);
}

int		parse_map(char *map_file, t_env *env)
{
	int		fd;
	char	*line;
	int		line_n;

	if ((fd = open(map_file, O_RDONLY)) < 0)
		return (-1);
	line = NULL;
	line_n = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line == NULL)
			continue ;
		if (parse_map_line(line_n, line, env) == -1)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line_n++;
	}
	close(fd);
	return ((env->map != NULL && final_check(env) == 0
		&& (line_n - 1) == env->map->height) ? 0 : -1);
}
