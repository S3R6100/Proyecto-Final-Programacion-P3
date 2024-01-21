#include <stdio.h>
#include "funciones.h"

int main(void) {
 int opcion, opcionS;
  char cedula[15];
  char nombre[20];
  char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
  float precios[MAX_PRODUCTOS];
  int stock[MAX_PRODUCTOS];
  int numProductos = 0;
   char archivo[50] = "inventario.txt";

do {
opcion = 0;
 mostrarMenuPrincipal();
 scanf("%d", &opcion);
 switch(opcion) {

   case 1:
    do {
      opcionS = 0;
      mostrarMenuProductos();
      scanf("%d", &opcionS);
      printf("\n");
      switch(opcionS){
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
      }while (opcionS != 5);
     printf("\n");
      break;

   case 2:
    do {
        opcionS = 0;
       mostrarMenuClientes();
       scanf("%d", &opcionS);
      printf("\n");
       switch(opcionS){
         case 1:
           printf("Ingrese el número de cédula ecuatoriana (10 dígitos): ");
           scanf("%s", cedula);
           if (validarCedulaEcuatoriana(cedula) ){
           printf("Ingrese el nombre del cliente: ");
           scanf("%s", nombre);
           ingresarCliente(cedula, nombre);
           }  else {
               printf("La cédula no es válida. Programa finalizado.\n");
           }
         break;
        
         case 2:
           modificarCliente();  
         break;

         case 3:
           consultarCliente();  
         break;

         case 4:
           verClientes();
         break;
         
         default:
         printf("Ingrese una opcion valida\n");
         break;
       }
       }while (opcionS != 5);
     printf("\n");
   break;

  case 3:
  do{
    opcionS = 0;
    mostrarMenuFacturas();
     scanf("%d", &opcionS);
    switch(opcionS){
    case 1:
      facturar();
      break;

      case 2:
        
      verListadoFacturas();
      break;
      case 3:
        
        break;

  case 4:
      printf("Gracias por usar el sistema.\n");
      break;
  default:
      printf("Opción inválida.\n");
      break;
    }
  
} while (opcion != 4);
    
  

 return 0;
}