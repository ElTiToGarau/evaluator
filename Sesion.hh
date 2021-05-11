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
#include "Curso.hh"
#include "Usuari.hh"

    /** @class Sesion
    @brief Representa un Sesion con su identificador, y el subconjunto de problemas por la que esta formada la sesión.
    */

class Sesion
{
private:
    /** @brief  Identificadores de los problemas que contiene la sesión en formato de prerequisitos */
    BinTree<string> problemes_sessio_bin;
    /** @brief  Número de problemas por el cual esta formada la sesión */
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

    /** @brief Busca en el arbol hasta encontar el valor de id.
        \pre <em>cierto</em>
        \post Llama a la función <em>insertar_problema_enviable</em> para añadir los problemas enviables no resueltos a partit del subarbol con raiz id.
    */
    static void find_leaves(const BinTree<string>& t, string id, Usuari& u);

    /** @brief Si el problema no esta resuelto lo añade al conjunto de problemas enviables, en caso contrario, sigue con los hijos del arbol.
        \pre El arbol base tiene que tener como valor el problema realizado con el ultimo envio.
        \post Añade al conjunto de problemas enviables del usuario los problemas no resuletos a partir de la raiz.
    */
    static void insertar_problema_enviable(const BinTree<string>& t, Usuari& u);

    /** @brief Retorna los problemas base de la sesión en cuestion.
        \pre <em>cierto</em>
        \post Retorna los problemas base de la sesión segun los prequisitos, y los problemas que ya hayan sido resueltos
    */
    static void return_problemas_base(const BinTree<string>& t, Usuari& u);

    /** @brief Recorre el arbol binario poniendo en el curso, los problemas que lo forman
        \pre <em>cierto</em>
        \post Se ha agregado al curso los problemas que forman el arbol binario, y devuelve false si no se ha intentado inserir un problema que ya estava, 
        y true en caso contrario.
    */
    static void insertar_problemas_curso(const BinTree<string>& t, Curso& c, const string id, bool& repetit);

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar una sesión.
        \pre <em>cierto</em>
        \post El resultado es una sesión sin problemas.
    */
    Sesion();

    //Modificadoras

    /** @brief Consulta la raiz del arbol binario de la sesión. 
        \pre <em>cierto</em>
        \post El resultado es el identificador de la raiz del arbol binario.
    */
    void return_raiz(Usuari& u);

    /** @brief Si existe un problema con cierto identificador en el arbol binario retorna los problemas que tiene como hojas si los tiene. 
        \pre <em>cierto</em>
        \post Retorna un conjunto con un maximo de los dos hijos que puede tener el problema
    */
    void trobar_fulles(const string id, Usuari& u);

    /** @brief Agrega al curso, los problemas por los cuales esta formada la sesión.
        \pre <em>cierto</em>
        \post Agrega al curso, los problemas por los cuales esta formada la sesión, y devuelve
        true en caso que se intente colocar un problema el cual ya estava en la lista, false en caso contrario.
    */
    bool modificar_problemas_curso(Curso& c, const string id);

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
    /** @brief Escribe por el canal standard de salida el conjunto de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el conjunto de problemas de forma ordenada.
    */
    void Escribir();

    /** @brief Lee por el canal standard de entrada la estructura de problemas de la sesión. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada el conjunto de problemas de forma ordenada.
    */
    void leer();
};

#endif
