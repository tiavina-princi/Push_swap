/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:51:29 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/21 22:17:34 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_str(char *s)
{
	size_t	len_s;

	if (!s)
	{
		len_s = print_str("(null)");
		return (len_s);
	}
	len_s = ft_strlen(s);
	write(1, s, len_s);
	return (len_s);
}
