#include "Problemas.hh"

    Problemas::Problemas() {
    }
    
    Problemas::Problemas(const Problemas& p) {
        lista_problemas = p.lista_problemas;
    }
    
    void Problemas::afegir_problema(string id) {
        Problema p;
        lista_problemas.insert(pair<string,Problema> (id,p));
    }
   
    int Problemas::num_problemas() const {
        return lista_problemas.size();
    }
    
    bool Problemas::existe_problema(string id) const {
        if(lista_problemas.count(id) == 1) return true;
        else return false;
    }
    
    void Problemas::Escribir() {
        list<pair<string,Problema>> lista_ordenada;
        for(map<string,Problema>::iterator it=lista_problemas.begin(); it!=lista_problemas.end(); ++it) {
            lista_ordenada.push_back(*it);
        }
        lista_ordenada.sort(cmp);
        for(list<pair<string,Problema>>::iterator it=lista_ordenada.begin(); it != lista_ordenada.end(); ++it){
            cout << (*it).first << "(";
            cout << (*it).second.consultar_totales() << ",";
            cout << (*it).second.consultar_correctos() << ",";
            cout << (((*it).second.consultar_totales()+1)/((*it).second.consultar_correctos()+1)) << ")" << endl;
        }
    }
    
    void Problemas::Escribir(string id) {
        cout << id;
        cout << "(" << lista_problemas[id].consultar_totales() << ",";
        cout << lista_problemas[id].consultar_correctos() << ",";
        cout << ((lista_problemas[id].consultar_totales()+1)/(lista_problemas[id].consultar_correctos()+1)) << ")" << endl;
    }
    
    void Problemas::leer(int P) {
        for(int i=0; i<P; ++i){
            string id;
            cin >> id;
            Problema p;
            lista_problemas.insert(pair<string,Problema>(id,p));
        }
    }

    bool Problemas::cmp(const pair<string,Problema>& a, const pair<string,Problema>& b) {
        int t = a.second.consultar_totales();
        int e = a.second.consultar_correctos();
        double ratio_a = ((t+1.0)/(e+1.0));
        t = b.second.consultar_totales();
        e = b.second.consultar_correctos();
        double ratio_b = ((t+1.0)/(e+1.0));
        if(ratio_a < ratio_b) return true;
        else if(ratio_b < ratio_a) return false;
        else {
            if(a.first < b.first) return true;
            else return false;
        }
    }
