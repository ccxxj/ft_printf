/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 11:25:10 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/16 17:01:04 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = ft_calloc((i + j + 1), sizeof(char));
	if (!join)
		return (NULL);
	while (j > 0)
	{
		join[i + j - 1] = s2[j - 1];
		j--;
	}
	while (i > 0)
	{
		join[i - 1] = s1[i - 1];
		i--;
	}
	return (join);
}
