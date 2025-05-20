/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/20 14:07:43 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	t_struct	var;

	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	var.len = 0;
	while (buffer[var.len] != '\0')
		var.len++;
	var.cache = ft_substr(buffer, var.len);
	if (!var.cache)
		return (NULL);
	get_next_line_read(fd, buffer, &var);
	if (!var.cache)
		return (NULL);
	var.substr = ft_substr(var.cache, var.linebreak - var.cache + 1);
	var.len = 0;
	while (var.linebreak[var.len + 1] != '\0')
		var.len++;
	ft_memcpy(buffer, var.linebreak + 1, var.len + 1);
	return (free(var.cache), var.substr);
}
