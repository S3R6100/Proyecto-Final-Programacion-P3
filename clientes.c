#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"
FILE *archivoFacturas;
FILE *archivo;

/*int validarCedulaEcuatoriana(const char *cedula) {
    // Verificar que la cédula tenga 10 dígitos
    if (strlen(cedula) != 10) {
        return 0; // Cédula incorrecta por longitud
    }

    // Verificar que todos los caracteres sean dígitos
    for (int i = 0; i < 10; ++i) {
        if (!isdigit(cedula[i])) {
            return 0; // Cédula incorrecta por no ser un número
        }
    }

    // Obtener los primeros 9 dígitos como un número entero
    int digitos = atoi(cedula);

    // Verificar el décimo dígito
    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int digito = digitos % 10;
        digitos /= 10;

        // Multiplicar por 2 los dígitos en posición impar
        if (i % 2 != 0) {
            digito *= 2;

            // Restar 9 si el resultado es mayor a 9
            if (digito > 9) {
                digito -= 9;
            }
        }

        suma += digito;
    }

    // Calcular el dígito verificador
    int digitoVerificador = (10 - (suma % 10)) % 10;

    // Verificar que el dígito verificador sea igual al décimo dígito de la cédula
    return digitoVerificador == (cedula[9] - '0');
}*/

void ingresarCliente(char clientes[][CLIENTES_COLUMNAS], int *numClientes, char cedula[], char nombre[]) {
  FILE *archivoClientes;
    archivoClientes = fopen("clientes.txt", "a+");

    if (archivoClientes != NULL) {
        if (cedula[0] == '\0') {
            int cedulaValida = 0;
            while (!cedulaValida) {
                printf("Ingrese el número de cédula ecuatoriana (10 dígitos): ");
                scanf("%s", cedula);

                if (validarCedula(cedula)) {
                    printf("La cédula es válida.\n");
                    cedulaValida = 1;
                } else {
                    printf("La cédula no es válida. Por favor, inténtelo nuevamente.\n");
                }
            }
        }

        if (nombre[0] == '\0') {
            printf("Ingrese el nombre del cliente: ");
            scanf("%s", nombre);
        }

        fprintf(archivoClientes, "%s %s\n", cedula, nombre);
        fclose(archivoClientes);
        printf("Cliente almacenado en 'clientes.txt' exitosamente.\n");
    } else {
        printf("No se pudo abrir el archivo 'clientes.txt' para almacenar el cliente.\n");
    }
}

void modificarCliente(char clientes[][CLIENTES_COLUMNAS], int numClientes, char cedula[]) {
    FILE *archivoClientes;
    archivoClientes = fopen("clientes.txt", "r+");

    if (archivoClientes != NULL) {
        char cedulaActual[15];
        char nombreActual[20];
        long posicion = 0;
        int encontrado = 0;

        printf("Ingrese la nueva cedula del cliente: ");
        char nuevaCedula[15];
        scanf("%s", nuevaCedula);

        rewind(archivoClientes);

        while (fscanf(archivoClientes, "%s %s", cedulaActual, nombreActual) != EOF) {
            posicion = ftell(archivoClientes);

            if (strcmp(cedulaActual, cedula) == 0) {
                fseek(archivoClientes, posicion - strlen(cedulaActual) - strlen(nombreActual) - 2, SEEK_SET);
                fprintf(archivoClientes, "%s %s", nuevaCedula, nombreActual);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Cliente no encontrado.\n");
        }

        fclose(archivoClientes);
    } else {
        printf("No se pudo abrir el archivo 'clientes.txt' para modificar el cliente.\n");
    }
}

void consultarCliente(char clientes[][CLIENTES_COLUMNAS], int numClientes, char cedula[]) {
    FILE *archivoClientes;
    archivoClientes = fopen("clientes.txt", "r");

    if (archivoClientes != NULL) {
        char cedulaActual[15];
        char nombreActual[20];
        int encontrado = 0;

        while (fscanf(archivoClientes, "%s %s", cedulaActual, nombreActual) != EOF) {
            if (strcmp(cedulaActual, cedula) == 0) {
                printf("Cedula: %s\n", cedulaActual);
                printf("Nombre: %s\n", nombreActual);
                printf("-------------------\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Cliente no encontrado.\n");
        }

        fclose(archivoClientes);
    } else {
        printf("No se pudo abrir el archivo 'clientes.txt' para consultar el cliente.\n");
    }
}

void verClientes(char clientes[][CLIENTES_COLUMNAS], int numClientes) {
    FILE *archivoClientes;
    archivoClientes = fopen("clientes.txt", "r");

    if (archivoClientes != NULL) {
        char cedula[15];
        char nombre[20];

        printf("Lista de clientes:\n");

        while (fscanf(archivoClientes, "%s %s", cedula, nombre) != EOF) {
            printf("Cedula: %s\n", cedula);
            printf("Nombre: %s\n", nombre);
            printf("-------------------\n");
        }

        fclose(archivoClientes);
    } else {
        printf("No se pudo abrir el archivo 'clientes.txt' para mostrar clientes.\n");
    }
}
