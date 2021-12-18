/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:39:03 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 22:17:14 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
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
