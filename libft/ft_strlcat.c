/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 12:52:40 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/26 16:06:26 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len_old;
	size_t		len_src;

	i = 0;
	len_old = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_old > dstsize)
		return (dstsize + len_src);
	while (i + len_old + 1 < dstsize && src[i] != '\0')
	{
		dst[len_old + i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i + len_old] = '\0';
	return (len_old + len_src);
}
