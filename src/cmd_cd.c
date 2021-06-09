/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:03:21 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:03:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_args(char **args)
{
	int			count;

	count = 0;
	while (args[count])
		count += 1;
	return (count);
}

static char		**set_dir(char **env, char *name)
{
	char	**arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 3);
	arg[0] = NULL;
	arg[1] = ft_strnew(PATH_MAX);
	arg[2] = ft_strnew(PATH_MAX);
	ft_strcat(arg[1], "OLDPWD");
	getcwd(arg[2], PATH_MAX);
	env = cmd_setenv(arg, env, name);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return (env);
}

static char		**access_dir(char **env, char *path, char *name)
{
	char		*msg;
	struct stat	stt;

	msg = NULL;
	if (!(access(path, F_OK) == -1))
		lstat(path, &stt);
	else
		msg = CD_NOTEXIST;
	if (!(access(path, R_OK) != -1) && !msg)
		msg = CD_NOPERM;
	if (!S_ISDIR(stt.st_mode) && !msg)
		msg = CD_NOTDIR;
	if (msg)
		ft_putendl(msg);
	else
	{
		env = set_dir(env, name);
		chdir(path);
	}
	return (env);
}

char			**cmd_cd(char **a, char **env, char *name)
{
	int			i;
	char		p[PATH_MAX + 1];

	i = -1;
	while (++i < PATH_MAX)
		p[i] = 0;
	if (count_args(a) < 3)
	{
		(a)++;
		if (!*a || !ft_strcmp(*a, "~") \
			|| ((*a)[0] == '~' && (*a)[1] == '/'))
			ft_strcat(p, ft_find_env("~", env));
		if (*a && (*a)[0] == '~' && (*a)[1] == '/' \
			&& ft_strlen(*a) > 2)
			ft_strncat(p, (*a + 1), ft_strlen(*a));
		else if (*a && !ft_strcmp(*a, "-"))
			ft_strcat(p, ft_find_env("$OLDPWD", env));
		else if (*a && (*a)[0] != '~' && (*a)[0] != '-')
			ft_strncat(p, *a, PATH_MAX);
		env = access_dir(env, p, name);
	}
	return (env);
}
