/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:18:53 by lkomarov          #+#    #+#             */
/*   Updated: 2017/01/18 15:19:01 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void ft_print_char(char a)
{
    if (g_str->fl_min == 0)
        g_str->fl_z == 1 ? ft_fill(0, g_str->w - 1) :
        ft_fill(1, g_str->w - 1);
    g_count += write(1, &a, 1);
    if (g_str->fl_min == 1)
        ft_fill(1, g_str->w - 1);
}

int ft_char(unsigned long long a)
{
    a = (signed char)a;
    ft_print_char(a);
    return 0;
}
