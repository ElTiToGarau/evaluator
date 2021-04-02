#include "Problema.hh"

Problema::Problema(){
    id="0";
    env_correctos=0;
    env_totales=0;
}

Problema::Problema(string id){
    this->id=id;
    env_correctos=0;
    env_totales=0;
}

Problema::Problema(const Problema& p){
    id=p.id;
    env_correctos=p.env_correctos;
    env_totales=p.env_totales;
}

void Problema::modificar(int correctos, int totales){
    env_correctos=correctos;
    env_totales=totales;
}

void Problema::modificar_correctos(int correctos){
    env_correctos=correctos;
}

void Problema::modificar_totales(int totales){
    env_totales=totales;
}

void Problema::incrementar_correctos(){
    ++env_correctos;
    ++env_totales;
}

void Problema::incrementar_totales(){
    ++env_totales;
}

void Problema::afegir_id(string id){
    if(this->id=="0") this->id=id;
    else cout << "L'id ja està iniciat" << endl;
}

string Problema::consultar_id() const{
    return id;
}

int Problema::consultar_correctos() const{
    return env_correctos;
}

int Problema::consultar_totales() const{
    return env_totales;
}