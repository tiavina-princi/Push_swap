/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:44:01 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/21 22:26:14 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_hexadecimal(unsigned int n)
{
	int		i;
	char	*str;
	size_t	len;

	len = 0;
	i = 0;
	if (n >= 16)
		len += print_hexadecimal(n / 16);
	i = (n % 16);
	str = "0123456789abcdef";
	len += print_char(str[i]);
	return (len);
}
