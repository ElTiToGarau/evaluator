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
        string p;
        cin >> p;
        BinTree<string> ses(p);
        ses=preorde(ses);
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

    BinTree<string> Sesion::preorde(const BinTree<string>& t){
        string a1, a2;
        cin >> a1 >> a2;
        if(a1!="0"){
            BinTree<string> e(a1);
            e = preorde(e);
        }
        else BinTree<string> e;
        if(a2!="0"){
            BinTree<string> d(a2);
            d = preorde(d);
        }
        else BinTree<string> d;
        return BinTree<string>(t.value(),e,d);
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

    bool Sesion::existe_problema(string id){
        return find(problemes_sessio_bin,id);
    }