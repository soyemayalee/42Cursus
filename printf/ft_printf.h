/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:23:43 by mayalee           #+#    #+#             */
/*   Updated: 2022/12/06 20:35:31 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		check_format(va_list args, const char temp);
int		percent_printer(void);
int		num_printer(int n);
int		str_printer(char *s);
int		hex_printer(unsigned int n, const char temp);
void	hex_convert(unsigned int n, const char temp);
int		get_hex_length(unsigned int n);
int		pointer_printer(unsigned long long ptr);
void	pointer_convert(uintptr_t n);
int		get_ptr_length(uintptr_t n);
int		unsigned_printer(unsigned int num);
char	*unsigned_itoa(unsigned int n);
int		get_ui_length(unsigned int n);
int		char_printer(int c);
char	*ft_itoa(int n);

#endif
