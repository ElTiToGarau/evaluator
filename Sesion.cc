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

    void Sesion::find_leaves(const BinTree<string>& t, string id, Usuari& u){
        if(not t.empty()){
            if(t.value()==id){
                insertar_problema_enviable(t,u);
            }
            else{
                find_leaves(t.left(), id, u);
                find_leaves(t.right(), id, u);
            }
        }
    }

    void Sesion::insertar_problema_enviable(const BinTree<string>& t, Usuari& u){
        if(not t.right().empty()){
            if(u.consultar_problema_resuelto(t.right().value())){
                insertar_problema_enviable(t.right(),u);
            }
            else u.afegir_problema_enviable(t.right().value());
        }
        if(not t.left().empty()){
            if(u.consultar_problema_resuelto(t.left().value())){
                insertar_problema_enviable(t.left(),u);
            }
            else u.afegir_problema_enviable(t.left().value());
        }
    }

    void Sesion::trobar_fulles(const string id, Usuari& u){
        find_leaves(problemes_sessio_bin,id,u);
    }


    bool Sesion::existe_problema(string id){
        return find(problemes_sessio_bin,id);
    }

    void Sesion::return_raiz(Usuari& u){
        if(u.mida_problemas_resueltos()==0){
            u.afegir_problema_enviable(problemes_sessio_bin.value());
        }
        else{
            return_problemas_base(problemes_sessio_bin,u);
        }
    }

    void Sesion::return_problemas_base(const BinTree<string>& t, Usuari& u){
        if(not t.empty()){    
            if(not u.consultar_problema_resuelto(t.value())){
                u.afegir_problema_enviable(t.value());
            }
            else{
                if(not t.right().empty()) return_problemas_base(t.right(),u);
                if(not t.left().empty()) return_problemas_base(t.left(),u);
            }
        }
    }

    bool Sesion::modificar_problemas_curso(Curso& c, const string id) {
        bool repetit=false;
        insertar_problemas_curso(problemes_sessio_bin,c,id,repetit);
        return repetit;
    }

    void Sesion::insertar_problemas_curso(const BinTree<string>& t, Curso& c, const string id, bool& repetit) {
        if(not t.empty() and not repetit){
            if(c.afegir_problemas(id,t.value())){
                repetit = true;
            }
            else{
                insertar_problemas_curso(t.right(),c,id,repetit);
                insertar_problemas_curso(t.left(),c,id,repetit);
            }
        }
    }