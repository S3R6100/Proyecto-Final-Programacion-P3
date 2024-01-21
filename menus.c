#include <stdio.h>

void mostrarMenuPrincipal(){
printf("////////////////////////////////////////////////////////////\n");
printf("\t\t\t Sistema de Gestion de Empresas\n");
printf("////////////////////////////////////////////////////////////\n");
printf("1. Gestion de Productos\n");
printf("2. Gestion de Clientes\n");
printf("3. Gestion de Facturas\n");
printf("4. Salir\n");
printf("\n");
return;
}

void mostrarMenuProductos(){
  printf("//////////////////////////////////////////\n");
  printf("\t\t Menu de Productos\n");
  printf("//////////////////////////////////////////\n");
  printf("1. Agregar Producto\n");
  printf("2. Mostrar Productos\n"); 
  printf("3. Editar Producto\n");
  printf("4. Eliminar Producto\n");
  printf("5. Volver\n");
}

void mostrarMenuClientes(){
  printf("///////////////////////////////\n");
  printf("\t\t Menu Clientes\n");
  printf("///////////////////////////////\n");
  printf("1. Agregar Cliente\n");
  printf("2. Editar Cliente\n"); 
  printf("3. Consultar Cliente\n");
  printf("4. Ver Clientes\n");
  printf("5. Volver\n");
}

void mostrarMenuFacturas(){
  printf("//////////////////////////////////////\n");
  printf("\t\t Menu Facturas\n");
  printf("//////////////////////////////////////\n");
  printf("1. Facturar\n");
  printf("2. Mostrar Facturas\n"); 
  printf("3. Buscar Facturas\n");
  printf("\n");
  printf("5. Volver\n");
}