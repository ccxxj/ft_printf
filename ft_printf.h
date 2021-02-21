/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:33:57 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/21 16:06:47 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef	struct	s_ptflist
{
	int			left_justify;
	int			precision;
	int			width;
	int			negnbr;
	int			temp;
	int			count;
	int			tempw;
	int			padzero;
	int			padspace;
	int			size;
	int			tsize;
	int			zero;
	char		flag[30];
	char		spcf;
}				t_ptflist;

int				ft_printf(const char *str, ...);
int				ft_process(const char *str, t_ptflist *node,
				va_list args, int count);
void			*ft_strlcpy2(char *dst, const char *src, int n);
int				ft_replace(t_ptflist *node, va_list args);
int				print_char(char c, t_ptflist *node);
int				print_beg(const char *str);
void			putstr_n(char *str, int n);
void			putchar_n(char c, int n);
void			print_process(char *str, t_ptflist *node);
int				print_intd(long long int i, t_ptflist *node);
int				ft_print_u(unsigned int i, t_ptflist *node);
int				print_str(char *str, t_ptflist *node, int free);
int				check_zero(t_ptflist *node, long long int i);
int				check_space(t_ptflist *node);
char			*ft_htoa(unsigned long long int n, char c, int i);
t_ptflist		nodeinit(void);
void			width_adp(int a, t_ptflist *node);

#endif
