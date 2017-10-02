/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:39:01 by zhakonze          #+#    #+#             */
/*   Updated: 2017/07/30 14:08:16 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint_str(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			i++;
	}
	if (i == len)
		return (1);
	else
		return (0);
}
