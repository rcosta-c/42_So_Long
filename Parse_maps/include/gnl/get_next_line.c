/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:58:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/24 08:26:20 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_chunckjoin(int fd, char *buffer);
static char	*ft_finalstr(char *buffer);
static char	*ft_nextgnl(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*final_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	buffer = ft_chunckjoin(fd, buffer);
	if (!buffer)
		return (NULL);
	final_str = ft_finalstr(buffer);
	buffer = ft_nextgnl(buffer);
	return (final_str);
}

static char	*ft_chunckjoin(int fd, char *buffer)
{
	char	*temp;
	int		temp_len;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	temp_len = 1;
	while (!ft_search_nl(buffer, '\n') && temp_len != 0)
	{
		temp_len = read(fd, temp, BUFFER_SIZE);
		if (temp_len == -1)
		{
			free (buffer);
			free (temp);
			buffer = NULL;
			return (NULL);
		}
		temp[temp_len] = '\0';
		buffer = ft_strchunckjoin(buffer, temp);
	}
	free (temp);
	return (buffer);
}

static char	*ft_finalstr(char *buffer)
{
	int		counter;
	char	*finalstr;

	counter = 0;
	if (!buffer[counter])
		return (NULL);
	while (buffer[counter] && buffer[counter] != '\n')
		counter++;
	finalstr = malloc(sizeof(char) * counter + 2);
	if (!finalstr)
		return (NULL);
	counter = 0;
	while (buffer[counter] && buffer[counter] != '\n')
	{
		finalstr[counter] = buffer[counter];
		counter++;
	}
	if (buffer[counter] == '\n')
	{
		finalstr[counter] = buffer[counter];
		counter++;
	}
	finalstr[counter] = '\0';
	return (finalstr);
}

static char	*ft_nextgnl(char *buffer)
{
	int		counter;
	int		next_counter;
	char	*nextstr;

	counter = 0;
	while (buffer[counter] && buffer[counter] != '\n')
		counter++;
	if (!buffer[counter])
	{
		free (buffer);
		return (NULL);
	}
	nextstr = malloc(sizeof(char *) * (ft_bufferlen(buffer) - counter + 1));
	if (!nextstr)
	{
		free (nextstr);
		return (NULL);
	}
	next_counter = 0;
	counter++;
	while (buffer[counter])
		nextstr[next_counter++] = buffer[counter++];
	nextstr[next_counter] = '\0';
	free (buffer);
	return (nextstr);
}
