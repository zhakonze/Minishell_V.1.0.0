/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:36:40 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/19 13:36:41 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    execve_pipe(char ***cmd) 
{
	int   p[2];
	pid_t pid;
	int   fd_in = 0;

	while (*cmd != NULL)
	{
		pipe(p);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
            close(p[0]);
            execve((*cmd)[0], *cmd, g_env);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&pid);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
}
