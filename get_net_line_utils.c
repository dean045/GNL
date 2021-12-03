/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:59:12 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/03 19:20:52 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nouveau;

	if (s && start >= ft_strlen(s))
	{
		nouveau = malloc(sizeof(char));
		nouveau[0] = '\0';
		return (nouveau);
	}
	nouveau = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!nouveau || !s)
		return (NULL);
	nouveau[len] = '\0';
	while (i < len && s[i + start])
	{
		nouveau[i] = (char)s[i + start];
		i++;
	}
	return (nouveau);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*n;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	n = malloc(sizeof(char) * (len + 1));
	if (!n)
		return (NULL);
	i = -1;
	while (++i < len)
		n[i] = s[i];
	n[i] = '\0';
	return (n);
}

int	get_new_line(char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\0' || i == ft_strlen(src))
		return (-1);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new;

	if (!s1)
		return (ft_strdup(s2));
	if(!s2)
		return (ft_strdup(s1));
	len1 = (size_t) ft_strlen(s1);
	len2 = (size_t)ft_strlen(s2);
	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	new[len1 + len2] = '\0';
	while (++i <= len1 || i <= len2)
	{
		if ((i < len1 && s1[len1 - i]) || (i == len1))
			new[len1 - i] = (char)s1[len1 - i];
		if ((i < len2 && s2[len2 - i]) || (i == len2))
			new[len2 + len1 - i] = (char)s2[len2 - i];
	}
	return (new);
}
