/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:58:32 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 21:06:09 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	pos_new_line(char *buf)
{
	size_t	ret;

	ret = 0;
	while (buf[ret] && buf[ret] != '\n')
		ret++;
	return (ret);
}

int	exit_gnl(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (-1);
}

int	fill_next_line(char *source, char **line, char *save)
{
	char	*temp;

	temp = ft_substr(source, 0, pos_new_line(source));
	if (temp == NULL)
		return (exit_gnl(line));
	*line = ft_strjoin_free(*line, temp);
	if (*line == NULL)
		return (exit_gnl(line));
	temp = ft_substr(source, pos_new_line(source) + 1, BUFFER_SIZE);
	if (temp == NULL)
		return (exit_gnl(line));
	ft_strlcpy(save, temp, BUFFER_SIZE);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	save[1024][BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	int			err;

	*line = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || *line == NULL)
		return (-1);
	ft_bzero(buf, BUFFER_SIZE + 1);
	if (pos_new_line(save[fd]) < ft_strlen(save[fd]))
		return (fill_next_line(save[fd], line, save[fd]));
	ft_strlcpy(*line, save[fd], BUFFER_SIZE);
	err = read(fd, buf, BUFFER_SIZE);
	while (err > 0)
	{
		if (fill_next_line(buf, line, save[fd]) == -1)
			return (-1);
		if (pos_new_line(buf) < ft_strlen(buf))
			return (1);
		ft_bzero(buf, BUFFER_SIZE + 1);
		err = read(fd, buf, BUFFER_SIZE);
	}
	ft_bzero(save[fd], BUFFER_SIZE + 1);
	if (err == 0)
		return (0);
	return (exit_gnl(line));
}
