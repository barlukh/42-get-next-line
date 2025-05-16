/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/16 16:47:03 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	static char	buffer[BUFFER_SIZE];
	// char		*cache;
	// size_t		len;
	// char		*linebreak;
	// char 		*substr;
	t_tools tools;

	read_bytes = 1;
	cache = ft_strdup(buffer);
	// linebreak = ft_strchr(cache, '\n');
	// if (!linebreak)
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 1)   // why 1
			return (NULL);
		cache = ft_strjoin(cache, buffer);   // free cache
		linebreak = ft_strchr(cache, '\n');
		if (linebreak != NULL)
			break ;
	}
	len = linebreak - cache;
	substr = create_substr(cache, len + 1);
	ft_memcpy(buffer, linebreak + 1, ft_strlen(linebreak + 1) + 1); // study this
	return (substr);
}
