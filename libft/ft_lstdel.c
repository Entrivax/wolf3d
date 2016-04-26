/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:35:01 by lpilotto          #+#    #+#             */
/*   Updated: 2015/12/03 13:50:58 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *tmp;

	if (*alst == NULL)
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	while (next)
	{
		(*del)(next->content, next->content_size);
		tmp = next;
		next = next->next;
		free(tmp);
	}
	*alst = NULL;
}
