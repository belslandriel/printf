/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:48:06 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/13 20:39:21 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_ptr(void *arg)
{
	int					count;
	unsigned long		adress;

	if (arg == NULL)
		return (write(1, "(nil)", 5));
	adress = (unsigned long)arg;
	count = 0;
	count = ft_write_str("0x");
	count += ft_write_aux(adress, 'x');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_write_aux(unsigned long nb, int type)

{
	const char	*hex_digits;
	int			count;

	if (type == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	count = 0;
	if (nb > 15)
	{
		count = ft_write_aux(nb / 16, type);
		if (count < 0)
			return (-1);
	}
	count += ft_write_c(hex_digits[nb % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
