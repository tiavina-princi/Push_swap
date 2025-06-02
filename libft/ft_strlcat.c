/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:18:31 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/08 11:12:17 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_size;
	size_t			src_size;
	unsigned int	i;
	unsigned int	j;

	src_size = ft_strlen(src);
	dest_size = get_len(dest);
	i = dest_size;
	j = 0;
	if (size == 0 || size <= (dest_size))
		return (src_size + size);
	while (j < size - dest_size - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_size + src_size);
}
