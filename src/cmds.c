/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:03:46 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:03:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**cmd_env(char **args, char **env, char *name)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
	return (env);
	(void)args;
	(void)name;
}

char		**cmd_exit(char **args, char **env, char *name)
{
	ft_tabfree(env);
	return (NULL);
	(void)args;
	(void)name;
}

char		**cmd_help(char **args, char **env, char *name)
{
	int		i;

	i = -1;
	ft_putchar('\n');
	ft_putendl(",-.-.o     o     |         |    |    ");
	ft_putendl("| | |.,---..,---.|---.,---.|    |    ");
	ft_putendl("| | |||   ||`---.|   ||---'|    |    ");
	ft_putendl("` ' '``   '``---'`   '`---'`---'`---'");
	ft_putendl("By: Dteemo\n\n");
	ft_putendl("Type program names and arguments, and hit enter.");
	ft_putendl("The following are built in:");
	while (++i < BLT_NUM)
		ft_putendl(cmd_str(i));
	return (env);
	(void)args;
	(void)name;
}

char		**cmd_pwd(char **args, char **env, char *name)
{
	char	buf[PATH_MAX + 1];
	int		i;

	i = 0;
	while (args[i])
		i += 1;
	if (i > 1)
		ft_putendl("Too many arguments...");
	else if (i == 1)
		ft_putendl(getcwd(buf, PATH_MAX));
	return (env);
	(void)name;
}

char		**cmd_unsetenv(char **args, char **env, char *name)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	(args[1]) ? (args[1] += (args[1][0] == '$')) : 0;
	if (!ft_strcmp(args[1], "PWD"))
		ft_putendl("I can't let you do that...");
	else if (args[1] && ft_find_env(args[1], env)[0] != 0)
	{
		while (env[++i])
			if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
				break ;
		free(env[i]);
		i -= 1;
		while (env[++i])
			env[i] = env[i + 1];
		env[i] = NULL;
	}
	return (env);
	(void)name;
}
