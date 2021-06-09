/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:58:13 by student           #+#    #+#             */
/*   Updated: 2020/08/14 20:58:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "utils.h"

# define BLT_NUM		(8)
# define TOK_DELIM		" \t\n\r\a\""
# define CD_NOTEXIST	("No such file or directory.")
# define CD_NOTDIR		("Not a directory.")
# define CD_NOPERM		("Permission denied.")

int		minishell(char **env, char *name);
char	**execute(char **args, char **env, char *name);
char	*cmd_str(int i);
char	**(*cmd_func(int i))(char **args, char **env, char *name);
char	**cmd_echo(char **args, char **env, char *name);
char	**cmd_cd(char **args, char **env, char *name);
char	**cmd_setenv(char **args, char **env, char *name);
char	**cmd_unsetenv(char **args, char **env, char *name);
char	**cmd_env(char **args, char **env, char *name);
char	**cmd_exit(char **args, char **env, char *name);
char	**cmd_pwd(char **args, char **env, char *name);
char	**cmd_help(char **args, char **env, char *name);

#endif
