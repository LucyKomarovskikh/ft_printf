/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:29:16 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/22 17:29:23 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int	ft_intcount(ptrdiff_t i)
{
    int d_count;

    d_count = 1;
    if (i < 0)
    {
        i = -i;
        d_count++;
    }
    while (i > 9)
    {
        d_count++;
        i /= 10;
    }
    return (d_count);
}