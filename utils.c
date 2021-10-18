/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:38 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/17 19:12:52 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_file(int argc, char argv[1])
{
	int	len;

	if (argc != 2)
		ft_message(1, 1);
	len = (int)ft_strlen(argv);
	if (argv[len - 1] != 'f' || argv[len - 2] != 'd' || argv[len - 3] != 'f' \
	|| argv[len - 4] != '.')
		ft_message(1, 1);
}

void	ft_message(int err_no, int f_exit)
{
	if (err_no == 0)
		ft_putstr_fd("Usage:\t+: zoom++\t -: zoom--\tnum9: z++\tnum3: z--\n \
	\n▲ shift up\t▼ shift down\t◀ shift left\t▶ shift right\n \
	\nparallel projection:\tp: view from above\to: side view\n \
	\nnum8/num2: change isometric\tnum7: rotation x\n \
	\nd: default\t esc: exit\n", 1);
	if (err_no == 1)
		ft_putstr_fd("Usage: [./fdf filename.fdf]\n", 1);
	if (err_no == 2)
		ft_putstr_fd("File not found!\n", 1);
	if (f_exit == 0)
		return ;
	if (f_exit == 1)
		exit (0);
}

void	ft_init_dots_for_map(t_fdf *fdf, int x, int y, int flag)
{
	if (flag == 1)
	{
		ft_init_xy(fdf, x, y);
		ft_init_x1y1(fdf, x + 1, y);
	}
	if (flag == 2)
	{
		ft_init_xy(fdf, x, y);
		ft_init_x1y1(fdf, x, y + 1);
	}
}

void	ft_init_x1y1(t_fdf *fdf, float x, float y)
{
	fdf->x1 = x;
	fdf->y1 = y;
}

void	ft_init_xy(t_fdf *fdf, float x, float y)
{
	fdf->x = x;
	fdf->y = y;
}
