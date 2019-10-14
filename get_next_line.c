/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:25:18 by djoye             #+#    #+#             */
/*   Updated: 2019/09/21 16:59:12 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_line(const int fd, char **line, char **arr, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0')
		i++;
	if (arr[fd][i] == '\0' && len != BUFF_SIZE)
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	else if (arr[fd][i] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, i);
		tmp = ft_strdup(arr[fd] + i + 1);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*arr[10240];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			len;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (len < 0)
		return (-1);
	if (len == 0 && (arr[fd] == NULL || arr[fd][0] == '\0'))
		return (0);
	ft_line(fd, line, arr, len);
	return (1);
}
