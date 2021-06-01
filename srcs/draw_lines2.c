/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:39:55 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/01 18:44:45 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void    coord_set(t_line *line, t_grid *grid)
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
	int color;

	while (line.x1 < line.x2)
	{
		color = 0x0000FF00;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.x1++;
	}
}
//dx == 0
void	my_mlx_drawline6(t_line line, t_data *img)
{
	int color;
	while (line.y1 < line.y2)
	{
		color = 0x0000FF00;
		my_mlx_pixel_put(img, line.x1, line.y1, color);
		line.y1++;
	}
}

