#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"

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

typedef	struct s_vars
{
	void	*mlx;
	void	*win;
	void	*character;
}				t_vars;
#endif