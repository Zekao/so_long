/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 01:12:08 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/19 04:33:09 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(int keycode, t_img *vars)
{
	if (keycode == 53 || keycode < 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_close_cross(t_img *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("you have clicked on the red cross.\n");
	exit(0);
}
