/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/21 11:28:24 by bgazur           ###   ########.fr       */
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
	var.cache = ft_substr(buffer, ft_strchr(buffer, '\0') - buffer);
	if (!var.cache)
		return (NULL);
	get_next_line_read(fd, buffer, &var);
	if (!var.cache)
		return (NULL);
	var.substr = ft_substr(var.cache, var.br - var.cache + 1);
	if (!var.substr)
		return (free(var.cache), NULL);
	ft_memcpy(buffer, var.br + 1, ft_strchr(var.br + 1, '\0') - var.br);
	return (free(var.cache), var.substr);
}
