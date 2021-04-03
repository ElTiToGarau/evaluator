/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios 
*/


#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <set>
#endif 

#include "Usuari.hh"

    /** @class Usuarios
    @brief Representa todo el conjunto de Usuarios.
    */
class Usuarios
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
    set<Problema, cmp> lista_usuarios;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un set de usuarios vacío.
    */
    Usuarios();

    //Modificadoras

    //Consultoras

    //Escritura

};

#endif