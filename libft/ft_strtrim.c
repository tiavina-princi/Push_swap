/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:50:39 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/14 10:55:12 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_addess_of_begining(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	find_address_of_end(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]) != NULL)
	{
		if (j == 0)
			return (0);
		j--;
	}
	return (j + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	b_addr;
	size_t	e_addr;
	size_t	len;

	e_addr = find_address_of_end(s1, set);
	if (e_addr == 0)
	{
		str = ft_strdup("\0");
		return (str);
	}
	b_addr = find_addess_of_begining(s1, set);
	len = 1 + e_addr - b_addr;
	str = malloc((len) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s1 + b_addr), len);
	return (str);
}
