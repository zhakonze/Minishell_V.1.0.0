/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 09:23:52 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/15 09:24:04 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prog_handle(int sign_n)
{
	(void)sign_n;
	ft_putchar('\n');
	ft_putstr("👉 👉");
	ft_putstr("\x1B[31m ▷ \x1B[0m");
}

void	proc_handler(int sign_n)//what this function does is it waits to catch the signal(ctrl + c), then prints a new line and continues...
{								//the interruption happens when a process is stack in a loop...
	(void)sign_n;
	ft_putendl("\n");
}
