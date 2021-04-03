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
#include "Usuarios.hh"

int main() {
    Problemas conjunt_problemes;
    Usuarios conjunto_usuarios;
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
            string id;
            cin >> id;
            if(not conjunto_usuarios.existe_usuarios(id)){
                Usuari u(id);
                conjunto_usuarios.afegir_usauri(u);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "Ya hay un usuario registrado con el mismo id." << endl;
        }
        else if(comando == "baja_usuario" or comando == "b"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.baja_usuario(id);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "No existe ningún usuario con este identifiacdor." << endl;
        }
        else if(comando == "inscribir_curso" or comando == "i"){

        }
        else if(comando == "curso_usuario" or comando == "cu"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                cout << conjunto_usuarios.curso_usuario(id) << endl;
            }
            else cout << "No existe ningún usuario con este identificador." << endl;
        }
        else if(comando == "sesion_problema" or comando == "sp"){

        }
        else if(comando == "problemas_resueltos" or comando == "pr"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.escribir_resueltos(id);
            }
            else cout << "No existe ningún usuario con este identificador." << endl;
        }
        else if(comando == "problemas_enviables" or comando == "pe"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.escribir_enviables(id);
            }
            else cout << "No existe ningún usuario con este identificador." << endl;
        }
        else if(comando == "envio" or comando == "e"){

        }
        else if(comando == "listar_problemas" or comando == "lp"){
            conjunt_problemes.Escribir();
        }
        else if(comando == "escribir_problema" or comando == "ep"){
            string p;
            cin >> p;
            conjunt_problemes.Escribir(p);
        }
        else if(comando == "listar_sesiones" or comando == "ls"){

        }
        else if(comando == "listar_cursos" or comando == "lc"){

        }
        else if(comando == "listar_usuarios" or comando == "lu"){
            conjunto_usuarios.Escribir();
        }
        else if(comando == "escribir_usuario" or comando == "eu"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.Escribir(id);
            }
            else cout << "No existe ningún usuario con este identificador." << endl;
        }
    }
}