/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:59:00 by xzhang            #+#    #+#             */
/*   Updated: 2023/09/19 16:42:12 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) +1);
	if (!dest)
		return (NULL);
	while (*s)
		dest[i++] = *s++;
	dest[i] = '\0';
	return (dest);
}
/* use in ft_itoa.c to if (n == -2147483648)return (ft_strdup("-2147483648")*/
