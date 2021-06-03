/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:08:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 21:11:04 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	i;

	if (keycode == ESC)
	{
		i = 0;
		while ((vars->grid->map)[i])
		{
			free(vars->grid->map[i]);
			i++;
		}
		free(vars->grid->map);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (1);
}

void	choose_octant(t_line line, t_data *img)
{
	if (line.dx == 0)
		my_mlx_drawline6(line, img);
	else if (line.dy > 0)
	{
		if (line.dx > line.dy)
			my_mlx_drawline1(line, img);
		else
			my_mlx_drawline2(line, img);
	}
	else if (line.dy != 0)
	{
		if (line.dx > abs(line.dy))
			 my_mlx_drawline3(line, img);
		 else
			 my_mlx_drawline4(line, img);
	}
	else
		my_mlx_drawline5(line, img);
}

void	how_to_draw(t_grid *grid, t_data *img)
{
	t_line	line;

	line.H = grid->H;
	coord_set(&line, grid);
	if (line.dx < 0 || (line.dx == 0 && line.y1 > line.y2))
	{
		coord_swap(&line, grid);
	}
	choose_octant(line, img);
}

void	draw_grid(t_grid *grid, t_data *img)
{
	int		i;
	int		j;
	double	d;

	d = B2 * (A2 * grid->biggest_line - A1 * grid->nbr_line) + B1 * 2 * grid->H;
	i = 0;
	grid->F = ((Y_RES * 1.0) / d);
	grid->x_2D0 = (int)((grid->nbr_line) * grid->F);
	grid->y_2D0 = (int)((grid->F) * B1 * grid->H);
	while ((grid->map)[i])
	{
		j = 1;
		while (j <= (grid->map)[i][0])
		{
			calculate_newpos(grid, i, j);
			if (grid->map[i + 1] && j - 1 < grid->map[i + 1][0])
				calculate_newpos_next_draw(grid, i + 1, j, img);
			if (j < grid->map[i][0])
				calculate_newpos_next_draw(grid, i, j + 1, img);
			j++;
		}
		i++;
	}
}

int	display_grid(t_grid *grid)
{
	t_vars	vars;
	t_data	img;
	int		xoffset;
	int		yoffset;

	vars.grid = grid;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, X_RES, Y_RES, "Fdf");
	img.img = mlx_new_image(vars.mlx, X_RES, Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	t_grid_init(vars.grid);
	vars.img = &img;
	draw_grid(vars.grid, &img);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	xoffset = (X_RES - (vars.grid->x2Dmax + vars.grid->x2Dmin)) / 2;
	yoffset = (Y_RES - (vars.grid->y2Dmax + vars.grid->y2Dmin)) / 2;
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, xoffset, yoffset);
	mlx_loop(vars.mlx);
	return (1);
}
