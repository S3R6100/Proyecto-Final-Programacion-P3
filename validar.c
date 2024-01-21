#include <stdbool.h>
#include <string.h>

bool validarCedula(char *cedula) {
    int suma = 0;
    int coeficiente[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int digitoVerificador = cedula[9] - '0'; // Convertir el caracter a entero
    for (int i = 0; i < 9; i++) {
        int producto = (cedula[i] - '0') * coeficiente[i]; // Convertir el caracter a entero y multiplicarlo por el coeficiente
        if (producto > 9) {
            producto -= 9;
        }
        suma += producto;
    }
    int residuo = suma % 10;
    int resultado = 10 - residuo;
    if (resultado == 10) {
        resultado = 0;
    }
    return resultado == digitoVerificador;
}