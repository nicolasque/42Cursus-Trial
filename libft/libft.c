/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:14 by nico              #+#    #+#             */
/*   Updated: 2023/11/23 18:55:24 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	new_c;
	unsigned char	*char_str;

	char_str = (unsigned char *)str;
	new_c = c;
	while (n--)
		*char_str++ = new_c;
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	c = s;
	i = 0;
	while (i < n)
		c[i++] = '\0';
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if ((dest == NULL && src == NULL) && n > 0)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (n--)
		*char_dest++ = *char_src++;
	return (dest);
}

void	*ft_memccpy(void *restrict dest, const void *restrict src,
	int c, size_t count)
{
	unsigned char	char_c;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	char_c = c;
	while (count--)
	{
		*char_dest++ = *char_src++;
		if (*char_src == char_c)
			return ((void *)char_dest + 1);
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char *char_dest;
	unsigned char *char_src;

	if ((dest == NULL && src == NULL) && count > 0)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (count--)
		*char_dest++ = *char_src++;
	return (dest);
}
