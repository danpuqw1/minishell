/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:03:29 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:03:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_eval(char **env, char *arg)
{
	int		i;
	char	*eval;

	i = 0;
	eval = NULL;
	while (env && env[++i])
		if (!ft_strncmp(env[i], (arg + 1), ft_strlen(arg) - 1))
			eval = ft_strrchr(env[i], '=') + 1;
	return (eval);
}

static char	*echo_arg(char **env, char *arg, int last)
{
	char	*str;

	if ((str = ((arg && arg[0] == '$') ? get_eval(env, arg) : arg)))
		ft_putstr(str);
	ft_putchar(!last ? ' ' : '\n');
	return (str);
}

char		**cmd_echo(char **args, char **env, char *name)
{
	int		i;

	i = 0;
	if (*args && args[1])
		while (args[++i])
			echo_arg(env, args[i], (args[i + 1] ? 0 : 1));
	return (env);
	(void)name;
}
