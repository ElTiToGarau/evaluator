/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios 
*/


#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <set>
#endif 

#include "Usuari.hh"

    /** @class Usuarios
    @brief Representa todo el conjunto de Usuarios.
    */
class Usuarios
{
private:
    struct cmp {
    bool operator() (Usuari& a, Usuari& b) const{
        return a.consultar_id() < b.consultar_id();
        }
    };
    set<Usuari, cmp> lista_usuarios;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar la clase Usuarios.
        \pre <em>cierto</em>
        \post El resultado es un set de usuarios vacío.
    */
    Usuarios();

    //Modificadoras
    /** @brief Añade al parametro implícito el nuevo usuario.
        \pre No existe ningún usuario con el mismo identificador.
        \post El resultado és el parametro implícito pero añadiendo u en este.
    */
    void afegir_usauri(Usuari& u);

    /** @brief Borra al usuario identificado por id del parametro implícito.
        \pre Existe un usuario con el identificador id.
        \post El resultado és el parametro implícito pero sin u en este.
    */
    void baja_usuario(string id);

    //Consultoras
    /** @brief Consulta el número de usuarios registrados.
        \pre <em>cierto</em>
        \post El resultado és el número total de usuarios registrados en la plataforma.
    */
    int num_usuarios() const;

    /** @brief Consulta el curso en el que està apuntado un usuario.
        \pre Existe un usuario identificado por id.
        \post El resultado és el curso el que està apuntadon el usuario, o zero si no esta apuntado a ningún curso.
    */
    int curso_usuario(string id) const;

    /** @brief Consulta sin existe un usario con identificador id.
        \pre <em>cierto</em>
        \post El resultado és el true si existe un usario con identificador id, y false si no exsite.
    */
    bool existe_usuarios(string id) const;

    //Escritura

    /** @brief Escribe por el canal standard de salida el set de usuarios de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el set de usuarios de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida el usuario concreto. 
        \pre El problema identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida el usuario concreto si existe, de otro modo imprime un mensaje de error.
    */
    void Escribir(string id);

    /** @brief Escribe en el canal standard de salida los problemas resueltos por el usuario identificado por id.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas resueltos por el usuario id en orden creciente.
    */   
    void escribir_resueltos(string id);

    /** @brief Escribe en el canal standard de salida los problemas enviables por el usuario identificado por id.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas enviables por el usuario id en orden creciente.
    */   
    void escribir_enviables(string id);
};

#endif