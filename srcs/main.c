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

void	put_surrounding(t_calculs *mlx, int x, int y, char **maps)
{
	int		i;
	int		a;
	int		b;

	a = 0;
	b = 0;
	i = -1;
	mlx->stuff.wall = ft_put_img(mlx, "imgs/wall.xpm");
	mlx->stuff.bg = ft_put_img(mlx, "imgs/grass.xpm");
	mlx->stuff.coll = ft_put_img(mlx, "imgs/collectible.xpm");
	mlx->stuff.exit = ft_put_img(mlx, "imgs/exit.xpm");
	mlx->stuff.collnbrmax = 0;
	mlx->stuff.collnbr = 0;
	while (++i < y)
	{
		mlx_put_image_to_window(mlx->img.mlx, mlx->img.win,
			mlx->stuff.wall, 0, 64 * i);
		mlx_put_image_to_window(mlx->img.mlx, mlx->img.win,
			mlx->stuff.wall, (x - 1) * 64, 64 * i);
	}
	put_surrounding2(mlx, x, y, maps);
}

static void	n(t_calculs *m, void *p, int f, int g)
{
	mlx_put_image_to_window(m->img.mlx, m->img.win, p, 64 * f, 64 * g);
}

static void	put_surroundings3(t_calculs *mlx, int x, int y, char **maps)
{
	int	f;
	int	g;

	f = 1;
	while (f < x - 1)
	{
		g = 1;
		while (g < y - 1)
		{
			if (maps[g][f] == '1')
				n(mlx, mlx->stuff.wall, f, g);
			else if (maps[g][f] != '1')
				n(mlx, mlx->stuff.bg, f, g);
			if (maps[g][f] == 'C')
			{
				mlx->stuff.collnbrmax++;
				n(mlx, mlx->stuff.coll, f, g);
			}
			if (maps[g][f] == 'E')
				n(mlx, mlx->stuff.exit, f, g);
			g++;
		}
		f++;
	}
}

void	put_surrounding2(t_calculs *mlx, int x, int y, char **maps)
{
	int	j;

	j = -1;
	while (++j < x)
	{
		n(mlx, mlx->stuff.wall, j, 0);
		n(mlx, mlx->stuff.wall, j, (y - 1));
	}
	put_surroundings3(mlx, x, y, maps);
}

int	main(int argc, char **argv)
{
	t_calculs	calc;

	(void)argc;
	calc.map = ft_fill_map(argv[1]);
	if (!ft_map_parse(calc.map) || !ft_check_map_objects(calc.map)
		|| !ft_namecheck(argv[1]))
		return (0);
	init_img(&calc);
	return (1);
}
