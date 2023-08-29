/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:49 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/14 14:58:19 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	len;

	if (size && ((count / size) >= SIZE_MAX))
		return (0);
	len = count * size;
	p = malloc(len);
	if (!p)
		return (0);
	ft_bzero(p, len);
	return (p);
}
