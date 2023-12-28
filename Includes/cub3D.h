/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:20:13 by amonier           #+#    #+#             */
/*   Updated: 2023/12/11 17:23:08 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libft/Includes/libft.h"
# include <math.h>
# include <mlx.h>

# define WINDOW_WIDTH 720
# define WINDOW_LENGTH 1280
# define IMG_WIDTH 720
# define IMG_LENGTH 1280

# define SCREEN_L_PX 640
# define SCREEN_H_PX 360
# define CENTER_SCREEN_X (320)
# define CENTER_SCREEN_Y (180)

# define FOV 60.0
# define H_WALL 1.0
# define H_CAM 0.5

# define H_SPRITE 0.4
# define L_SPRITE 0.4

# define MOUV 0.1

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// creation mini map

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_square
{
	int	x_pixel_origin;
	int	y_pixel_origin;
	int	length_x_pixel;
	int	width_y_pixel;
}		t_square;

typedef struct s_column
{
	int		y;
	int		limit;
	int		color;
	t_data	*img;
	int		img_width;
	int		img_height;
	double	x_pos_img;
	int		x_in_texture;
	int		y_in_texture;
	int		y_begin;	
}			t_column;

typedef struct s_point_lst
{
	int					pixel_x;
	int					pixel_y;
	double				x_pos;
	double				y_pos;
	struct s_point_lst	*next;
}		t_point_lst;

typedef struct s_ray
{
	double	ray_x;
	double	ray_y;
	double	dist;
	double	sprite_dst;
}		t_ray;

typedef struct s_wall_lst
{
	double					x_start;
	double					y_start;
	double					x_end;
	double					y_end;
	double					norm_x;
	double					norm_y;
	struct s_wall_lst		*next;
}						t_wall_lst;

typedef struct s_sprite_lst
{
	int					pos_x;
	int					pos_y;
	double				center_x;
	double				center_y;
	double				norm_x;
	double				norm_y;
	double				vec_l_x;
	double				vec_l_y;
	double				x_begin;
	double				y_begin;
	double				x_end;
	double				y_end;
	struct s_sprite_lst	*next;
}			t_sprite_lst;

typedef struct s_ray_fov
{
	t_ray			*ray;
	double			original_dist;
	double			dist_cam_wall;
	t_wall_lst		*wall;
	int				height_wall_in_px;
	int				center_wall_y;
	int				resize_height_wall_px;
	int				resize_center_y;
	double			sprite_dist;
	t_sprite_lst	*sprite;
	int				sprite_height_in_px;
}				t_ray_fov;

typedef struct s_body
{
	double		center_x;
	double		center_y;
	double		diameter;
	t_ray		*front_ray;
	t_ray		*right_ray;
	t_ray		*left_ray;
	t_ray		*back_ray;
	t_ray_fov	*fov_tab;
	int			pixel_x_center;
	int			pixel_y_center;
	int			length_x_pixel;
	int			width_y_pixel;
	t_point_lst	*body_point;
}		t_body;

typedef struct s_player
{
	char	direction;
	int		x_pos;
	int		y_pos;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		size_x;
	int		size_y;	
}			t_map;

typedef struct s_texture
{
	char	*no;
	t_data	*img_no;
	int		no_width;
	int		no_height;
	char	*so;
	t_data	*img_so;
	int		so_width;
	int		so_height;
	char	*we;
	t_data	*img_we;
	int		we_width;
	int		we_height;
	char	*ea;
	t_data	*img_ea;
	int		ea_width;
	int		ea_height;
	char	*f;
	int		*ftab;
	char	*c;
	int		*ctab;
}			t_texture;

typedef struct s_pars
{
	char		**file;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	t_player	*player_info;
	int			map_close;
}			t_pars;

typedef struct s_img_sprite
{
	int		status;
	t_data	*img_one;
	int		img_one_width;
	int		img_one_height;
	t_data	*img_two;
	int		img_two_width;
	int		img_two_height;
	t_data	*img_three;
	int		img_three_width;
	int		img_three_height;
}			t_img_sprite;

typedef struct s_infos
{
	t_texture		*texture;
	t_player		*player;
	t_map			*map;
	t_body			*body_player;
	t_wall_lst		*wall;
	t_sprite_lst	*sprite;
	t_img_sprite	*img_sprite;
}				t_infos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_infos	*infos;
}			t_vars;
// vars permet de stocker des infos utils

// fonction a faire plus rapide selon la mlx doc:
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			clear_image(t_data *img);

//----------------------MLX---------------------------

void			init_window(t_vars *vars, t_data *img);
t_vars			*init_all(void);
void			destroy(t_vars *vars);

//-> HOOK

void			all_hook(t_vars *vars);
int				cross(t_vars *param);
int				mouse_hook(int keycode, int x, int y, t_vars *mlx);
int				keyboard(int keycode, t_vars *param);
void			destroy_tex(t_vars *vars);

//---------------------PARSING-------------------------
t_infos			*parsing(int argc, char **argv);
void			init_pars(t_pars *pars);
void			good_format(char **argv, t_pars *temp);
int				count_nb_line_file(char **argv, t_pars *temp);
void			copy_file(char **argv, t_pars *temp);
void			print_double_char(char **str);
t_infos			*pars_to_info(t_pars *pars);
void			print_wall(t_wall_lst *wall);
void			find_wall_one(t_wall_lst *temp, \
	t_wall_lst **wall, int i, int j);
void			find_wall_two(t_wall_lst *temp, \
	t_wall_lst **wall, int i, int j);
void			find_wall_three(t_wall_lst *temp, \
	t_wall_lst **wall, int i, int j);
void			find_wall_four(t_wall_lst *temp, \
	t_wall_lst **wall, int i, int j);

void			free_double_tab_char(char **tab);
void			use_file(t_pars *pars);
void			find_string_begin_line(t_pars *pars, \
	char *string, char **string_to_init);
int				nb_line_double_tab(char **tab);
void			extract_map(t_pars *pars);
void			free_t_pars(t_pars *pars);
void			char_to_char(t_pars *pars, char target, char new_one);
void			new_map(t_pars *pars);
int				cmp_char_to_charlst(char c, char *lst);
void			check_map(t_pars *pars, t_sprite_lst *sprite);
void			print_double_char(char **str);
void			cpy_to_new_map(char *line_new_map, int len_tot, char *to_copy);
void			fill_line(char *str, int len);
void			fill_new_map(t_pars *pars, char **new_map, int len);
void			exit_check_map(t_pars *pars, t_sprite_lst *sprite);
void			free_t_infos(t_infos *infos);

t_wall_lst		*ft_lst_wall_new(int x, int y, int x_last, int y_last);
t_wall_lst		*ft_lst_wall_last(t_wall_lst *lst);
void			ft_lst_wall_clear(t_wall_lst **lst);
void			ft_lst_wall_addback(t_wall_lst **lst, t_wall_lst *new);

t_wall_lst		*create_wall_lst(t_pars *pars);
void			print_wall(t_wall_lst *wall);

void			texture_check(t_infos *info, t_vars *vars);
void			destroy_bis(t_vars *vars);
void			free_info_bis(t_infos *infos);
char			*ft_strduppos(char *src, int start, int ending);
int				end_line(char *line);
int				is_valid_xpm(char *line);
int				is_xpm(int i, char *line);
int				end_line_err(char *line);
void			check_lines(t_texture *tex, t_vars *vars);
int				check_null_str(t_texture *tex);
int				check_null_img(t_texture *tex);

void			color_check(t_infos *info, t_vars *vars);
void			exit_color(t_vars *vars);
void			free_color(int *t, char **temp);

//----------------------MINI_MAP--------------------------
// redessine la map a chaque fois:
void			create_mini_map(t_vars *vars, \
	t_infos *infos, int pix_length, int pix_width);
// permet de dessiner la position du player au debut uniquement:
void			create_player_point(t_vars *vars, \
	t_infos *infos, int pix_length, int pix_width);
t_body			*create_body_bis(t_vars *vars, t_infos *infos, \
	int pix_length, int pix_width);
void			end_create_player(t_vars *vars, \
	t_body *body_player, t_ray *ray);
void			define_ray(t_ray *ray, int x, int y);
void			initialise_point_list_circle(t_vars *vars, \
	t_body *body_player, t_square square);

void			ft_lst_point_addback(t_point_lst **lst, t_point_lst *new);
t_point_lst		*ft_lst_point_new(int x, int y, \
	double x_p, double y_p);
void			ft_lst_point_clear(t_point_lst **lst);
t_point_lst		*ft_lst_point_last(t_point_lst *lst);

// colorier les point donne en lst
void			color_point_lst(t_vars *vars, \
	t_point_lst *point_lst, int color);

// dessiner rayon pas encore caclule distances 
void			draw_ray(t_vars *vars, t_body *body, t_ray *ray, int color);

// rotate ray 
void			rotate_ray(t_ray *ray_1, double angle);
t_ray			*create_new_rotate_ray(t_vars *vars, \
	t_ray *ray_1, double angle);

// verif des points enfonction direction du mouvement
int				verification_point_dir(t_vars *vars, t_body *body, t_ray *dir);
void			applied_move_on_body(t_body *body, t_ray *ray);

// keycode mouv and mouv 
void			mouv(int keycode, t_vars *vars);
void			change_sprite(t_vars *vars, t_sprite_lst *sprite_lst);

// utils
double			degree_to_radian(double angle);
void			simplifying_wall(t_wall_lst **wall);
t_ray_fov		*create_fov_ray_tab(t_vars *vars, t_infos *infos);
void			free_fov_ray_tab(t_ray_fov *fov_tab);
void			rotate_fov(t_ray_fov *fov_tab, double angle);

double			distance_two_point(double x1, double y1, double x2, double y2);
// raycast 
double			throw_ray_method_one(t_vars *vars, t_body *body, t_ray *ray);
void			raycast(t_vars *vars, t_infos *infos);
int				dist_cam_screen_calculate(void);
int				height_wall_px_calculate(t_vars *vars, t_ray *ray);
void			draw_column(t_vars *vars, int x, int h_wall_px, int y_central);
void			draw_line(t_vars *vars, int count, \
	int h_wall_px, int y_central);
void			draw_wall(t_vars *vars, t_ray *ray, int count);
double			distance_correction_two(t_wall_lst *wall, \
	t_body *body, t_ray *ray);
int				calcul_center_down(t_ray *ray);
int				calcul_center_up(t_ray *ray);

t_wall_lst		*throw_ray_method_two(t_vars *vars, t_body *body, t_ray *ray);
void			raycast_two(t_vars *vars, t_infos *infos);
int				preselection_wall(double x, double y, \
	t_ray *ray, t_wall_lst *wall);
int				preselection_sprite(double x, double y, \
	t_ray *ray, t_sprite_lst *sprite);
int				dist_cam_screen_calculate(void);
double			distance_correction(t_vars *vars, double dist, t_ray *ray);
double			distance_correction_two(t_wall_lst *wall, \
	t_body *body, t_ray *ray);
int				height_wall_px_calculate(t_vars *vars, t_ray *ray);
void			draw_column(t_vars *vars, int x, int h_wall_px, int y_central);
void			draw_column_for_sprite(t_vars *vars, \
	t_ray_fov *fov_tab, int count, int x);
void			draw_column_2(t_vars *vars, \
	t_ray_fov *fov_tab, int count, int x);
void			draw_line_2(t_vars *vars, t_ray_fov *fov_tab, int count);
void			color_c_f(int y, int x, int limit, t_vars *vars);
double			find_x_pos_img(t_vars *vars, t_ray_fov *fov_tab, int count);
void			draw_if_one(t_column *col, t_vars *vars, \
	t_ray_fov *fov_tab, int count);
void			draw_if_two(t_column *col, t_vars *vars, \
	t_ray_fov *fov_tab, int count);
void			draw_if_three(t_column *col, t_vars *vars, \
	t_ray_fov *fov_tab, int count);
void			draw_if_four(t_column *col, t_vars *vars, \
	t_ray_fov *fov_tab, int count);

// sprite
t_sprite_lst	*throw_ray_meth_two_sprite(t_vars *vars, \
	t_body *body, t_ray *ray);
void			display_sprite(t_vars *vars, t_ray_fov *fov_tab, int count);
t_sprite_lst	*ft_lst_sprite_new(int x, int y);
t_sprite_lst	*ft_lst_sprite_last(t_sprite_lst *lst);
void			ft_lst_sprite_clear(t_sprite_lst **lst);
void			ft_lst_sprite_addback(t_sprite_lst **lst, t_sprite_lst *new);
t_sprite_lst	*sprite_mapping(t_pars *pars);
void			init_sprite(t_vars *vars);
int				change_status_sprite(void *tvars);
void			sprite_ges(t_vars *vars, t_infos *infos);

#endif