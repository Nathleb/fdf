/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:08:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/05/31 19:59:12 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_drawline(int x1, int y1, int x2, int y2, t_data *img, int color)
{
	t_line line;

	line.e = (x2 - x1) * 1.0;
	line.dx = (int)(line.e * 2);
	line.dy = ((y2 - y1) * 2);
	while (x1 < x2)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		x1++;
		if ((line.e = line.e - line.dy) <= 0)
		{
			y1++;
			line.e += line.dx;
		}
	}
	//my_mlx_pixel_put(img, x2, y2, color);
}

void	my_mlx_drawline2(int x1, int y1, int x2, int y2, t_data *img, int color)
{
	t_line line;

	line.e = (x2 - x1) * 1.0;
	line.dx = (int)(line.e * 2);
	line.dy = ((y2 - y1) * 2);
	while (x1 < x2)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		x1++;
		if ((line.e = line.e + line.dy) <= 0)
		{
			y1--;
			line.e += line.dx;
		}
	}
	//my_mlx_pixel_put(img, x2, y2, color);
}

void what_to_draw(int x1, int y1, int x2, int y2, t_data *img, int color)
int		color_from_z(int z)
{
	return (255 << 24 | z << 16 | 120 << 8 | 120);
}

void	draw_grid(t_grid *grid, t_data *img)
{
	int i;
	int j;
	double x2D;
	double y2D;

	i = 0;
	grid->x_2D0 = X_RES/2;
	grid->y_2D0 = Y_RES/2;
	while ((grid->map)[i])
	{
		j = 1;
		while (j <= (grid->map)[i][0])
		{
			x2D = grid->x_2D0 + FACTEUR * (A1*i + A2*j);
			y2D = grid->y_2D0 + FACTEUR * (B2 * (A2 * i - A1 * j) - B1 *(grid->map)[i][j]);
			if (i + 1 < (grid->nbr_line))
			{
				grid->x2D_next = grid->x_2D0 + FACTEUR * (A1*(i + 1) + A2 * j); ;
				grid->y2D_next = grid->y_2D0 + FACTEUR * (B2 * (A2 * (i + 1) - A1 * j) - B1 * (grid->map)[i + 1][j]);
				my_mlx_drawline((int)x2D, (int)y2D, (int)(grid->x2D_next), (int)(grid->y2D_next), img, color_from_z((grid->map)[i][j]));
			}
			if (j < grid->map[i][0])
			{
				grid->x2D_next = grid->x_2D0 + FACTEUR * (A1 * i + A2 * (j + 1)); ;
				grid->y2D_next = grid->y_2D0 + FACTEUR * (B2 * (A2 * i - A1 * (j + 1)) - B1 *(grid->map)[i][j + 1]);
				my_mlx_drawline2((int)x2D, (int)y2D, (int)grid->x2D_next, (int)(grid->y2D_next), img, color_from_z((grid->map)[i][j]));
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
	img.img = mlx_new_image(mlx, X_RES, Y_RES);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_grid(grid, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (1);
}
