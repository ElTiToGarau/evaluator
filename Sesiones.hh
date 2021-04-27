/** @file Sesiones.hh
    @brief Especificación de la clase Sesiones 
*/

#ifndef _SESIONES_HH_
#define _SESIONES_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <map>
#include <list>
#endif 

#include "Sesion.hh"
#include "Problema.hh"

    /** @class Sesiones
    @brief Representa todo el conjunto de Sesiones.
    */
class Sesiones
{
private:
    map<string, Sesion> conjunt_sesions;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un set de problemas vacío.
    */
    Sesiones();

    //Modificadoras
    /** @brief Añade al parámetro implícito el nuevo problema.
        \pre No existe otra sesión con el mismo id que s.
        \post El resultado es el parámetro implícito pero añadiendo s a este.
    */
    void afegir_sesion(string id, const Sesion& s);

    //Consultoras
    /** @brief Consulta el número de sesiones que existen
        \pre <em>cierto</em>
        \post El resultado es el número de sesiones que hay en total.
    */
    int num_sesiones() const;

    /** @brief Consulta si existe una sesión con identificador id.
        \pre <em>cierto</em>
        \post El resultado es el true si existe una sesión con identificador id, y false si no exsite.
    */
    bool existe_sesion(string id);

    /** @brief Consulta si existe un determinado problema en una lista de sesiones.
        \pre <em>cierto</em>
        \post El resultado es el true si existe el problema en la lista de sesiones, y false en caso contrario.
    */
    string existe_problema(const list<string>& l, string p);
    
    /** @brief Consulta los problemas raiz de cada sesión en la lista.
        \pre <em>cierto</em>
        \post El resultado es una lista con todos los problemas base de las sesiones en la lista.
    */
    list<string> problemas_raiz(const list<string>& l);

    //Escritura y lectura
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

    /** @brief Lee por el canal standard de entrada el conjunto de sesiones. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada el conjunto de sesiones y ponerlos en el parámetro implícito.
    */
    void leer(int Q);
};

#endif
