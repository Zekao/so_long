/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 02:57:59 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 03:10:09 by emaugale         ###   ########.fr       */
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
    return (1);
}