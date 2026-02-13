/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:07:45 by parenas-          #+#    #+#             */
/*   Updated: 2026/02/13 12:06:35 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// I can use read / malloc and free

char	*get_next_line(int fd)
{
	if (fd < 1)
		return (NULL);
}

char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	
}

char	*_set_line(char *line_buffer)
{
	
}
/*#include <fcntl.h>

int main(int argc, char **argv)
{
	pepe = open(lol.txt, una flag);
	getnelain(pepe);
}*/
