/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:15:56 by jilin             #+#    #+#             */
/*   Updated: 2025/02/27 01:02:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static void	ft_putstr(const char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s++, 1);
		(*count)++;
	}
}

static void	ft_putnbr(int n, int *count)
{
	char c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}

static void	ft_puthex(unsigned int n, int *count)
{
	char *hex = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16, count);
	write(1, &hex[n % 16], 1);
	(*count)++;
}

int	ft_print(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int), &count);
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned int), &count);
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, format, 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	int count;

	// Test ft_print
	count = ft_print("Strings: %s, Integers: %d, Hex: %x, Percent: %%\n", "Hello", 42, 255);
	ft_print("Characters written: %d\n", count);

	// Compare with printf
	printf("Strings: %s, Integers: %d, Hex: %x, Percent: %%\n", "Hello", 42, 255);
	printf("Characters written: %d\n", count);

	return (0);
}

/* ************************************************************************** */
#include <unistd.h> //→ Provides write() function for output.
#include <stdarg.h> //→ Provides macros (va_list, va_start, va_arg, va_end) to handle variable arguments.
#include <stdio.h> //→ Included for testing with printf().
#include <limits.h> //→ Defines INT_MIN (-2147483648), useful for handling integer overflow.

static void	ft_putstr(const char *s, int *count)
// const char *s → Pointer to the string to print.
// int *count → Pointer to the character count.
{
	if (!s)
		s = "(null)";
	// If s is NULL, print "(null)" instead.
	while (*s)
		*count += write(1, s++, 1);
	// Iterates through s, writing each character and updating count.
}

static void	ft_putnbr_base(long n, int base, char *digits, int *count)
// long n → Allows handling of int values safely (prevents overflow when n == INT_MIN).
// int base → Specifies the numerical base (10 for decimal, 16 for hexadecimal).
// char *digits → Holds the characters representing digits (e.g., "0123456789abcdef" for base 16).
// int *count → Pointer to a counter tracking the number of characters printed.
{
	if (n < 0)
	{
		if (n == INT_MIN) // Handle overflow case
		{
			ft_putstr("-2147483648", count);
			return;
		}
		write(1, "-", 1);
		(*count)++;
		n = -n;
		// If n is negative:
		// If n == INT_MIN (-2147483648), directly print "-2147483648" (to avoid overflow when negating).
		// Otherwise, print "-" and convert n to positive.
	}
	if (n >= base)
		ft_putnbr_base(n / base, base, digits, count);
	// Recursively divides n by base to extract higher-order digits first.
	write(1, &digits[n % base], 1);
	(*count)++;
	// Converts the remainder n % base to a character using digits[] and writes it to standard output.
}

int	ft_printf(const char *format, ...)
// const char *format → Format string containing text and format specifiers.
// ... → Variadic arguments.
{
	va_list args;
	int count = 0;

	va_start(args, format);
	// va_list args → Stores the list of arguments.
	// int count = 0 → Tracks the number of printed characters.
	// va_start(args, format) → Initializes args for traversal.
	while (*format)
	// Iterates through format, processing characters one by one.
	{
		if (*format == '%' && *(++format))
		// If format encounters %, check the next character to determine the specifier.
		{
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &count);
			// va_arg(args, char *) retrieves the next argument as a char * (string).
			// Calls ft_putstr to print it.
			else if (*format == 'd')
				ft_putnbr_base((long)va_arg(args, int), 10, "0123456789", &count);
			// va_arg(args, int) retrieves the next argument as an int.
			// Casts it to long to prevent integer overflow.
			// Calls ft_putnbr_base with base 10.
			else if (*format == 'x')
				ft_putnbr_base(va_arg(args, unsigned int), 16, "0123456789abcdef", &count);
			// va_arg(args, unsigned int) retrieves an unsigned int (to ensure positive values).
			// Calls ft_putnbr_base with base 16.
			else if (*format == '%')
				count += write(1, "%", 1);
			// Prints a literal % when encountering %%.
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
			// Prints % followed by the unknown character.
		}
		else
			count += write(1, format, 1);
		// If not a % specifier, print the character normally.
		format++;
		// Moves to the next character.
	}
	va_end(args);
	return (count);
	// va_end(args) → Cleans up va_list.
	// Returns the total count of printed characters.
}

int main (void)
{
	ft_printf("Test string: %s, number: %d, hex: %x, percent: %%\n", "Hello", -2147483648, 255);
	printf("Test string: %s, number: %d, hex: %x, percent: %%\n", "Hello", -2147483648, 255);
	return (0);
	// Calls ft_printf with:
	// String: "Hello"
	// Integer: -2147483648
	// Hexadecimal: 255 (printed as ff)
	// Percent sign: %%
	// Also calls standard printf for comparison.
}

//* EXPLANATION:
//? The ft_printf function is a simplified version of the printf function

