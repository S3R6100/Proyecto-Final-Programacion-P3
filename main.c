#include <stdio.h>
#include "funciones.h"
#include "validar.h"
#include "fecha.h"

int main(void) {
    int opcion, opcionS;
    char cedula[15];
    char nombre[20];
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    char clientes[CLIENTES_FILAS][CLIENTES_COLUMNAS];
    int stock[MAX_PRODUCTOS];
    int numProductos = 0;
    char archivo[50] = "inventario.txt";

    do {
        opcion = 0;
        mostrarMenuPrincipal();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                do {
                    opcionS = 0;
                    mostrarMenuProductos();
                    scanf("%d", &opcionS);
                    printf("\n");
                    switch (opcionS) {
                        case 1:
                            leerProducto(nombres, precios, stock, &numProductos);
                            mandarProducto(nombres, precios, stock, numProductos);
                            break;

                        case 2:
                            mostrarProducto();
                            break;

                        case 3:
                            editarProducto(nombres, precios, stock, numProductos);
                            break;

                        case 4:
                            eliminarProducto(nombres, precios, stock, numProductos);
                            break;

                        case 5:
                            break;

                        default:
                            printf("Ingrese una opcion valida\n");
                            break;
                    }
                } while (opcionS != 5);
                printf("\n");
                break;

            case 2:
                do {
                    opcionS = 0;
                    char archivo[50] = "clientes.txt";
                    int numClientes;

                    FILE *archivoClientes;
                    archivoClientes = fopen("clientes.txt", "a+");
                    if (archivoClientes == NULL) {
                        printf("El archivo 'clientes.txt' no pudo abrirse\n");
                        return 1;
                    }
                    mostrarMenuClientes();
                    scanf("%d", &opcionS);
                    printf("\n");
                    switch (opcionS) {
                        case 1:
                            ingresarCliente(clientes, &numClientes, cedula, nombre);
                            break;

                        case 2:
                            modificarCliente(clientes, numClientes, cedula);
                            break;

                        case 3:
                            consultarCliente(clientes, numClientes, cedula);
                            break;

                        case 4:
                            verClientes(clientes, numClientes);
                            break;

                        default:
                            printf("Ingrese una opcion valida\n");
                            break;
                    }
                } while (opcionS != 5);
                printf("\n");
                break;

            case 3:
                do {
                    opcionS = 0;
                    char archivo[50] = "facturas.txt";
                    mostrarMenuFacturas();
                    scanf("%d", &opcionS);
                    switch (opcionS) {
                        case 1:
                            facturar();
                            break;

                        case 2:
                            buscarFactura(archivo);
                            break;

                        case 3:
                            verListadoFacturas(archivo);
                            break;

                        case 4:
                            printf("Gracias por usar el sistema.\n");
                            break;

                        default:
                            printf("Opción inválida.\n");
                            break;
                    }
                } while (opcion != 4);
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
