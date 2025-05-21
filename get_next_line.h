/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:17:53 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/21 19:38:31 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_struct
{
	char	*cache;
	char	*br;
	ssize_t	read_bytes;
	char	*substr;
}	t_struct;

/** Reads and returns a line from a file pointed to by a file descriptor
 * @param fd File descriptor to read data from
 * @return Read line (string)
 */
char	*get_next_line(int fd);

/** Checks for a newline character or end of file, reads into the buffer
 * @param fd File descriptor to read data from
 * @param buffer Buffer to fill by the read call
 * @param var Struct storing all helper variables
 * @return None (return ;), 'NULL' on error
 */
void	get_next_line_read(int fd, char **buffer, t_struct *var);

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

/** Concatenates two strings using dynamic memory allocation
 * @param cache String stored in cache (remnant of a previous read call)
 * @param buffer String in the buffer from the most recent read call
 * @param var Struct storing all helper variables
 * @return Pointer to the new string, 'NULL' if the allocation fails
 */
char	*ft_strjoin(char *cache, char *buffer, t_struct *var);

/** Creates a substring using dynamic memory allocation
 * @param s Source string for the substring
 * @param len Length of the substring
 * @return Pointer to the new substring, 'NULL' if the allocation fails
 */
char	*ft_substr(char **s, size_t len);

#endif
