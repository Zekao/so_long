/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:39:03 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/19 04:42:46 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../include/get_next_line.h"

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}

static int	ft_count_size(int nbr)
{
	int	size;

	size = 1;
	if (nbr == 0)
		return (2);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		size++;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	long int	nb;
	int			size;
	char		*str;

	nb = nbr;
	size = ft_count_size(nb);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		str[0] = '0';
	size--;
	str[size] = '\0';
	while (nb)
	{
		str[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}

int	ft_move(int keycode, t_calculs *vars)
{
	int			x;
	int			y;
	char		*move_number;
	static int	move = 0;

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
	mlx_put_image_to_window(vars->img.mlx, vars->img.win,
		vars->img.wall, 0, 0);
	move_number = ft_itoa(move);
	if (move_number != NULL)
	{
		mlx_string_put(vars->img.mlx, vars->img.win, 26, 18,
			0x00313500, move_number);
	}
	free(move_number);
	return (0);
}
