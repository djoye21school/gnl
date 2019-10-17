/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:49:54 by djoye             #+#    #+#             */
/*   Updated: 2019/09/21 17:08:54 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(argv[argc - 1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	close(fd);
}
