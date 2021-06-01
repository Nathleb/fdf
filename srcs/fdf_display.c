/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:08:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/01 15:29:12 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	choose_octant(t_line line, t_data *img)
{	
	if (line.dx == 0)
		my_mlx_drawline6(line,img);
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
	t_line line;

	coord_set(&line, grid);	
	if (line.dx < 0 || (line.dx == 0 && line.y1 > line.y2))
	{
		coord_swap(&line, grid);
	}
	choose_octant(line, img);
}

double	calculate_x2D(t_grid *grid, int i, int j)
{
	return(grid->x_2D0 + grid->F * (A1 * j + A2 * i));
}

double calculate_y2D(t_grid *grid, int i, int j)
{
	return(grid->y_2D0 + grid->F * (B2 * (A2 * j - A1 * i) - B1 * (grid->map)[i][j]));
}

void	draw_grid(t_grid *grid, t_data *img)
{
	int i;
	int j;

	i = 0;
	grid->x_2D0 = X_RES/2;
	grid->y_2D0 = Y_RES/5;
	grid->F = 50;
	while ((grid->map)[i])
	{
		j = 1;
		while (j <= (grid->map)[i][0])
		{
			grid->x2D = calculate_x2D(grid, i ,j);
			grid->y2D = calculate_y2D(grid, i ,j); 
			if (grid->map[i + 1] && j - 1 < grid->map[i + 1][0])
			{
				grid->x2D_next = calculate_x2D(grid, i + 1 ,j);
				grid->y2D_next = calculate_y2D(grid, i + 1 ,j);
				how_to_draw(grid, img);
			}
			if (j < grid->map[i][0])
			{
				grid->x2D_next = calculate_x2D(grid, i ,j + 1);
				grid->y2D_next = calculate_y2D(grid, i ,j + 1);
				how_to_draw(grid, img);
			}
			my_mlx_pixel_put(img, (int)grid->x2D, (int)grid->y2D, 0x00FFFF);
			j++;
		}
		i++;
	}
}

int display_grid(t_grid *grid)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, X_RES, Y_RES, "Fdf");
	img.img = mlx_new_image(mlx, X_RES, Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_grid(grid, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (1);
}
