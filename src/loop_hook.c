/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:23:06 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/13 15:53:00 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "game.h"
#include "hooks.h"

int		loop_hook(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	key_test(env);
	render_screen(env);
	return (1);
}
