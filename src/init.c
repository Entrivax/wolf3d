/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:44:38 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/09 14:58:53 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

int		get_files(t_env *env, int argc, char **av)
{
	if (argc == 1)
	{
		env->mf = "res/map1";
		env->tf = "res/tilesmap1";
	}
	else if (argc == 3)
	{
		env->mf = *(av + 1);
		env->tf = *(av + 2);
	}
	else
	{
		destroy_env(&env);
		return (print_usage(av));
	}
	return (1);
}

void	print_infos(void)
{
	ft_putendl("\nWolf3d use ripped textures by ULTIMECIA.");
	ft_putendl("\nSome textures may have been edited or replaced.\n");
}
