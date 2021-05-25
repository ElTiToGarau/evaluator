/** @file Usuarios.cc
    @brief Código de la clase Usuarios
*/

#include "Usuarios.hh"

    Usuarios::Usuarios(){}

    void Usuarios::afegir_usauri(const string id) {
        Usuari u;
        lista_usuaris.insert(pair<string,Usuari>(id,u));
    }

    void Usuarios::baja_usuario(const string id) {
        lista_usuaris.erase(id);
    }

    void Usuarios::inscribir_usuario_curso(Cursos& c, Sesiones& s, string id, int curs) {
        //Función que inscribe a un usuario a un determinado curso, y pone como problemas enviables a los problemas de cada sesión
        //no resueltos a los que por prerequisitos se pueden realizar envios.
        Curso curso;
        c.devolver_curso(curso,curs);
        int mida = curso.consultar_num_sesiones();
        for(int i=0; i<mida; ++i){
            s.problemas_raiz(curso.devolver_sesion_especifica2(i), lista_usuaris[id]);
        }
        if(lista_usuaris[id].consultar_num_enviables()!=0){
            lista_usuaris[id].inscribir_curso(curs);
            c.incrementar_usuarios_inscritos(curs);
        }
        else {
            lista_usuaris[id].modificar_inscrito_en_curso(false);
        }
    }

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
        return lista_usuaris[id].consultar_incscrito_curso();
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

    void Usuarios::leer() {
        int M;
        cin >> M;
        for(int i=0; i<M; ++i){
            string id;
            cin >> id;
            Usuari u;
            lista_usuaris.insert(pair<string,Usuari> (id,u));
        }
    }

    void Usuarios::aumentar_problema_enviable(const string id, const string p){
        lista_usuaris[id].aumentar_problema_enviable(p);
    }

    void Usuarios::afegir_problema_intentado(const string id, const string p) {
        lista_usuaris[id].afegir_problema_intentado(p);
    }

    void Usuarios::aumentar_numero_envios(const string id) {
        lista_usuaris[id].aumentar_numero_envios();
    }

    void Usuarios::afegir_problema_resuelto(const string id, const string p) {
        lista_usuaris[id].aumentar_problema_enviable(p);
        lista_usuaris[id].afegir_problema_resuelto(p);
    }

    int Usuarios::consultar_num_enviables(const string id) {
        return lista_usuaris[id].consultar_num_enviables();
    }

    void Usuarios::modificar_inscrito_en_curso(const string id, bool s){
        lista_usuaris[id].modificar_inscrito_en_curso(s);
    }

    void Usuarios::devolver_usuario(Usuari& u, const string id) {
        u = lista_usuaris[id];
    }

    void Usuarios::actualizar_usuario(Usuari& u, const string id) {
        lista_usuaris[id] = u;
    }

    void Usuarios::enivio_problema(int r, string id, string p, string ses, Problemas& cjt_problemas, Sesiones& cjt_sesiones){
        //Función que realiza el envio, y modifica las estadísticas en ambos casos, así como en caso de envio correcto, 
        //pone los nuevos problemas enviables que se pueden enviar por cumplir los prerequisitos, y también pone al problema,
        //enviado correctamente como problema resuelto, por ultimo en caso que el número de problemas enviables sea zero, 
        //después de buscar los problemas enviables, se entiende que se ha acabado el curso, y se desinscribe al usuario del
        //curso, así como modifica las estadísticas del curso.
        if(r==0){
            lista_usuaris[id].afegir_problema_intentado(p);
            lista_usuaris[id].aumentar_numero_envios();
            lista_usuaris[id].aumentar_problema_enviable(p);
            cjt_problemas.incrementar_totales(p);
        }
        else{
            cjt_problemas.incrementar_correctos(p);
            lista_usuaris[id].afegir_problema_intentado(p);
            lista_usuaris[id].aumentar_problema_enviable(p);
            lista_usuaris[id].afegir_problema_resuelto(p);
            lista_usuaris[id].aumentar_numero_envios();
            cjt_sesiones.trobar_fulles(ses,p,lista_usuaris[id]);
            if(lista_usuaris[id].consultar_num_enviables()==0){
                lista_usuaris[id].curso_acabado();
            }
        }
    }