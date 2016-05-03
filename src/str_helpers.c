/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <lpilotto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:35:25 by lpilotto          #+#    #+#             */
/*   Updated: 2016/05/03 12:35:44 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **split)
{
	int		i;

	if (split != NULL)
	{
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
	}
}

int		split_length(char **split)
{
	int		i;

	if (split == NULL)
		return (-1);
	i = -1;
	while (split[++i])
		;
	return (i);
}
