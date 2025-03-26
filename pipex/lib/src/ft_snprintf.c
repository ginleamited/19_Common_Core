/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:07:04 by jilin             #+#    #+#             */
/*   Updated: 2025/03/26 14:14:40 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int ft_snprintf_write(char *buf, size_t size, const char *str, int *pos)
{
	int i = 0;
	while (str[i] && *pos < (int)size - 1)
	{
		buf[*pos] = str[i++];
		(*pos)++;
	}
	return (i);
}

int ft_snprintf(char *buf, size_t size, const char *format, ...)
{
	va_list args;
	int pos = 0;
	int i = 0;
	if (!buf || size == 0)
		return (0);
	va_start(args, format);
	while (format[i] && pos < (int)size - 1)
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			pos += ft_snprintf_write(buf, size, str, &pos);
			i += 2;
		}
		else
			buf[pos++] = format[i++];
	}
	buf[pos] = '\0';
	va_end(args);
	return (pos);
}
