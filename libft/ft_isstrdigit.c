/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:41:40 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 20:45:16 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrdigit(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}
