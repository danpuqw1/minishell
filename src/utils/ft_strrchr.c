/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:02:12 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:02:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	k;

	i = 0;
	k = c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == k)
			return (char*)(s + i);
		i--;
	}
	return (NULL);
}
