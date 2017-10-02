/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _help_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:59:06 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/18 08:01:00 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		new_env(int c, char **v, char **envv)//this function creates environment variables..
{
	int		len;// this will hold the strlen of each column. 
	int		i;

	(void)c;//we typescast so as to silent the variables...
	(void)v;//we typecast so as to silent the variables... 
	len = -1;//we start at -1 so that when ++i it starts at 0.
	i = -1;//same as above
	while (envv[++len])// will start at envv[0] then get what it got from the env and store it in g_env.
		len++;
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	while (envv[++i])//this will just move the next variable.
		g_env[i] = ft_strdup(envv[i]);//allocating for memory for each individual string in the array...
}

char		*ft_getenv(char *s_envstr)//this function is to be used in the echo function.
{
	int		i;
	char	*temp;//will be a temp holder to store the *s_envstr(which is the variable we want to get from environ).

	i = -1;
	while (g_env[++i])
	{
		temp = ft_strjoin(s_envstr + 1, "=");// + 1 is to ommit "$" sign, and join the variable name with the equal sign
		if (ft_strstartswith(g_env[i], temp))// this works the same way as strncmp..
		{
			free(temp);//we then free temp to prevent memory leaks...
			return (ft_strchr(g_env[i], '=') + 1);//returns the string after the "=" sign, thats why we + 1;
		}
		free(temp);//free temp if not found
	}
	return (NULL);
}

void		exec_commang_env(void)//this just prints out the actual env.
{
	int		i;

	i = -1;
	while (g_env[++i])
		ft_putendl(g_env[i]);
}
