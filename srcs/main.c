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

void    put_surrounding(void *mlx, void *mlx_win, int x, int y)
{
	int     i;
	int     a;
	int     b;
	int     pix = 64;
		t_maps	map;

	a = 0;
	b = 0;
	i = -1;
	map.wall = mlx_xpm_file_to_image(mlx, "imgs/map-32.xpm", &a, &b);
	map.bg = mlx_xpm_file_to_image(mlx, "imgs/grass.xpm", &a, &b);
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
			mlx_put_image_to_window(mlx, mlx_win, map.bg, pix * f, pix * g);
			g++;
		}
		f++;
		}
}

int	ft_close(int keycode, t_img *vars)
{
	printf ("keycode : %d\n", keycode);
	if (keycode == 53 || keycode < 0)
	{
		mlx_destroy_image(vars->mlx, vars->character);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_close_cross(t_img *vars)
{
	mlx_destroy_image(vars->mlx, vars->character);
	mlx_destroy_window(vars->mlx, vars->win);
	printf("you have clicked on the red cross.\n");
	exit(0);
}

void    init_img(char **map)
{
	int     x_size;
	int     y_size;
	int		x;
	int		y;
	t_img	img;

	x = ft_strlen(map[1]);
	y = ft_strstrsize(map);
	x_size = 8;
	y_size = 8;
	// x_pos = 96;
	// y_pos = 96;
	img.mlx = mlx_init();
	img.character = mlx_xpm_file_to_image(img.mlx, "imgs/movement-1.xpm", &x_size, &y_size);
	img.win = mlx_new_window(img.mlx, x * 64, y * 64, "So_long");
	put_surrounding(img.mlx, img.win, x, y);
	mlx_put_image_to_window(img.mlx, img.win, img.character, x, y);
	mlx_hook(img.win, 2, 1L<<0, ft_close, &img);
	mlx_hook(img.win, 17, 0L, ft_close_cross, &img);
		mlx_loop(img.mlx);
}

int     main(int argc, char **argv)
{
	char	**map;
	char	*str;
	int	i;

	i = 0;
	map = ft_fill_map(argv[1]);
	if(!ft_map_parse(map) || !ft_check_map_objects(map) || !ft_namecheck(argv[1]))
		return (0);
	init_img(map);
}