/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:20:55 by lkomarov          #+#    #+#             */
/*   Updated: 2016/12/10 21:20:59 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
//#include "./libft/libft.h"
#include <limits.h>

#define IF_FLAG(c) c == '-' || c == '+' || c == ' ' || c == '#' || c == '0'
#define IF_NBR(c) (c > 48 && c <= 57)
#define IF_INT(c) (c == 'd' || c == 'i' || c == 'D' || c == 'U')
#define IF_WRITE_C (g_str->fl_pl == 1 || g_str->fl_sp == 1 || c == '-')

extern unsigned int g_count;
extern unsigned int g_count_i;

typedef struct format_string {
    unsigned int            pr_spec;
    unsigned int            fl_min;
    unsigned int            fl_pl;
    unsigned int           fl_sp;
    unsigned int            fl_ht;
    unsigned int            fl_z;
    int            w;
    int    pr;
    char                    *l;
    char            t;
    int            star_w;
    int            star_pr;
} s_fmt ;

extern s_fmt *g_str;


int ft_d_num(char *str);
void    ft_pr_ht(char *str);
void ft_print_char(char a);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
void ft_pr_string(char *str, int flag);
void ft_pr_s(const char *str);
int ft_convert(unsigned long long *n);
void    ft_tap(unsigned long long i, int length, unsigned int base);
void    ft_notap(unsigned long long i, int length, int base);
int ft_fill(int flag, int length);
int     ft_str(char *s);
int    ft_ixo(unsigned long long n);
int ft_char(unsigned long long a);
const char *ft_all_toa(unsigned long long nb, unsigned int base);
int ft_find_nbr(const char *str);
int	ft_intcount(ptrdiff_t i);
int	ft_check_lt(char type, int i);
void ft_fouth_length(const char* format);
void ft_third_precision(const char *format);
void ft_second_width(const char *format);
void ft_first_flag(const char *format);
s_fmt *ft_create_new(void);
void ft_check_fmt(const char *format);
void ft_pr_struct(unsigned long long *temp);
int ft_printf(const char *format, ...);



#endif