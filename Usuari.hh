/** @file Usuari.hh
    @brief Especificación de la clase Usuari 
*/


#ifndef _USUARI_HH_
#define _USUARI_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <string>
#include <vector>
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
        \post El resultado es un usuario con identificador igual a cero, número de envíos totales igual a cero y número de envíos correctos igual a cero.
    */   
    Usuari();

    /** @brief Creadora con identificador concreto. 
        \pre <em>cierto</em>
        \post El resultado es un problema con identificador igual a id, número de envíos totales igual a cero y número de envíos correctos igual a cero.
    */   
    Usuari(string id);
  
    //Modificadoras

    
    //Consultoras


    //Escritura y lectura de Problema

private:
    string id;
    int num_intentados;
    int num_resueltos;
    int env_totales;
    bool inscrito_en_curso;
    int curso_inscrito;
    vector<Problema> problemas_resueltos;
    vector<Problema> problemas_resolvibles;
};

#endif