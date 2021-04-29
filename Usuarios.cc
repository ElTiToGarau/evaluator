#include "Usuarios.hh"

    Usuarios::Usuarios(){}

    void Usuarios::afegir_usauri(const string id) {
        Usuari u;
        lista_usuaris.insert(pair<string,Usuari>(id,u));
    }

    void Usuarios::baja_usuario(const string id) {
        lista_usuaris.erase(id);
    }

    void Usuarios::inscribir_usuario_curso(string id, int c, const list<string>& l) {
        lista_usuaris[id].inscribir_curso(c, l);
    }

    /*void Usuarios::comprovar_resultado(string id, string p, int r){

    }
    */
    int Usuarios::num_usuarios() const {
        return lista_usuaris.size();
    }

    int Usuarios::curso_usuario(string id){
        return lista_usuaris[id].cusro_inscrito();
    }

    bool Usuarios::existe_usuarios(string id) const {
        if(lista_usuaris.count(id)==1) return true;
        else return false;
    }

    bool Usuarios::consultar_incscrito_curso(string id) {
        if(lista_usuaris[id].consultar_incscrito_curso()) return true;
        else return false;
    }

    bool Usuarios::problema_enviable(string id, string p) {
        if(lista_usuaris[id].consultar_problema_enviable(p)) return true;
        else return false;
    }

    void Usuarios::Escribir(){
        for(map<string,Usuari>::iterator it=lista_usuaris.begin(); it!=lista_usuaris.end(); ++it){
            cout << (*it).first << "(";
            cout << (*it).second.consultar_total_envios() << ",";
            cout << (*it).second.consultar_resueltos() << ",";
            cout << (*it).second.consultar_intentados() << ",";
            if((*it).second.consultar_incscrito_curso()){
                cout << (*it).second.cusro_inscrito() << ")" << endl;
            }
            else cout << 0 << ")" << endl;
        }
    }

    void Usuarios::Escribir(string id){
        cout << id << "(";
        cout << lista_usuaris[id].consultar_total_envios() << ",";
        cout << lista_usuaris[id].consultar_resueltos() << ",";
        cout << lista_usuaris[id].consultar_intentados() << ",";
        if(lista_usuaris[id].consultar_incscrito_curso()){
            cout << lista_usuaris[id].cusro_inscrito() << ")" << endl;
        }
        else cout << 0 << ")" << endl;
    }

    void Usuarios::escribir_resueltos(string id) {
        lista_usuaris[id].escribir_resueltos();
    }

    void Usuarios::escribir_enviables(string id) {
        lista_usuaris[id].escribir_enviables();
    }

    void Usuarios::leer(int M) {
        for(int i=0; i<M; ++i){
            string id;
            cin >> id;
            Usuari u;
            lista_usuaris.insert(pair<string,Usuari> (id,u));
        }
    }

    map<string,int> Usuarios::devolver_problemas_resueltos(string id){
        return lista_usuaris[id].devolver_problemas_resueltos();
    }
