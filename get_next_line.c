/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:15:56 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/06 14:55:34 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_dupfree(char *s, unsigned int start)
{
	unsigned int	i;
	unsigned int	len;
	char			*result;
	
	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	if (*s)
		free(s);
	return (result);
}


char *get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	char			*result;
	int				ret;
	static char		*tmp;

	if (fd == -1)
		return (NULL);
	while (!tmp || get_new_line(tmp) < 1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret]= '\0';
		tmp = ft_strjoin(tmp, buf);
		if (ret < BUFFER_SIZE)
			break;
	}
	result = ft_substr(tmp, 0, get_new_line(tmp) + 1);
	tmp = ft_dupfree(tmp, get_new_line(tmp) + 1);
	return (result);
}
