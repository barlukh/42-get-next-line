/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:44:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/21 17:12:06 by bgazur           ###   ########.fr       */
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
	var.cache = ft_substr(buffer[fd], ft_strchr(buffer[fd], '\0') - buffer[fd]);
	if (!var.cache)
		return (free(buffer[fd]), buffer[fd] = NULL);
	get_next_line_read(fd, buffer[fd], &var);
	if (!var.cache)
		return (free(buffer[fd]), buffer[fd] = NULL);
	var.substr = ft_substr(var.cache, var.br - var.cache + 1);
	if (!var.substr)
		return (free(var.cache), var.cache = NULL);
	ft_memcpy(buffer[fd], var.br + 1, ft_strchr(var.br + 1, '\0') - var.br);
	return (free(var.cache), var.substr);
}
