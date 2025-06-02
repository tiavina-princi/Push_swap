/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:14:23 by tiarandr          #+#    #+#             */
/*   Updated: 2025/04/15 04:24:56 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *buffer)
{
	char	*str;
	char	*tmp;
	int		nb_read;

	str = ft_strjoin_custom("", "");
	if (str == NULL)
		return (NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read <= 0)
			break ;
		buffer[nb_read] = '\0';
		tmp = ft_strjoin_custom(str, buffer);
		free(str);
		if (tmp == NULL)
			return (NULL);
		str = tmp;
	}
	if (nb_read <= 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static void	save_next_line(char **save, int index)
{
	size_t	len;
	int		i;
	char	*tmp;

	i = 0;
	len = ft_strlen(*save + index);
	if (len == 0)
	{
		free(*save);
		(*save) = NULL;
		return ;
	}
	tmp = malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
	{
		free(*save);
		(*save) = NULL;
		return ;
	}
	while ((*save)[index])
		tmp[i++] = (*save)[index++];
	tmp[i] = '\0';
	free(*save);
	*save = tmp;
}

static void	get_new_line(char **save, int fd, char *buffer)
{
	char	*tmp;
	char	*src;

	tmp = *save;
	src = read_fd(fd, buffer);
	if (src != NULL)
	{
		*save = NULL;
		*save = ft_strjoin_custom(tmp, src);
		free(src);
		free(tmp);
	}
	free(buffer);
}

static	char	*setting(char **save, int fd)
{
	size_t	index;
	char	*line;
	char	*buffer;

	line = NULL;
	if (*save == NULL || (ft_strchr(*save, '\n') == NULL))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		get_new_line(save, fd, buffer);
		if (*save == NULL)
			return (NULL);
	}
	line = dup_line(*save);
	if (line == NULL)
		return (NULL);
	index = ft_strlen(line);
	save_next_line(save, index);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = setting(&save, fd);
	if (line == NULL)
	{
		if (save != NULL)
			free(save);
		save = NULL;
		return (NULL);
	}
	return (line);
}
