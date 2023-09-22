/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:29:52 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/22 18:38:58 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = ft_itoa(va_arg(args, int));
	else if (c == 's')
		count = (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		count = (ft_putchar(va_arg(args, int)));
	else if (c == '%')
		count = (ft_putchar('%'));
	else if (c == 'x' || c == 'X')
		count = (ft_pinthex(va_arg(args, unsigned int), c));
	else if (c == 'u')
		count = (ft_uitoa(va_arg(args, unsigned int)));
	else if (c == 'p')
		count = (ft_ppointer(va_arg(args, unsigned long)));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_checktype(str[i], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
