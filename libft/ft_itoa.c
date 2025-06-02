/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:21:01 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/12 07:07:09 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*setting(int n, int len)
{
	int		sign;
	char	*str;

	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign > 0)
	{
		str[0] = '-';
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	str = NULL;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	else if (n == 2147483647)
	{
		str = ft_strdup("2147483647");
		return (str);
	}
	else if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	len = get_len(n);
	str = setting(n, len);
	return (str);
}
