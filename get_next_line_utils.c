/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:40 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/19 13:09:01 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrd;
	const unsigned char	*ptrs;
	size_t				i;

	ptrd = (unsigned char *)dest;
	ptrs = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *cache, char *buffer)
{
	size_t	cache_len;
	char	*new_cache;

	if (!cache || !buffer)
		return (NULL);
	cache_len = ft_strlen(cache);
	new_cache = malloc(sizeof(char) * (cache_len + BUFFER_SIZE + 1));
	if (!new_cache)
		return (NULL);
	ft_memcpy(new_cache, cache, cache_len);
	free(cache);
	ft_memcpy(new_cache + cache_len, buffer, BUFFER_SIZE);
	new_cache[cache_len + BUFFER_SIZE] = '\0';
	return (new_cache);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*new_substr(char const *cache, size_t len)
{
	char	*substr;
	size_t	i;

	if (!cache)
		return (NULL);
	substr = malloc(sizeof(char) * (len + 2));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		substr[i] = cache[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
