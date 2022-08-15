/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:02:30 by lrosch            #+#    #+#             */
/*   Updated: 2021/10/27 14:31:39 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
** function that copies a string for length size
** function is only used by substr function
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == 0)
		return (0);
	src_len = ft_strlen(src);
	if (dest == 0 || src == 0)
		return (0);
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < (size - 1) && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (size < src_len)
		dest[size - 1] = '\0';
	else if (size != 0)
		dest[i] = '\0';
	return (src_len);
}

/*
** function to extract a sub string from a string *s for
** length len starting from int start
** (also used for copying strings)
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		*dest = '\0';
		return (dest);
	}
	dest = malloc(len + 1);
	if (dest == 0)
		return (0);
	while (i < start)
		i++;
	ft_strlcpy(dest, (s + i), len + 1);
	return (dest);
}

/* function to make one long string out of two short strings */

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	int		b;
	char	*result;

	b = 0;
	i = 0;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	result = malloc(j + k + 1);
	if (result == 0)
		return (result);
	while (i < j)
	{
		result[i] = s1[i];
		i++;
	}
	while (i <= j + k)
	{
		result[i] = s2[b];
		i++;
		b++;
	}
	return (result);
}
