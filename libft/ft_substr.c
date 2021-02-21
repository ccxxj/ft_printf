/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 11:05:47 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/21 20:40:27 by xxu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned long	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		len = 0;
	if (start < i && start + len > i)
		len = i - start;
	sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}
