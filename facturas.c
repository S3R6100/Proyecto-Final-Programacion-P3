#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"
#include "fecha.h"
#include "validar.h"

void facturar() { // Añadir llave de apertura
    char archivo[MAX_NOMBRE];
    printf("Ingrese el nombre del archivo de facturas: ");
    scanf("%s", archivo);

    FILE *f = fopen(archivo, "a+");
    if (f == NULL) {
        printf("Error al abrir el archivo de facturas.\n");
        return;
    }

    char cedula[11];
    char nombre[MAX_NOMBRE];
    int numProductos;
    float total = 0;

    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);
    if (validarCedula(cedula)) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombre);
        printf("Ingrese el número de productos: ");
        scanf("%d", &numProductos);
        if (numProductos > 0 && numProductos <= MAX_PRODUCTOS) {
            char nombreProducto[numProductos][MAX_NOMBRE];
            int cantidad[numProductos];
            float precio[numProductos];
            for (int i = 0; i < numProductos; i++) {
                printf("Ingrese el nombre del producto %d: ", i + 1);
                scanf("%s", nombreProducto[i]);
                printf("Ingrese la cantidad del producto %d: ", i + 1);
                scanf("%d", &cantidad[i]);
                printf("Ingrese el precio del producto %d: ", i + 1);
                scanf("%f", &precio[i]);
                total += cantidad[i] * precio[i];
            }
            char *fecha = obtenerFecha();
            fprintf(f, "%s %s %s %f %d\n", fecha, cedula, nombre, total, numProductos);
            for (int i = 0; i < numProductos; i++) {
                fprintf(f, "%s %d %f\n", nombreProducto[i], cantidad[i], precio[i]);
            }
            printf("Factura generada.\n");
            printf("Fecha: %s\n", fecha);
            printf("Cédula: %s\n", cedula);
            printf("Nombre: %s\n", nombre);
            printf("Total: %f\n", total);
            printf("Número de productos: %d\n", numProductos);
            printf("Detalle de productos:\n");
            printf("Nombre Cantidad Precio\n");
            for (int i = 0; i < numProductos; i++) {
                printf("%s %d %f\n", nombreProducto[i], cantidad[i], precio[i]);
            }
            free(fecha); // Liberar la memoria asignada por obtenerFecha
        } else {
            printf("Número de productos inválido.\n");
        }
    } else {
        printf("Cédula inválida.\n");
    }
    fclose(f);
} // Añadir llave de cierre

void buscarFactura(char *archivo) { // Añadir llave de apertura
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo de facturas.\n");
        return;
    }

    int opcion;
    char criterio[50];
    printf("Ingrese el criterio de búsqueda:\n");
    printf("1. Fecha\n");
    printf("2. Cédula\n");
    printf("3. Número de factura\n");
    scanf("%d", &opcion);
    printf("Ingrese el valor del criterio: ");
    scanf("%s", criterio);

    // Recorrer el archivo de las facturas y buscar el criterio
    char fecha[11], cedula[11], nombre[50];
    float total;
    int numProductos, cantidad;
    char nombreProducto[50];
    float precio;
    int encontrado = 0;
    int numFactura = 0;
    while (!feof(f)) {
      // Leer los datos de la factura
      fscanf(f, "%s %s %s %f %d\n", fecha, cedula, nombre, &total, &numProductos);
      // Comparar el criterio con los datos de la factura
      if (opcion == 1 && strcmp(criterio, fecha) == 0) {
        encontrado = 1;
      } else if (opcion == 2 && strcmp(criterio, cedula) == 0) {
        encontrado = 1;
      } else if (opcion == 3 && strcmp(criterio, numFactura) == 0) {
        encontrado = 1;
      }

      if (encontrado) {
        // Mostrar los datos de la factura
        printf("Factura número: %d\n", numFactura);
        printf("Fecha: %s\n", fecha);
        printf("Cédula: %s\n", cedula);
        printf("Nombre: %s\n", nombre);
        printf("Total: %f\n", total);
        printf("Número de productos: %d\n", numProductos);
        printf("Detalle de productos:\n");
        printf("Nombre Cantidad Precio\n");


        for (int i = 0; i < numProductos; i++) {
          fscanf(f, "%s %d %f\n", nombreProducto, &cantidad, &precio);
          printf("%s %d %f\n", nombreProducto, cantidad, precio);
        }


        break;
      }
      numFactura++;
    }
    if (!encontrado) {
      printf("No se encontró ninguna factura con el criterio especificado.\n");
    }
    fclose(f);
} // Añadir llave de cierre

void verListadoFacturas(char *archivo) { // Añadir llave de apertura

    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo de facturas.\n");
        return;
    }

    // Mostrar el encabezado de la tabla
    printf("| Fecha | Cédula | Nombre | Total | Número de productos |\n");
    printf("|-------|--------|--------|-------|----------------------|\n");

    // Recorrer el archivo de las facturas y mostrar los datos de cada una
    char fecha[11], cedula[11], nombre[50];
    float total;
    int numProductos;
    while (fscanf(f, "%s %s %s %f %d\n", fecha, cedula, nombre, &total, &numProductos) == 5) {

        printf("| %s | %s | %s | %.2f | %d |\n", fecha, cedula, nombre, total, numProductos);

        for (int i = 0; i < numProductos; i++) {
            fscanf(f, "%*s %*d %*f\n"); 
        }
    }

    // Cerrar el archivo
    fclose(f);
} // Añadir llave de cierre