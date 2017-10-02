/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:00:05 by qmanamel          #+#    #+#             */
/*   Updated: 2017/07/30 13:00:08 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exec_command_unset(char *str)//so what this function is doing is its creating a whole dup of evnvironment varibles excluding the stated one.
{
	int		i;
	int		j;
	char	**r_env;

	j = 0;
	i = -1;
	if (!str)
		return (0);
	while (g_env[++i])//this loop is more like strlen only thay
		i++;
	r_env = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (g_env[++i])
	{
		if (ft_strstartswith(g_env[i], str))//if the variable starts with or is the same as  str, skip it.
			++i;
		else
		{
			r_env[j] = ft_strdup(g_env[i]);
			j++;
		}
	}
	ft_freestrarr(g_env);
	g_env = r_env;
	return (1);
}
