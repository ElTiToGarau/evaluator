/** @file Sesion.hh
    @brief Especificación de la clase Sesion 
*/


#ifndef _SESION_HH_
#define _SESION_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include "BinTree.hh"
#include <map>
#include <list>
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
    
    /** @brief Lee el arbol binario en formato preorden. 
        \pre El arbol que se pasa por referencia tiene que tener una raiz.
        \post El resultado es devolver el arbol binario, leido en formato preorden.
    */
    static void preorde(BinTree<string>& t);
    
    /** @brief Escribe el arbol binario en formato postorden. 
        \pre El arbol que se pasa por referencia tiene que tener una raiz.
        \post El resultado es escribir por el canal standard de salida el arbol binario en formato postorden.
    */
    static void postorde(const BinTree<string>& t);
    
    /** @brief Devuelve el tamaño del arbol binario. 
        \pre <em>cierto</em>
        \post El resultado es el tamaño del arbol binario que se ha introducido por referencia.
    */
    static int recalcular_num_problemas(const BinTree<string>& t);
    
    /** @brief Indica si existe un problema con cierto identificador en el arbol binario. 
        \pre <em>cierto</em>
        \post El resultado es true si existe un problema en el arbol binario con identificador id, y false en caso contrario.
    */
    static bool find(const BinTree<string>& t, string id);

    /** @brief Retorna los problemas base de la sesión en cuestion.
        \pre <em>cierto</em>
        \post Retorna los problemas base de la sesión segun los prequisitos, y los problemas que ya hayan sido resueltos
    */
    static void return_problemas_base(const BinTree<string>& t, const map<string,int>& m, list<string>& l);

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
    
    /** @brief Consulta la raiz del arbol binario de la sesión. 
        \pre <em>cierto</em>
        \post El resultado es el identificador de la raiz del arbol binario.
    */
    list<string> return_raiz(const map<string,int>& t);

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
