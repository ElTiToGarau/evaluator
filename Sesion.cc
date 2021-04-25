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
        
    }