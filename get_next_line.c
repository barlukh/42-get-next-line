/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/15 13:18:41 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		i;
	static char	buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	size_t		len;
	char 		*substr;

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
	len = ft_strchr(&buffer[i], '\n') - &buffer[i] + 1;
	substr = create_substr(&buffer[i], len);
	if (!substr)
		return (NULL);
	while (len > 0 && i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
		len--;
	}
	return (substr);
}
