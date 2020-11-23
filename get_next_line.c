/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:04:04 by mstoneho          #+#    #+#             */
/*   Updated: 2020/11/13 20:04:06 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_new_line(char **tail, char **line)
{
	char	*nl_p;
	char	*tmp;
	int		returned;

	if ((nl_p = ft_strchr(*tail, '\n')))
	{
		*nl_p = '\0';
		tmp = *tail;
		*line = ft_strdup(tmp);
		*tail = ft_strdup(++nl_p);
		free(tmp);
		returned = 1;
		if (NULL == *line || NULL == *tail)
		{
			free(*line);
			free(*tail);
			returned = -1;
		}
		return (returned);
	}
	else
		return (0);
}

int		read_file(int fd, char **tail, char *buf, char **line)
{
	char	*tmp;
	int		br;
	int		nl;

	while ((br = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[br] = '\0';
		if (NULL == *tail)
			*tail = ft_strdup("");
		tmp = *tail;
		if (NULL == *tail || NULL == (*tail = ft_strjoin(tmp, buf)))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		nl = find_new_line(tail, line);
		if (nl == 1)
			break ;
		else if (nl == -1)
			return (-1);
	}
	if (br < 0)
		return (-1);
	return (br ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	int			returned;
	char		*buf;
	static char	*tail;

	if (!line || (fd < 0 || fd > 256) || BUFFER_SIZE < 1
	|| NULL == (buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if ((find_new_line(&tail, line)))
	{
		free(buf);
		return (1);
	}
	returned = read_file(fd, &tail, buf, line);
	free(buf);
	if (returned != 0 || tail == NULL || tail[0] == '\0')
	{
		if (!returned)
		{
			*line = ft_strdup("");
		}
		return (returned);
	}
	*line = tail;
	tail = NULL;
	return (returned);
}
