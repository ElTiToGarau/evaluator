/** @file Probelmas.hh
    @brief Especificación de la clase Probelmas 
*/


#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <vector>
#endif 

#include "Problema.hh"

    /** @class Sesion
    @brief Representa todo el conjunto de problemas.
    */
class Problemas
{
private:
    vector<Problema> lista_problemas;
    bool cmp(const Problema& p1, const Problema& p2);

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un vector de problemas vacío.
    */
    Problemas();

    /** @brief Creadora de una cópia. 
        \pre <em>cierto</em>
        \post El resultado es una copia de la lista de problemas p.
    */
    Problemas(const Problemas& p);

    //Modificadoras
    /** @brief Añade al parametro implícito el nuevo problema
        \pre p no existe ya en el parametro implícito.
        \post El resultado és el parametro implícito pero añadiendo p a este.
    */
    void afegir_problema(const Problema& p);

    //Escritura
    /** @brief Escribe por el canal standard de salida el vector de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el vector de problemas de forma ordenada.
    */
    void Escribir();
};

#endif