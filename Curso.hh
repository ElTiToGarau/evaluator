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
    /** @brief  Conjunto de los identificadores de las sesiones por las cuales se conforma el curso */
    list<string> conjunto_sesiones;
    /** @brief  Número total de veces que se ha completado el curso */
    int veces_completado;
    /** @brief  Número total de usuarios inscritos en el curso actualmente */
    int usuarios_incritos;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un curso.
        \pre <em>cierto</em>
        \post El resultado es un curso sin inicializar
    */
    Curso();

    //Modificadoras

    /** @brief Modifica el número de veces que se ha completado el curso. 
        \pre <em>cierto</em>
        \post El resultado es que el curso se ha resuelto una vez más.
    */
    void incrementar_veces_resuelto();

    /** @brief Modifica el número de usuarios inscritos en el curso. 
        \pre <em>cierto</em>
        \post El resultado es que el curso tiene un concursante más.
    */
    void incrementar_usuarios_inscritos();

    /** @brief Modifica el número de usuarios inscritos en el curso. 
        \pre <em>cierto</em>
        \post El resultado es que el curso tiene un concursante menos.
    */
    void decrementar_usuarios_inscritos();

    //Consultoras

    /** @brief Consulta el número de sesiones que hay en el curso. 
        \pre <em>cierto</em>
        \post El resultado es el número de sesiones que contiene el curso.
    */
    int consultar_num_sesiones();

    /** @brief Consulta el número de veces que se ha completado el curso. 
        \pre <em>cierto</em>
        \post El resultado es el número de veces que se ha completado el curso.
    */
    int consultar_veces_resuelto();

    /** @brief Devuelve una copia de la lista de sesiones que forman el curso. 
        \pre <em>cierto</em>
        \post El resultado es el conjunto de sesiones las cuales conforman el curso.
    */
    list<string> lista_sesiones();

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

    /** @brief Escribe por el canal standard de salida la sesiones que conforman curso. 
        \pre <em>cierto</em>
        \post El resultado es escribir por el canal standard de salida el conjunto de sesiones que conforman el curso.
    */
    void escribir_sesiones();
};

#endif