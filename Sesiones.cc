#include "Sesiones.hh"

    Sesiones::Sesiones(){}

    void Sesiones::afegir_sesion(string id, const Sesion& s){
        conjunt_sesions.insert(pair<string,Sesion>(id,s));
    }

    int Sesiones::num_sesiones() const{
        return conjunt_sesions.size();
    }

    bool Sesiones::existe_sesion(string id){
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

    void Sesiones::leer(int Q){
        for(int i=0; i<Q; ++i){
            string id;
            cin >> id;
            Sesion s;
            s.leer();
            conjunt_sesions.insert(pair<string,Sesion>(id,s));
        }
    }

    string Sesiones::existe_problema(Curso c, const string p){
        int mida = c.consultar_num_sesiones();
        for(int i=0; i<mida; ++i){
            if(conjunt_sesions[c.devolver_sesion_especifica(i)].existe_problema(p)) return (c.devolver_sesion_especifica(i));
        }
        return "0";
    }
    
    void Sesiones::problemas_raiz(const string l, const map<string,int>& m, list<string>& llista){
        conjunt_sesions[l].return_raiz(m,llista);
    }

    list<string> Sesiones::trobar_fulles(const string s, const string p){
        return conjunt_sesions[s].trobar_fulles(p);
    }

    bool Sesiones::poner_problemas_sesion(Curso& c){
        int mida = c.consultar_num_sesiones();
        for (int i=0; 0<mida; ++i){
            string id = c.devolver_sesion_especifica(i);
            if(conjunt_sesions[id].modificar_problemas_curso(c,id)){
                return false;
            }
        }
        return true;
    }