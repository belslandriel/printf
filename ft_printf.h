/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:26:30 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/13 20:39:34 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	ft_write_c(char c);

int	ft_write_str(char *str);

int	ft_write_d_i(int nb);

int	ft_write_uns(unsigned int nb);

int	ft_write_hex(unsigned int nb, int type);

int	ft_write_ptr(void *arg);

int	ft_printf(const char *format, ...);

int	ft_write_aux(unsigned long nb, int type);

#endif
