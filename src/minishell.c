/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:04:19 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:04:20 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

static char	**run_cmd(char **comands, char **env, char *name)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (comands[j])
	{
		args = ft_strtok(comands[j], TOK_DELIM);
		env = execute(args, env, name);
		free(comands[j]);
		j += 1;
		while (args[i])
			free(args[i++]);
		(args) ? free(args) : 0;
	}
	return (env);
	(void)name;
}

static void	set_dir(char **env, char *name)
{
	char	**arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 4);
	arg[0] = NULL;
	arg[1] = ft_strdup("PWD");
	arg[2] = ft_strnew(PATH_MAX);
	arg[3] = 0;
	getcwd(arg[2], PATH_MAX);
	cmd_setenv(arg, env, name);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

int			minishell(char **env, char *name)
{
	int		status;
	char	*line;
	char	**comands;

	status = 1;
	while (status)
	{
		ft_putstr("> ");
		set_dir(env, name);
		line = read_line();
		comands = ft_strtok(line, ";");
		env = run_cmd(comands, env, name);
		status = env ? 1 : 0;
		free(comands);
		free(line);
	}
	return (status);
}
