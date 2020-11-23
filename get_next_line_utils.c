/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstoneho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:04:19 by mstoneho          #+#    #+#             */
/*   Updated: 2020/11/13 20:04:21 by mstoneho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *s, int c)
{
	while (s != NULL && *s)
	{
		if (*(char*)s++ == c)
			return ((char*)--s);
	}
	return (c == '\0' ? (char*)s : NULL);
}

char			*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == s2)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1));
	return (s2);
}

size_t			ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	while (NULL != str && str[len] != '\0')
		len++;
	return (len);
}

char			*ft_strlcpy(char *dest, char const *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((char*)dest + i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (NULL == str)
		return (NULL);
	tmp = ft_strlcpy(str, s1, s1_len);
	ft_strlcpy(tmp, s2, s2_len);
	return (str);
}
