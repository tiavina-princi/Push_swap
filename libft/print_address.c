/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:21:23 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/25 09:20:52 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_address_hexa(unsigned long address, size_t *len)
{
	char	*str;

	if (address >= 16)
		print_address_hexa(address / 16, len);
	str = "0123456789abcdef";
	*len += print_char(str[address % 16]);
}

size_t	print_address(void *ptr)
{
	size_t	len;

	len = 0;
	if (!ptr)
	{
		len = print_str("(nil)");
		return (len);
	}
	len += print_str("0x");
	print_address_hexa((long)ptr, &len);
	return (len);
}
