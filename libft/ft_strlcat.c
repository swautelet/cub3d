/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:16:25 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:21:17 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	res = ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (!dst || !src)
		return (0);
	if (dstsize <= i)
		res += dstsize;
	else
		res += i;
	while (src[j] && (i + 1) < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (res);
}
