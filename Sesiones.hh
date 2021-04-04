/** @file Sesiones.hh
    @brief Especificación de la clase Sesiones 
*/

#ifndef _SESIONES_HH_
#define _SESIONES_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <set>
#endif 

#include "Sesion.hh"
#include "Problema.hh"

    /** @class Sesiones
    @brief Representa todo el conjunto de sesiones.
    */
class Sesiones
{
private:
    string id;
    struct cmp {
    bool operator() (Sesion& a, Sesion& b) const{
        return a.consultar_id() < b.consultar_id();
        }
    };
    set<Sesion, cmp> lista_sesiones;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un set de problemas vacío.
    */
    Sesiones();

    //Modificadoras
    /** @brief Añade al parametro implícito el nuevo problema.
        \pre No existe otra sesíon con el mismo id que s.
        \post El resultado és el parametro implícito pero añadiendo s a este.
    */
    void afegir_sesion(const Sesion& s);

    //Consultoras
    /** @brief Consulta el número de sesiones que existen
        \pre <em>cierto</em>
        \post El resultado és el número de sesiones que hay en total.
    */
    int num_sesiones() const;

    /** @brief Consulta si existe una sesión con identificador id.
        \pre <em>cierto</em>
        \post El resultado és el true si existe una sesión con identificador id, y false si no exsite.
    */
    bool existe_sesion(string id) const;

    //Escritura
    /** @brief Escribe por el canal standard de salida el set de sesiones de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el set de sesiones de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida la sesión concreto. 
        \pre La sesión identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida la sesión.
    */
    void Escribir(string id);
};

#endif