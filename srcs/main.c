/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:30:47 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/10 19:30:47 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    put_surrounding(void *mlx, void *mlx_win, int x, int y, char **maps)
{
	int     i;
	int     a;
	int     b;
	int     pix = 64;
	t_maps	map;

	a = 0;
	b = 0;
	i = -1;
	map.wall = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &a, &b);
	map.bg = mlx_xpm_file_to_image(mlx, "imgs/grass.xpm", &a, &b);
	map.coll = mlx_xpm_file_to_image(mlx, "imgs/collectible.xpm", &a, &b);
	map.exit = mlx_xpm_file_to_image(mlx, "imgs/exit.xpm", &a, &b);
	map.collnbrmax = 0;
	map.collnbr = 0;
	while (++i < y) //GAUCHE ET DROITE
	{
		mlx_put_image_to_window(mlx, mlx_win, map.wall, 0, pix * i);//cote gauche
		mlx_put_image_to_window(mlx, mlx_win, map.wall, (x - 1) * pix, pix * i);//cote droit
	}
	int     j;

	j = -1;
	while (++j < x) //HAUT ET BAS
	{
		mlx_put_image_to_window(mlx, mlx_win, map.wall, pix * j, 0);
		mlx_put_image_to_window(mlx, mlx_win, map.wall, pix * j, (y - 1) * pix);
	}
	int     f;
	int     g;

	f = 1;
	while (f < x - 1)
	{
		g = 1;
		while (g < y - 1)
		{
			if (maps[g][f] == '1')
				mlx_put_image_to_window(mlx, mlx_win, map.wall, pix * f, pix * g);
			else if (maps[g][f] != '1')
				mlx_put_image_to_window(mlx, mlx_win, map.bg, pix * f, pix * g);
			if (maps[g][f] == 'C')
			{
				map.collnbrmax++;
				mlx_put_image_to_window(mlx, mlx_win, map.coll, pix * f, pix * g);
			}
			if (maps[g][f] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, map.exit, pix * f, pix * g);
			g++;
		}
		f++;
		}
}

int	ft_close(int keycode, t_img *vars)
{
	// printf ("keycode : %d\n", keycode);
	if (keycode == 53 || keycode < 0)
	{
		// mlx_destroy_image(vars->mlx, vars->character);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	ft_swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_move(int keycode, t_calculs *vars)
{
	int	x;
	int y;
	static int move = 0;

	x = vars->x_size;
	y = vars->y_size;
	if (keycode == 0 && movement_handler_left(vars, x, y) == 1)
		printf("number of movements : %d\n", ++move);
	else if (keycode == 2 && movement_handler_right(vars, x, y) == 1)
		printf("number of movements : %d\n", ++move);
	else if (keycode == 13 && movement_handler_up(vars, x, y) == 1)
		printf("number of movements : %d\n", ++move);
	else if (keycode == 1 && movement_handler_down(vars, x, y) == 1)
		printf("number of movements : %d\n", ++move);
	return (0);
}

int	ft_close_cross(t_img *vars)
{
	// mlx_destroy_image(vars->mlx, vars->left);
	mlx_destroy_window(vars->mlx, vars->win);
	printf("you have clicked on the red cross.\n");
	exit(0);
}

void    init_img(t_calculs *calc)
{

	calc->x = ft_strlen(calc->map[1]) - 1;
	calc->y = ft_strstrsize(calc->map);
	calc->x_size = ft_get_stuff_x(calc->map, 'P');
	calc->y_size = ft_get_stuff_y(calc->map, 'P');
	calc->stuff.collnbrmax = ft_get_nbr(calc->map, 'C');
	calc->calc1 = (calc->x_size % calc->x * 64);
	calc->calc2 = (calc->y_size % calc->y * 64);
	int	charsx = 0;
	int	charsy = 0;
	calc->img.mlx = mlx_init();
	calc->img.grass = mlx_xpm_file_to_image(calc->img.mlx, "imgs/grass.xpm", &charsx, &charsy);
	calc->img.left = mlx_xpm_file_to_image(calc->img.mlx, "imgs/left.xpm", &charsx, &charsy);
	calc->img.right = mlx_xpm_file_to_image(calc->img.mlx, "imgs/right.xpm", &charsx, &charsy);
	calc->img.up = mlx_xpm_file_to_image(calc->img.mlx, "imgs/back.xpm", &charsx, &charsy);
	calc->img.down = mlx_xpm_file_to_image(calc->img.mlx, "imgs/front.xpm", &charsx, &charsy);
	calc->img.win = mlx_new_window(calc->img.mlx, calc->x * 64, calc->y * 64, "so_long");
	put_surrounding(calc->img.mlx, calc->img.win, calc->x, calc->y, calc->map);
	mlx_put_image_to_window(calc->img.mlx, calc->img.win, calc->img.left, calc->calc1, calc->calc2);
	mlx_hook(calc->img.win, 2, 1L<<0, ft_close, &calc->img);
	mlx_hook(calc->img.win, 17, 0L, ft_close_cross, &calc->img);
	mlx_key_hook(calc->img.win, ft_move, calc);
	mlx_loop(calc->img.mlx);
}

int     main(int argc, char **argv)
{
	t_calculs calc;

	(void)argc;
	calc.map = ft_fill_map(argv[1]);
	if(!ft_map_parse(calc.map) || !ft_check_map_objects(calc.map) || !ft_namecheck(argv[1]))
		return (0);
	init_img(&calc);
	return (1);
}