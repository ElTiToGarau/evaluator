/** @file Curso.hh
    @brief Especificación de la clase Curso 
*/


#ifndef _CURSO_HH_
#define _CURSO_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <list>
#endif 

#include "Problema.hh"
#include "Sesion.hh"

    /** @class Curso
    @brief Representa un Curso con su identificador, y el subconjunto de sesiones por el que esta formado el curso.
    */

class Curso
{
private:
    list<Sesion> problemes_sessio;
    int num_sesiones;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un curso con id=0 y sin problemas.
    */
    Curso();

    //Modificadoras

    //Consultoras

    /** @brief Consulta el número de sesiones que hay en el curso. 
        \pre <em>cierto</em>
        \post El resultado es el número de sesiones que contiene el curso.
    */
    int consultar_num_sesiones();

    //Escritura y lectura

    /** @brief Lee por el canal standard de entrada la sesiones del curso. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada el las sesiones que formaran el curso, si hay intersección de problemas en las sesiones devuelve false,
        de otro modo devuelve true.
    */
    bool leer();
};

#endif