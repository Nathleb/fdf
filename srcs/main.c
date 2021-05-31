/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:59:26 by nle-biha          #+#    #+#             */
/*   Updated: 2021/05/31 19:07:06 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int realloc_newline_map(t_grid *grid, int line_nbr)
{
	int **newmap;

	if ((newmap = malloc(sizeof(int *) * line_nbr + 2)) == NULL)
		return 0;
	newmap[line_nbr + 1] = NULL;
	while (--line_nbr >= 0)
		newmap[line_nbr] = (grid->map)[line_nbr];
	free((grid->map));
	grid->map = newmap;
	return (1);
}

int parse_line(char *line, t_grid *grid, int line_nbr)
{
	char **line_sp_split;
	int i;
	
	if ((realloc_newline_map(grid, line_nbr)) == 0 || (line_sp_split = ft_split(line, ' ')) == NULL)
		return 0;
	i = 0;
	while (line_sp_split[i])
		i++;
	(grid->map)[line_nbr] = malloc(sizeof(int) * i + 1);	
	(grid->map)[line_nbr][0] = i;
	while (i-- >= 1)
		(grid->map)[line_nbr][i + 1] = ft_atoi(line_sp_split[i]);
	return (1);
}

int parsing_fdf(int fd, t_grid *grid)
{
	char *line;
	int loop_on;
	int line_nbr;
	
	line_nbr = 0;
	loop_on = 1;
	grid->map = malloc(0);
	while (get_next_line(fd, &line) && loop_on)
	{
		if (parse_line(line, grid, line_nbr) == 0)
			loop_on = 0;
		line_nbr++;
		free(line);
	}
	if (loop_on == 0)
	{
		while (line_nbr >= 0)
			if ((grid->map)[line_nbr])
				free((grid->map)[line_nbr--]);
		free(grid->map);
		return (0);
	}
	else
		free(line);
	grid->nbr_line = line_nbr;
	return (1);
}

int main(int argc, char **argv)
{
	t_grid grid;
	int fd;
	
	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) != -1)
		if (parsing_fdf(fd, &grid))
			display_grid(&grid);
/*	int i = 0;
	int j;
	while ((grid.map)[i])
	{
		j = 1;
		while (j <= (grid.map)[i][0])
		{
			printf("%d ", (grid.map)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}*/
	return(0);
}
