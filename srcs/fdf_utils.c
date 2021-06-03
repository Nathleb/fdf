/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:56:29 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 21:55:52 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calculate_x2D(t_grid *grid, int i, int j)
{
	return (grid->x_2D0 + grid->F * (A1 * j + A2 * i));
}

double	calculate_y2D(t_grid *grid, int i, int j)
{
	double	r;
	double	mul;

	mul = grid->F * (B2 * (A2 * j - A1 * i) - (B1 * (grid->map)[i][j]));
	r = grid->y_2D0 + mul;
	return (r);
}

void	t_grid_init(t_grid *grid)
{
	grid->x2Dmin = 2147483647;
	grid->y2Dmin = 2147483647;
	grid->x2Dmax = -2147483648;
	grid->y2Dmax = -2147483648;
}

void	calculate_newpos(t_grid *grid, int i, int j)
{
	grid->x2D = calculate_x2D(grid, i, j);
	grid->y2D = calculate_y2D(grid, i, j);
	grid->z2D = grid->map[i][j];
	grid->x2Dmin = min_int((int)(grid->x2D), grid->x2Dmin);
	grid->y2Dmin = min_int((int)(grid->y2D), grid->y2Dmin);
	grid->y2Dmax = max_int((int)(grid->y2D), grid->y2Dmax);
	grid->x2Dmax = max_int((int)(grid->x2D), grid->x2Dmax);
}

void	calculate_newpos_next_draw(t_grid *grid, int i, int j, t_data *img)
{
	grid->x2D_next = calculate_x2D(grid, i, j);
	grid->y2D_next = calculate_y2D(grid, i, j);
	grid->z2D_next = grid->map[i][j];
	how_to_draw(grid, img);
}
