/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 02:57:59 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 06:17:56 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_check_collision(int current, int next)
{
    int res;
    
    res = current + next;
    printf("valeur de res : %d\n", res);
    if (res == 129)
        return (0);
    else if (res == 147)
        return (2);
    else if (res == 149)
        return (42);
    return (1);
}