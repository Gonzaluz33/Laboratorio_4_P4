#include "idioma.hpp"
#include "dt_idioma.hpp"
#include "controlador_usuarios.hpp"
#include <set>
#include <vector>

Idioma::Idioma(string nombre){
    this->nombre = nombre;
}

Idioma::~Idioma(){
}

string Idioma::getNombre(){
    return this->nombre;
}

DTIdioma Idioma::getDataIdioma(){
    DTIdioma dti = DTIdioma(this->nombre);
    return dti;
}

void Idioma::agregarObservador(IObserver *o){
    observadores.insert(o);
}

void Idioma::eliminarObservador(IObserver *o){
    observadores.erase(o);
}

void Idioma::notificarCambio(string nombre_curso){
    set<IObserver*>::iterator it;
    for(it = observadores.begin(); it != observadores.end(); ++it)
        (*it)->notificar(nombre_curso, getNombre()); 
}

static void quitarIdioma(vector<DTIdioma>& idiomas,DTIdioma idioma)
{   
    vector<DTIdioma>::iterator it;
    for (it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        if ((*it) == idioma)
        {
            idiomas.erase(it);
        }
    }
}

vector <DTIdioma> Idioma::compararIdioma(vector <DTIdioma>iS){ //Retorna un DataIdioma con los datos de i si este no se encuentra en la lista iS
    //comparo, si es igual lo elimino de la nueva
    ControladorUsuarios *cu = ControladorUsuarios::getInstance(); 
    //vector<DTIdioma> idiomasNoSuscritos = ptr->listarIdiomas(); 
    //vector<DTIdioma>::iterator it;
    //for(it = iS.begin(); it != iS.end(); ++it){
    //    vector<DTIdioma>::iterator it2 = idiomasNoSuscritos.begin();
    //    while(it2 != iS.end() && it2)
    //    if(iS == *it){ 
    //        idiomasNoSuscritos.erase(it);
    //    }
    //}
    //return idiomasNoSuscritos;

    vector<DTIdioma> idiomas_todos = cu->listarIdiomas();
    vector<DTIdioma>::iterator it;
    for (it = iS.begin(); it != iS.end(); ++it)
    {
        quitarIdioma(idiomas_todos,(*it));
    }
    return idiomas_todos;
}

