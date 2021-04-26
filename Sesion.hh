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
    @brief Representa un Sesion con su identificador, y el subconjunto de problemas por la que esta formada la sesión.
    */

class Sesion
{
private:
    BinTree<string> problemes_sessio_bin;
    int num_problemas;
    static BinTree<string> preorde(const BinTree<string>& t);
    static void postorde(const BinTree<string>& t);
    static int recalcular_num_problemas(const BinTree<string>& t);
    static bool find(const BinTree<string>& t, string id);

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es una sesión sin problemas.
    */
    Sesion();

    //Modificadoras

    //Consultoras

    /** @brief Consulta el número de problemas que hay en la sesión. 
        \pre <em>cierto</em>
        \post El resultado es el número de problemas que contiene la sesión.
    */
    int consultar_num_problemas();

    /** @brief Consulta si existe un problema con identificador id. 
        \pre <em>cierto</em>
        \post El resultado true si sí existe tal problema, i false en caso contrario.
    */
    bool existe_problema(string id);

    //Escritura y lectura
    /** @brief Escribe por el canal standard de salida el vector de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el vector de problemas de forma ordenada.
    */
    void Escribir();

    /** @brief Lee por el canal standard de entrada la estructura de problemas de la sesión. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada el conjunto de problemas de forma ordenada.
    */
    void leer();
};

#endif