/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:59:56 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/16 14:44:42 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			env_overwrite_pos(char *str)//this function will check if the key exists// returning i would be at what position the key to be overwritten is vertically...
{
	int		i;
	char	*temp;

	i = -1;
	while (g_env[++i])
	{
		temp = ft_strjoin(str, "=");//this will join the key. which is the variable name with the equal sign.
		if (ft_strstartswith(g_env[i], temp))//checks by comparing if the str given in temp is also found in the environment.
		{
			free(temp);//temp at this point is then freed provided the key does exist in the environment.
			return (i);//i will then return at which position the already existing varible is from top going down.
		}
		free(temp);//provided that the temp varible doesn't exist temp still has to be freed to prevent memory leaks...
	}
	return (i);
}

char		**realloc_env(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size));
	i = -1;
	while (g_env[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
	}
	free(g_env);
	return (new);
}

void		set_env(char *key, char *value)//Value would be anything that comes after the equal sign...
{
	int		pos;
	char	*temp;

	pos = env_overwrite_pos(key);//will check if the key already exist, and return at which position it exists....//if the key doesn't exist pos will be at the end of the array.
	temp = ft_strjoin("=", value);
	if (g_env[pos])
	{
		free(g_env[pos]);
		if (value)//if the value exists e.g we might have a case were the key is there but has no value.
			g_env[pos] = ft_strjoin(key, temp);
		else
			g_env[pos] = ft_strjoin(key, "=");
	}
	else// this would be us creating a new one from scratch...
	{
		g_env = realloc_env(pos + 1);
		if (value)
			g_env[pos] = ft_strjoin(key, temp);
		else
			g_env[pos] = ft_strjoin(key, "=");
	}
	free(temp);
}

int			exec_command_setenv(char **s_env_str)
{
	if (!s_env_str[1] || !ft_isprint_str(s_env_str[1])
	|| ft_strcmp(s_env_str[2], "=") || !ft_isprint_str(s_env_str[3]))
	{
		ft_putendl(SETENV_SYNTAX);
		return (1);
	}
	set_env(s_env_str[1], s_env_str[3]);
	return (1);
}
