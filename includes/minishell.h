/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:00:38 by zhakonze          #+#    #+#             */
/*   Updated: 2017/08/18 10:56:14 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <dirent.h>
# include <pwd.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1024
# define CLEAR "\e[1;1H\e[2J"
# define SETENV_SYNTAX "syntax error: [Key] = [Value]"
# define ENV_ERROR_1 "\e[0;31mNot found , try [setenv]\e[1;0m"


char	**g_env;

void	prog_handle(int sign_n);
void	proc_handler(int sign_n);
void	exit_shell(void);
void	exec_commang_env(void);
void	new_env();
char	*ft_getenv(char *s_envstr);
int		exec_command(char **rcmd);
int		parse_input(char **input);
int		exec_command_main(char **command);
int		run_rcmds(char **commands);
void	exec_cd(char *dir, int old_pwd_bool);
void    execve_pipe(char ***cmd);
int		exec_command_cd(char **dir);
int		exec_command_echo(char **line);
int		exec_command_unset(char *str);
int		exec_command_setenv(char **g_env);
void	set_env(char *key, char *value);

#endif
