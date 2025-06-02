/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:48:02 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/25 09:20:41 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	argument_counter(const char *s)
{
	int	i;
	int	argc;

	i = 0;
	argc = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c' || s[i] == 's' || s[i] == 'd' || s[i] == 'p'
				|| s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
				argc++;
		}
		i++;
	}
	return (argc);
}

static void	find_arg_type(char c, va_list *arg_type, int *len)
{
	if (c == 'c')
		*len += print_char((char)va_arg(*arg_type, int));
	else if (c == 'd' || c == 'i')
		*len += print_nbr(va_arg(*arg_type, int));
	else if (c == 's')
		*len += print_str(va_arg(*arg_type, char *));
	else if (c == '%')
		*len += print_char('%');
	else if (c == 'u')
		*len += print_unsigned_int(va_arg(*arg_type, unsigned int));
	else if (c == 'p')
		*len += print_address(va_arg(*arg_type, void *));
	else if (c == 'x')
		*len += print_hexadecimal(va_arg(*arg_type, unsigned int));
	else if (c == 'X')
		*len += print_hexadecimal_uppercase(va_arg(*arg_type, unsigned int));
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg_type;
	int		argc;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	argc = argument_counter(format);
	va_start(arg_type, format);
	while (argc > 0 || format[i])
	{
		while (format[i] != '%' && format[i])
			len += print_char(format[i++]);
		if (format[i] == '%')
		{
			i++;
			find_arg_type(format[i], &arg_type, &len);
			i++;
		}
		argc--;
	}
	va_end(arg_type);
	return (len);
}
