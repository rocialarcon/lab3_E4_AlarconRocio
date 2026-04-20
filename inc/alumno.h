/*********************************************************************************************************************
Copyright 2016-2025, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnologia
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

#ifndef ALUMNO_H_
#define ALUMNO_H_

/** @file Alumno.h
 ** @brief Declaraciones publicas del modulo Alumno utilizando el patron ADT
 ** @author Rocio Alarcon
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stddef.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/** @brief Declaracion de puntero para el tipo Alumno */
typedef struct alumno_s * alumno_t;

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Funcion publica para crear una instancia de un alumno.
 * @param apellido   Cadena de caracteres con el apellido del alumno.
 * @param nombre     Cadena de caracteres con el nombre del alumno.
 * @param documento  Numero entero con el documento del alumno.
 * @return           puntero a la esturctura asignada para almacenar al alumno, o NULL si fallo la creacion.
 */
alumno_t AlumnoCrear(const char * apellido, const char * nombre, int documento);

/**
 * @brief transforma los datos del alumno a un texto JSON.
 * @param alumno   Puntero a la estructura con los datos del alumno.
 * @param cadena   Cadena de caracteres para generar el resultado.
 * @param espacio  Cantidad de bytes disponibles en la cadena de resultado.
 * @return         La longitud de la cadena generada, o -1 si el espacio no es suficiente.
 */
int AlumnoSerializar(alumno_t alumno, char * cadena, size_t espacio);
/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H_ */
