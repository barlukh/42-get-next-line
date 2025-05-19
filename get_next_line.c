/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/19 09:29:56 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_tools var;

	var.read_bytes = 1;
	var.cache = ft_strdup(buffer);
	var.linebreak = ft_strchr(var.cache, '\n');
	if (!var.linebreak)
	while (var.read_bytes > 0)
	{
		var.read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (var.read_bytes < 1)
			return (NULL);
		var.cache = ft_strjoin(var.cache, buffer);
		var.linebreak = ft_strchr(var.cache, '\n');
		if (var.linebreak != NULL)
			break ;
	}
	var.len = var.linebreak - var.cache;
	var.substr = new_substr(var.cache, var.len + 1);
	ft_memcpy(buffer, var.linebreak + 1, ft_strlen(var.linebreak + 1) + 1);
	return (var.substr);
}
