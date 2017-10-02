/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:32:48 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/14 14:32:49 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			parse_input(char **input)
{
	int		r;
	int		i;
	int		count;
	char	buffer;

	count = 1;
	i = 0;
	*input = (char *)malloc(sizeof(char));
	while ((r = read(0, &buffer, 1)) && buffer != '\n')
	{
		*(*input + i++) = buffer;
		*input = ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = 0;
	if (!r)
	{
		free(*input);
		return (0);
	}
	return (1);
}

int			exec_command_main(char **command)
{
	if (command)
	{
		if (!ft_strcmp(command[0], "exit"))
			return (0);
		else if (!ft_strcmp(command[0], "clear")
		|| !ft_strcmp(command[0], "CLEAR"))
			ft_putstr(CLEAR);
		else if (!ft_strcmp(command[0], "env"))
			exec_commang_env();
		else if (!ft_strcmp(command[0], "setenv"))
			exec_command_setenv(command);
		else if (!ft_strcmp(command[0], "clear"))
			ft_putstr(CLEAR);
		else if (!ft_strcmp(command[0], "echo") && command[1][0] == '$')
			ft_putendl(ft_getenv(command[1]));
		else if (!ft_strcmp(command[0], "echo"))
			exec_command_echo(command);
		else if (!ft_strcmp(command[0], "cd"))
			exec_command_cd(command);
		else if (!ft_strcmp(command[0], "unsetenv"))
			exec_command_unset(command[1]);
		else
			exec_command(command);
	}
	return (1);
}

int 		exec_pipe(char **str, int len)
{
	char 	**pipes[len];
	char	**temp_pipe;
	int 	i;

	i = -1;
	while(str[++i])
	{
		temp_pipe = ft_strsplit(str[i], ' ');
		pipes[i] = temp_pipe;
	}
	pipes[i] = NULL;
	execve_pipe(pipes);
	ft_freestrarr(temp_pipe);
	return(1);
}

int			pipe_parse(char *command)
{
	char	**temp_pipes;
	int 	len;

	len = 0;
	temp_pipes = ft_strsplit_num(command, '|', &len);
	exec_pipe(temp_pipes, len);
	ft_freestrarr(temp_pipes);
	return (1);
}

int			run_rcmds(char **commands)
{
	int		i;
	int		ret;
	char	**command;

	i = -1;
	ret = 0;
	while (commands[++i])
	{
		if (strchr(commands[i], 124))
		{
			ret = pipe_parse(commands[i]);
			if (commands[i + 1])
				i++;
			else
				return(ret);
		}
		command = ft_strsplit(commands[i], ' ');
		ret = exec_command_main(command);
		ft_freestrarr(command);
	}
	return (ret);
}
