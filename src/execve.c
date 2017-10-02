/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:59:15 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/16 14:43:41 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			exit_shell(void)// this functions dose just as the name says exits the shell 
{								 //by freeing all evironment variables, and finally exiting the shell.
	ft_freestrarr(g_env);		 // ft_freestrarr() will be found in lib_ft and all it does is free individual variables  then frees the eviron as a whole ...
	exit(0);//this will terminates the calling process immediately, where 0 would mean successful termination.
}

int				exec_shell_rcmd(char *path, char **args)
{
	pid_t		pid;

	pid = fork();//system call fork() is used to create processes,It takes no arguments and returns a process ID
	signal(SIGINT, proc_handler);
	if (pid == 0)//if the pid is 0, that means it created/running the child process
		execve(path, args, g_env);
	else if (pid < 0)// if the pid is less than 0, that means its an error\smething went wrong...
	{
		free(path);
		ft_putendl("Fork failed to create new process");
	}
	wait(&pid);// wait will wait for a process to end before any other execution/wait will always take an address as an grgument. 
	if (path)
		free(path);
	return (1);
}

int				is_exec(char *path, struct stat f, char **command)
{
	if (f.st_mode & S_IFREG)//st_mode checks the mode of a file\information about the file// S_IFREG means regular file
	{
		if (f.st_mode & S_IXUSR)// "f" means its the start struct for the current permissions on the file./ S_IXUSR Owner has Execute/search permission.
			return (exec_shell_rcmd(path, command));
		else
		{
			ft_putstr("Minishell v.2.0: permmision denied: ");
			ft_putendl(path);
		}
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

int				path_check(char **command)
{
	int			i;// index counter...
	char		*bin_path;//stores the path value from the path variable excluding the colon 
	char		**path;//stores PATH value separated by colon, taken from environ
	struct stat f;

	i = -1;// pretty much the same as starting from 0, then increamenting "i" like so "i++".
	path = ft_strsplit(ft_getenv("$PATH"), ':');//splitting path environ with colon and storing it in path
	while (path && path[++i])
	{
		bin_path = ft_strjoinfr(ft_strjoin(path[i], "/"), command[0], 0);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (is_exec(bin_path, f, command));
		}
	}
	ft_freestrarr(path);
	return (0);
}

int				exec_command(char **rcmd)
{
	struct stat	d_stat;

	if (path_check(rcmd))
		return (0);
	if (lstat(rcmd[0], &d_stat) != -1)
	{
		if (d_stat.st_mode & S_IXUSR)
			return (exec_shell_rcmd(ft_strdup(rcmd[0]), rcmd));
	}
	ft_putstr("Minishell v.2.0 : command not found ");
	ft_putendl(rcmd[0]);
	return (0);
}
