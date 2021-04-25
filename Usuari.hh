/** @file Usuari.hh
    @brief Especificación de la clase Usuari 
*/


#ifndef _USUARI_HH_
#define _USUARI_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <set>
#include <map>
#endif 

#include "Problema.hh"

/** @class Usuari
    @brief Representa un Usuari con su identificador, el número de problemas que ha intentado resolver, cuantos de estos ha resuelto satisfactoriamente y cuàntos envío en total ha realizado.
    También tenemos que saber si el usuario está inscrito en algun curso, y si es así en cual, así como un registro de los problemas ya resueltos, y otro de los problemas que ya se peuden intentar resolver en el curso actual.
*/

class Usuari
{
public:
    //Constructoras 

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un usuario con identificador igual a cero, y con el resto  de parámetros implíctos inicializados a cero, con los registros vacíos, y sin estar apuntado a ningún curso.
    */   
    Usuari();
  
    //Modificadoras

    /** @brief Modificadora del número total de envíos.
        \pre <em>cierto</em>
        \post El parámetro implícito pas a tener el número total de envíos igual a num.
    */
    void modificar_numero_envios(int num);

    /** @brief Se añade un problema a la lista de problemas intentados.
        \pre p no esta ya en la lista.
        \post Se añade p a la lista de problemas intentados.
    */
    void afegir_problema_intentado(const string id);

    /** @brief Se añade un problema a la lista de problemas resueltos.
        \pre p no esta ya en la lista.
        \post Se añade p a la lista de problemas resueltos.
    */
    void afegir_problema_resuelto(const string id, const int num);

    /** @brief Se añade un problema a la lista de problemas enviables.
        \pre p no esta ya en la lista.
        \post Se añade p a la lista de problemas enviables.
    */
    void afegir_problema_enviable(const string id);

    /** @brief Suprime un problema a la lista de problemas enviables.
        \pre p esta en la lista.
        \post Se elimina p a la lista de problemas enviables.
    */
    void suprimir_problema_enviable(const string id);

    /** @brief Se aumenta en 1 el numero de envios a cierto problema de la lista de problemas enviables.
        \pre p esta en la lista de problemas enviables.
        \post Se aumenta en 1 el númerode envios al problema id de la lista de problemas enviables.
    */
    void aumentar_problema_enviable(const string id);

    /** @brief Inscribe al usuario a un curso.
        \pre El usuario no esta inscrito a ningún curso y también un curso con identificador c.
        \post Inscribe al usuario al curso con identificador c.
    */
    void inscribir_curso(const int c);
    
    //Consultoras

    /** @brief Consulta si un problema esta dentro de la lista de problemas enviables.
        \pre <em>cierto</em>
        \post El resultado es true si el problema esta en la lista de problemas enviables, y false en cason contrario.
    */   

    bool consultar_problema_enviable(string p);

    /** @brief Consultora de el número de problemas que ha intentado resolver.
        \pre <em>cierto</em>
        \post El resultado es el número de problemas que ha intentado resolver.
    */   

    int consultar_intentados() const;

    /** @brief Consultora de el número de problemas resueltos satisfactoriamente.
        \pre <em>cierto</em>
        \post El resultado es el número de problemas resueltos satisfactoriamente.
    */   
    int consultar_resueltos() const;

    /** @brief Consultora de el número de envios total realizados.
        \pre <em>cierto</em>
        \post El resultado es el número total de envio realizados.
    */   
    int consultar_total_envios() const;

    /** @brief Consultora de si el usuario está inscrito en un curso.
        \pre <em>cierto</em>
        \post El resultado es true si el usuario está inscrito en un curso y false si no lo está.
    */   
    bool consultar_incscrito_curso() const;

    /** @brief Consultora de el curso que está inscrito el usuario.
        \pre El usuario tiene que estar inscrito en algun curso.
        \post El resultado el identificador de el curso al cual estás inscrito.
    */   
    int cusro_inscrito();

    //Escritura y lectura de Usuari

    /** @brief Escribe en el canal standard de salida los problemas resueltos.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas resueltos en orden creciente.
    */   
    void escribir_resueltos();

    /** @brief Escribe en el canal standard de salida los problemas enviables.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas enviables en orden creciente.
    */   
    void escribir_enviables();

private:
    int env_totales;
    bool inscrito_en_curso;
    int curso_inscrito;
    map<string,int> problemas_resueltos;
    map<string,int> problemas_enviables;
    set<string> problemas_intentados;
};

#endif
