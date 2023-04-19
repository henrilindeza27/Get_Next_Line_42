/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:22 by hlindeza          #+#    #+#             */
/*   Updated: 2023/04/18 17:05:05 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (buffer[fd][i])
				buffer[fd][i++] = 0;
		}
		return (NULL);
	}
	while (buffer[fd][0] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_check_buffer(buffer[fd]))
			break ;
	}
	return (line);
}
