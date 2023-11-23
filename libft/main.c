/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:43:50 by nico              #+#    #+#             */
/*   Updated: 2023/11/23 16:17:15 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Asume que ft_memset está definida en otro lugar
void *ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);


// Función para imprimir resultados de pruebas
void print_test_result(const char *test_desc, const char *expected, const char *received, size_t len) {
    printf("Prueba: %s\n", test_desc);
    printf("Esperado: ");
    for (size_t i = 0; i < len; ++i) {
        if (isprint(expected[i])) {
            printf("%c ", expected[i]);
        } else {
            printf(". ");  // Representa caracteres no imprimibles
        }
    }
    printf("\nRecibido: ");
    for (size_t i = 0; i < len; ++i) {
        if (isprint(received[i])) {
            printf("%c ", received[i]);
        } else {
            printf(". ");  // Representa caracteres no imprimibles
        }
    }
    printf("\nResultado: ");
    if (memcmp(expected, received, len) == 0) {
        printf("\033[0;32mÉxito\033[0m\n");
    } else {
        printf("\033[0;31mFallo\033[0m\n");
    }
    printf("\n");
}

int main() {
    char buffer[20];
    char expected[20];
	char source[20];

	
	printf("\n============================================================ \n");
	printf("---PRUEBAS DE FT_MEMSET: ---\n");
    // Prueba 1: Llenar con 'A'
    memset(expected, 'A', sizeof(expected));
    ft_memset(buffer, 'A', sizeof(buffer));
    print_test_result("Llenar con 'A'", expected, buffer, sizeof(buffer));

    // Prueba 2: Llenar con '\0'
    memset(expected, '$', sizeof(expected));
    ft_memset(buffer, '$', sizeof(buffer));
    print_test_result("Llenar con '$'", expected, buffer, sizeof(buffer));

	printf("============================================================ \n");

	printf("---PRUEBAS DE FT_BZERO: ---\n");

	bzero(expected, sizeof(expected));
	ft_bzero(buffer, sizeof(buffer));
	print_test_result("Probar bzero" , expected, buffer, sizeof(buffer));

	printf("============================================================ \n");
    // Puedes agregar más pruebas según sea necesario
	printf("---PRUEBAS DE FT_MEMCPY: ---\n");

    // Prueba 1: Copia simple
    strcpy(source, "Test");
    memcpy(expected, source, 5);
    ft_memcpy(buffer, source, 5);
    print_test_result("Copia simple", expected, buffer, 5);

    // Prueba 2: Copia con overlap (destino antes que fuente)
    memcpy(source, "OverlapTest", 12);
    memcpy(expected, source, 12);
    memmove(expected + 2, expected, 10); // Usando memmove para el caso de overlap
    ft_memcpy(source, source, 10);
    print_test_result("Copia con overlap (destino antes que fuente)", expected, source + 2, 10);

    // Prueba 3: Copia con overlap (fuente antes que destino)
    memcpy(source, "OverlapTest", 12);
    memcpy(expected, source, 12);
    memmove(expected, expected + 2, 10); // Usando memmove para el caso de overlap
    ft_memcpy(source, source + 2, 10);
    print_test_result("Copia con overlap (fuente antes que destino)", expected, source, 10);

    // Prueba 4: Copia de una gran cantidad de datos
    ft_memset(source, 'x', sizeof(source));
    memcpy(expected, source, sizeof(source));
    ft_memcpy(buffer, source, sizeof(source));
    print_test_result("Copia de una gran cantidad de datos", expected, buffer, sizeof(source));

    // Prueba 5: Copia con longitud cero
    strcpy(source, "ZeroLength");
    strcpy(expected, source);
    ft_memcpy(buffer, source, 0);
    print_test_result("Copia con longitud cero", expected, buffer, strlen(expected) + 1);

    return 0;

}





	// printf("---PRUEBAS DE FT_MEMCPY: ---\n");
	
	// char src[20] = "Hello world";
	// char dest[20];

	// //Hacemos la operacion con la funcion original
	// memcpy(dest, src, sizeof(src));
	// print_test_result("Coapiando 'hello world'", src, dest, strlen(dest) );
	// //resetanos a 0 los valores
	// ft_bzero(src, sizeof(src));
	// ft_bzero(dest, sizeof(dest));
	// //Usamos a funcion que yo he creado
	// ft_memcpy(dest, src, strlen(src));
	
	// print_test_result("Coapiando 'hello world'", src, dest, strlen(dest) );
    // return 0;


















