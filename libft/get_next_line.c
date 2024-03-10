/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 03:05:10 by mayalee           #+#    #+#             */
/*   Updated: 2023/06/02 11:39:28 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char *result, char *buffer)
{
	char	*str;

	str = gnl_ft_strjoin(result, buffer);
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
	line = (char *)malloc(1 * (gnl_ft_strlen(buffer) - i + 1));
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
	line = gnl_ft_calloc(size + 2, 1);
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
		input = gnl_ft_strjoin(input, temp);
		if (gnl_ft_strchr(temp, '\n'))
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
