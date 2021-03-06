/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:02:53 by student           #+#    #+#             */
/*   Updated: 2020/08/14 21:02:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t		ft_tablen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len += 1;
	return (len);
}
