#include <stdio.h>
#include "alumno.h"

int main(void) {
    alumno_t aux = AlumnoCrear("Alarcon", "Rocio", 43939417);

    if ( aux == NULL) {
        printf("error: no se pudo crear el alumno.\n");
        return -1;
    }

    char texto_json[256];
    int resultado;

    resultado = AlumnoSerializar(aux, texto_json, sizeof(texto_json));

    if(resultado == -1) {
        printf("Error: no alcanzo el espacio para armar el JSON.\n");
    } else{
        printf("El resultado de la serializacion es:\n");
        printf("%s\n", texto_json);
    }

    return 0;

}
