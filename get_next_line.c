/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/15 12:31:14 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	int			i;
	int			j;
	char 		*line;

	i = 0;
	while (buffer[i] == '\0' && i < BUFFER_SIZE)
		i++;
	if (i == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			return (NULL);
		i = 0;
	}
	while (buffer[i] == '\0' && i < BUFFER_SIZE)
		i++;
	j = ft_strchr(&buffer[i], '\n') - &buffer[i] + 1;
	line = ft_substr(&buffer[i], 0, j);
	while (j > 0 && i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
		j--;
	}
	return (line);
}
