/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:11:20 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/15 17:42:20 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int num, const char c)
{
	int	len;

	len = 0;
	if (num == 0)
		return (ft_print_char('0'));
	if (num >= 16)
	{
		ft_print_hex(num / 16, c);
		ft_print_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
		{
			if (c == 'x')
				ft_print_char(num - 10 + 'a');
			else if (c == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
	len = ft_hex_len(num);
	return (len);
}
