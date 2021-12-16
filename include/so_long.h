#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef	struct s_img
{
	void	*mlx;
	void	*win;
	void	*character;
}	t_img;

typedef	struct s_maps
{
	void	*wall;
	void	*bg;
}			t_maps;


/*	My functions to check the content of my map */
int	ft_check_map_objects(char **str);
int	ft_error(char *str);
int ft_namecheck(char *file);
int	ft_strstrsize(char **str);
char	**ft_fill_map(char *argv);
int ft_get_character_x(char **map);
int ft_get_character_y(char **map);
/*												*/

#endif