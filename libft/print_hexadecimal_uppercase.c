/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_uppercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:25:29 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/21 22:27:19 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_hexadecimal_uppercase(unsigned int n)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (n >= 16)
		len += print_hexadecimal_uppercase(n / 16);
	i = (n % 16);
	str = "0123456789ABCDEF";
	len += print_char(str[i]);
	return (len);
}
