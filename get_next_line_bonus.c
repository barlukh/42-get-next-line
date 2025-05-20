/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:44:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/20 10:32:05 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	t_struct	var;

	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	var.len = 0;
	while (buffer[fd][var.len] != '\0')
		var.len++;
	var.cache = ft_substr(buffer[fd], var.len);
	if (!var.cache)
		return (NULL);
	get_next_line_read(fd, buffer[fd], &var);
	if (!var.cache)
		return (NULL);
	var.substr = ft_substr(var.cache, var.linebreak - var.cache + 1);
	var.len = 0;
	while (var.linebreak[var.len + 1] != '\0')
		var.len++;
	ft_memcpy(buffer[fd], var.linebreak + 1, var.len + 1);
	return (free(var.cache), var.substr);
}
