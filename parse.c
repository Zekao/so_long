/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:37:18 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/11 23:15:15 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>

static int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

int ft_check_top_bottom(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (0);
	while (str[i + 1])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'C' || str[i] == 'E' || str[i] == 'P')
			i++;
		return(0);
	}
	if (str[i] != '1')
		return (0);
	return (1);
	
}

int	ft_map_parse(char **map)
{
	int	i;

	i = 0;
	if (ft_check_top_bottom(map[i]) == 0)
		return (ft_error("Error : problem with the parsing of the map\n"));
	printf("map[%d] : good", i);
	i++;
	while(map[i])
	{
		if (ft_check_line(map[i]) == 0)
			return (ft_error("Error : prolem with the parsing of the map\n"));
		// printf("map[%d] : good", i);	
		i++;
	}
	return (1);
}