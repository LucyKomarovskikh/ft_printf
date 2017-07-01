/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:53:39 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/23 17:55:32 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_d_num(char *str)
{
    int d_num;

    d_num = ft_strlen(str);
    (g_str->fl_ht == 1) && (g_str->t == 'o') ? d_num++ : d_num;
    if (*str == '0' && g_str->t == 'o')
        d_num++;
    return (d_num);
}