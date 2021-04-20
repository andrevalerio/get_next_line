/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:31:39 by avalerio          #+#    #+#             */
/*   Updated: 2021/03/06 11:00:00 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *temp_s;
	unsigned char *temp_d;

	temp_s = (unsigned char *)src;
	temp_d = (unsigned char *)dest;
	if ((temp_s == NULL) && (temp_d == NULL))
		return (NULL);
	if (temp_d < temp_s)
	{
		while (n--)
			*temp_d++ = *temp_s++;
	}
	else
	{
		temp_d = temp_d + n;
		temp_s = temp_s + n;
		while (n--)
			*--temp_d = *--temp_s;
	}
	return (dest);
}

char	*strjoin_free(char *s1_stc, char *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*s3;

	if (!s1_stc && !s2)
		return (0);
	s1_l = ft_strlen(s1_stc);
	s2_l = ft_strlen(s2);
	if (!(s3 = malloc(sizeof(char) * (s1_l + s2_l + 1))))
		return (NULL);
	ft_memmove(s3, s1_stc, s1_l);
	ft_memmove(s3 + s1_l, s2, s2_l);
	s3[s1_l + s2_l] = '\0';
	free(s1_stc);
	return (s3);
}
