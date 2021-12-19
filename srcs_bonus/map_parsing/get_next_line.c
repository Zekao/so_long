/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:24:09 by emaugale          #+#    #+#             */
/*   Updated: 2021/11/26 20:16:04 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check(char *memory, int fd)
{
	char	*buffer;
	int		bytescopy;

	bytescopy = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(memory, '\n') <= 0 && bytescopy)
	{
		bytescopy = read(fd, buffer, BUFFER_SIZE);
		if (bytescopy == -1)
			return (ft_free(buffer));
		buffer[bytescopy] = '\0';
		memory = ft_strjoin(memory, buffer, 0, -1);
	}
	free(buffer);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = ft_check(memory, fd);
	if (!memory)
		return (ft_free(memory));
	line = ft_get_line(memory);
	memory = ft_get_next(memory);
	return (line);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}
