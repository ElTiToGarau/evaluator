/** @file Usuari.cc
    @brief Código de la clase Usuari
*/

#include "Usuari.hh"

    Usuari::Usuari(){
        env_totales=0;
        inscrito_en_curso=false;
        curso_inscrito=0;
    }

    void Usuari::afegir_problema_intentado(const string id){
        problemas_intentados.insert(id);
    }

    void Usuari::afegir_problema_resuelto(string id) {
        map<string,int>::iterator it=problemas_enviables.find(id);
        problemas_resueltos.insert(pair<string,int>(id,(*it).second));
        problemas_enviables.erase(id);
    }

    void Usuari::afegir_problema_enviable(const string id) {
        problemas_enviables.insert(pair<string,int>(id,0));
    }

    void Usuari::suprimir_problema_enviable(string id) {
        problemas_enviables.erase(id);
    }

    void Usuari::aumentar_problema_enviable(const string id) {
        ++problemas_enviables[id];
    }

    void Usuari::inscribir_curso(int c){
        inscrito_en_curso=true;
        curso_inscrito = c;
    }

    bool Usuari::consultar_problema_enviable(string p)const{
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

    int Usuari::cusro_inscrito()const{
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

    void Usuari::aumentar_numero_envios() {
        ++env_totales;
    }

    int Usuari::consultar_num_enviables() const {
        return problemas_enviables.size();
    }

    void Usuari::modificar_inscrito_en_curso(bool s) {
        inscrito_en_curso=s;
    }

    void Usuari::curso_acabado(){
        inscrito_en_curso=false;
        curso_inscrito=0;
    }

    int Usuari::mida_problemas_resueltos() const{
        return problemas_resueltos.size();
    }

    bool Usuari::consultar_problema_resuelto(string p) const{
        if(problemas_resueltos.count(p)==1) return true;
        else return false;
    }