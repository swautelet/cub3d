/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:41:06 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:20:29 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	if (n < 0)
	{
		a = -n;
		ft_putchar_fd('-', fd);
	}
	else
		a = n;
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putchar_fd(a % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(a + '0', fd);
	}
}
