/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:00:24 by zhakonze          #+#    #+#             */
/*   Updated: 2017/07/30 14:12:05 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		display_prompt(void)
{
	ft_putstr("👉️ 👉");
	ft_putstr("\x1b[32m");
	ft_putstr("\x1b[0m");
	ft_putstr(" ▷ \x1b[0m");
}

int			ft_isemptystr(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			return (0);
	}
	return (1);
}

int			main(int c, char **v, char **envv)
{
	char	*input;
	int		ret;
	char	**commands;

	new_env(c, v, envv);
	ft_putstr(CLEAR);
	while (42)
	{
		display_prompt();
		signal(SIGINT, prog_handle);
		parse_input(&input);
		commands = ft_strsplit(input, ';');
		free(input);
		ret = run_rcmds(commands);
		ft_freestrarr(commands);
		if (!ret)
			exit_shell();
	}

	ft_freestrarr(g_env);
	return (0);
}
