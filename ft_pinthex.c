/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:12:00 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/22 09:09:43 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pinthex(unsigned int n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_putchar(hex[n]);
		count++;
	}
	else
	{
		count += ft_pinthex(n / 16, c);
		count += ft_pinthex(n % 16, c);
	}
	return (count);
}
