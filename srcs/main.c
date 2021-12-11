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
	int     pix = 32;
		t_maps	map;

	a = 0;
	b = 0;
	i = -1;
	map.wall = mlx_xpm_file_to_image(mlx, "imgs/map-32.xpm", &a, &b);
	map.bg = mlx_xpm_file_to_image(mlx, "imgs/map2-32.xpm", &a, &b);
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

int	close(int keycode, t_vars *vars)
{
	printf ("keycode : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->character);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
void    init_img(void)
{
	int     a;
	int     b;
	t_img	img;

	a = 96;
	b = 96;
	img.mlx = mlx_init();
	img.character = mlx_xpm_file_to_image(img.mlx, "imgs/movement-1.xpm", &a, &b);
	img.win = mlx_new_window(img.mlx, 32 * 32, 32 * 32, "So_long");
	put_surrounding(img.mlx, img.win, 32, 32);
	mlx_put_image_to_window(img.mlx, img.win, img.character, 50, 50);
	mlx_hook(img.win, 2, 1L<<0, close, &img);
		mlx_loop(img.mlx);
}

int     main(void)
{
	/*if (ac != 2)
	  {
	  write(1, "Input Error", 11);
	  return (0);
	  }*/
	/*if (ft_checkfile(av[1]) == 0)
	  {
	  printf("(Input Errror : File is not a .ber)\n");
	  return (0);
	  }*/
	init_img();
}