/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:08:42 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 06:37:06 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int movement_handler_left(t_calculs *vars, int x, int y)
{
	if (ft_check_collision(vars->map[y][x], vars->map[y][x - 1]) == 0)
		return (0);
	else if (ft_check_collision(vars->map[y][x], vars->map[y][x - 1]) == 2)
	{
		ft_replace_collectible_left(vars, x, y);
		vars->stuff.collnbr++;
	}
	else if (ft_check_collision(vars->map[y][x], vars->map[y][x - 1]) == 42)
	{
		if (vars->stuff.collnbr == vars->stuff.collnbrmax)
			ft_success("congratulations, you won. now you can go to sleep");
	}
	else
		ft_swap(&vars->map[y][x - 1], &vars->map[y][x]);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
	vars->x_size = ft_get_stuff_x(vars->map, 'P');
	vars->y_size = ft_get_stuff_y(vars->map, 'P');
	vars->calc1 = (vars->x_size % vars->x * 64);
	vars->calc2 = (vars->y_size % vars->y * 64);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win,
		 vars->img.character, vars->calc1, vars->calc2);
	return (1);
}

int movement_handler_right(t_calculs *vars, int x, int y)
{
	if (ft_check_collision(vars->map[y][x], vars->map[y][x + 1]) == 0)
		return (0);
	else if (ft_check_collision(vars->map[y][x], vars->map[y][x + 1]) == 2)
	{
		ft_replace_collectible_right(vars, x, y);
		vars->stuff.collnbr++;
	}
	else if (ft_check_collision(vars->map[y][x], vars->map[y][x + 1]) == 42)
	{
		if (vars->stuff.collnbr == vars->stuff.collnbrmax)
			ft_success("congratulations, you won. now you can go to sleep");
	}
	else 
		ft_swap(&vars->map[y][x + 1], &vars->map[y][x]);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, 
		vars->img.grass, vars->calc1, vars->calc2);
	vars->x_size = ft_get_stuff_x(vars->map, 'P');
	vars->y_size = ft_get_stuff_y(vars->map, 'P');
	vars->calc1 = (vars->x_size % vars->x * 64);
	vars->calc2 = (vars->y_size % vars->y * 64);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win,
		vars->img.character, vars->calc1, vars->calc2);
	return (1);
}

int movement_handler_up(t_calculs *vars, int x, int y)
{
	if (ft_check_collision(vars->map[y][x], vars->map[y - 1][x]) == 0)
		return (0);
	else if (ft_check_collision(vars->map[y][x], vars->map[y - 1][x]) == 2)
	{
		ft_replace_collectible_up(vars, x, y);
		vars->stuff.collnbr++;
	}
	else if (ft_check_collision(vars->map[y][x], vars->map[y - 1][x]) == 42)
	{
		if (vars->stuff.collnbr == vars->stuff.collnbrmax)
			ft_success("congratulations, you won. now you can go to sleep");
	}
	else
		ft_swap(&vars->map[y - 1][x], &vars->map[y][x]);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
	vars->x_size = ft_get_stuff_x(vars->map, 'P');
	vars->y_size = ft_get_stuff_y(vars->map, 'P');
	vars->calc1 = (vars->x_size % vars->x * 64);
	vars->calc2 = (vars->y_size % vars->y * 64);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);    
	return (1);
}

int movement_handler_down(t_calculs *vars, int x, int y)
{
	if (ft_check_collision(vars->map[y + 1][x], vars->map[y][x]) == 0)
		return (0);
	else if (ft_check_collision(vars->map[y][x], vars->map[y + 1][x]) == 2)
	{
		ft_replace_collectible_down(vars, x, y);
		vars->stuff.collnbr++;
	}
	else if (ft_check_collision(vars->map[y][x], vars->map[y + 1][x]) == 42)
	{
		if (vars->stuff.collnbr == vars->stuff.collnbrmax)
			ft_success("congratulations, you won. now you can go to sleep");
	}
	else
		ft_swap(&vars->map[y + 1][x], &vars->map[y][x]);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
	vars->x_size = ft_get_stuff_x(vars->map, 'P');
	vars->y_size = ft_get_stuff_y(vars->map, 'P');
	vars->calc1 = (vars->x_size % vars->x * 64);
	vars->calc2 = (vars->y_size % vars->y * 64);
	mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);
	return (1);
}