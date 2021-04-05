/** @file Cursos.hh
    @brief Especificación de la clase Cursos 
*/

#ifndef _CURSOS_HH_
#define _CURSOS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <map>
#include <iostream>
#endif 

#include "Sesion.hh"
#include "Curso.hh"

    /** @class Cursos
    @brief Representa todo el conjunto de cursos.
    */
class Cursos
{
private:
    string id;
    int N;
    map<int, Curso> list_cursos;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un map de cursos vacío, con id igual a "0" y con N=0.
    */
    Cursos();

    /** @brief Creadora con id especifico. 
        \pre <em>cierto</em>
        \post El resultado es un map de cursos vacío, con identificador igual a id y con N=0.
    */
    Cursos();

    //Modificadoras
    /** @brief Añade al parametro implícito el nuevo curso.
        \pre <em>cierto</em>
        \post El resultado és el parametro implícito pero añadiendo c a este.
    */
    void afegir_curso(const Curso& c);

    //Consultoras
    /** @brief Consulta el número de sesiones que existen
        \pre <em>cierto</em>
        \post El resultado és el número de sesiones que hay en total.
    */
    int num_cursos() const;

    /** @brief Consulta si existe una sesión con identificador id.
        \pre <em>cierto</em>
        \post El resultado és el true si existe una sesión con identificador id, y false si no exsite.
    */
    bool existe_curso(int id) const;

    /** @brief Indica a que sesion pertenece el problema p dentro del curso c. 
        \pre <em>cierto</em>
        \post El resultado es el identificador de la sesion en la que se encuentra p en el curso c, en caso de que p no formase parte del curso retorna "NO_EN_CURSO".
    */
    string sesion_problema(int c, string p);

    //Escritura y lecttura
    /** @brief Escribe por el canal standard de salida el map de cursos de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el map de cursos de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida el curso concreto. 
        \pre El curso identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida el curso concreto.
    */
    void Escribir(int id);

    /** @brief Lee por el canal standard de entrada el conjunto de cursos. 
        \pre <em>cierto</em>
        \post El resultado es leer del canal standard de entrada el conjunto de cursos y ponerlos en el parametro implícito.
    */
    void leer();
};

#endif