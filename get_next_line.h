/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:53 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/20 08:11:04 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_struct
{
	char	*cache;
	char	*linebreak;
	ssize_t	read_bytes;
	char 	*substr;
} t_struct;

/** Copies bytes from one memory area to another; the areas must not overlap
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return Pointer to the destination memory area
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/** Calculates the length of a string
 * @param s String to calculate the length of
 * @return Number of bytes in the passed string
 */
size_t	ft_strlen(const char *s);

/** Concatenates two strings using dynamic memory allocation
 * @param cache String stored in cache (remnant of a previous read call)
 * @param buffer String in the buffer from the most recent read call
 * @param var Struct storing all helper variables
 * @return Pointer to the new string, 'NULL' if the allocation fails
 */
char	*ft_strjoin(char *cache, char *buffer, t_struct *var);

/** Scans a string for the first instance of 'c'
 * @param s String to search
 * @param c Character to search for, passed as an int
 * @return Pointer to the matching location, 'NULL' if no match
 */
char	*ft_strchr(const char *s, int c);

/** Creates a substring using dynamic memory allocation
 * @param s Source string for the substring
 * @param len Length of the substring
 * @return Pointer to the new substring, 'NULL' if the allocation fails
 */
char	*ft_substr(char const *s, size_t len);

/** Reads and returns a line from a file pointed to by a file descriptor
 * @param fd File descriptor to read data from
 * @return Read line (string)
 */
char	*get_next_line(int fd);

#endif
