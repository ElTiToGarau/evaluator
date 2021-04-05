/** @file main.cc
    @brief Programa principal d'EVALUATOR <em>Plataforma de gestión de problemas i cursos de programación</em>.
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
#include "Sesiones.hh"
#include "Curso.hh"
#include "Cursos.hh"

int main() {
    Problemas conjunt_problemes;
    Usuarios conjunto_usuarios;
    Sesiones conjunto_sesiones;
    Cursos conjunto_cursos;
    conjunt_problemes.leer();
    conjunto_sesiones.leer();
    conjunto_cursos.leer();
    conjunto_usuarios.leer();
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
            string s;
            cin >> s;
            if(not conjunto_sesiones.existe_sesion(s)){
                Sesion ses(s);
                ses.leer();
                conjunto_sesiones.afegir_sesion(ses);
                cout << conjunto_sesiones.num_sesiones() << endl;
            }
            else cout << "Ya existe una sesión con el mismo id." << endl;
        }
        else if(comando == "nuevo_curso" or comando == "nc"){
            int s;
            cin >> s;
            Curso c;
            if(c.leer(s)){
                conjunto_cursos.afegir_curso(c);
                cout << conjunto_cursos.num_cursos() << endl;
            }
            else cout << "Hay uno o más problemas que se repiten en el curso!" << endl;
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
            int c;
            cin >> c;
            if(conjunto_cursos.existe_curso(c)){
                string p;
                cin >> p;
                if(conjunt_problemes.existe_problema(p)){
                    string ses = conjunto_cursos.sesion_problema(c,p);
                    if(ses != "NO_EN_CURSO") cout << ses << endl;
                    else cout << "El problema no esta en el curso." << endl;
                }
                else cout << "No existe el problema: " << p << endl;
            }
            else cout << "No existe el curso: " << c << endl;
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
            if(conjunt_problemes.existe_problema(p)){
                conjunt_problemes.Escribir(p);
            }
            else cout << "No existe ningún problema con este identificador." << endl;
        }
        else if(comando == "listar_sesiones" or comando == "ls"){
            conjunto_sesiones.Escribir();
        }
        else if(comando == "escribir_sesion" or  comando == "es"){
            string s;
            cin >> s;
            if(conjunto_sesiones.existe_sesion(s)){
                conjunto_sesiones.Escribir(s);
            }
            else cout << "No existe ningúna sesión con este identificador." << endl;
        }
        else if(comando == "listar_cursos" or comando == "lc"){
            conjunto_cursos.Escribir();
        }
        else if(comando == "escribir_curso" or comando == "lc"){
            int c;
            cin >> c;
            if(conjunto_cursos.existe_curso(c)){
                conjunto_cursos.Escribir(c);
            }
            else cout << "No existe ningún curso con este identificador." << endl;
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
        else cout << "El comando introducido no esta dentro de los aceptados, porfavor vuelvelo a intentar." << endl;
    }
}