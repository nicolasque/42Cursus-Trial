/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:14 by nico              #+#    #+#             */
/*   Updated: 2023/12/08 03:49:25 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
* Esta función llena los primeros n bytes del área de memoria apuntada por str
* con el valor constante c. Devuelve un puntero a la zona de memoria str.
 */
void	*ft_memset(char *str, char c, size_t n)
{
	unsigned char	new_c;
	unsigned char	*char_str;

	char_str = (unsigned char *)str;
	new_c = c;
	while (n--)
		*char_str++ = new_c;
	return (str);
}

/*
* Esta función pone a cero (bytes con '0') los primeros n bytes del área de memoria apuntada por s.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	c = (char *)s;
	i = 0;
	while (i < n)
		c[i++] = 0;
}

/*
* Esta función copia n bytes desde el área de memoria src al área de memoria dest.
* Si dest y src se superponen, el comportamiento es indefinido. Devuelve un puntero a dest.
*/
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

/*
* Esta función copia bytes desde la cadena src a la cadena dest, deteniéndose después de haber copiado c
* (convertido a un unsigned char) o después de haber copiado n bytes, lo que ocurra primero.
* Devuelve un puntero al siguiente carácter en dest después de c, o NULL si c no fue encontrado en los primeros n caracteres de src.
*/
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

/*
* Esta función copia n bytes desde src a dest. Las dos cadenas pueden superponerse;
* la copia se realiza de manera no destructiva. Devuelve un puntero a dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	if ((dest == NULL && src == NULL) && count > 0)
		return (NULL);
	if (char_dest < char_src)
	{
		while (count--)
			*char_dest++ = *char_src++;
	}
	else
	{
		char_dest += count;
		char_src += count;
		while (count--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}

/*
* Esta función busca el primer carácter c (convertido a un unsigned char) en los primeros n bytes
* de la cadena str. Devuelve un puntero al carácter coincidente, o NULL si no se encontró el carácter.
*/
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

/*
* Esta función compara los primeros n bytes de las cadenas str1 y str2.
* Devuelve un entero menor, igual o mayor que cero si str1 es respectivamente menor, igual o mayor que str2.
*/
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *char_str1;
	unsigned char *char_str2;

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

int ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
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

/*
* Esta función busca el primer carácter c (convertido a un char) en la cadena str.
* Devuelve un puntero al carácter coincidente, o NULL si no se encontró el carácter.
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (char *)str;
		str++;
	}
	if (*str == c)
		return (char *)str;
	return (NULL);
}

/*
* Esta función busca el último carácter c (convertido a un char) en la cadena str.
* Devuelve un puntero al carácter coincidente, o NULL si no se encontró el carácter.
*/
char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	str += i;
	while (i-- >= 0)
	{
		if (*str == c)
			return (char *)str;
		str --;
	}
	return (NULL);
}

/*
* Esta función compara no más de n caracteres (caracteres que siguen a un carácter nulo no se comparan)
* de las cadenas str1 y str2. Devuelve un entero menor, igual o mayor que cero si str1 es respectivamente
* menor, igual o mayor que str2.
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char un1;
	unsigned char un2;

	while (n > 0)
	{
		un1 = (unsigned char )(*str1);
		un2 = (unsigned char )(*str2);
		if (un1 != un2 || *str1 == '\0')
			return (un1 - un2);
		str1 ++;
		str2 ++;
		n--;
	}
	return (0);
}

/*
* Esta función copia hasta size - 1 caracteres de la cadena de origen a dest, añadiendo un carácter nulo
* final. Devuelve la longitud total de la cadena que intentó crear, que es la longitud de src.
*/
size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	int i;

	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
		size --;
	}
	if (size != 0)
		dest[i] = '\0';
	return ft_strlen(src);
}

