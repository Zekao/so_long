/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:37:18 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/16 11:31:19 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

int	ft_strstrsize(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int ft_check_top_bottom(char **str)
{
	int	i;
	char	*last;
	char	*first;
	
	first = str[0];
	// printf("premiere ligne : %s\n", first);
	last = str[ft_strstrsize(str) - 1];
	// printf("derniere ligne : %s\n", last);
	if (ft_strstrsize(str) - 1 < 1)
		return (0);
	i = 0;
	while (first[i + 1])
	{
		if (first[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (last[i])
	{
		if (last[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (0);
	i++;
	while (str[i + 1])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' 
			&& str[i] != 'E' && str[i] != 'P')
			return (0);
		i++;
	}
	if (str[i - 1] != '1')
		return (0);
	return (1);
	
}

int	ft_map_parse(char **map)
{
	int	i;

	i = 0;
	if (ft_check_top_bottom(map) == 0)
		return (ft_error("Error : problem with the parsing of first/last line of the map.\n"));
	i++;
	while(map[i])
	{
		if (ft_check_line(map[i]) == 0)
			return (ft_error("Error : prolem with the parsing of the map.\n"));
		i++;
	}
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	char	**map;
// 	char	*str;
// 	int	i;

// 	i = 0;
// 	map = ft_fill_map(argv[1]);
// 	if(!ft_map_parse(map) || !ft_check_map_objects(map) || !ft_namecheck(argv[1]))
// 		return (0);
// }