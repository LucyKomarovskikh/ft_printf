/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:30:37 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/22 19:05:42 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pr_s(const char *str)
{
	if (g_str->t == 'p' && ft_strcmp(str, "0x") != 0)
		g_count += write(1, "0x", 2);
	while (*str != '\0')
	{
		g_count += write(1, str, 1);
		str++;
	}
}
