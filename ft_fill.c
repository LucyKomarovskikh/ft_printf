/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:29:45 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/22 19:02:49 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_fill(int flag, int length)
{
	char	c;
	int		n;

	c = '0';
	n = 0;
	flag != 0 ? (c = ' ') : c;
	while (length > n)
	{
		g_count += write(1, &c, 1);
		n++;
	}
	return (n);
}