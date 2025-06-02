/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:55:21 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/21 22:17:38 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_nbr(int n)
{
	int		i;
	long	nb;
	char	str[11];
	size_t	len;

	nb = n;
	i = 0;
	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	while (i > 0)
		len += print_char(str[--i]);
	return (len);
}
