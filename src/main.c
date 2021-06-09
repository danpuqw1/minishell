/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:04:09 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:04:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*cmd_str(int i)
{
	char	*cmd_str[BLT_NUM + 1];

	cmd_str[0] = "cd";
	cmd_str[1] = "echo";
	cmd_str[2] = "exit";
	cmd_str[3] = "env";
	cmd_str[4] = "setenv";
	cmd_str[5] = "unsetenv";
	cmd_str[6] = "help";
	cmd_str[7] = "pwd";
	cmd_str[8] = NULL;
	return (cmd_str[i]);
}

char		**(*cmd_func(int i))(char **args, char **env, char *name)
{
	char	**(*cmd_func[BLT_NUM])(char **args, char **env, char *name);

	cmd_func[0] = &cmd_cd;
	cmd_func[1] = &cmd_echo;
	cmd_func[2] = &cmd_exit;
	cmd_func[3] = &cmd_env;
	cmd_func[4] = &cmd_setenv;
	cmd_func[5] = &cmd_unsetenv;
	cmd_func[6] = &cmd_help;
	cmd_func[7] = &cmd_pwd;
	return (cmd_func[i]);
}

static void	init_env(char ***env, char **envp)
{
	int		i;
	int		j;

	i = -1;
	while (envp[++i])
		NULL;
	(*env) = (char **)ft_memalloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char *)ft_memalloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*env)[i][j] = envp[i][j];
		(*env)[i][j] = 0;
	}
	(*env)[i] = NULL;
	i = -1;
	return ;
}

int			main(int argc, char *argv[], char *envp[])
{
	char	**env;

	init_env(&env, envp);
	return (minishell(env, argv[0]));
	(void)argc;
}
