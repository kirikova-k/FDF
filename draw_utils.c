/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:11:31 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/16 18:50:56 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_and_cgange_z(t_fdf *fdf)
{
	fdf->z *= fdf->change_z;
	fdf->z1 *= fdf->change_z;
	if (fdf->change_z < -600)
		fdf->change_z = -600;
	if (fdf->change_z > 600)
		fdf->change_z = 600;
	fdf->x *= fdf->zoom;
	fdf->y *= fdf->zoom;
	fdf->x1 *= fdf->zoom;
	fdf->y1 *= fdf->zoom;
	if (fdf->zoom < 3)
		fdf->zoom = 3;
	if (fdf->zoom > 500)
		fdf->zoom = 500;
}

/************colors:*/
/**0xffffff//white**/
/**x9900ff//violet*/
/**0xff00cc//pink*/
/*0x00ccff//cian*/
/*0xe80c0c//red*/
void	ft_color(t_fdf *fdf)
{
	if (fdf->z > 0 || fdf->z1 > 0)
	{
		if (fdf->z > 150 * fdf->zoom / 10 || fdf->z1 > 150 * fdf->zoom / 10)
			fdf->color = 0x9900ff;
		else
			fdf->color = 0x00ccff;
	}
	else if (fdf->z < 0 || fdf->z1 < 0)
	{
		if ((fdf->z < -150 * fdf->zoom / 10 || fdf->z1 < -150 * fdf->zoom / 10))
			fdf->color = 0xe80c0c;
		else
			fdf->color = 0xff00cc;
	}
	else if (fdf->z == 0 || fdf->z1 == 0)
		fdf->color = 0xffffff;
}

void	ft_shift(t_fdf *fdf)
{
	fdf->x += fdf->shift_x + 350;
	fdf->y += fdf->shift_y + 350;
	fdf->x1 += fdf->shift_x + 350;
	fdf->y1 += fdf->shift_y + 350;
	if (fdf->shift_x < -10000)
		fdf->shift_x = -10000;
	if (fdf->shift_y < -10000)
		fdf->shift_y = -10000;
	if (fdf->shift_x > 10000)
		fdf->shift_x = 10000;
	if (fdf->shift_y > 10000)
		fdf->shift_y = 10000;
}

void	ft_isometric(t_fdf *fdf)
{
	if (fdf->flag_p == 1)
		return ;
	fdf->x = (fdf->x - fdf->y) * cos(fdf->angle);
	fdf->y = (fdf->x + fdf->y) * sin(fdf->angle) - fdf->z;
	fdf->x1 = (fdf->x1 - fdf->y1) * cos(fdf->angle);
	fdf->y1 = (fdf->x1 + fdf->y1) * sin(fdf->angle) - fdf->z1;
}

void	rotate_x(t_fdf *fdf)
{
	float	previous_y;
	float	previous_y1;

	if (fdf->flag_rx != 1)
		return ;
	previous_y = fdf->y;
	previous_y1 = fdf->y1;
	fdf->y = previous_y * cos(fdf->angle_r) + (-fdf->z * sin(fdf->angle_r));
	fdf->z = previous_y * sin(fdf->angle_r) + fdf->z * cos(fdf->angle_r);
	fdf->y1 = previous_y1 * cos(fdf->angle_r) + (-fdf->z1 * sin(fdf->angle_r));
	fdf->z1 = previous_y1 * sin(fdf->angle_r) + fdf->z1 * cos(fdf->angle_r);
}
