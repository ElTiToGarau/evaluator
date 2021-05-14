/** @file Cursos.cc
    @brief Código de la clase Cursos
*/

#include "Cursos.hh"

    Cursos::Cursos(){}

    void Cursos::afegir_curso(const Curso& c){
        list_cursos.push_back(c);
    }

    int Cursos::num_cursos() const {
        return list_cursos.size();
    }

    bool Cursos::existe_curso(int id)const{
        if(list_cursos.size()> id-1) return true;
        else return false;
    }

    int Cursos::consultar_num_usuarios(int c) const{
        return list_cursos[c-1].consultar_num_usuarios();
    }

    void Cursos::Escribir(){
        for(int i=0; i<list_cursos.size(); ++i){
            cout << i+1 << " " << list_cursos[i].consultar_veces_resuelto() << " ";
            cout << list_cursos[i].consultar_num_usuarios() << " ";
            cout << list_cursos[i].consultar_num_sesiones() << " ";
            list_cursos[i].escribir_sesiones();
            cout << endl;
        }
    }

    void Cursos::Escribir(int i){
        cout << i << " " << list_cursos[i-1].consultar_veces_resuelto() << " ";
        cout << list_cursos[i-1].consultar_num_usuarios() << " ";
        cout << list_cursos[i-1].consultar_num_sesiones() << " ";
        list_cursos[i-1].escribir_sesiones();
        cout << endl;
    }

    void Cursos::leer(Sesiones& ses){
        int N;
        cin >> N;
        for(int i=0; i<N; ++i){
            Curso c;
            int s;
            cin >> s;
            c.leer(s);
            if(ses.poner_problemas_sesion(c)){
                list_cursos.push_back(c);
            }
        }
    }

    void Cursos::incrementar_veces_resuelto(int c){
        list_cursos[c-1].incrementar_veces_resuelto();
    }

    void Cursos::incrementar_usuarios_inscritos(int c){
        list_cursos[c-1].incrementar_usuarios_inscritos();
    }

    void Cursos::decrementar_usuarios_inscritos(int c){
        list_cursos[c-1].decrementar_usuarios_inscritos();
    }

    void Cursos::devolver_curso(Curso& curs, int c) {
        curs = list_cursos[c-1];
    }

    string Cursos::devolver_sesion_especifica(string id, int c)const{
        return list_cursos[c-1].devolver_sesion_especifica(id);
    }