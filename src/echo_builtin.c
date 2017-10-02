/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:59:43 by qmanamel          #+#    #+#             */
/*   Updated: 2017/07/30 12:59:46 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		exec_command_echo(char **line)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] != '"' && line[i][j] != '\'')
				ft_putchar(line[i][j]);
			j++;
		}
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
