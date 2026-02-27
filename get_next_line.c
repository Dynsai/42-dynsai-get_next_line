/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:07:45 by parenas-          #+#    #+#             */
/*   Updated: 2026/02/27 17:49:21 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
char	*_set_line(char *line_buffer);
size_t	ft_strlen(const char *s);
char	*free_ptr(char	**ptr_to_free);

char *get_next_line(int fd)
{
    static char *left_c;
    char *read_buffer;
    char *line;
    char *new_left;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    read_buffer = malloc(BUFFER_SIZE + 1);
    if (!read_buffer)
        return NULL;
    left_c = _fill_line_buffer(fd, left_c, read_buffer);
    free(read_buffer);
    if (!left_c)
        return NULL;
    new_left = _set_line(left_c);
    line = left_c;
    left_c = new_left;
    return line;
}

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
    char *tmp_buffer;
    ssize_t b_read;

    if (!left_c)
        left_c = ft_strdup("");
    while (!ft_strchr(left_c, '\n'))
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if (b_read == -1)
			return(free_ptr(&left_c));
        if (b_read == 0)
            break;
        buffer[b_read] = '\0';
        tmp_buffer = left_c;
        left_c = ft_strjoin(tmp_buffer, buffer);
        free(tmp_buffer);
    }
    if (left_c[0] == '\0')
        return(free_ptr(&left_c));
    return left_c;
}

char	*_set_line(char *line_buffer)
{
	char	*ptr_break;
	char	*line_after;
	int		size_before;
	int		size_after;

	ptr_break = ft_strchr(line_buffer, '\n');
	if (!ptr_break)
		return (NULL);
	size_before = ptr_break - line_buffer;
	size_after = ft_strlen(line_buffer) - (size_before + 1);
	line_after = ft_substr(line_buffer, size_before + 1, size_after);
	line_buffer[size_before + 1] = '\0';
	return (line_after);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*free_ptr(char	**ptr_to_free)
{
	free(*ptr_to_free);
	*ptr_to_free = NULL;
	return (NULL);
}
