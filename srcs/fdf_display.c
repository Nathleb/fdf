/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:08:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/02 02:40:32 by nle-biha         ###   ########.fr       */
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

	line.H = grid->H;
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
	return(grid->y_2D0 + grid->F * (B2 * (A2 * j - A1 * i) - (B1 * 8 / grid->H * (grid->map)[i][j])));
}

void	draw_grid(t_grid *grid, t_data *img)
{
	int i;
	int j;

	i = 0;
	grid->F = ((X_RES * 1.0) / (grid->nbr_line + grid->biggest_line));
	grid->x_2D0 = (int)(grid->nbr_line * grid->F);
	grid->y_2D0 = (int)(grid->F); 
	fprintf(stderr,"%f %d %d %d", grid->F, grid->x_2D0, grid->y_2D0, grid->biggest_line);
	while ((grid->map)[i])
	{
		j = 1;
		while (j <= (grid->map)[i][0])
		{
			grid->x2D = calculate_x2D(grid, i ,j);
			grid->y2D = calculate_y2D(grid, i ,j); 
			grid->z2D = grid->map[i][j];
			if (grid->map[i + 1] && j - 1 < grid->map[i + 1][0])
			{
				grid->x2D_next = calculate_x2D(grid, i + 1 ,j);
				grid->y2D_next = calculate_y2D(grid, i + 1 ,j);
				grid->z2D_next = grid->map[i + 1][j];
				how_to_draw(grid, img);
			}
			if (j < grid->map[i][0])
			{
				grid->x2D_next = calculate_x2D(grid, i ,j + 1);
				grid->y2D_next = calculate_y2D(grid, i ,j + 1);
				grid->z2D_next = grid->map[i][j + 1];
				how_to_draw(grid, img);
			}
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
	img.img = mlx_new_image(mlx, 2*X_RES, 2*Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_grid(grid, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (1);
}
