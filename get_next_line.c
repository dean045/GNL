/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:15:56 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/03 19:38:14 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buf;
	char			*result;
	int				ret;
	int				x;
	static char		*tmp;

	x = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd == -1 || !buf)
		return (NULL);
	while (x < 1)
	{
		if (tmp && get_new_line(tmp) > 0)
		{
			result = ft_substr(tmp, 0, get_new_line(tmp) + 1);
			tmp = ft_substr(tmp, get_new_line(tmp) + 1, ft_strlen(tmp) - get_new_line(tmp));
		}
		else
		{
			ret = read(fd, buf, BUFFER_SIZE);
			buf[ret]= '\0';
			x = get_new_line(buf);
			if (x > 0)
			{
				result = ft_strjoin(tmp, ft_substr(buf, 0, BUFFER_SIZE - x + 1));
				free(tmp);
				tmp = ft_substr(buf, x + 1, BUFFER_SIZE);
			}
			else
				tmp = ft_strjoin(tmp, buf);
		}
	}
	return (result);
}
