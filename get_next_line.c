/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/14 11:58:54 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*cache;
	ssize_t		bytes_read;
	ssize_t		i;
	char		*ret;

	if (cache == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			return (NULL);
		cache = ft_strdup(buffer);
	}

	i = 0;
	while (*cache != '\n' && i < bytes_read)
	{
		cache++;
		i++;
	}
	ret = ft_substr(cache - i, 0, i + 1);
	cache++;
	return (ret);
}
