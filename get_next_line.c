/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/19 16:53:45 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_tools		var;

	var.cache = ft_substr(buffer, ft_strlen(buffer));
	var.linebreak = ft_strchr(var.cache, '\n');
	while (var.linebreak == NULL)
	{
		var.read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (var.read_bytes < 1)
		{
			if (*var.cache)
			{
				var.linebreak = ft_strchr(var.cache, '\0');
				break ;
			}
			return (free(var.cache), NULL);
		}
		var.cache = ft_strjoin(var.cache, buffer);
		if (!var.cache)
			return (NULL);
		var.linebreak = ft_strchr(var.cache, '\n');
	}
	var.substr = ft_substr(var.cache, var.linebreak - var.cache + 1);
	ft_memcpy(buffer, var.linebreak + 1, ft_strlen(var.linebreak + 1) + 1);
	return (free(var.cache), var.substr);
}
