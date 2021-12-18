/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 05:25:45 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 22:37:40 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_replace_collectible_right(t_calculs *vars, int x, int y)
{
	vars->map[y][x + 1] = 'P';
	vars->map[y][x] = '0';
	return (1);
}

int	ft_replace_collectible_left(t_calculs *vars, int x, int y)
{
	vars->map[y][x - 1] = 'P';
	vars->map[y][x] = '0';
	return (1);
}

int	ft_replace_collectible_up(t_calculs *vars, int x, int y)
{
	vars->map[y - 1][x] = 'P';
	vars->map[y][x] = '0';
	return (1);
}

int	ft_replace_collectible_down(t_calculs *vars, int x, int y)
{
	vars->map[y + 1][x] = 'P';
	vars->map[y][x] = '0';
	return (1);
}
