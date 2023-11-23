/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:14 by nico              #+#    #+#             */
/*   Updated: 2023/11/23 15:19:54 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	new_c;
	unsigned char	*char_str;

	char_str = (unsigned char *)str;
	new_c = c;
	i = 0;
	while (i < n)
		char_str[i++] = new_c;
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
	size_t	i;
	
	return (dest);
}