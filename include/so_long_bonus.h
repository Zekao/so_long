/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:10:20 by emaugale          #+#    #+#             */
/*   Updated: 2021/12/19 04:39:35 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*left;
	void	*right;
	void	*up;
	void	*down;
	void	*collectible;
	void	*grass;
	void	*wall;
}	t_img;

typedef struct s_maps
{
	void	*wall;
	void	*bg;
	void	*coll;
	void	*exit;
	int		life;
	void	*ennemy;
	int		collnbr;
	int		collnbrmax;
}			t_maps;

typedef struct s_calculs
{
	int		x;
	int		y;
	int		x_size;
	int		y_size;
	int		calc1;
	int		calc2;
	int		move;
	char	**map;
	t_img	img;
	t_maps	stuff;
}		t_calculs;

/*	My functions to check the content of my map */

int		ft_check_map_objects(char **str);
int		ft_error(char *str);
int		ft_namecheck(char *file);
int		ft_strstrsize(char **str);
char	**ft_fill_map(char *argv);
int		ft_get_stuff_x(char **map, char c);
int		ft_get_stuff_y(char **map, char c);
int		ft_map_parse(char **map);

/* My functions to move on my map */
int		movement_handler_right(t_calculs *vars, int x, int y);
int		movement_handler_left(t_calculs *vars, int x, int y);
int		movement_handler_up(t_calculs *vars, int x, int y);
int		movement_handler_down(t_calculs *vars, int x, int y);

/* check if i can do my mouvement */
int		ft_check_collision(int current, int next);
/*												*/

/* Stuff for my collectibles */
int		ft_replace_collectible_right(t_calculs *vars, int x, int y);
int		ft_replace_collectible_left(t_calculs *vars, int x, int y);
int		ft_replace_collectible_up(t_calculs *vars, int x, int y);
int		ft_replace_collectible_down(t_calculs *vars, int x, int y);
int		ft_success(char *str);
int		ft_get_nbr(char **str, char c);

/*												*/
size_t	ft_strlen(char const *str);
void	ft_swap(char *a, char *b);
char	*ft_itoa(int nbr);
void	*ft_put_img(t_calculs *calc, char *path);
int		ft_move(int keycode, t_calculs *vars);
void	*init_stuff(t_calculs *calc);
void	init_img(t_calculs *calc);
int		ft_close(int keycode, t_img *vars);
int		ft_close_cross(t_img *vars);
void	put_surrounding(t_calculs *mlx, int x, int y, char **maps);
void	put_surrounding2(t_calculs *mlx, int x, int y, char **maps);

#endif