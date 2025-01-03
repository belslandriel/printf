/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:47:53 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/15 17:17:14 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_c(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_write_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (str[count] != '\0')
	{
		if (write(1, &str[count], 1) != 1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_write_d_i(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nb < 0)
	{
		count = ft_write_c('-');
		if (count < 0)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_write_d_i(nb / 10);
		count += ft_write_d_i(nb % 10);
	}
	else
	{
		count += ft_write_c(nb + '0');
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_write_uns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count = ft_write_uns(nb / 10);
		count += ft_write_c((nb % 10) + '0');
		if (count < 0)
			return (-1);
	}
	else
	{
		count = ft_write_c(nb + '0');
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_write_hex(unsigned int nb, int type)
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
		count = ft_write_hex(nb / 16, type);
		if (count < 0)
			return (-1);
	}
	count += ft_write_c(hex_digits[nb % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
