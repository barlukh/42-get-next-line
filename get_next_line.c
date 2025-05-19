/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/19 13:07:02 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_tools		var;
	static char	buffer[BUFFER_SIZE];

	var.cache = new_substr(buffer, ft_strlen(buffer));
	var.linebreak = ft_strchr(var.cache, '\n');
	if (!var.linebreak)
	{
		while (true)
		{
			var.read_bytes = read(fd, buffer, BUFFER_SIZE);
			if (var.read_bytes < 1)
				return (NULL);
			var.cache = ft_strjoin(var.cache, buffer);
			if (!var.cache)
				return (NULL);
			var.linebreak = ft_strchr(var.cache, '\n');
			if (var.linebreak != NULL)
				break ;
		}
	}
	var.substr = new_substr(var.cache, var.linebreak - var.cache);
	ft_memcpy(buffer, var.linebreak + 1, ft_strlen(var.linebreak + 1) + 1);
	free(var.cache);
	return (var.substr);
}
