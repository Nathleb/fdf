/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:08:24 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/01 02:39:48 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     color_from_z(int z)
{
    return (255 << 24 | z << 16 | 120 << 8 | 120);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
//dy > 0 (et dx > 0) dx>dy
void	my_mlx_drawline1(t_line line, t_data *img)
{
	int color;

	line.e = (line.x2 - line.x1);
	line.dx = (line.x2 - line.x1) * 2;
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.x1 < line.x2)
	{
		color = 0x00FFFF00;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
		if ((line.e = line.e - line.dy) <= 0)
		{
			line.y1++;
			line.e += line.dx;
		}
	}
}
//dy > 0 dy>dx
void	my_mlx_drawline2(t_line line, t_data *img)
{
	int color;

	line.e = line.y2 - line.y1;
	line.dy = 2 * line.e;
	line.dx = 2 * (line.x2 - line.x1);
	while (line.y1 < line.y2)
	{
		color = 0x0000FFFF;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1++;
		if ((line.e = line.e - line.dx) < 0)
		{
			line.x1++;
			line.e += line.dy;
		}
	}
}

//dy < 0 (et dx > 0) -dy<dx
void	my_mlx_drawline3(t_line line, t_data *img)
{
	int color;

	line.e = (line.x2 - line.x1);
	line.dx = (line.e * 2);
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.x1 < line.x2)
	{
		color = 0x00FF0000;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
		if ((line.e = line.e + line.dy) <= 0)
		{
			line.y1--;
			line.e += line.dx;
		}
	}
}

void	my_mlx_drawline4(t_line line, t_data *img)
{
	int color;

	line.e = (line.y2 - line.y1);
	line.dx = ((line.x2 - line.x1) * 2);
	line.dy = ((line.y2 - line.y1) * 2);
	while (line.y1 < line.y2)
	{
		color = 0x0000FF00;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1--;
		if ((line.e = line.e + line.dx) > 0)
		{
			line.x1++;
			line.e += line.dy;
		}
	}
}
