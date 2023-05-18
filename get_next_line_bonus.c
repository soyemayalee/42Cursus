/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 03:26:25 by mayalee           #+#    #+#             */
/*   Updated: 2022/12/24 12:51:29 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(char *result, char *buffer)
{
	char	*str;

	str = ft_strjoin(result, buffer);
	free(result);
	return (str);
}

char	*getting_next_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(1 * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (NULL);
	i += 1;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = 0;
	free(buffer);
	return (line);
}

char	*getting_line(char *buffer)
{
	char	*line;
	int		size;
	int		index;

	index = 0;
	size = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	line = ft_calloc(size + 2, 1);
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] && buffer[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = 0;
	return (line);
}

char	*file_reader(int fd, char *input)
{
	char	*temp;
	int		bytes;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = 0;
		input = ft_strjoin(input, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (input);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = file_reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = getting_line(buffer[fd]);
	buffer[fd] = getting_next_line(buffer[fd]);
	return (line);
}

//OPEN_MAX = constant that defines the max num of open files
//allowed for a single program
	//OPEN_MAX deprecated & now doesn't work
	//reason: max num of file that can be opened simultaneously is not fixed

//_SC_OPEN_MAX = max number of 'open' descriptors you can have
//not the max number of files
	//because on POSIX system, file descriptor 
	//doesn't actually have to be a file
	//may be socket, a pipe or sth else that can be used by ex.read or write

//soft limit for the max number of openable files per process
	//= ulimit -n = 1024
	//for hard limit, it's ulimit -n -H