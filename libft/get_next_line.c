/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:14:28 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 16:50:46 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*ft_memmove2(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

static char			*ft_strjoingnl(const char *s1, const char *s2)
{
	size_t			len1;
	size_t			len2;
	char			*res;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memmove2(res, s1, len1);
	ft_memmove2(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	free((char *)s1);
	return (res);
}

int				has_ret(char *str)
{
	int				i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*save;
	char			*buff;
	int				readbytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	readbytes = 1;
	while (!has_ret(save) && readbytes != 0)
	{
		if ((readbytes = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[readbytes] = '\0';
		save = ft_strjoingnl(save, buff);
	}
	free(buff);
	*line = ft_clean(save);
	save = ft_clean_save(save);
	if (readbytes == 0)
		return (0);
	return (1);
}
