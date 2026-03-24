/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutokgoz <hutokgoz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:10:16 by hutokgoz          #+#    #+#             */
/*   Updated: 2026/02/19 15:11:41 by hutokgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*read_line(char *stash, int fd)
{
	char	*buffer;
	int		read_size;

	read_size = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((!stash || !ft_strchr(stash, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (read_size == 0)
			break ;
		if (read_size > 0)
			buffer[read_size] = '\0';
		stash = gnl_join(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (len > i)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*temp;
	char	*new_stash;
	int		i;

	temp = ft_strchr(stash, '\n');
	if (!temp)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(temp + 1) + 1);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (temp[i + 1])
	{
		new_stash[i] = temp[i + 1];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	stash[fd] = read_line(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
