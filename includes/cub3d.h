/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:09:32 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/10 17:58:14 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define PI 3.14159265
# define OR 1.61803398

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_Q 12
# define KEY_E 14
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ENTER 36
# define KEY_SPACE 49
# define KEY_ESC 53

# define MOV_UP 0b00000001
# define MOV_DOWN 0b00000010
# define MOV_LEFT 0b00000100
# define MOV_RIGHT 0b00001000
# define TURN_LEFT 0b00010000
# define TURN_RIGHT 0b01000000

# define SPEED 0.1
# define SPEEDTURN 0.07535

# define X_RES 25600
# define Y_RES 14400

# include <errno.h>
# include <math.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"


// SPRITES VAR
typedef struct s_var
{
	float	spriteX;
	float	spriteY;
	float	invDet;
	float	transformX;
	float	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		texY;
	int		d;
}				t_var;

// LIST SPRITES
typedef struct 	s_sprite
{
	float			x;
	float			y;
	int				id;
	t_var			var;
	struct s_sprite	*next;
}					t_sprite;

// MAP
typedef struct	s_map
{
	char		**map;
	int			line;
	int			collumn;
}				t_map;

// COLLUMN PXL
typedef struct s_col
{
	int	x;
	int	start;
	int	size_max;
	int	color;
}				t_col;

// WINDOWS
typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	int		keypress;
}				t_win;

// VECTOR
typedef struct	s_vector 
{
	float	x;
	float	y;
}				t_vector;

// RAY
typedef struct	s_ray
{
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
	float	cameraX;
	float	rayDirX;
	float	rayDirY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	float	perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		nb_player;
	char	camera;
}				t_ray;

// IMAGE
typedef struct	s_img
{
	char	*road;
	void	*img;
	int		*addr;
	int		w;
	int		h;
	int		endian;
	int		bytes;
	int		sizeline;
}				t_img;

// WALL_SIZE
typedef struct s_wall
{
	int	start;
	int	stop;
	int	height;
}
				t_wall;

//TEXTURES
typedef	struct		s_texture
{
	t_img			cardino[4];
	t_wall			wall;
	float			wallX;
	float			step;
	float			texPos;
	int				texWidth;
	int				texHeight;
	int				texNum;
	int				texX;
	int				texY;
	int				f[3];
	int				c[3];
	int				floor;
	int				ceiling;
	char			*sprite;
}					t_texture;

//ALL
typedef struct	s_global
{
	t_map		map;
	t_win		win;
	t_texture	tex;
	t_ray		ray;
	t_sprite	sprite;
	int			zbuffer[X_RES];
}				t_g;

// ft_error.c
void	ft_err(int err);

// tools.c
void	skip_space_eol(char *s);
int		iscardino(t_g *g, char *s, int nb);
int		is_wall(t_g g, int x, int y);

// mlx_tools.c
void	my_pixel_put(t_win *win, int x, int y, int color);
// void	clear_window(t_g *g);
void	close_window(t_g *g);
void	draw_col(t_win *win, t_col col);
// void	draw_col(t_g *g, int x, int start, int stop, int color);
t_img	*open_xpm(void *mlx_ptr, char *cardino);

// move.c
void	mov_updown(t_g *g, int neg);
void	mov_lateral(t_g *g, int neg);
void	rot_view(t_g *g, int neg);

// windows.c
void	new_win(t_g *g);
void	get_wall_size(int x_win, t_g *g);

// raycasting.c
float	ft_dda(t_g *g, int x_win);

// test.c
void	ft_print_struct_p(t_g g);
int		ft_print_map(t_g g);
// void	ft_print_struct_p(t_g g);
// void	ft_print_player(t_g g);
void	ft_print_img(t_g g);
void	test(t_g g);

// key_event_move.c
void	move(t_g *g);
int		key_deal(int key, void *param);
int		key_death(int key, void *param);

// minimap
int		minimap(t_g *g);

// inti_texture.c
void	get_texture(t_g *g);
// texture.c
void	ft_dda_x_inf_y(t_ray *ray);
void	ft_dda_x_sup_y(t_ray *ray);
void	draw_wall(t_g *g, int x);
void	draw_screen(t_g *g);

// ft_init_struct.c
void	ft_init_player(t_ray *ray, t_map *map, int i);
void	ft_init_global(t_g *global);

// ft_read_map.c
void	ft_complet_data(t_g *g, char *line);
void	ft_complet_map(t_g *g, char *line);

// Cub3d.c
void	ft_cub(int fd);

void	draw_line(t_vector p0, t_vector p1, t_g *g, int rgb);
#endif
