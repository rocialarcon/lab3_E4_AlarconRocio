/*********************************************************************************************************************
Copyright 2016-2025, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnología
Universidad Nacional de Tucuman
http://www.microprocesadores.unt.edu.ar/

Copyright 2016-2025, Rocio Alarcon <rocialarcon555@gmail.com>
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file Alumno.c
 ** @brief Implementacion privada del modulo alumno
 ** @author Rocio Alarcon
 **/

/* === Headers files inclusions ================================================================ */

#include "alumno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/** @brief Definicion real de la estructura del alumno */
struct alumno_s {
    char apellido[30];
    char nombre[30];
    int documento;
};
/* === Private function declarations =========================================================== */

static int SerializarTexto(const char * clave, const char * valor, char * cadena,size_t espacio);
static int SerializarNumero(const char * clave, int valor, char * cadena, size_t espacio);

/* === Private variable definitions ============================================================ */

#ifndef USAR_MEMORIA_DINAMICA
    static struct alumno_s alumnos_estaticos[10];
    static int alumno_creados = 0;
#endif

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

/**
 * @brief Funcion interna para serializar un campo de texto en formato JSON.
 * @param clave   Nombre del campo.
 * @param cadena  Arreglo donde se guardara el texto resultante.
 * @param espacio Cantidad de bytes disponibles en el arreglo.
 * @return        La cantidad de caracteres escritos.
 */
static int SerializarTexto(const char * clave, const char * valor, char * cadena, size_t espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\"", clave, valor);
}

/**
 * @brief Funcion interna para serializar un campo numerico en formato JSON.
 * @param clave   Nombre del campo.
 * @param valor   Numero entero a guardar.
 * @param cadena  Arreglo donde se guardara el texto resultante.
 * @param espacio Cantidad de bytes disponibles en el arreglo.
 * @return        La cantidad dde caracteres escritos.
 */
static int SerializarNumero(const char * clave, int valor, char * cadena, size_t espacio) {
    return snprintf(cadena, espacio, "\"%s\":%d", clave, valor);
}
/* === Public function implementation ========================================================== */

alumno_t AlumnoCrear(const char * apellido, const char * nombre, int documento) {
    alumno_t nuevo_alumno = NULL;

#ifdef USAR_MEMORIA_DINAMICA
    nuevo_alumno = malloc(sizeof(struct alumno_s));
#else
    if(alumno_creados < 10) {
        nuevo_alumno = &alumnos_estaticos[alumno_creados];
        alumno_creados++;
    }
#endif

    if(nuevo_alumno != NULL) {
        strncpy(nuevo_alumno->apellido, apellido, sizeof(nuevo_alumno->apellido)-1);
        strncpy(nuevo_alumno->nombre, nombre, sizeof(nuevo_alumno->nombre)-1);
        nuevo_alumno->documento = documento;
    }
    return nuevo_alumno;
}

int AlumnoSerializar(alumno_t alumno, char * cadena, size_t espacio) {
    int letras_escritas = 0;
    int aux = 0;

    if(alumno == NULL) {
        return -1;
    }

    aux = snprintf(cadena + letras_escritas, espacio, "{");
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = SerializarTexto("apellido", alumno->apellido, cadena + letras_escritas, espacio);
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = snprintf(cadena + letras_escritas, espacio, ", ");
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = SerializarTexto("nombre", alumno->nombre, cadena + letras_escritas, espacio);
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = snprintf(cadena + letras_escritas, espacio, ", ");
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = SerializarNumero("documento", alumno->documento, cadena + letras_escritas, espacio);
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    aux = snprintf(cadena + letras_escritas, espacio, "}");
    if (aux >= espacio) return -1;
    letras_escritas = letras_escritas + aux;
    espacio = espacio - aux;

    return letras_escritas;
}

/* === End of documentation ==================================================================== */
