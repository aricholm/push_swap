/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:02:37 by aricholm          #+#    #+#             */
/*   Updated: 2021/08/24 17:16:23 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;
	char	*dst;

	if (!s)
		return (0);
	i = 0;
	src = (void *)s;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*src;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	src = (void *)s;
	ptr = malloc(ft_strlen(src) + 1);
	if (!ptr)
		return (0);
	while (src[i] != 0)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	dst = malloc(len + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = ((char *)s1)[i];
		i++;
	}
	i = 0;
	while (((char *)s2)[i])
	{
		dst[len + i] = ((char *)s2)[i];
		i++;
	}
	dst[len + i] = 0;
	return (dst);
}
