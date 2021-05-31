/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:54:56 by nle-biha          #+#    #+#             */
/*   Updated: 2021/05/31 19:16:46 by nle-biha         ###   ########.fr       */
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
# define Y_RES 540
# define X_RES 960
# define PI 3.1415
# define OMEGA 0.785
# define ALPHA 0.615
# define FACTEUR 100
# define A1 cos(OMEGA)
# define A2 sin(OMEGA)
# define B1 cos(ALPHA)
# define B2 sin(ALPHA)

typedef struct	s_grid
{
	
	int x_2D0;
	int y_2D0;
	double x2D_next;
	double y2D_next;
	double facteur;
	int nbr_line;
	int color;
	int **map;
}				t_grid;

typedef struct	s_line
{
	int x;
	int y;
	int dx;
	int dy;
	double e;
}				t_line;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		display_grid(t_grid *grid);
int		ft_strisdigit(const char *str);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_next_line(int fd, char **line);
void    free_nulltermchartab(char **tab);
#endif
