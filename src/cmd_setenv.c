/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:03:36 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:03:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**replace(char **args, char **env)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(env[i], args[1]);
	ft_strcat(env[i], "=");
	ft_strcat(env[i], args[2]);
	return (env);
}

static char	**create_new(char **args, char **env)
{
	char	***e;
	char	**envp;
	int		i;

	i = -1;
	e = &env;
	while ((*e)[++i])
		NULL;
	envp = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = -1;
	while ((*e)[++i])
		envp[i] = ft_strdup((*e)[i]);
	ft_tabfree(env);
	envp[i] = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strncat(envp[i], args[1], ft_strlen(args[1]));
	ft_strncat(envp[i], "=", 1);
	ft_strncat(envp[i], args[2], ft_strlen(args[2]));
	e = &envp;
	return (*e);
}

static void	free_arg(char **arg)
{
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

static char	**one_arg(char **args, char **env, char *name)
{
	int		i;
	int		j;
	char	**arg;

	i = (args[1][0] == '"');
	j = 0;
	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strnew(sizeof(args[1]));
	arg[2] = ft_strnew(sizeof(args[1]));
	while (args[1][i] != '=' && args[1][i])
		arg[1][j++] = args[1][i++];
	if (!args[1][i])
	{
		free(arg);
		return (env);
	}
	j = 0;
	while (args[1][++i] != '"' && args[1][i])
		arg[2][j++] = args[1][i];
	env = cmd_setenv(arg, env, name);
	free_arg(arg);
	return (env);
}

char		**cmd_setenv(char **args, char **env, char *name)
{
	if (!args[1])
		return (env);
	if (!args[2])
		return (one_arg(args, env, name));
	if (ft_find_env(args[1], env)[0] != 0)
		return (replace(args, env));
	return (create_new(args, env));
	(void)name;
}
