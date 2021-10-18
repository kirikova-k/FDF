/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:18:09 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/16 18:46:30 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_default(t_fdf *fdf)
{
	fdf->flag_rx = 0;
	fdf->flag_p = 0;
	fdf->angle = 0.8;
	fdf->zoom = 20;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->change_z = 1;
	fdf->angle_r = 0;
}

void	ft_key_shift(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->shift_y -= 10;
	if (key == 125)
		fdf->shift_y += 10;
	if (key == 123)
		fdf->shift_x -= 10;
	if (key == 124)
		fdf->shift_x += 10;
}

void	ft_key_change_projactions(int key, t_fdf *fdf)
{
	if (key == 91)
		fdf->angle -= 0.05;
	if (key == 84)
		fdf->angle += 0.05;
	if (key == 35 && fdf->flag_p == 1)
		fdf->flag_p = 0;
	else if (key == 35)
		fdf->flag_p = 1;
	if (key == 31 && fdf->angle != 0)
		fdf->angle = 0;
	else if (key == 31)
		fdf->angle = 0.8;
	else if (key == 89)
	{
		fdf->angle_r += 0.1;
		fdf->flag_rx = 1;
		fdf->flag_p = 0;
	}
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == 2)
		ft_key_default(fdf);
	if (key <= 126 && key >= 123)
		ft_key_shift(key, fdf);
	if (key == 69)
		fdf->zoom += 2;
	if (key == 78)
		fdf->zoom -= 2;
	if (key == 53)
		exit(0);
	ft_key_change_projactions(key, fdf);
	if (key == 92)
		fdf->change_z += 2;
	if (key == 85)
		fdf->change_z -= 2;
	ft_draw_map(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_img	*img;

	ft_check_file(argc, argv[1]);
	img = (t_img *)malloc(sizeof(t_img));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL || img == NULL)
		exit (0);
	fdf->width = 0;
	ft_read_file(argv[1], fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGTH, "FDF");
	fdf->zoom = 20;
	img->image = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGTH);
	img->addr = mlx_get_data_addr(img->image, &img->pixel_bits, \
	&img->size_line, &img->endian);
	fdf->img = img;
	fdf->angle = 0.8;
	fdf->change_z = 1;
	ft_draw_map(fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
/*addr char массив байты всей картинки*/
