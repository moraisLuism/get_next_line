/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <lmorais-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:40:00 by lmorais-          #+#    #+#             */
/*   Updated: 2023/11/05 17:39:35 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_copy_to_stabuf(char *stabuf, char *buffer)
{
	char	*temp;
	char	*res;

	res = 0;
	if (!stabuf && buffer)
	{
		res = ft_strdup(buffer);
		if (!res)
			return (ft_free_stabuf(&res, 0));
		return (res);
	}
	temp = ft_strdup(stabuf);
	if (!temp)
	{
		ft_free_stabuf(&stabuf, 0);
		return (ft_free_stabuf(&temp, 0));
	}
	ft_free_stabuf(&stabuf, 0);
	res = ft_strjoin(temp, buffer);
	if (!res)
		ft_free_stabuf(&res, 0);
	ft_free_stabuf(&temp, 0);
	return (res);
}

static int	ft_new_line(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_extract_line(char *stabuf)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stabuf)
		return (ft_free_stabuf(&stabuf, 0));
	while (stabuf[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_stabuf(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stabuf[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_stabuf(char *stabuf)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stabuf)
		return (NULL);
	while (stabuf[i] != '\n')
		i++;
	if (stabuf[i + 1] == '\0')
		return (ft_free_stabuf(&stabuf, 0));
	res = ft_substr(stabuf, i + 1, ft_strlen(stabuf));
	if (!res)
	{
		ft_free_stabuf(&stabuf, 0);
		return (NULL);
	}
	ft_free_stabuf(&stabuf, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	long		readbyte;
	static char	*stabuf = NULL;
	char		*line;

	line = 0;
	readbyte = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stabuf(&stabuf, 0));
	while (readbyte > 0)
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if ((readbyte <= 0 && !stabuf) || readbyte == -1)
			return (ft_free_stabuf(&stabuf, 0));
		buffer[readbyte] = '\0';
		stabuf = ft_copy_to_stabuf(stabuf, buffer);
		if (ft_new_line(stabuf))
		{
			line = ft_extract_line(stabuf);
			if (!line)
				return (ft_free_stabuf(&stabuf, 0));
			return (stabuf = ft_recreate_stabuf(stabuf), line);
		}
	}
	return (ft_free_stabuf(&stabuf, 1));
}
