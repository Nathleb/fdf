/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:56:29 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:54:19 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calculate_x2D(t_grid *g, int i, int j)
{
	return (g->x_2D0 + g->F * (g->A1 * j + g->A2 * i));
}

double	calculate_y2D(t_grid *g, int i, int j)
{
	double	r;
	double	mul;

	mul = g->F * (g->B2 * (g->A2 * j - g->A1 * i) - (g->B1 * g->map[i][j]));
	r = g->y_2D0 + mul;
	return (r);
}

void	t_grid_init(t_grid *grid)
{
	grid->x2Dmin = 2147483647;
	grid->y2Dmin = 2147483647;
	grid->x2Dmax = -2147483648;
	grid->y2Dmax = -2147483648;
	grid->A1 = cos(OMEGA);
	grid->A2 = sin(OMEGA);
	grid->B1 = cos(ALPHA);
	grid->B2 = sin(ALPHA);
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
