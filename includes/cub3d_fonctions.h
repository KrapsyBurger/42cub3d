/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_fonctions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:09:42 by ychibani          #+#    #+#             */
/*   Updated: 2022/11/22 22:04:32 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FONCTIONS_H
# define CUB3D_FONCTIONS_H

/*
**				Mlx
*/

int				__mlx_init(t_cub *cub);
int				__move_little_square(int key_hook, t_program_data *data);
int				__close_little_window(t_program_data *data);
int				__put_image_to_window(t_program_data *data);
unsigned long	__create_rgb(int r, int g, int b);

/*
**				Movements
*/

void			__up_hook(t_program_data *data, t_player *player);
void			__down_hook(t_program_data *data, t_player *player);
void			__rotate_right_hook(t_player *player);
void			__rotate_left_hook(t_player *player);
void			__left_hook(t_program_data *data, t_player *player);

/*
**				Parsing
*/

int				__parameter_analyse(int ac, char **av);
void			__usage(void);

/*
**				Init
*/

int				__init_cub3d(t_program_data *data, char **av);
void			__init_parsing_struct(t_parsing *data);
void			__init_user_pos(t_player *player, t_program_data *data);
int				__init_user(t_program_data *data, t_player *player);
int				__init_buf(t_program_data *data);
void			__init_drawing_data(t_program_data *data, int x);
void			__dir(t_player *player, char c);
void			__face_west(t_player *player);
void			__face_east(t_player *player);
void			__face_south(t_player *player);
void			__face_north(t_player *player);

/*		
**				Parsing
*/		

char			*__ft_strjoin(char *s1, char *s2, int b);
char			*__fill_string(int fd);
int				__cub_checker(char *s);
void			__usage(void);
void			__jump_to_next_elem(char *s, int *len, int *start);
int				__elem_compare(char *elem);
void			__sub_and_trim(char **s1, t_parsing *data, int len, int start);
void			__elem_saving(t_parsing *data, int *len, int direction);
int				__no_so_parse(t_parsing *data, int *len, int *start);
int				__we_ea_parse(t_parsing *data, int *len, int *start);
int				__f_c_parse(t_parsing *data, int *len, int *start);
int				__first_last_line_check(char *s);
int				__idx_positioning_and_malloc(t_parsing *data, int *len,
					int *start, int *line_counter);
int				__parsing(t_program_data *data, int len);
int				__map_opening(t_parsing *data, char *s);
int				__map_end(char **map);
int				__map_desc_parse(t_parsing *data, int len, int start);
int				__map_valid_elem_compare(int one, int player, int zero);
int				__map_valid_elem_in_map_check(char **map, int t_i, int s_i);
int				__map_char_checker(char **map, int tab_idx, int string_idx);
int				__map_char_check_around(char **map,
					int tab_idx, int string_idx, char c);
int				__map_check_around_helper(char **map, int tab_idx,
					int string_idx, char c);
int				__is_map_closed_check(char **map);
int				__is_there_space(char *s, int a);
int				__elements_check(t_parsing *data);
int				__is_there_enough_values(char *s,
					int commas, int i, int values);
void			__rgb_c_getter(t_parsing *data);
void			__rgb_f_getter(t_parsing *data);
int				__load_textures(t_program_data *data);

/*		
**			Quit
*/		

void			__quit(t_program_data *data);

/*		
**			Clean
*/		

void			__free_int_tab(int **tab, int *index);
void			__free(void *addr);
void			__free_parsing_struct(t_parsing *data);

/*		
**			Draw
*/		

void			__draw_pixel(t_cub *cub, int x, int y, int color);
int				__put_image_to_window(t_program_data *data);

/*		
**			Game
*/		

int				__raycast_loop(t_program_data *data);
int				__dda(t_program_data *data, t_player *player);

/*		
**			Utils
*/		

size_t			__get_time(void);

#endif