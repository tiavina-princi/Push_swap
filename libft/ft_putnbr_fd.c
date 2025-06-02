/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:55:21 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/12 07:08:57 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nb;
	char	str[100];

	nb = n;
	i = 0;
	if (nb == 0)
		write(fd, "0", 1);
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	while (i > 0)
		write(fd, &str[--i], 1);
}
