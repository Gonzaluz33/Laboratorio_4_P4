using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "dt_fecha.hpp"
#include"controlador_usuarios.hpp"
#include "estudiante.hpp"
#include "profesor.hpp"
#include "dt_idioma.hpp"


int main(){
    int opcion;

    do {
        cout << "MENU" << endl;
        cout << "1. Alta de Usuario" << endl;
        cout << "2. Consulta de Usuario" << endl;
        cout << "3. Alta de Idioma" << endl;
        cout << "4. Consultar Idiomas" << endl;
        cout << "5. Alta de Curso" << endl;
        cout << "6. Agregar Leccion" << endl;
        cout << "7. Agregar Ejercicio" << endl;
        cout << "8. Habilitar Curso" << endl;
        cout << "9. Eliminar Curso" << endl;
        cout << "10. Consultar Curso" << endl;
        cout << "11. Inscribirse a Curso" << endl;
        cout << "12. Realizar Ejercicio" << endl;
        cout << "13. Consultar Estadísticas" << endl;
        cout << "14. Suscribirse a Notificaciones" << endl;
        cout << "15. Consulta de Notificaciones" << endl;
        cout << "16. Eliminar Suscripciones" << endl;
        cout << "17. Cargar Datos de Prueba" << endl;
        cout << "18. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Realizar la acción correspondiente según la opción seleccionada
        switch (opcion) {
        case 1:
            {
                cout << "Ha seleccionado la opción 1: Alta de Usuario" << endl;
                cout << "Ingrese el Nickname del Usuario: ";
                string nickname;
                cin >> nickname;
                string contrasenia;
                do{
                    cout << "Ingrese una contraseña (de al menos 6 caracteres): ";
                    cin >> contrasenia;
                    if(contrasenia.size() < 6)
                        cout << "La contraseña debe tener al menos 6 caracteres" << endl;
                }while(contrasenia.size() < 6);
                cout << "Ingrese un nombre: ";
                string nombre;
                cin >> nombre;
                cout << "Ingrese una descripcion: ";
                string descripcion;
                cin >> descripcion;
                int opcion_tipo;
                do{
                    cout << "Ingrese el tipo de usuario (1_ Profesor 2_Estudiante): ";
                    cin >> opcion_tipo;
                    if(opcion_tipo < 1 || opcion_tipo > 2)
                    cout << "Ingrese un número dentro de las opciones" << endl;
                }while(opcion_tipo < 1 || opcion_tipo > 2);
                ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                TipoUsuario tipo;
                switch (opcion_tipo) {
                case 1:
                    {
                        tipo = Prof;
                        cu->iniciarAltaUsuario(nickname,contrasenia,nombre,descripcion,tipo);
                        cout << "Ingrese el nombre del instituto: ";
                        string instituto;
                        cin >> instituto;
                        cu->datosAdicionalesProfesor(instituto);
                        cout << "Seleccionar Idiomas (debe seleccionar almenos un idioma)";
                        vector<DTIdioma> idiomas_a_listar = cu->listarIdiomas();
                        int opcion3;
                        bool es_el_primero = true;
                        do{
                            cout << "Mostrando Idiomas..." << endl;
                            cout << "Ingrese el número 0 cuando haya seleccionado todos los idiomas" << endl;
                            vector<DTIdioma>::iterator it;
                            int i = 1;
                            for(it = idiomas_a_listar.begin() ; it != idiomas_a_listar.end(); ++it){
                                cout << i << ". " << it->getNombre() << endl;
                                i++;
                            }
                            cout << "Ingrese el idioma seleccionado";
                            cin >> opcion3;
                            if(opcion3 != 0){
                                DTIdioma idioma_seleccionado = idiomas_a_listar[opcion3-1];
                                cu->seleccionarIdioma(idioma_seleccionado);
                            }
                            if(opcion3 > idiomas_a_listar.size() + 1 || opcion3 < 0 ){
                                cout << "Ingrese un número dentro de las opciones" << endl;  
                            } else if(es_el_primero){
                                if(opcion3 == 0){
                                    cout << "Debe ingresar al menos un idioma" << endl;
                                }else{
                                    es_el_primero = false;
                                }
                            }
                        }while(opcion3 != 0 || es_el_primero);
                    }
                    break;

                case 2:
                    {
                        tipo = Est;
                        cu->iniciarAltaUsuario(nickname,contrasenia,nombre,descripcion,tipo);
                        cout << "Ingrese el pais de Residencia";
                        string pais;
                        cin >> pais;
                        cout << "Ingrese la fecha de nacimiento separados por espacios: dia mes año en formato numerico";
                        int dia;
                        int mes;
                        int anio;
                        cin >> dia >> mes >> anio;
                        DTFecha fecha = DTFecha(dia,mes,anio);
                        cu->datosAdicionalesEstudiante(pais,fecha);
                    }
                    break;
                }
                if(cu->altaUsuario()){
                    cout << "El usuario se dio de alta correctamente";
                }else{
                    cout << "El nickname ingresado ya existe en el sistema";
                }
            }
            break;
        case 2:
           cout << "Ha seleccionado la opción 2: Consulta de Usuario" << endl;
            cout << "Listando los usuarios" << endl;
            ControladorUsuarios* cu = ControladorUsuarios::getInstance();
            vector<string> nicknames = cu->listarNickname();
            vector<string>::iterator it;
            int i = 1;
            for(it = nicknames.begin();it != nicknames.end();it++){
                cout << i << ". " << *it << endl;
                i++;
            }
            string u;
            do{
                cout << "Seleccione un usuario con su nombre: ";
                cin >> u;
                it = nicknames.begin();
                while(it != nicknames.end() && *it != u){
                    it++;
                }
                if(*it != u){
                    cout << "El nombre de usuario no existe" << endl;
                }
            }while(*it != u);
            cout << "informacion del usuario:" << endl;
            map<string,Usuario*> us = cu->getUsuarios();
            //Usuario* pu = us.find(u)->second->;
            cout << "Nombre: " << us.find(u)->second->getNombre() << endl;
            cout << "Descripcion: " << us.find(u)->second->getDescripcion() << endl;
            if (us.find(u)->second->getTipo() == Est){
                Estudiante* e = dynamic_cast<Estudiante*>(us.find(u)->second);
                cout << "Pais de residencia: " << e->getPaisResidencia() << endl;
            }else{
                Profesor* p = dynamic_cast<Profesor*>(us.find(u)->second);
                cout << "Instituto donde trabaja: " << p->getInstituto() << endl;
                vector<DTIdioma>::iterator iter2;
                cout << "Idiomas en los que se especializa: " << endl;
                for(iter2 = p->getDTidiomas().begin();iter2 != p->getDTidiomas().end(); iter2++){
                    cout << iter2->getNombre() << endl;
                }
            }
            break;
        case 3:
            cout << "Ha seleccionado la opción 3: Alta de Idioma" << endl;
            bool error;
            do{
                cout << "ingrese el nombre del idioma a dar de alta: ";
                string i;
                cin >> i;
                DTIdioma dti = DTIdioma(i);
                ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                error = cu->iniciarAltaIdioma(dti);
                if (error){
                    cout << "Ya existe un idioma con ese nombre" << endl;
                }else{
                    cout << "El idioma fue dado de alta correctamente" << endl;
                }
            }while(error);
            break;
        case 4:
            cout << "Ha seleccionado la opción 4: Consultar Idiomas" << endl;
            vector<DTIdioma> dtidiomas;
            do{
                cout << "Idiomas disponibles:" << endl;
                ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                dtidiomas = cu->listarIdiomas();
                vector<DTIdioma>::iterator it;
                if(dtidiomas.size() > 0){
                    int i = 1;
                    for(it = dtidiomas.begin();it != dtidiomas.end(); it++){
                        cout << i << ". " << it->getNombre() << endl;
                    }
                }else {
                    cout << "No hay ningun idioma en el sistema" << endl;
                }
            }while(dtidiomas.empty());
            break;
        case 5:
            cout << "Ha seleccionado la opción 5: Alta de Curso" << endl;
            break;
        case 6:
            cout << "Ha seleccionado la opción 6: Agregar Leccion" << endl;
            break;
        case 7:
            cout << "Ha seleccionado la opción 7: Agregar Ejercicio" << endl;
            break;
        case 8:
            cout << "Ha seleccionado la opción 8: Habilitar Curso" << endl;
            break;
        case 9:
            cout << "Ha seleccionado la opción 9: Eliminar Curso" << endl;
            break;
        case 10:
            cout << "Ha seleccionado la opción 10: Consultar Curso" << endl;
            break;
        case 11:
            cout << "Ha seleccionado la opción 11: Inscribirse a Curso" << endl;
            break;
        case 12:
            cout << "Ha seleccionado la opción 12: Realizar Ejercicio" << endl;
            break;
        case 13:
            cout << "Ha seleccionado la opción 13: Consultar Estadísticas" << endl;
            break;
        case 14:
            cout << "Ha seleccionado la opción 14: Suscribirse a Notificaciones" << endl;
            break;
        case 15:
            cout << "Ha seleccionado la opción 15: Consulta de Notificaciones" << endl;
            break;
        case 16:
            cout << "Ha seleccionado la opción 16: Eliminar Suscripciones" << endl;
            break;
        case 17:
            cout << "Ha seleccionado la opción 17: Cargar Datos de Prueba" << endl;
            break;
        case 18:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
        
        cout << endl;
    } while (opcion != 5);

    return 0;
}
