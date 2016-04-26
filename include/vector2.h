/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:51:05 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/13 15:03:28 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct		s_vector2
{
	double	x;
	double	y;
}					t_vector2;

t_vector2			*set_vector2(t_vector2 *vector, double x, double y);
double				get_length(t_vector2 *vector);
t_vector2			*normalize_vector2(t_vector2 *vector);
t_vector2			*rotate_vector2(t_vector2 *vector, double angle);

#endif
