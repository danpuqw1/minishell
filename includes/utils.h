/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:58:22 by student           #+#    #+#             */
/*   Updated: 2020/08/14 20:58:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# define BUFF_SIZE 32

char	**ft_strtok(char *s, char *sep);
char	*ft_find_env(char *name, char **env);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_putchar(char c);
int		ft_putendl(char *str);
int		ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_next_line(const int fd, char **line);
size_t	ft_tablen(char **tab);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_error(int err, char *exe, char *msg);
void	ft_strclr(char *s);
void	ft_tabfree(char **tab);

#endif
