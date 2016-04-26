/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:42:40 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/13 15:53:15 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int		loop_hook(void *param);
int		key_test(t_env *env);
int		key_release_event(int keycode, void *param);
int		key_press_event(int keycode, void *param);

#endif
