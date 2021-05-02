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

    string Sesiones::existe_problema(Cursos& c, int curs, const string p){
        list<string> l = c.lista_sesiones(curs);
        for(list<string>::const_iterator it=l.begin(); it!=l.end(); ++it){
            if(conjunt_sesions[(*it)].existe_problema(p)) return (*it);
        }
        return "0";
    }
    
    list<string> Sesiones::problemas_raiz(const list<string>& l, const map<string,int>& m){
        list<string> llista;
        for(list<string>::const_iterator it=l.begin(); it!=l.end(); ++it){
            conjunt_sesions[(*it)].return_raiz(m,llista);
        }
        return llista;
    }

    list<string> Sesiones::trobar_fulles(const string s, const string p){
        return conjunt_sesions[s].trobar_fulles(p);
    }
