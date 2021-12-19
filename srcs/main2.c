/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:49:47 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/19 01:20:26 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_stuff(t_calculs *calc)
{
	calc->x = ft_strlen(calc->map[1]) - 1;
	calc->y = ft_strstrsize(calc->map);
	calc->x_size = ft_get_stuff_x(calc->map, 'P');
	calc->y_size = ft_get_stuff_y(calc->map, 'P');
	calc->stuff.collnbrmax = ft_get_nbr(calc->map, 'C');
	calc->calc1 = (calc->x_size % calc->x * 64);
	calc->calc2 = (calc->y_size % calc->y * 64);
	calc->img.mlx = mlx_init();
	calc->img.grass = ft_put_img(calc, "imgs/grass.xpm");
	calc->img.wall = ft_put_img(calc, "imgs/wall.xpm");
	calc->img.left = ft_put_img(calc, "imgs/left.xpm");
	calc->img.right = ft_put_img(calc, "imgs/right.xpm");
	calc->img.up = ft_put_img(calc, "imgs/back.xpm");
	calc->img.down = ft_put_img(calc, "imgs/front.xpm");
	calc->img.win = mlx_new_window(calc->img.mlx, calc->x * 64,
			calc->y * 64, "so_long");
	return (calc);
}

void	init_img(t_calculs *calc)
{
	calc = init_stuff(calc);
	put_surrounding(calc, calc->x, calc->y, calc->map);
	mlx_put_image_to_window(calc->img.mlx, calc->img.win, calc->img.left,
		calc->calc1, calc->calc2);
	mlx_hook(calc->img.win, 2, 1L << 0, ft_close, &calc->img);
	mlx_hook(calc->img.win, 17, 0L, ft_close_cross, &calc->img);
	mlx_key_hook(calc->img.win, ft_move, calc);
	mlx_loop(calc->img.mlx);
}
