/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:48:03 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/15 16:35:44 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		len = ft_num_len(n);
		num = (char *)malloc(len + 1);
		if (!num)
			return (0);
		num[len] = '\0';
		while (n)
		{
			num[len - 1] = n % 10 + '0';
			n = n / 10;
			len --;
		}
		len = ft_print_str(num);
		free(num);
	}
	return (len);
}
