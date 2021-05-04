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
#include "Curso.hh"

    /** @class Sesiones
    @brief Representa todo el conjunto de Sesiones.
    */
class Sesiones
{
private:
    /** @brief  Conjunto de sesiones ordenadas por su identificador*/
    map<string, Sesion> conjunt_sesions;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un conjunto de sesiones.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de sesiones sin inicializar.
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
    string existe_problema(Curso c, const string p);

    /** @brief Consulta los problemas raiz de cada sesión en la lista.
        \pre <em>cierto</em>
        \post El resultado es una lista con todos los problemas base de las sesiones en la lista.
    */
    void problemas_raiz(const string l, const map<string,int>& m, list<string>& llista);

    /** @brief Si existe un problema con cierto identificador en el arbol binario retorna los problemas que tiene como hojas si los tiene la sesión concreta. 
        \pre La sesión s tiene que estar en el conjunto de sesiones.
        \post Retorna un conjunto con un maximo de los dos hijos que puede tener el problema p de la sesión s.
    */
    list<string> trobar_fulles(const string s, const string p);

    /** @brief Añade en el mapa que se pasa por referencia los problemas de las sesón
        \pre La sesión s tiene que estar en el conjunto de sesiones.
        \post Añade en el mapa todos los problemas que corresponen a la sesión, y devuelve true si no hay problemas repetidos en el mapa, y false en caso contrario.
    */
    bool poner_problemas_sesion(Curso& c);

    //Escritura y lectura
    /** @brief Escribe por el canal standard de salida el conjunto de sesiones de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el conjunto de sesiones de forma ordenada.
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
