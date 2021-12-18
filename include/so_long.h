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
	void	*collectible;
	void	*grass;
	void	*exit;
}	t_img;
 
typedef	struct s_maps
{
	void	*wall;
	void	*bg;
}			t_maps;

typedef struct s_calculs
{
	int	x;
	int	y;
	int	x_size;
	int	y_size;
	int	calc1; // x
	int	calc2; // y
	char **map;
	t_img img;
}		t_calculs;

/*	My functions to check the content of my map */

int		ft_check_map_objects(char **str);
int		ft_error(char *str);
int		ft_namecheck(char *file);
int		ft_strstrsize(char **str);
char	**ft_fill_map(char *argv);
int 	ft_get_stuff_x(char **map, char c);
int 	ft_get_stuff_y(char **map, char c);
int		ft_map_parse(char **map);
/*												*/
size_t	ft_strlen(char const *str);
#endif