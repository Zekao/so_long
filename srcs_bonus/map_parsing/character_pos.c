/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:11:32 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 22:24:14 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_stuff_x(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_get_stuff_y(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
