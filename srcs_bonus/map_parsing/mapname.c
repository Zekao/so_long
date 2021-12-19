/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:46:46 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/19 04:32:36 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../include/get_next_line.h"

int	ft_namecheck(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (ft_error("Error : Problem with the map name"));
	while (file[i])
		i++;
	i--;
	if ((file[i] != 'r' && file[i - 1] != 'e' && file[i - 2]
			!= 'b' && file[i - 3] != '.') || ft_strlen(file) < 4)
		return (ft_error("Error : Problem with the map name"));
	return (1);
}
