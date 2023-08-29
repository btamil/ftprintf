/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:12:28 by tponnusa          #+#    #+#             */
/*   Updated: 2022/12/15 18:15:52 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_nbr(int n);
int		ft_print_str(char *s);
int		ft_print_hex(unsigned int n, const char c);
int		ft_print_ptr(unsigned long long n);
int		ft_print_percent(void);
int		ft_print_unsigned(unsigned int n);

#endif