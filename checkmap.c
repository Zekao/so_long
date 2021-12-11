/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:59:34 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/11 23:00:26 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_map_parse(char **map);

int ft_error(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
	char    **fullmap;
    char	*line;
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("couldn't open the map file"));
    line = get_next_line(fd);
	while (line)
        line = get_next_line(fd);
	fd = open(argv[1], O_RDONLY);
    fullmap = malloc(sizeof(char *) * i + 1);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        fullmap[i] = strdup(line);
        line = get_next_line(fd);
    }
    ft_map_parse(fullmap);
}