/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 19:20:46 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:40:53 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i = i + 1;
		s++;
	}
	return (i);
}
