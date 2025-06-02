/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:16:16 by tiarandr          #+#    #+#             */
/*   Updated: 2025/04/07 11:05:44 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dup_line(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != '\n')
		len++;
	str = malloc((len + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_custom(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str [j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
