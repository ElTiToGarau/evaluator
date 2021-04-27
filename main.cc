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
    int P,Q,N,M;
    cin >> P;
    conjunt_problemes.leer(P);
    cin >> Q;
    conjunto_sesiones.leer(Q);
    cin >> N;
    conjunto_cursos.leer(N);
    cin >> M;
    conjunto_usuarios.leer(M);
    string comando;
    cin >> comando;
    while(comando != "fin"){
        if(comando == "nuevo_problema" or comando == "np"){
            string id;
            cin >> id;
            if(not conjunt_problemes.existe_problema(id)){
                conjunt_problemes.afegir_problema(id);
            }
            else cout << "error: el problema ya existe" << endl;
        }
        else if(comando == "nueva_sesion" or comando == "ns"){
            string s;
            cin >> s;
            if(not conjunto_sesiones.existe_sesion(s)){
                Sesion ses;
                ses.leer();
                conjunto_sesiones.afegir_sesion(s,ses);
                cout << conjunto_sesiones.num_sesiones() << endl;
            }
            else cout << "error: la sesion ya existe" << endl;
        }
        /*
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
        */
        else if(comando == "alta_usuario" or comando == "a"){
            string id;
            cin >> id;
            if(not conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.afegir_usauri(id);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "error: el usuario ya existe" << endl;
        }
        else if(comando == "baja_usuario" or comando == "b"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.baja_usuario(id);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "inscribir_curso" or comando == "i"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                int c;
                cin >> c;
                if(conjunto_cursos.existe_curso(c)){
                    if(not conjunto_usuarios.consultar_incscrito_curso(id)){
                        list<string> S = conjunto_cursos.lista_sesiones(c);
                        list<string> P = conjunto_sesiones.problemas_raiz(S);
                        conjunto_usuarios.inscribir_usuario_curso(id,c,P);
                        cout << conjunto_cursos.consultar_num_usuarios(c) << endl;
                    }
                    else cout << "error: usuario inscrito en otro curso" << endl;
                }
                else cout << "error: el curso no existe" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "curso_usuario" or comando == "cu"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_usuarios.consultar_incscrito_curso(id)){
                    cout << conjunto_usuarios.curso_usuario(id) << endl;
                }
                else cout << 0 << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "sesion_problema" or comando == "sp"){
            int c;
            cin >> c;
            if(conjunto_cursos.existe_curso(c)){
                string p;
                cin >> p;
                if(conjunt_problemes.existe_problema(p)){
                    list<string> L = conjunto_cursos.lista_sesiones(c);
                    string ses = conjunto_sesiones.existe_problema(L,p);
                    if(ses!="0"){
                        cout << ses << endl;
                    }
                    else cout << "error: el problema no pertenece al curso" << endl;
                }
                else cout << "error: el problema no existe" << endl;
            }
            else cout << "error: el curso no existe" << endl;
        }
        else if(comando == "problemas_resueltos" or comando == "pr"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.escribir_resueltos(id);
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "problemas_enviables" or comando == "pe"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_usuarios.consultar_incscrito_curso(id)){
                    conjunto_usuarios.escribir_enviables(id);
                }
                else cout << "error: usuario no inscrito en ningun curso" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        /*
        else if(comando == "envio" or comando == "e"){
            string id;
            cin >> id;
            if(conjunto_usuarios.existe_usuarios(id) and conjunto_usuarios.consultar_incscrito_curso(id)){
                string p;
                cin >> p;
                int curs;
                curs = conjunto_usuarios.curso_usuario(id);
                if(conjunto_cursos.existe_problema_en_curso(curs,id)){
                    if(conjunto_usuarios.problema_enviable(id,p)){
                        int r;
                        cin >> r;
                        conjunto_usuarios.comprovar_resultado(id,p,r);
                    }
                    else cout << "El problema no es enviable por el usuario." << endl;
                }
                cout << "El problema a enviar no forma parte del curso en el que esta inscrito el usuario." << endl;
            }
            cout << "El usuaio introducido o no existe o no esta inscrito a ningún curso." << endl;
        }
        */
        else if(comando == "listar_problemas" or comando == "lp"){
            conjunt_problemes.Escribir();
        }
        else if(comando == "escribir_problema" or comando == "ep"){
            string p;
            cin >> p;
            if(conjunt_problemes.existe_problema(p)){
                conjunt_problemes.Escribir(p);
            }
            else cout << "error: el problema no existe" << endl;
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
            else cout << "error: la sesion no existe" << endl;
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
            else cout << "error: el curso no existe" << endl;
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
            else cout << "error: el usuario no existe" << endl;
        }
        else cout << "El comando: "<< comando << ", no esta dentro de los aceptados, porfavor vuelvelo a intentar." << endl;
        cin >> comando;
    }
}
