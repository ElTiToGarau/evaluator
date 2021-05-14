#include "Curso.hh"

    Curso::Curso(){
        veces_completado=0;
        usuarios_incritos=0;
    }

    int Curso::consultar_num_sesiones()const{
        return conjunto_sesiones.size();
    }

    string Curso::devolver_sesion_especifica(string id) const{
        map<string,string>::const_iterator it;
        it = problemas_sesiones.find(id);
        if(it!=problemas_sesiones.end()){
            return (*it).second;
        }
        else return "0";
    }

    string Curso::devolver_sesion_especifica2(int i) const{
        return conjunto_sesiones[i];
    }

    int Curso::consultar_num_usuarios()const{
        return usuarios_incritos;
    }

    int Curso::consultar_veces_resuelto()const{
        return veces_completado;
    }

    void Curso::incrementar_usuarios_inscritos(){
        ++usuarios_incritos;
    }

    void Curso::incrementar_veces_resuelto(){
        ++veces_completado;
    }

    void Curso::leer(int s){
        for(int i=0; i<s; ++i){
            string id;
            cin >> id;
            conjunto_sesiones.push_back(id);
        }
    }

    void Curso::escribir_sesiones(){
        int mida = conjunto_sesiones.size();
        cout << "(";
        for(int i=0; i<mida-1; ++i){
            cout << conjunto_sesiones[i] << " ";
        }
        cout << conjunto_sesiones[mida-1] << ")";
    }

    void Curso::decrementar_usuarios_inscritos(){
        --usuarios_incritos;
    }

    bool Curso::afegir_problemas(const string ses, const string p){
        bool repetit=false;
        if(problemas_sesiones.count(p)==0){
            problemas_sesiones.insert(pair<string,string>(p,ses));
        }
        else repetit=true;
        return repetit;
    }