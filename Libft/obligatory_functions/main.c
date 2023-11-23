/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:43:50 by nico              #+#    #+#             */
/*   Updated: 2023/11/23 15:16:48 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Asume que ft_memset está definida en otro lugar
void *ft_memset(void *str, int c, size_t n);
void ft_bzero(void *s, size_t n);

// Función para imprimir resultados de pruebas
void print_test_result(const char *test_desc, const char *expected, const char *received, size_t len) {
    printf("Prueba: %s\n", test_desc);
    printf("Esperado: ");
    for (size_t i = 0; i < len; ++i) {
        printf("%02x ", (unsigned char)expected[i]);
    }
    printf("\nRecibido: ");
    for (size_t i = 0; i < len; ++i) {
        printf("%02x ", (unsigned char)received[i]);
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

    // Puedes agregar más pruebas según sea necesario
	printf("---PRUEBAS DE FT_BZERO: ---\n");

	bzero(expected, sizeof(expected));
	ft_bzero(buffer, sizeof(buffer));
	print_test_result("Probar bzero" , expected, buffer, sizeof(buffer));

	printf("============================================================ \n");
	



    return 0;
}
