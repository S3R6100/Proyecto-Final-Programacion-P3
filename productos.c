#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50
#define MAX_LINEA 100

void leerProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int *numProductos) {
    int numeroProductosALeer;

    printf("Cuantos productos desea leer?\n");
    scanf(" %d", &numeroProductosALeer);

    for (int i = 0; i < numeroProductosALeer && *numProductos < MAX_PRODUCTOS; i++) {
        printf("\nIngrese el nombre del producto %d:\n", *numProductos + 1);
        scanf(" %s", nombres[*numProductos]);

        printf("Ingrese el precio del producto %d:\n", *numProductos + 1);
        scanf(" %f", &precios[*numProductos]);

        printf("Ingrese la cantidad en inventario del producto %d:\n", *numProductos + 1);
        scanf(" %d", &stock[*numProductos]);

        (*numProductos)++;
    }

    if (*numProductos >= MAX_PRODUCTOS) {
        printf("El inventario está lleno. No se puede agregar más productos.\n");
    }
}

void mandarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int numProductos) {
    FILE *archivo = fopen("baseDatos.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%d\t", i + 1);
        fprintf(archivo, "%s\t", nombres[i]);
        fprintf(archivo, "%d\t", stock[i]);
        fprintf(archivo, "%.2f\t", precios[i]);
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

void mostrarProducto() {
    FILE *archivo = fopen("baseDatos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    printf("\n*** Lista de productos ***\n");

    char linea[MAX_LINEA];

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        char nombre[MAX_NOMBRE];
        float precio;
        int cantidad;

        if (sscanf(linea, "%*d %s %f %d", nombre, &precio, &cantidad) == 3) {
            printf("%s - Precio: %.2f - Cantidad: %d\n", nombre, precio, cantidad);
        }
    }

    fclose(archivo);
}

int buscarProducto(const char nombreBuscar[MAX_NOMBRE], char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void editarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int numProductos) {
    printf("\n*** Editar producto ***\n");

    mostrarProducto();

    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea editar: ");
    scanf("%s", nombreBuscar);

    int indiceProducto = buscarProducto(nombreBuscar, nombres, numProductos);

    if (indiceProducto != -1) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", nombres[indiceProducto]);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &precios[indiceProducto]);
        printf("Ingrese la nueva cantidad en inventario: ");
        scanf("%d", &stock[indiceProducto]);

        printf("Producto \"%s\" editado con éxito.\n", nombreBuscar);

        FILE *archivo = fopen("baseDatos.txt", "w");
        if (archivo == NULL) {
            printf("Error al abrir el archivo para escritura.\n");
            return;
        }

        for (int j = 0; j < numProductos; j++) {
            fprintf(archivo, "%d %s %.2f %d\n", j + 1, nombres[j], precios[j], stock[j]);
        }
        fclose(archivo);
    } else {
        printf("Producto \"%s\" no encontrado.\n", nombreBuscar);
    }
}

void eliminarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int *numProductos) {
    printf("\n*** Eliminar producto ***\n");

    mostrarProducto();

    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    scanf("%49s", nombreBuscar);

    int indiceProducto = buscarProducto(nombreBuscar, nombres, *numProductos);

    if (indiceProducto != -1) {
        for (int i = indiceProducto; i < *numProductos - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            precios[i] = precios[i + 1];
            stock[i] = stock[i + 1];
        }

        (*numProductos)--;

        printf("Producto \"%s\" eliminado con éxito.\n", nombreBuscar);

        FILE *archivo = fopen("baseDatos.txt", "w");
        if (archivo == NULL) {
            printf("Error al abrir el archivo para escritura.\n");
            return;
        }

        for (int j = 0; j < *numProductos; j++) {
            fprintf(archivo, "%d %s %.2f %d\n", j + 1, nombres[j], precios[j], stock[j]);
        }
        fclose(archivo);
    } else {
        printf("Producto \"%s\" no encontrado.\n", nombreBuscar);
    }
}