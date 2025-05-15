/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:53 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/14 14:47:00 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/** Copies bytes from one memory area to another; the areas must not overlap
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return Pointer to the destination memory area
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/** Scans a string for the first instance of 'c'
 * @param s String to search
 * @param c Character to search for, passed as an int
 * @return Pointer to the matching location, 'NULL' if no match
 */
char	*ft_strchr(const char *s, int c);

/** Duplicates a string using dynamic memory allocation
 * @param s String to duplicate
 * @return Pointer to the duplicated string, 'NULL' if the allocation fails
 */
char	*ft_strdup(const char *s);

/** Calculates the length of a string
 * @param s String to calculate the length of
 * @return Number of bytes in the passed string
 */
size_t	ft_strlen(const char *s);

/** Creates a substring using dynamic memory allocation
 * @param s String to make the substring from
 * @param start Starting index
 * @param len Length of the substring
 * @return Pointer to the new substring, 'NULL' if the allocation fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/** Reads and returns a line from a file pointed to by a file descriptor
 * @param fd File descriptor to read from
 * @return String (line) that was read
 */
char	*get_next_line(int fd);

#endif