/*
* Esta función añade la cadena de origen a la cadena de destino, pero para un total de no más de size
* caracteres. Devuelve la longitud inicial de dest más la longitud de src.
*/
size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	if ((!dest || !src) && size == 0)
		return (0);
	size_t dest_len = ft_strlen(dest);
	size_t src_len = ft_strlen(src);
	size_t i = 0;
	
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + i < size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
* Esta función localiza la primera aparición de la cadena little en la cadena big, donde no más de len
* caracteres son buscados. Si little es una cadena vacía, big se devuelve. Si little no ocurre en big para
* len caracteres, se devuelve NULL.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (little[0] == '\0' || len == 0)
		return ((char *)big);
	while (big[i] != '\0' && len > i)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] != '\0' && i + j < len)
				j++;
			if (j == ft_strlen(little))
				return ((char *)big + i);
		}
		i++;
	}
	return NULL;
}

/*
* Esta función convierte la cadena inicial en str a un valor int.
*/
int	ft_atoi(const char *str)
{
	int i;
	int minus_counter;
	int exit;
	
	i = 0;
	minus_counter = 0;
	while (ft_isspace(str[i])) i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus_counter ++;	
	exit = 0;
	while (ft_isdigit(str[i]))
		exit = 10 * exit + (str[i++] - '0');
	if (minus_counter % 2 != 0)
		return (-exit);
	return (exit);
}

/*
* Esta función asigna memoria para un arreglo de nitems elementos, cada uno de tamaño size bytes,
* y luego escribe ceros en el espacio asignado.
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	void *exit;

	exit = malloc(nitems * size);
	
	if (exit == NULL)
		return NULL;
	ft_bzero(exit, nitems * size);
	return (exit);
}

/*
* Esta función devuelve un puntero a una nueva cadena que es una copia de la cadena str.
*/
char	*ft_strdup(const char *str)
{
	char	*new_str;
	int	i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (new_str == NULL)
		return NULL;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
	
}

/*
========================================================================
                    Second part
========================================================================
*/


/*
* Esta función devuelve una cadena de caracteres que es una subcadena de la cadena s.
* La subcadena comienza en el índice start y tiene un tamaño máximo de len.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*exit;

	exit = (char *)malloc(len + 1);
	if (exit == NULL || s == NULL)
		return NULL;
	if (start >= ft_strlen(s))
		return (exit);
	i = 0;
	while (i < len)
	{
		exit[i] = s[start + i]; 
		i++;
	}
	exit[i] = '\0';
	return (exit);
}

/*
* Esta función concatena dos cadenas de caracteres.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*exit;
	int	i;

	if (s1 == NULL || s2 == NULL)
		return NULL;
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);

	if (exit == NULL)
		return NULL;
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (exit);
}

/*
* Esta función devuelve una copia de s1 con los caracteres especificados en set eliminados
* del principio y del final de la cadena.
*/
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char *exit;
// 	int i;
// 	int j;
// 	int	start_trim = 0;

// 	if (s1 == NULL || set == NULL)
// 		return NULL;
// 	i = 0;
// 	while (s1[i])
// 	{
// 		j = 0;
// 		while(set[j])
// 		{
// 			if (s1[i] == set[j++])
// 			{
// 				start_trim ++;
// 				break;
// 			}
// 		}
// 		if (j >= ft_strlen(set))
// 			break;
// 		i++;
// 	}

// 	printf("Viejo string: %s \n", s1);
// 	exit = ft_substr(s1, start_trim, (ft_strlen(s1) - start_trim));
// 	printf("Nuevo string: %s \n", exit);
// 	return 0;
// }
char	*ft_strtrim(char const *s1, char const *set)
{
	char *exit;

	if (s1 == NULL || set == NULL)
		return NULL;
	while (*s1)
	{
	    if (!ft_strchr(set, *s1))
	        break;
	    s1++;
	}
	while (*s1)
	{
		if (!ft_strrchr(set, *s1))
			break;
		s1++;
	}
	exit = malloc(ft_strlen(s1));
	
	return (ft_strdup(s1));
}

// int main(int argc, char const *argv[])
// {
// 	ft_strtrim("   Hello world", " Ht");
// 	return 0;
// }
