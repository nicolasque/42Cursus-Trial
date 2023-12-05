/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:14 by nico              #+#    #+#             */
/*   Updated: 2023/12/05 21:01:02 by nico             ###   ########.fr       */
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
	unsigned char	*char_dest;
	unsigned char	*char_src;
	unsigned char	byte;

	if ((dest == NULL && src == NULL) && count > 0)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	while (count--)
	{
		byte = *char_src++;
		if (char_dest == char_src)
			char_src++;
		*char_dest++ = byte;
	}
	return (dest);
}

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	char_c;
	char	*char_str;

	char_c = c;
	char_str = (char *)str;
	while (n--)
	{
		if (*char_str == char_c)
			return char_str;
		char_str++;
	}
	return NULL;
}

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *char_str1;
	unsigned char *char_str2;

	// if (!str1 || !str2)
	// 	return -1;
	char_str1 = (unsigned char *)str1;
	char_str2 = (unsigned char *)str2;
	
	while (n--)
	{
		if(*char_str1 != *char_str2)
			return (*char_str1 - *char_str2);
		char_str1++;
		char_str2++;
	}
	return (0);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

int ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strchr(const char *str, int c)
{

}