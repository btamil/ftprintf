/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:09:44 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/18 17:26:22 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf2(va_list args, const char ch)
{
	int	len;

	len = 0;
	if (ch == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (ch == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (ch == 'd' || ch == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (ch == 'x' || ch == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), ch);
	else if (ch == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (ch == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (ch == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_print_char(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			len += ft_printf2(arg_ptr, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(arg_ptr);
	return (len);
}
