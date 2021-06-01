/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:08:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/01 03:00:53 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	how_to_draw(t_grid *grid, t_data *img)
{
	t_line line;

	line.dx = (int)(grid->x2D_next - grid->x2D);
	line.dy = (int)(grid->y2D_next - grid->y2D);
	line.x1 = (int)(grid->x2D);
	line.x2 = (int)(grid->x2D_next);
	line.y1 = (int)(grid->y2D);
	line.y2 = (int)(grid->y2D_next);
	//line.e = 0;
	fprintf(stderr,"%d %d %d %d\n", line.x1, line.y1, line.x2, line.y2);
	if (line.dx > 0)
	{
		if (line.dy > 0)
		{
			if (line.dx >= line.dy)
				my_mlx_drawline1(line, img);
			else
				my_mlx_drawline2(line, img);
		}
		else
		{
			if (line.dx > abs(line.dy))
				 my_mlx_drawline3(line, img);
			 else
				 my_mlx_drawline4(line, img);
		}
	}
}

void	draw_grid(t_grid *grid, t_data *img)
{
	int i;
	int j;

	i = 0;
	grid->x_2D0 = X_RES/2;
	grid->y_2D0 = Y_RES/5;
	while ((grid->map)[i])
	{
		j = 1;
		while (j <= (grid->map)[i][0])
		{
			grid->x2D = grid->x_2D0 + F * (A1 * j + A2 * i);
			grid->y2D = grid->y_2D0 + F * (B2 * (A2 * j - A1 * i) - B1 * (grid->map)[i][j]);
			if (i + 1 < (grid->nbr_line))
			{
				grid->x2D_next = grid->x_2D0 + F * (A1 * j + A2 * (i + 1)); ;
				grid->y2D_next = grid->y_2D0 + F * (B2 * (A2 * j - A1 * (i + 1)) + B1 * (grid->map)[i + 1][j]);
				how_to_draw(grid, img);
			}
			if (j < grid->map[i][0])
			{
				grid->x2D_next = grid->x_2D0 + F * (A1 * (j + 1) + A2 * i); ;
				grid->y2D_next = grid->y_2D0 + F * (B2 * (A2 * (j + 1) - A1 * i) + B1 * (grid->map)[i][j + 1]);
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
