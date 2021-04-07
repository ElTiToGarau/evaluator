/** @file Problema.hh
    @brief Especificación de la clase Problema 
*/


#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <string>
#endif 

/** @class Problema
    @brief Representa un Problema con su identificador, así como el número total de envios al problema, y también el número de envios correctos al problema.
*/
class Problema
{
public:
  //Constructoras 

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un problema.
      \pre <em>cierto</em>
      \post El resultado es un problema con identificador igual a cero, número de envíos totales igual a cero y número de envíos correctos igual a cero.
  */   
  Problema();

    /** @brief Creadora con identificador concreto. 
      \pre <em>cierto</em>
      \post El resultado es un problema con identificador igual a id, número de envíos totales igual a cero y número de envíos correctos igual a cero.
  */   
  Problema(string id);

    /** @brief Creadora con copia de un problema.. 
      \pre <em>cierto</em>
      \post El resultado es un problema identico a p.
  */   
  Problema(const Problema& p);
  
  //Modificadoras

    /** @brief Modifica los valores de número total de envíos y número correcto de envíos.
      \pre Número total de envíos >= número correcto de envíos y totales >= correctos.
      \post El parámetro implícito pasa a tener total de envíos "totales", y número correcto de envíos "correctos".
  */   
  void modificar(int correctos, int totales);
  
    /** @brief Modifica el valor de envíos correctos.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito pasa a tener número correcto de envíos "correctos".
  */   
  void modificar_correctos(int correctos);

    /** @brief Modifica el valor de total de envíos.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito pasa a tener total de envíos "totales".
  */   
  void modificar_totales(int totales);

  /** @brief Incrementa en 1 el número total de envíos.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito pasa a tener número total de envíos + 1.
  */   
  void incrementar_totales();

  /** @brief Incrementa en 1 el número total de envíos y el número de envíos correctos.
      \pre Número total de envíos >= número correcto de envíos.
      \post El parámetro implícito pasa a tener número total de envíos + 1 y número correcto de envíos + 1.
  */   
  void incrementar_correctos();

  /** @brief Pone en el parámetro implicito id igual a "id", solo si no se havia puesto otro id con anterioridad.
      \pre string == "0".
      \post El parámetro implícito pasa a tener id igual a "id".
  */   
  void afegir_id(string id);

  //Consultoras

    /** @brief Consultora del identificador.
      \pre <em>cierto</em>
      \post El resultado es el identificador del parámetro implícito
  */
    string consultar_id() const;

    /** @brief Consultora del número de envíos totales.
      \pre <em>cierto</em>
      \post El resultado es el número total de envíos del parámetro implícito
  */
    int consultar_totales() const;

    /** @brief Consultora del número de envíos correctos.
      \pre <em>cierto</em>
      \post El resultado es el número de envíos coprrectos del parámetro implícito
  */
    int consultar_correctos() const;

  //Escritura y lectura de Problema

private:
    string id;
    int env_totales;
    int env_correctos;
};

#endif
