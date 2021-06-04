/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:08:24 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 12:23:23 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//dy > 0 (et dx > 0) dx>dy
void	my_mlx_drawline1(t_line line, t_data *img)
{
	int	color;
	int	x1init;

	x1init = line.x1;
	line.e = (line.x2 - line.x1);
	line.dx = (line.x2 - line.x1) * 2;
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.x1 < line.x2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.x1 - x1init) * 1.0 / (line.x2 - x1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
		line.e = line.e - line.dy;
		if (line.e < 0)
		{
			line.y1++;
			line.e += line.dx;
		}
	}
}

//dy > 0 dy>dx
void	my_mlx_drawline2(t_line line, t_data *img)
{
	int	color;
	int	y1init;

	y1init = line.y1;
	line.e = line.y2 - line.y1;
	line.dy = 2 * line.e;
	line.dx = 2 * (line.x2 - line.x1);
	while (line.y1 < line.y2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.y1 - y1init) * 1.0 / (line.y2 - y1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1++;
		line.e = line.e - line.dx;
		if (line.e < 0)
		{
			line.x1++;
			line.e += line.dy;
		}
	}
}

//dy < 0 (et dx > 0) -dy<dx
void	my_mlx_drawline3(t_line line, t_data *img)
{
	int	color;
	int	x1init;

	x1init = line.x1;
	line.e = (line.x2 - line.x1);
	line.dx = (line.e * 2);
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.x1 < line.x2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.x1 - x1init) * 1.0 / (line.x2 - x1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
		line.e = line.e + line.dy;
		if (line.e < 0)
		{
			line.y1--;
			line.e += line.dx;
		}
	}
}

void	my_mlx_drawline4(t_line line, t_data *img)
{
	int	color;
	int	y1init;

	y1init = line.y1;
	line.e = (line.y2 - line.y1);
	line.dx = ((line.x2 - line.x1) * 2);
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.y1 > line.y2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.y1 - y1init) * 1.0 / (line.y2 - y1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1--;
		line.e = line.e + line.dx;
		if (line.e > 0)
		{
			line.x1++;
			line.e += line.dy;
		}
	}
}
