/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:36:00 by ogarthar          #+#    #+#             */
/*   Updated: 2021/10/16 18:47:28 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_height_width(char *file_name, t_fdf *fdf)
{
	char	*line;
	int		fd;

	fdf->height = 1;
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_message(2, 1);
	if (get_next_line(fd, &line) < 0)
		ft_message(2, 1);
	free(line);
	ft_message(0, 0);
	while (get_next_line(fd, &line))
	{
		if (fdf->width == 0)
			fdf->width = ft_wcount(line, ' ');
		fdf->height++;
		free(line);
	}
	free(line);
	close(fd);
}

void	fill_matrix(int *line_nums, char *line)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(line, ' ');
	while (numbers[i])
	{
		line_nums[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	ft_read_file(char *file_name, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ft_get_height_width(file_name, fdf);
	fdf->z_matrix = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	if (fdf->z_matrix == NULL)
		exit (0);
	while (i < fdf->height)
	{
		fdf->z_matrix[i] = (int *)malloc(sizeof(int) * (fdf->width + 1));
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(fdf->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	fdf->z_matrix[i] = NULL;
}
