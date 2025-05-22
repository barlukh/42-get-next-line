/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:44:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/22 10:48:08 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[MAX_FD];
	t_struct	var;

	if (!buf[fd])
	{
		buf[fd] = malloc(BUFFER_SIZE);
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	var.cache = ft_substr(&buf[fd], ft_strchr(buf[fd], '\0') - buf[fd]);
	if (!var.cache)
		return (NULL);
	if (line_read(fd, &buf[fd], &var) == NULL)
		return (NULL);
	var.substr = ft_substr(&var.cache, var.br - var.cache + 1);
	if (!var.substr)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	ft_memcpy(buf[fd], var.br + 1, ft_strchr(var.br + 1, '\0') - var.br);
	free(var.cache);
	return (var.substr);
}
