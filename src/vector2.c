/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:53:20 by lpilotto          #+#    #+#             */
/*   Updated: 2016/04/13 15:03:34 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector2.h"

t_vector2	*set_vector2(t_vector2 *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
	return (vector);
}

double		get_length(t_vector2 *vector)
{
	return (sqrt(vector->x * vector->x + vector->y * vector->y));
}

t_vector2	*normalize_vector2(t_vector2 *vector)
{
	double	length;

	length = get_length(vector);
	vector->x /= length;
	vector->y /= length;
	return (vector);
}

t_vector2	*rotate_vector2(t_vector2 *vector, double angle)
{
	double	c;
	double	s;
	double	x;
	double	y;

	c = cos(angle);
	s = sin(angle);
	x = vector->x;
	y = vector->y;
	vector->x = x * c - y * s;
	vector->y = x * s + y * c;
	return (vector);
}
