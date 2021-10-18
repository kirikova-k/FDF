/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:16:53 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/16 18:57:52 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*char	*dst; // color*/
/* стр 23 color = указатель на первый эл массива*/
/*	+ (номер строки * кол-во байт в строке) + номер пикселя в строке*/
/* ( сколько бит в одном пикселе/8 [делим на 8 т к переводим и байт в биты])*/
#include "fdf.h"

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGTH && x > 0 && y > 0)
	{
		dst = fdf->img->addr + (y * fdf->img->size_line + x * \
		(fdf->img->pixel_bits / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_line(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;

	fdf->z = fdf->z_matrix[(int)fdf->y][(int)fdf->x] * fdf->zoom / 10;
	fdf->z1 = fdf->z_matrix[(int)fdf->y1][(int)fdf->x1] * fdf->zoom / 10;
	ft_zoom_and_cgange_z(fdf);
	ft_color(fdf);
	rotate_x(fdf);
	ft_isometric(fdf);
	ft_shift(fdf);
	x_step = fdf->x1 - fdf->x;
	y_step = fdf->y1 - fdf->y;
	max = ft_fmax((float)fabs((double)x_step), (float)fabs((double)y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(fdf->x - fdf->x1) || (int)(fdf->y - fdf->y1))
	{
		my_mlx_pixel_put(fdf, fdf->x, fdf->y, fdf->color);
		fdf->x += x_step;
		fdf->y += y_step;
	}
	my_mlx_pixel_put(fdf, fdf->x, fdf->y, fdf->color);
}

void	ft_draw_background(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(fdf, x, y, 0x222222);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	ft_draw_background(fdf);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
			{
				ft_init_dots_for_map(fdf, x, y, 1);
				ft_draw_line(fdf);
			}
			if (y < fdf->height - 1)
			{
				ft_init_dots_for_map(fdf, x, y, 2);
				ft_draw_line(fdf);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->image, 0, 0);
}
