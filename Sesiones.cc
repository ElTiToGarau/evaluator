#include "Sesiones.hh"

    Sesiones::Sesiones(){}

    void Sesiones::afegir_sesion(string id, const Sesion& s){
        conjunt_sesions.insert(pair<string,Sesion>(id,s));
    }

    int Sesiones::num_sesiones() const{
        return conjunt_sesions.size();
    }

    bool Sesiones::existe_sesion(string id)const{
        if(conjunt_sesions.count(id)==1) return true;
        else return false;
    }

    void Sesiones::Escribir(){
        for(map<string,Sesion>::iterator it=conjunt_sesions.begin(); it!=conjunt_sesions.end(); ++it){
            cout << (*it).first << " ";
            cout << (*it).second.consultar_num_problemas() << " ";
            (*it).second.Escribir();
        }
    }

    void Sesiones::Escribir(string id){
        cout << id << " ";
        cout << conjunt_sesions[id].consultar_num_problemas() << " ";
        conjunt_sesions[id].Escribir();
    }

    void Sesiones::leer(){
        int Q;
        cin >> Q;
        for(int i=0; i<Q; ++i){
            string id;
            cin >> id;
            Sesion s;
            s.leer();
            conjunt_sesions.insert(pair<string,Sesion>(id,s));
        }
    }
    
    void Sesiones::problemas_raiz(const string l, Usuari& u){
        conjunt_sesions[l].return_raiz(u);
    }

    void Sesiones::trobar_fulles(const string s, const string p, Usuari& u){
        conjunt_sesions[s].trobar_fulles(p,u);
    }

    bool Sesiones::poner_problemas_sesion(Curso& c){
        //Función que pone dentro de el map del curso pasado por referencia curso, el problema y a que sesión pertenece dicho problema,
        //a parte devuelve false si se intenta poner un problema repetido dentro del mapa del curso.
        bool repetit = true;
        int mida = c.consultar_num_sesiones();
        int i=0;
        while (i<mida and repetit){
            string id = c.devolver_sesion_especifica2(i);
            if(conjunt_sesions[id].modificar_problemas_curso(c,id)){
                repetit = false;
            }
            ++i;
        }
        return repetit;
    }