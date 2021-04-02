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
};

#endif