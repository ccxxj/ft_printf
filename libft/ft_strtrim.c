/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 15:47:07 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/20 20:51:37 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	trim_top(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				j++;
			else
				break ;
		}
		if (s1[i] == set[j])
			i++;
		else
			break ;
	}
	return (i);
}

static	int	trim_bottom(char const *s1, char const *set, int len)
{
	int	j;
	int	bottom;

	bottom = len;
	while (len > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] != set[j])
				j++;
			else
				break ;
		}
		if (s1[len - 1] == set[j])
			len--;
		else
			break ;
	}
	return (bottom - len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		top;
	int		trim_len;

	if (!s1 || !set)
		return (NULL);
	top = trim_top(s1, set);
	if ((size_t)top == ft_strlen(s1))
		trim_len = 0;
	else
		trim_len = ft_strlen(s1) - top - trim_bottom(s1, set, ft_strlen(s1));
	return (ft_substr(s1, top, trim_len));
}
