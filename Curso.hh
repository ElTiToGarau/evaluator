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
    int veces_completado;
    int usuarios_incritos;

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

    /** @brief Indica a que sesión pertenece el problema p. 
        \pre <em>cierto</em>
        \post El resultado es el identificador de la sesión en la que se encuentra p, en caso de que p no formase parte del curso retorna "NO_EN_CURSO".
    */
    string sesion_problema(string id);

    /** @brief Consulta el número de usuarios inscritos en el curso. 
        \pre <em>cierto</em>
        \post El resultado es el número de usuarios inscritos en el curso.
    */
    int consultar_num_usuarios();

    //Escritura y lectura

    /** @brief Lee por el canal standard de entrada la sesiones del curso. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada un número de sesiones <em>s</em> que formaran el curso, si hay intersección de problemas en las sesiones devuelve false,
        de otro modo devuelve true.
    */
    bool leer(int s);
};

#endif