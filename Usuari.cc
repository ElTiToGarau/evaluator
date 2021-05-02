#include "Usuari.hh"

    Usuari::Usuari(){
        env_totales=0;
        inscrito_en_curso=false;
        curso_inscrito=0;
    }

    void Usuari::modificar_numero_envios(int num){
        env_totales=num;
    }

    void Usuari::afegir_problema_intentado(const string id){
        problemas_intentados.insert(id);
    }

    void Usuari::afegir_problema_resuelto(const string id){
        map<string,int>::iterator it=problemas_enviables.find(id);
        int num=(*it).second;
        problemas_resueltos.insert(pair<string,int>(id,num));
    }

    void Usuari::afegir_problema_enviable(const string id) {
        problemas_enviables.insert(pair<string,int>(id,0));
    }

    void Usuari::suprimir_problema_enviable(const string id) {
        problemas_enviables.erase(id);
    }

    void Usuari::aumentar_problema_enviable(const string id) {
        ++problemas_enviables[id];
    }

    void Usuari::inscribir_curso(int c, const list<string>& l){
        inscrito_en_curso=true;
        curso_inscrito = c;
        for(list<string>::const_iterator it=l.begin(); it!=l.end(); ++it){
            problemas_enviables.insert(pair<string,int>((*it),0));
        }
    }

    bool Usuari::consultar_problema_enviable(string p){
        if(problemas_enviables.count(p)==1) return true;
        else return false;
    }

    int Usuari::consultar_intentados() const {
        return problemas_intentados.size();
    }

    int Usuari::consultar_resueltos() const {
        return problemas_resueltos.size();
    }

    int Usuari::consultar_total_envios() const {
        return env_totales;
    }

    bool Usuari::consultar_incscrito_curso() const {
        return inscrito_en_curso;
    }

    int Usuari::cusro_inscrito(){
        return curso_inscrito;
    }

    void Usuari::escribir_resueltos() {
        for(map<string,int>::iterator it=problemas_resueltos.begin(); it!=problemas_resueltos.end(); ++it) {
            cout << (*it).first;
            cout << "(" << (*it).second << ")" << endl;
        }
    }

    void Usuari::escribir_enviables() {
        for(map<string,int>::iterator it=problemas_enviables.begin(); it!=problemas_enviables.end(); ++it) {
            cout << (*it).first;
            cout << "(" << (*it).second << ")" << endl;
        }
    }

    map<string,int> Usuari::devolver_problemas_resueltos(){
        return problemas_resueltos;
    }

    void Usuari::aumentar_numero_envios() {
        ++env_totales;
    }
