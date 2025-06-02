/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:52:09 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/21 22:30:11 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

size_t	print_unsigned_int(unsigned int n)
{
	char			*str;
	unsigned long	nb;
	int				len_nb;
	int				i;

	i = 0;
	nb = n;
	if (nb == 0)
		print_char('0');
	len_nb = find_len(n);
	str = malloc((len_nb + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (nb > 0)
	{
		str[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	str[i] = '\0';
	while (i > 0)
		print_char(str[--i]);
	free(str);
	return (len_nb);
}
