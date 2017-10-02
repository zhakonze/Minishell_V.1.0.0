/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:37:46 by zhakonze          #+#    #+#             */
/*   Updated: 2017/08/16 14:49:41 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		exec_cd(char *dir, int old_pwd_bool)//old_pwd_bool is a boolean expression represented by two values "0" and "1", where 0 would mean it doesn't exsit.
{												// "1" will mean that we should print out the PWD... and "0" would just take you to the directory if exsits...
	char	*curr_dir;
	char	buff[BUFF_SIZE];
	char	*oldpwd;

	oldpwd = ft_getenv("$OLDPWD");//will get the old pwd and store it in oldpwd.
	curr_dir = getcwd(buff, BUFF_SIZE);// "getcwd"copies an absolute pathname of the current working directory to the array pointed to by buf
	set_env("OLDPWD", curr_dir);//set_env will update the OLDPWD to what the current directory is,because everytime change into a directory
	if (!chdir(dir))// if the function returns an error/ if directory is not changed.
	{
		if (old_pwd_bool) //at this point old_pwd_bool is at default 0, which simply means the user just typed in cd or the user specified which path to change to, 
			ft_putendl(oldpwd);// 1 would mean that the user is typed "cd -"
	}
	else//this else will specify what could have caused the error if any...
	{
		ft_putstr("cd:");
		if (access(dir, F_OK))// accesss check accessibility of a folder.  F_OK tests for the existence of the file.   
			ft_putstr(" no such file or directory: ");
		else if (access(dir, R_OK))//R_OK is read only permission.
			ft_putstr(" permission denied: ");
		else
			ft_putstr(" not a directory");
		ft_putstr(dir);
		ft_putchar('\n');
	}
}

int			exec_command_cd(char **dir)
{
	char	*home;

	home = ft_getenv("$HOME");
	if (dir[1] && dir[2])
		ft_putendl("cd: string not in pwd:");
	else if (!dir[1] || !ft_strcmp(dir[1], "--"))
	{
		exec_cd(home, 0);//calling the exec_cd and setting the old_pwd_bool to "0" would mean its an error
		return (1);
	}
	else if (dir[1][0] == '-')
	{
		home = ft_getenv("$OLDPWD");
		exec_cd(home, 1);
		return (1);
	}
	else
		exec_cd(dir[1], 0);
	return (1);
}
