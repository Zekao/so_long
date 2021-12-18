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
	map.wall = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &a, &b);
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

static void	ft_swap(char *a, char *b)
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

	x = vars->x_size;
	y = vars->y_size;
	if (keycode == 0)
	{
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
		ft_swap(&vars->map[y][x - 1], &vars->map[y][x]);
		vars->x_size = ft_get_stuff_x(vars->map, 'P');
		vars->y_size = ft_get_stuff_y(vars->map, 'P');
		vars->calc1 = (vars->x_size % vars->x * 64);
		vars->calc2 = (vars->y_size % vars->y * 64);
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
		ft_swap(&vars->map[y][x + 1], &vars->map[y][x]);
		vars->x_size = ft_get_stuff_x(vars->map, 'P');
		vars->y_size = ft_get_stuff_y(vars->map, 'P');
		vars->calc1 = (vars->x_size % vars->x * 64);
		vars->calc2 = (vars->y_size % vars->y * 64);
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);
	}
	else if (keycode == 13)
	{
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
		ft_swap(&vars->map[y - 1][x], &vars->map[y][x]);
		vars->x_size = ft_get_stuff_x(vars->map, 'P');
		vars->y_size = ft_get_stuff_y(vars->map, 'P');
		vars->calc1 = (vars->x_size % vars->x * 64);
		vars->calc2 = (vars->y_size % vars->y * 64);
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);
	}
	else if (keycode == 1)
	{
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.grass, vars->calc1, vars->calc2);
		ft_swap(&vars->map[y + 1][x], &vars->map[y][x]);
		vars->x_size = ft_get_stuff_x(vars->map, 'P');
		vars->y_size = ft_get_stuff_y(vars->map, 'P');
		vars->calc1 = (vars->x_size % vars->x * 64);
		vars->calc2 = (vars->y_size % vars->y * 64);
		mlx_put_image_to_window(vars->img.mlx, vars->img.win, vars->img.character, vars->calc1, vars->calc2);
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

void    init_img(t_calculs *calc)
{

	calc->x = ft_strlen(calc->map[1]);
	calc->y = ft_strstrsize(calc->map);
	calc->x_size = ft_get_stuff_x(calc->map, 'P');
	calc->y_size = ft_get_stuff_y(calc->map, 'P');

	calc->calc1 = (calc->x_size % calc->x * 64);
	calc->calc2 = (calc->y_size % calc->y * 64);
	int	charsx = 0;
	int	charsy = 0;
	calc->img.mlx = mlx_init();
	calc->img.grass = mlx_xpm_file_to_image(calc->img.mlx, "imgs/grass.xpm", &charsx, &charsy);
	calc->img.character = mlx_xpm_file_to_image(calc->img.mlx, "imgs/character.xpm", &charsx, &charsy);
	// calc->x_size = ft_get_stuff_x(calc->map, 'C');
	// calc->y_size = ft_get_stuff_y(calc->map, 'C');
	//calc->img.collectible = mlx_xpm_file_to_image(calc->img.mlx, "imgs/cloder-chest.xpm", &calc->x_size, &calc->y_size);
	calc->img.win = mlx_new_window(calc->img.mlx, calc->x * 64, calc->y * 64, "so_long");
	put_surrounding(calc->img.mlx, calc->img.win, calc->x, calc->y);
	mlx_put_image_to_window(calc->img.mlx, calc->img.win, calc->img.character, calc->calc1, calc->calc2);
	mlx_hook(calc->img.win, 2, 1L<<0, ft_close, &calc->img);
	mlx_hook(calc->img.win, 17, 0L, ft_close_cross, &calc->img);
	mlx_key_hook(calc->img.win, ft_move, calc);
	printf("calc->>x : %d\n", calc->x_size);
	printf("calc->>y : %d\n", calc->y_size);
		mlx_loop(calc->img.mlx);
}

int     main(int argc, char **argv)
{
	t_calculs calc;

	int	i;

	(void)argc;
	i = 0;
	calc.map = ft_fill_map(argv[1]);
	if(!ft_map_parse(calc.map) || !ft_check_map_objects(calc.map) || !ft_namecheck(argv[1]))
		return (0);
	init_img(&calc);
}