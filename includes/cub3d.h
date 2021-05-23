/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:09:32 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/22 21:47:16 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define PI 3.14159265
#define OR 1.61803398

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_W 13
#define KEY_Q 12
#define KEY_E 14
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_ENTER 36
#define KEY_SPACE 49
#define KEY_ESC 53

#define MOV_UP 0b00000001
#define MOV_DOWN 0b00000010
#define MOV_LEFT 0b00000100
#define MOV_RIGHT 0b00001000
#define TURN_LEFT 0b00010000
#define TURN_RIGHT 0b01000000

#define SPEED 0.2

#define X_RES 2560
#define Y_RES 1440

# include <errno.h>
# include <math.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

// PARSCING
typedef	struct	s_data
{
	int			w;
	int			h;
	char		*cardino[2][5];
	char		*sprite;
	int			f[3];
	int			c[3];
	int			floor;
	int			ceiling;
}				t_data;

typedef struct	s_map
{
	char		**map;
	int			line;
	int			collumn;
}				t_map;

typedef struct	s_player
{
	char		view;
	float		x;
	float		y;
	float		dirX;
	float		dirY;
	float		planeX;
	float		planeY;
	int			side;
	int			dir;
	int			nb;
}				t_player;


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
}				t_win;

// VECTOR
typedef struct	s_vector 
{
	float x;
	float y;
}				t_vector;

typedef struct	s_rc_var
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
}				t_rc_var;

// MOVE
typedef struct	s_mov
{
	int		rot_left;
	int		rot_right;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
}				t_mov;

// IMAGE
typedef struct	s_img
{
	char *road;
	void *img;
	
}				t_img;

//TEXTURES
typedef	struct		s_texture
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
	int		floor;
	int		ceiling;
}				t_texture;
//ALL
typedef struct	s_global
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_win		win;
	t_texture	img_c;
	t_mov		mov;
}				t_g;

// ft_error.c
void	ft_err(int err);

// ft_utils
double	ft_dda(t_g *g, int x_win, t_rc_var *var);
void	skip_space_eol(char *s);
int		iscardino(t_data *data, char *s, int nb);
void	my_pixel_put(t_win *win, int x, int y, int color);
int		is_wall(t_g g, int x, int y);

// windows.c
void	new_win(t_g *g);
void	close_window(t_g *g);

// move.c
void	mov_updown(t_g *g, int neg);
void	mov_lateral(t_g *g, int neg);
void	rot_view(t_g *g, int neg);

// test.c
void	ft_print_struct_p(t_g g);
int		ft_print_map(t_g g);
void	ft_print_struct_p(t_g g);
void	ft_print_player(t_g g);
void	ft_print_img(t_g g);
void	test(t_g g);

// key_event_move.c
void	move(t_g *g);
int		deal_key(int key, void *param);
int     death_key(int key, void *param);

// minimap
int		minimap(t_g *g);

// inti_texture.c
void	get_texture(t_g *g);

// ft_init_struct.c
void	ft_init_player(t_player *player);
void	ft_init_global(t_g *global);

// ft_read_map.c
int		ft_read_file(int fd, t_g *tg);

// Cub3d.c
void	ft_cub(int fd);

#endif
