#include "Sesion.hh"

    Sesion::Sesion(){
        num_problemas=0;
    }

    int Sesion::consultar_num_problemas() {
        return num_problemas;
    }

    void Sesion::Escribir() {
        postorde(problemes_sessio_bin);
        cout << endl;
    }

    void Sesion::leer() {
        BinTree<string> ses;
        preorde(ses);
        problemes_sessio_bin = ses;
        num_problemas = recalcular_num_problemas(problemes_sessio_bin);
    }

   void Sesion::postorde(const BinTree<string>& t){
        if(not t.empty()){
            cout << "(";
            postorde(t.left());
            postorde(t.right());
            cout << t.value();
            cout << ")";
        }
    }

    void Sesion::preorde(BinTree<string>& t){
        string a;
        cin >> a;
        if(a!="0"){
            BinTree<string> l;
            preorde(l);
            BinTree<string> r;
            preorde(r);
            t=BinTree<string>(a,l,r);
        }
    }

    int Sesion::recalcular_num_problemas(const BinTree<string>& t){
        int x;
        if(t.empty()) x=0;
        else x=recalcular_num_problemas(t.left())+recalcular_num_problemas(t.right())+1;
        return x;
    }

    bool Sesion::find(const BinTree<string>& t, string id){
        bool b;
        if(t.empty()) b=false;
        else if(t.value()==id){
            b=true;
        }
        else{
            b=find(t.left(), id);
            if(not b) b=find(t.right(), id);
        }
        return b;
    }

    list<string> Sesion::find_leaves(const BinTree<string>& t, string id){
        list<string> b;
        if(t.empty()) return b;
        else if(t.value()==id){
            BinTree<string> d=t.right();
            BinTree<string> e=t.left();
            if(not d.empty()) b.push_back(d.value());
            if(not e.empty()) b.push_back(e.value());
        }
        else{
            b=find_leaves(t.left(), id);
            if(b.empty()) b=find_leaves(t.right(), id);
        }
        return b;
    }

    bool Sesion::existe_problema(string id){
        return find(problemes_sessio_bin,id);
    }

    list<string> Sesion::trobar_fulles(const string id){
        list<string> L = find_leaves(problemes_sessio_bin,id);
        return L;
    }

    void Sesion::return_raiz(Usuari& u){
        if(u.mida_problemas_resueltos()==0){
            u.afegir_problema_enviable(problemes_sessio_bin.value());
        }
        else{
            bool found = false;
            return_problemas_base(problemes_sessio_bin,u,found);
        }
    }

    void Sesion::return_problemas_base(const BinTree<string>& t, Usuari& u, bool& found){
        while(not t.empty() and not found){
            string a=t.value();
            if(u.consultar_problema_resuelto(a)){
                if(not t.right().empty()) return_problemas_base(t.right(),u,found);
                if(not t.left().empty()) return_problemas_base(t.left(),u,found);
            }
            else{
                u.afegir_problema_enviable(a);
                found = true;
            }
        }
    }

    bool Sesion::modificar_problemas_curso(Curso& c, const string id) {
        return insertar_problemas_curso(problemes_sessio_bin,c,id);
    }

    bool Sesion::insertar_problemas_curso(const BinTree<string>& t, Curso& c, const string id) {
        if(not t.empty()){
            if(c.afegir_problemas(id,t.value())){
                return true;
            }
            insertar_problemas_curso(t.right(),c,id);
            insertar_problemas_curso(t.left(),c,id);
        }
        return false;
    }