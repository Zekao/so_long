#ifndef SO_LONG_H
# define SO_LONG_H


typedef struct s_player
{
	int	pos;

	int	C;
	int	moves;
	int	*Cpos;
	int	*Epos;
}	t_player;

typedef struct s_map
{
	int	x;
	int	y;
	int	px;
	int py;
	int	Cmax;
	int	Pmax;
	int	Emax;
	t_player	user;
}	t_map;

typedef	struct s_img
{
	void	*mlx;
	void	*window;
	void	*start;
	void	*win;
	void	*lose;
	void	*bg;
	void	*wall;
	void	*player1;
	void	*player2;
	void	*exit1;
	void	*exit2;
	void	*col;
}	t_img;

#endif