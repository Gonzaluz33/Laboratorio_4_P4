#include "idioma.hpp"
#include "dt_idioma.hpp"
#include "controlador_usuarios.hpp"
#include <set>

Idioma::Idioma(string nombre){
    this->nombre = nombre;
}

Idioma::~Idioma(){
}

void Idioma::getNombre(){
    return this->nombre;
}

DTIdioma Idioma::getDataIdioma(){
    DTIdioma dti = DTIdioma(this->nombre);
    return dti;
}

void Idioma::agregarObservador(IObserver *o){
    observadores->insert(o);
}

void Idioma::eliminarObservador(IObserver *o){
    observadores->erase(o);
}

void Idioma::notificarCambio(string nombre_curso){
    set<IObserver*>::iterator it;
    for(it = observers.begin(); it != observers.end(); ++it)
        it->notificar(nombre_curso, getNombre()); 
}

vector <DTIdioma> Idioma::compararIdioma(vector <DTIdioma>iS){ //Retorna un DataIdioma con los datos de i si este no se encuentra en la lista iS
    //comparo, si es igual lo elimino de la nueva
    ControladorUsuarios *ptr = ControladorUsuarios::getInstance(); 
    vector<DTIdioma> idiomasNoSuscritos = ptr->listarIdiomas(); 
    vector<DTIdioma>::iterator it;
    for(it = iS.begin(); it != iS.end(); ++it){
        if(iS == it.current()){ 
            idiomasNoSuscritos.erase(it);
        }
    }
    return idiomasNoSuscritos; 
}

