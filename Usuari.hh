/** @file Usuari.hh
    @brief Especificación de la clase Usuari 
*/


#ifndef _USUARI_HH_
#define _USUARI_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <string>
#include <set>
#endif 

#include "Problema.hh"

/** @class Usuari
    @brief Representa un usuario con su identificador, el número de problemas que ha intentado resolver, cuantos de estos ha resuelto satisfactoriamente y cuàntos envío en total ha realizado.
    También tenemos que saber si el usuario está inscrito en algun curso, y si es así en cual, así como un registro de los problemas ya resueltos, y otro de los problemas que ya se peuden intentar resolver en el curso actual.
*/

class Usuari
{
public:
    //Constructoras 

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un usuario con identificador igual a cero, y con el resto  de paràmetros implíctos inicializados a cero, con los registros vacíos, y sin estar apuntado a ningún curso.
    */   
    Usuari();

    /** @brief Creadora con identificador concreto. 
        \pre <em>cierto</em>
        \post El resultado es un usuario con identificador igual a id, y con el resto  de paràmetros implíctos inicializados a cero, con los registros vacíos, y sin estar apuntado a ningún curso.
    */   
    Usuari(string id);

    /** @brief Creadora copia de un usuario. 
        \pre <em>cierto</em>
        \post El resultado es un usuario identico a u.
    */   
    Usuari(const Usuari& u);
  
    //Modificadoras

    /** @brief Modificadora del número total de envíos.
        \pre <em>cierto</em>
        \post El parametro implícito pas a tener el número total de envíos igual a num.
    */
    void modificar_numero_envios(int num);

    /** @brief Se añade un problema a la lista de problemas intentados.
        \pre p no esta ya en la lista.
        \post Se añade p a la lista de problemas intentados.
    */
    void afegir_problema_intentado(const Problema& p);

    /** @brief Se añade un problema a la lista de problemas resueltos.
        \pre p no esta ya en la lista.
        \post Se añade p a la lista de problemas resueltos.
    */
    void afegir_problema_resuelto(const Problema& p);

    /** @brief Inscribe al usuario a un curso.
        \pre El usuario no esta inscrito a ningún curso y también un curso con identificador c.
        \post Inscribe al usuario al curso con identificador c.
    */
    void inscribir_curso(int c);
    
    //Consultoras

    /** @brief Consultora del identificador del usuario.
        \pre <em>cierto</em>
        \post El resultado es el identificador del usario.
    */   
    string consultar_id() const;

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
    int cusro_inscrito() const;

    //Escritura y lectura de Usuari

    /** @brief Lee del canal standard de entrada el id de un usario.
        \pre el parametro implícito id tiene que ser igual a 0.
        \post Se ha leido del canal standard de entrada el id de un usario.
    */   
    void leer();

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
    string id;
    int env_totales;
    bool inscrito_en_curso;
    int curso_inscrito;
    struct cmp {
    bool operator() (Problema& a, Problema& b) const{
        return a.consultar_id() < b.consultar_id();
        }
    };
    set<Problema,cmp> problemas_resueltos;
    set<Problema,cmp> problemas_enviables;
    set<Problema,cmp> problemas_intentados;
};

#endif