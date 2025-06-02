/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:55:48 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/07 10:47:28 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			counter++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (counter);
}

static int	count_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_memory(char **strs, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

static	char	**setting(char const *s, char c, int limit, char **strs)
{
	int		index;
	int		i;
	int		len;

	i = 0;
	len = 0;
	index = 0;
	while (index < limit)
	{
		while (s[i] && s[i] == c)
			i++;
		len = count_len(s + i, c);
		strs[index] = ft_substr(s, i, len);
		i += len;
		if (!strs[index])
		{
			free_memory(strs, index);
			return (NULL);
		}
		index++;
	}
	strs[index] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words_count;

	words_count = count_words(s, c);
	strs = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = setting(s, c, words_count, strs);
	if (!strs)
		return (NULL);
	return (strs);
}
