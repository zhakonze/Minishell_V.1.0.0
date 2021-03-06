/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 07:55:26 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/10 07:55:27 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;
	t_list		*current;

	if (!alst || !*alst)
		return ;
	current = *alst;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(&current, del);
		current = temp;
	}
	*alst = NULL;
}
