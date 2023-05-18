/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:05:10 by mayalee           #+#    #+#             */
/*   Updated: 2022/12/24 12:51:05 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = file_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = getting_line(buffer);
	buffer = getting_next_line(buffer);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *str;
	int fd;

	fd = open("empty", O_RDONLY);
	while ((str = get_next_line(fd))!= NULL)
	{
		printf("%s", str);
		free(str);
	}
	return (0);
}
*/

/*
read(int fd, void *buf, size_t nbyte)
read return values
value
	read() was successful, the returned value = # of bytes actually read
	and placed in output buffer
-1
	read() was unsuccessful. 
*/