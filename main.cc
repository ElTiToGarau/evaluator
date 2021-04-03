/** @file main.cc
    @brief Programa principal d'EVALUATOR <em>Plataforma de gestió de problemes i cursos de programació</em>.
*/

#ifndef NO_DIAGRAM 
using namespace std;
#include <iostream>
#endif

#include "Problema.hh"
#include "Problemas.hh"
#include "Usuari.hh"
#include "Sesion.hh"

/** @brief Programa principal d'EVALUATOR <em>Plataforma de gestió de problemes i cursos de programació</em>.
*/
int main() {
    Problemas conjunt_problemes;
    string comando;
    cin >> comando;
    while(comando != "fin"){
        if(comando == "nuevo_problema" or comando == "np"){
            string id;
            cin >> id;
            Problema p(id);
            conjunt_problemes.afegir_problema(p);
        }
        else if(comando == "nueva_sesion" or comando == "ns"){

        }
        else if(comando == "nuevo_curso" or comando == "nc"){

        }
        else if(comando == "alta_usuario" or comando == "a"){

        }
        else if(comando == "baja_usuario" or comando == "b"){

        }
        else if(comando == "inscribir_curso" or comando == "i"){

        }
        else if(comando == "curso_usuario" or comando == "cu"){

        }
        else if(comando == "sesion_problema" or comando == "sp"){

        }
        else if(comando == "problemas_resueltos" or comando == "pr"){

        }
        else if(comando == "problemas_enviables" or comando == "pe"){

        }
        else if(comando == "envio" or comando == "e"){

        }
        else if(comando == "listar_problemas" or comando == "lp"){

        }
        else if(comando == "listar_sesiones" or comando == "ls"){

        }
        else if(comando == "listar_cursos" or comando == "lc"){

        }
        else if(comando == "listar_usuarios" or comando == "lu"){

        }
    }
}