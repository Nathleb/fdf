/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:39:55 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/04 12:25:28 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_from_z(int z1, int z2, double pour, int H)
{
	int	z;

	z = (int)(120 * ((z1 * (1 - pour) + z2 * pour) / H));
	return ((125 + z) << 24 | (125 + z) << 16 | z << 8 | 255);
}

void	coord_swap(t_line *line, t_grid *grid)
{
	line->x1 = (int)(grid->x2D_next);
	line->x2 = (int)(grid->x2D);
	line->y1 = (int)(grid->y2D_next);
	line->y2 = (int)(grid->y2D);
	line->dx = (int)(grid->x2D - grid->x2D_next);
	line->dy = (int)(grid->y2D - grid->y2D_next);
	line->z1 = grid->z2D_next;
	line->z2 = grid->z2D;
}

void	coord_set(t_line *line, t_grid *grid)
{
	line->dx = (int)(grid->x2D_next - grid->x2D);
	line->dy = (int)(grid->y2D_next - grid->y2D);
	line->x1 = (int)(grid->x2D);
	line->x2 = (int)(grid->x2D_next);
	line->y1 = (int)(grid->y2D);
	line->y2 = (int)(grid->y2D_next);
	line->z1 = grid->z2D;
	line->z2 = grid->z2D_next;
}

//dy = 0
void	my_mlx_drawline5(t_line line, t_data *img)
{
	int	color;
	int	x1init;

	x1init = line.x1;
	while (line.x1 < line.x2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.x1 - x1init) * 1.0 / (line.x2 - x1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
	}
}

//dx == 0
void	my_mlx_drawline6(t_line line, t_data *img)
{
	int	color;
	int	y1init;

	y1init = line.y1;
	while (line.y1 < line.y2)
	{
		color = color_from_z(line.z1, line.z2,
				(line.y1 - y1init) * 1.0 / (line.y2 - y1init), line.H);
		if (line.x1 > 0 && line.x1 < X_RES && line.y1 > 0 && line.y1 < Y_RES)
			my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1++;
	}
}
