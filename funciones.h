#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

///Funciones Menu///
void mostrarMenuPrincipal();
void mostrarMenuProductos();
void mostrarMenuClientes();
void mostrarMenuFacturas();

///Funciones Productos///
void leerProducto(char nombre[MAX_PRODUCTOS][MAX_NOMBRE], float precio[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int *numProductos);
void mostrarProducto();
void mandarProducto(char nombre[MAX_NOMBRE][MAX_PRODUCTOS], float precio[MAX_PRODUCTOS], int stock[MAX_PRODUCTOS], int numeroProducto);
void editarProducto(char nombre[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int numProductos) ;
void eliminarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos);


///Funciones Clientes///
#define CLIENTES_FILAS 100
#define CLIENTES_COLUMNAS 20 
void ingresarCliente(char clientes[][CLIENTES_COLUMNAS], int *numClientes, char cedula[], char nombre[]);
void modificarCliente(char clientes[][CLIENTES_COLUMNAS], int numClientes, char cedula[]);
void consultarCliente(char clientes[][CLIENTES_COLUMNAS], int numClientes, char cedula[]);
void verClientes(char clientes[][CLIENTES_COLUMNAS], int numClientes);
///Funciones Facturas///
void facturar();
void buscarFactura(char *archivo);
void verListadoFacturas(char *archivo);