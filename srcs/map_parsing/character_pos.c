/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:11:32 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/16 10:20:40 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_get_character_x(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'P')
                return (j);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_get_character_y(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'P')
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}