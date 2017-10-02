/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:04:44 by zhakonze          #+#    #+#             */
/*   Updated: 2017/07/28 09:06:44 by zhakonze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_first_word(char *str)
{
	int i;

	i = 0;
	char *ret;
	while (!ft_is_blank(str[i]))
		i++;
	ret = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (!ft_is_blank(str[i]))
	{
		ret[i] = str[i];
		i++;
	}
	return(ret);
}
