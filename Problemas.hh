/** @file Problemas.hh
    @brief Especificación de la clase Probelmas 
*/


#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <set>
#endif 

#include "Problema.hh"

    /** @class Problemas
    @brief Representa todo el conjunto de problemas.
    */
class Problemas
{
private:
    struct cmp {
    bool operator() (Problema& a, Problema& b) const{
        double rat1,rat2;
        rat1=(a.consultar_totales() + 1)/(a.consultar_correctos() + 1);
        rat2=(b.consultar_totales()+1)/(b.consultar_correctos()+1);
        if(rat1!=rat2) return rat1<rat2;
        else return a.consultar_id() < b.consultar_id();
        }
    };
    set<Problema, cmp> lista_problemas;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un set de problemas vacío.
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

    //Consultoras
    /** @brief Consulta el número de probelmas que existen
        \pre <em>cierto</em>
        \post El resultado és el número de problemas que hay en total.
    */
    int num_problemas() const;

    //Escritura
    /** @brief Escribe por el canal standard de salida el set de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el set de problemas de forma ordenada.
    */
    void Escribir();
};

#endif