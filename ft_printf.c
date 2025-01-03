/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:33:35 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/13 16:30:53 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_analize(const char type, va_list args)
{
	if (type == 'c')
		return ((char)ft_write_c(va_arg(args, int)));
	if (type == 's')
		return (ft_write_str(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_write_d_i(va_arg(args, int)));
	if (type == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	if (type == 'u')
		return (ft_write_uns(va_arg(args, unsigned int)));
	if (type == 'X' || type == 'x')
		return ((char)ft_write_hex(va_arg(args, int), type));
	if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	int			res;
	va_list		args;

	va_start (args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			res = ft_analize(format[i], args);
		}
		else
			res = ft_write_c(format[i]);
		if (res < 0)
			return (-1);
		count += res;
		i++;
	}
	va_end (args);
	return (count);
}
