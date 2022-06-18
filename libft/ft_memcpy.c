/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:51:00 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:20:09 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*res;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	res = dst;
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (res);
}
