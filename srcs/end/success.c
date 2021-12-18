/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 06:22:30 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/18 06:34:44 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}

int ft_success(char *str)
{
    ft_putstr_fd(str, 1);
    exit (0);
}

int ft_get_nbr(char **str, char c)
{
    int res;
    int i;
    int j;

    
    i = 0;
    res = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == c)
                res++;
            j++;
        }
        i++;
    }
    return (res);
}