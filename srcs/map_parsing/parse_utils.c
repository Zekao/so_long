/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:23:24 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 03:56:24 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

static int ft_count_size(char *argv)
{
    char *str;
    int i;
    int fd;

    i = 0;
	fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);	
	}
    free(str);
	close(fd);
	return (i);
}

char	**ft_fill_map(char *argv)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;
	int		size;
	
	size = ft_count_size(argv);
	i = 0;
	fd = open(argv, O_RDONLY);
	map = malloc(sizeof(char *) * (size + 1));
	str = get_next_line(fd);
	while(str)
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free(str);
	close(fd);
	return (map);
}
