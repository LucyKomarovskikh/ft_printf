/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:27:50 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/23 18:31:59 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


s_fmt *g_str;
unsigned int g_count_i;

s_fmt *ft_create_new(void)
{
    g_str = (s_fmt *)malloc(sizeof(s_fmt));
    if (g_str)
    {
        g_str->fl_pl = 0;
        g_str->fl_min = 0;
        g_str->fl_ht = 0;
        g_str->fl_z = 0;
        g_str->fl_sp = 0;
        g_str->l = 0;
        g_str->pr = 1;
        g_str->w = 0;
        g_str->t = 0;
        g_str->pr_spec = 0;
        g_str->star_w = 0;
        g_str->star_pr = 0;
    }
    return (g_str);
}

void ft_check_fmt(const char *format)
{
    g_str = ft_create_new();
    if (g_str)
    {
        ft_first_flag(format);
        g_str->t = format[g_count_i];
    }
}

void ft_pr_struct(unsigned long long *arg)
{
    g_str->pr < 0 ? ((g_str->pr = 1) && (g_str->pr_spec = 0)) : g_str->pr;
    g_str->w < 0 ? ((g_str->w = -(g_str->w)) && 
			(g_str->fl_min = 1)) : g_str->w;
    (g_str->t == 'O' || g_str->t == 'D') ? g_str->l = "l" : g_str->l;
    if (ft_check_lt(g_str->t, 0) == 1)
        ft_ixo(*arg);
    else if (g_str->t == 'U')
        ft_pr_s(ft_all_toa(*arg, 10));
    else
        ft_print_char(g_str->t);
}

void ft_w_pr_bon(va_list *arg)
{
    unsigned long long temp;

    if (g_str->star_w > 0)
        g_str->star_w == 1 ? g_str->w = va_arg(*arg, unsigned int) : va_arg(*arg, unsigned int);
    if (g_str->star_pr > 0)
        g_str->star_pr == 1 ? g_str->pr = va_arg(*arg, unsigned int) : va_arg(*arg, unsigned int);
    (g_str->t != '%') ? (g_str->t == 's' || g_str->t == 'S' ? (ft_str(va_arg(*arg, char *))) :
                         (temp = va_arg(*arg, unsigned long long), ft_pr_struct(&temp))) : ft_print_char('%');
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    g_count = 0;

    va_start(ap, format);
    while (*format != '\0')
    {
        if (*format != '%')
        {
            g_count += write(1, format, 1);
            format++;
        }
        else if(*format == '%' && *(format + 1) == '\0')
            return (0);
        else
        {
            ft_check_fmt(format + 1);
            ft_w_pr_bon(&ap);
            format = format + g_count_i + 2;
            g_count_i = 0;
        }
    }
    va_end(ap);
    return (g_count);
}


//int main(void)
//{
//#pragma clang diagnostic ignored "-Wformat"
//
//
//    setlocale(LC_ALL, "");
//    setlocale(LC_ALL, "en_US.UTF-8");
//    setlocale(LC_ALL, ".OCP");
//    setlocale(LC_ALL, ".ACP");

//    printf("---------------------------P vs X---------------------------\n\n");
//    printf("1 REAL PRINTF N of CHARACTERS %d\n", printf("%05.Z", 0));
//    ft_printf("%05.Z", 0);

//
//    ft_printf("%#.0p, %#.p, %#p, %#0p ", 0, 0, 0, 0);
//    printf("1 REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%#.0p, %#.p, %#p, %#0p ", 0, 0, 0, 0));
//
//
//    printf("---------------------------P vs X---------------------------\n\n");
//
//    printf("1. REAL PRINTF N of CHARACTERS %d\n", printf("%C", L'ÁM-^L´'));
//    ft_printf("%S", L"(null)");

//    printf("2. REAL PRINTF N of CHARACTERS %d\n", printf("%05.s ", 0));
//    ft_printf("%05.s ", 0);
//
//    printf("3. REAL PRINTF N of CHARACTERS %d\n", printf("%*s ", 5, 0));
//    ft_printf("%*s ", 5, 0);
//
//
//    printf("4. REAL PRINTF N of CHARACTERS %d\n", printf("%#10.6p ", 999));
//    ft_printf("%#10.6p ", 999);

//    printf("5. REAL PRINTF N of CHARACTERS %d\n", printf("%#10.x ", 0));
//    ft_printf("%#10.x ", 0);
//
//    printf("6. REAL PRINTF N of CHARACTERS %d\n", printf("%#10.o ", 0));
//
//    ft_printf("%#10.o ", 0);
//
//    ft_printf("%#10.5p ", 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%#10.5p ", 0));
//    ft_printf("%#10.10x ", 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%#10.10x ", 0));
//    ft_printf("%#10.10o ", 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%#10.10o ", 0));

//    ft_printf("%0.p", 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%0.p", 0));
//    ft_printf("%3*p", 10, 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%3*p", 10, 0));
//

//    ft_printf("%.o, \n", 0, 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%.o\n", 0, 0));

//    ft_printf("@moulitest: %#.x %#.0x ", 0, 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("@moulitest: %#.x %#.0x ", 0, 0));
//
//    ft_printf("@moulitest: %5.d %5.0d", 0, 0);
//    printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("@moulitest: %5.d %5.0d", 0, 0));

//    ft_printf("%u ", "4294967296");
//    printf(" REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%u ", "4294967296"));
//
//
// ft_printf("%*.*x", 5, 6, 42);
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%*.*x", 5, 6, 42));
//
//   ft_printf("3. %-+03.1llo     ", -11);
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%-+03.1llo     ", -11));

//   ft_printf("4. %-+3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%-+3.1llo     ", 245678 ));
//
//   ft_printf("5. %-+ 3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%-+ 3.1llo     ", 245678 ));
//
//   ft_printf("6. %-+ 03.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%-+ 03.1llo     ", 245678 ));
//
//   ft_printf("7. %- 03.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%- 03.1llo     ", 245678 ));
//
//   ft_printf("8. %- 3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%- 3.1llo     ", 245678 ));
//
//
//   ft_printf("9. %+ 3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%+ 3.1llo     ", 245678 ));
//
//  ft_printf("1. %+3.1llo    ", 245678 );
//  printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%+3.1llo     ", 245678 ));
//
//  ft_printf("11. %+ 03.1llo     ", 245678 );
//  printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%+ 03.1llo     ", 245678 ));
//
//  ft_printf("12. %+03.1llo     ", 245678 );
//  printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%+03.1llo     ", 245678 ));
//
//  ft_printf("13. % 03.1llo     ", 245678 );
//  printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("% 03.1llo     ", 245678 ));
//
//   ft_printf("14. % 3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("% 3.1llo ", 245678 ));
//
//   ft_printf("15. %03.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%03.1llo     ", 245678 ));
//
//   ft_printf("%3.1llo     ", 245678 );
//   printf("REAL PRINTF N of CHARACTERS %d\n\n\n", printf("%3.1llo     ", 245678 ));
//
//
//
//    printf("%015d", 10.4);
//    return 0;
//}

//    printf("WIDTH %d\n", g_str->w);
//    printf("PRECISION %d\n", g_str->pr);
//    printf("MIN %d, SPACE %d, PLUS %d, HT %d, ZERO %d\n, STARW %d, STARPR %d\n",
//           g_str->fl_min, g_str->fl_sp, g_str->fl_pl, g_str->fl_ht, g_str->fl_z, g_str->star_w, g_str->star_pr);
//    	printf("LENGTH %s\n", g_str->l);
//    printf("TYPE %c\n", g_str->t);
//  printf ("SKOLKO YA %d\n\n", g_count);
