/** @file Problemas.hh
    @brief Especificación de la clase Problemas 
*/


#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#endif 

#include "Problema.hh"

    /** @class Problemas
    @brief Representa todo el conjunto de Problemas.
    */
class Problemas
{
private:
    /** @brief Diccionario de problemas ordenados por el nombre de cada problema */
    map<string,Problema> lista_problemas;

    /** @brief Función de comparación de dos problemas. 
        \pre <em>cierto</em>
        \post Compara dos probelmas en función del ratio de cada uno, en caso de empate compara el identificador de cada problema.
    */
    static bool cmp(const pair<string,Problema>& a, const pair<string,Problema>& b);
    
public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un conjunto de problemas.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de problemas sin inicializar.
    */
    Problemas();

    //Modificadoras
    /** @brief Añade al parámetro implícito el nuevo problema.
        \pre No existe ningún problema con el mismo id.
        \post El resultado és el parámetro implícito pero añadiendo el nuevo problema a este.
    */
    void afegir_problema(string id);

    /** @brief Incrementa en 1 el número total de envíos de un usuario concreto.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito del usuario id pasa a tener número total de envíos + 1.
  */   
  void incrementar_totales(const string id);

  /** @brief Incrementa en 1 el número total de envíos y el número de envíos correctos de un usuario concreto.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito del usuario id pasa a tener número total de envíos + 1 y número correcto de envíos + 1.
  */   
  void incrementar_correctos(const string id);

    //Consultoras
    /** @brief Consulta el número de probelmas que existen
        \pre <em>cierto</em>
        \post El resultado és el número de problemas que hay en total.
    */
    int num_problemas() const;

    /** @brief Consulta si existe un problema con identificador id.
        \pre <em>cierto</em>
        \post El resultado és true si existe un problema con identificador id, y false si no exsite.
    */
    bool existe_problema(string id) const;

    //Escritura y lectura
    /** @brief Escribe por el canal standard de salida el conjunto de problemas de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el conjunto de problemas de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida el problema concreto. 
        \pre El problema identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida el problema.
    */
    void Escribir(string id);

    /** @brief Lee por el canal standard de entrada el conjunto de problemas. 
        \pre P > 0
        \post El resultado es leer del canal standard de entrada el conjunto de <em>P</em> problemas.
    */
    void leer();
};

#endif
