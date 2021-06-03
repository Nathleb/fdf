/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:56 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 19:28:13 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx_linux/mlx.h"
# define Y_RES 1000
# define X_RES 1920
# define ESC 65307
# define PI 3.1415
# define OMEGA 0.785 - PI/2
# define ALPHA 0.615 - PI/2
# define A1 cos(OMEGA)
# define A2 sin(OMEGA)
# define B1 cos(ALPHA)
# define B2 sin(ALPHA)
#define MIN(a, b)       ((a) < (b) ? (a) : (b))
#define MAX(a, b)       ((a) < (b) ? (b) : (a))
typedef struct	s_grid
{
	
	int x_2D0;
	int y_2D0;
	int	z2D;
	int z2D_next;
	int x2Dmin;
	int	x2Dmax;
	int y2Dmin;
	int y2Dmax;
	double x2D_next;
	double y2D_next;
	double F;
	double H;
	double x2D;
	double y2D;
	int nbr_line;
	int biggest_line;
	int **map;

}				t_grid;

typedef struct	s_line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int z1;
	int z2;
	int dx;
	int dy;
	int e;
	int H;
}				t_line;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
	t_grid	*grid;
	t_data	*img;
}				t_vars;

int		display_grid(t_grid *grid);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_next_line(int fd, char **line);
void    free_nulltermchartab(char **tab);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    my_mlx_drawline1(t_line line, t_data *img);
void    my_mlx_drawline2(t_line line, t_data *img);
void    my_mlx_drawline3(t_line line, t_data *img);
void    my_mlx_drawline4(t_line line, t_data *img);
void	my_mlx_drawline6(t_line line, t_data *img);
void	coord_swap(t_line *line, t_grid *grid);
void    coord_set(t_line *line, t_grid *grid);
void	my_mlx_drawline5(t_line line, t_data *img);
int     color_from_z(int z1, int z2, double pour, int H);
double calculate_y2D(t_grid *grid, int i, int j);
double	calculate_x2D(t_grid *grid, int i, int j);
void    t_grid_init(t_grid *grid);
void	calculate_newpos(t_grid *grid, int i, int j);
void    calculate_newpos_next_draw(t_grid *grid, int i, int j, t_data *img);
#endif
