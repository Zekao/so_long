/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:26:41 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 22:31:22 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

static int	ft_check_players(char **str)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

static int	ft_check_collectibles(char **str)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}

static int	ft_check_exit(char **str)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (exit);
}

int	ft_check_map_objects(char **str)
{
	if (ft_check_collectibles(str) < 1 || ft_check_exit(str) < 1
		|| ft_check_players(str) < 1 || ft_check_players(str) > 1)
		return (ft_error("Error : problem in the map content.\n"));
	return (1);
}
