/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:13:45 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/16 18:53:22 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGTH 1080

# include <unistd.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"

/*pixel_bits; //сколько бит в одном пикселе*/
/*size_line;	// байт в строке*/

typedef struct s_img
{
	void		*image;
	char		*addr;
	int			pixel_bits;
	int			size_line;
	int			endian;
}t_img;

typedef struct s_fdf
{
	int		height;
	int		width;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	int		shift_x;
	int		shift_y;
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
	int		flag_p;
	int		flag_rx;
	int		flag_rz;
	float	angle;
	int		change_z;
	float	angle_r;
	float	angle_r1;
	t_img	*img;
}t_fdf;

//*/*/main.c/*/*//
int		main(int argc, char **argv);
int		deal_key(int key, t_fdf *fdf);
void	ft_key_shift(int key, t_fdf *fdf);
void	ft_key_change_projactions(int key, t_fdf *fdf);
void	ft_key_default(t_fdf *fdf);
//*/*/utils.c/*/*//
void	ft_check_file(int argc, char argv[1]);
void	ft_message(int err_no, int f_exit);
void	ft_init_dots_for_map(t_fdf *fdf, int x, int y, int flag);
void	ft_init_x1y1(t_fdf *fdf, float x, float y);
void	ft_init_xy(t_fdf *fdf, float x, float y);
///*/*/read_file.c/*/*///
void	ft_read_file(char *file_name, t_fdf *data);
void	ft_get_height_width(char *file_name, t_fdf *fdf);
void	fill_matrix(int *line_nums, char *line);
//*/*/draw.c/*/*//
float	ft_fmax(float a, float b);
void	ft_draw_map(t_fdf *fdf);
void	ft_draw_background(t_fdf *fdf);
void	ft_draw_line(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
//*/*/draw_utils.c/*/*//
void	ft_zoom_and_cgange_z(t_fdf *fdf);
void	ft_color(t_fdf *fdf);
void	ft_shift(t_fdf *fdf);
void	ft_isometric(t_fdf *fdf);
void	rotate_x(t_fdf *fdf);

#endif
