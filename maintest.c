/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parenas- <parenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:19:51 by parenas-          #+#    #+#             */
/*   Updated: 2026/02/27 17:32:23 by parenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    char    *line;
    char    *archivo = "test.txt";
    int     fd;

    fd = open(archivo, O_RDONLY);
    // fd = 0;
    if (fd < 0)
    {
        printf("Error al abrir %s", archivo);
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return(0);
}
