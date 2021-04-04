/** @file Sesion.hh
    @brief Especificación de la clase Sesion 
*/


#ifndef _SESION_HH_
#define _SESION_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include "BinTree.hh"
#endif 

#include "Problema.hh"

    /** @class Sesion
    @brief Representa un Sesion con su identificador, y el subconjunto de problemas por la que esta formada la sesion.
    */

class Sesion
{
private:
    string id;
    BinTree<Problema> problemes_sessio;
    int num_problemas;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es una sesion con id=0 y sin problemas.
    */
    Sesion();

    /** @brief Creadora con identificador especifico. 
        \pre <em>cierto</em>
        \post El resultado es una sesion con identificador igual a id y sin problemas.
    */
    Sesion(string id);

    /** @brief Creadora de una cópia. 
        \pre <em>cierto</em>
        \post El resultado es una copia de la sesion s.
    */
    Sesion(const Sesion& s);

    //Modificadoras

    //Consultoras
    /** @brief Consulta el id de la sesión. 
        \pre <em>cierto</em>
        \post El resultado es el id de la sesion.
    */
    string consultar_id();

    /** @brief Consulta el número de problemas que hay en la sesión. 
        \pre <em>cierto</em>
        \post El resultado es el número de problemas que contiene la sesión.
    */
    int consultar_num_problemas();

    //Escritura y lectura
    /** @brief Escribe por el canal standard de salida el vector de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el vector de problemas de forma ordenada.
    */
    void Escribir();

    /** @brief Lee por el canal standard de entrada la estructura de problemas de la sesion. 
        \pre <em>cierto</em>
        \post El resultado es leer en el canal standard de entrada el vector de problemas de forma ordenada.
    */
    void leer();
};

#endif