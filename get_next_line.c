/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:16 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/21 20:31:54 by bgazur           ###   ########.fr       */
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
	line_read(fd, &buf, &var);
	if (!var.cache)
		return (NULL);
	var.substr = ft_substr(&var.cache, var.br - var.cache + 1);
	if (!var.substr)
		return (NULL);
	ft_memcpy(buf, var.br + 1, ft_strchr(var.br + 1, '\0') - var.br);
	return (free(var.cache), var.substr);
}
