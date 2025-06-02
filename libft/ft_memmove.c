/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:43:52 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/17 16:16:20 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (dest);
	i = n;
	if ((unsigned char *)dest > (unsigned char *)src)
	{
		while (i > 0)
		{
			--i;
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
