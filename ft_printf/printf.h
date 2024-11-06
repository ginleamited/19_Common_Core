/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:34:58 by jilin             #+#    #+#             */
/*   Updated: 2024/11/06 23:55:08 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	printf_format(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putunsignednbr(int nb);
int	ft_0xputpointerhex(unsigned long nb, int flag);
int	ft_putpointerhex(unsigned long nb, int flag);
int	ft_putnbrhex(unsigned int nb, int flag);

#endif