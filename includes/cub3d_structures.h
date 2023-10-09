/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:18:15 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/21 19:50:40 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

typedef struct s_img
{
	int		*addr;
	void	*new_img;
	int		bits_per_pixel;
	int		img_width;
	int		img_height;
	int		line_length;
	int		endian;

}	t_img;

typedef struct s_cub
{
	void	*win;
	void	*mlx;
	t_img	img;

}	t_cub;

typedef struct s_player
{
	double		posx;
	double		posy;
	double		angle;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		ray_dirx;
	double		ray_diry;
	double		deltadistx;
	double		deltadisty;
	double		move_speed;
	double		rotate_speed;
	double		side_distx;
	double		side_disty;
	double		perpwall;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
}	t_player;

typedef struct s_drawing
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wallx;
	double	step;
	double	texture_pos;
	int		text_x;
	int		text_y;
}	t_drawing;

typedef struct s_parsing
{
	int		map_fd;
	char	*full_map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*color_f;
	char	*color_c;
	char	*c_red;
	int		c_r;
	int		c_g;
	int		c_b;
	char	*c_green;
	char	*c_blue;
	char	*f_red;
	char	*f_green;
	char	*f_blue;
	int		f_r;
	int		f_b;
	int		f_g;
	char	**map_desc;
}	t_parsing;

typedef struct s_program_data
{
	t_cub		cub;
	t_player	*player;
	t_parsing	*parsed;
	t_drawing	*draw;
	int			**textures;
	int			**buff;
	int			reset;
	int			side;
	int			text_num;

}	t_program_data;

#endif