/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/22 10:15:13 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	t_struct	var;

	if (!buf)
	{
		buf = malloc(BUFFER_SIZE);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	var.cache = ft_substr(&buf, ft_strchr(buf, '\0') - buf);
	if (!var.cache)
		return (NULL);
	if (line_read(fd, &buf, &var) == NULL)
		return (NULL);
	var.substr = ft_substr(&var.cache, var.br - var.cache + 1);
	if (!var.substr)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	ft_memcpy(buf, var.br + 1, ft_strchr(var.br + 1, '\0') - var.br);
	free(var.cache);
	return (var.substr);
}
