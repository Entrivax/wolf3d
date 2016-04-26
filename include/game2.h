/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:42:40 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/21 13:43:22 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME2_H
# define GAME2_H

void	test_other_sides(t_inter *in, int y, int *tex, t_env *env);
void	render_pixel(t_inter *in, int x, int y, t_env *env);
void	set_up_v(t_env *env, float angle, t_vector2 *v);

#endif
