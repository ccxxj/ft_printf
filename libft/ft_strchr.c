/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:32:48 by Xiaojing      #+#    #+#                 */
/*   Updated: 2020/11/27 11:31:43 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] || c == '\0')
	{
		if (s[i] != c)
			i++;
		else
			return ((char *)s + i);
	}
	return (0);
}
