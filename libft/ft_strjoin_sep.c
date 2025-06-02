/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:15:38 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 11:15:44 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_lenstrs(char **strs, int size)
{
	int	len;
	int	j;
	int	i;

	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		j = ft_strlen(strs[i]);
		len += j;
		i++;
	}
	return (len);
}

static void	setting(char *str, char **strs, int size, char	*sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < size)
	{
		if (i == 0)
			ft_strcpy(str, strs[i]);
		else
			ft_strcat(str, strs[i]);
		if (counter < size - 1)
		{
			ft_strcat(str, sep);
			counter++;
		}
		i++;
	}
}

char	*ft_strjoin_sep(char **strs, int size, char *sep)
{
	char	*str;
	int		len_strs;
	int		size_sep;
	int		total_len;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	len_strs = get_lenstrs(strs, size);
	size_sep = ft_strlen(sep) * (size - 1);
	total_len = len_strs + size_sep + 1;
	str = malloc((total_len) * sizeof(char));
	if (!str)
		return (NULL);
	setting(str, strs, size, sep);
	return (str);
}
