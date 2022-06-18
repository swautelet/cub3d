/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:51:04 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:21:58 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	return (str);
}
