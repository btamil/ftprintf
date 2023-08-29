/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:17:43 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/15 18:25:49 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len ++;
	}
	return (len);
}

static	void	ft_print_ptr2(uintptr_t num)
{
	if (num >= 16)
	{
		ft_print_ptr2(num / 16);
		ft_print_ptr2(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_print_ptr2(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
