/** @file Problema.hh
    @brief Especificación de la clase Problema 
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
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
      \post El resultado es un problema sin inicializar.
  */   
  Problema();

    /** @brief Creadora con copia de un problema.. 
      \pre <em>cierto</em>
      \post El resultado es un problema identico a p.
  */   
  Problema(const Problema& p);
  
  //Modificadoras

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

  //Consultoras

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
    /** @brief Número de envíos totales al problema */
    int env_totales;
    /** @brief Número de envíos correctos al problema */
    int env_correctos;
};

#endif
