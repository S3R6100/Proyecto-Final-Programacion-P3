#include <time.h>

char *obtenerFecha() {
    time_t t = time(NULL); // Obtener el tiempo actual
    struct tm *tiempoLocal = localtime(&t); // Convertir el tiempo a una estructura tm
    char *fecha = (char *)malloc(11); // Reservar memoria para la fecha
    strftime(fecha, 11, "%d/%m/%Y", tiempoLocal); // Formatear la fecha como dd/mm/yyyy
    return fecha; // Devolver la fecha
}