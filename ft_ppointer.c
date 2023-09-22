/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:13:33 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/19 21:19:56 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_phexapointer(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n < 16)
	{
		ft_putchar(hex[n]);
		count++;
	}
	else
	{
		count += ft_phexapointer(n / 16);
		count += ft_phexapointer(n % 16);
	}
	return (count);
}

int	ft_ppointer(unsigned long n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	return (ft_phexapointer(n) + 2);
}
