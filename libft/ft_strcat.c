/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:33:04 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 11:39:27 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	len_dest;
	int	i;

	i = 0;
	len_dest = ft_strlen(dest);
	while (src[i])
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';
	return (dest);
}
