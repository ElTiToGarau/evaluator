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
#include <list>
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

        Se ejecuta automáticamente al declarar un usuario.
        \pre <em>cierto</em>
        \post El resultado es un usuario sin inicializar.
    */
    Usuari();
  
    //Modificadoras

    /** @brief Aumenta en 1 el número total de envios realizados.
        \pre <em>cierto</em>
        \post El parámetro implícito pasa a tener 1 envío mas.
    */
    void aumentar_numero_envios();

    /** @brief Se añade un problema al conjunto de problemas intentados.
        \pre <em>cierto</em>
        \post Se añade p al conjunto de problemas intentados.
    */
    void afegir_problema_intentado(const string id);

    /** @brief Se añade un problema al conjunto de problemas resueltos.
        \pre p tiene que pertenecer al conjunto de problemas enviables.
        \post Se añade p al conjunto de problemas resueltos.
    */
    void afegir_problema_resuelto(const string id);

    /** @brief Se añade un problema al conjunto de problemas enviables.
        \pre p no esta ya en el conjunto.
        \post Se añade p al conjunto de problemas enviables.
    */
    void afegir_problema_enviable(const string id);

    /** @brief Suprime un problema del conjunto de problemas enviables.
        \pre p esta en el conjunto.
        \post Se elimina p al conjunto de problemas enviables.
    */
    void suprimir_problema_enviable(const string id);

    /** @brief Se aumenta en 1 el numero de envios a cierto problema del conjunto de problemas enviables.
        \pre p esta en el connunto de problemas enviables.
        \post Se aumenta en 1 el númerode envios al problema id del conjunto de problemas enviables.
    */
    void aumentar_problema_enviable(const string id);

    /** @brief Se añade un conjunto de problemas al conjunto de problemas enviables.
        \pre p no esta ya en el conjunto.
        \post Se añade L al conjunto de problemas enviables.
    */
    void afegir_problemas_enviable(const list<string>& L);

    /** @brief Inscribe al usuario a un curso.
        \pre El usuario no esta inscrito a ningún curso y también deve existir el curso con identificador c.
        \post Inscribe al usuario al curso con identificador c.
    */
    void inscribir_curso(int c, const list<string>& l);
    
    //Consultoras

    /** @brief Consulta si un problema esta dentro del conjunto de problemas enviables.
        \pre <em>cierto</em>
        \post El resultado es true si el problema esta en el conjunto de problemas enviables, y false en cason contrario.
    */   

    bool consultar_problema_enviable(string p);

     /** @brief Consultora de el número de problemas enviables.
        \pre <em>cierto</em>
        \post El resultado es el número de problemas que se pueden enviar.
    */   
    int consultar_num_enviables() const;

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

    /** @brief Consulta que problemas se han resuelto y con cuantos intentos.
        \pre <em>cierto</em>
        \post El resultado devuelve los problemas resueltos en orden creciente por el identificador del curso, así como cuantas veces se ha intentado resolver el problema.
    */   
    map<string,int> devolver_problemas_resueltos();

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
    /** @brief  Envíos totales realizados por el usuario */
    int env_totales;
    /** @brief  True si el usuario esta inscrito en un curso, false en caso contrario */
    bool inscrito_en_curso;
    /** @brief  En caso de que el usuario este incsrito en un curso, indica en que curso esta inscrito */
    int curso_inscrito;
    /** @brief  Problemas resueltos, y cuantos intentos se han hecho a cada uno */
    map<string,int> problemas_resueltos;
    /** @brief  Problemas enviables, y cuantos intentos se han hecho a cada uno */
    map<string,int> problemas_enviables;
    /** @brief  Problemas los cuales por lo menos ha hecho un envío */
    set<string> problemas_intentados;
};

#endif
