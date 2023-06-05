using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "dt_fecha.hpp"
#include"controlador_usuarios.hpp"


int main(){
    int opcion;

    do {
        cout << "MENU" << endl;
        cout << "1. Alta de Usuario" << endl;
        cout << "2. Consulta de Usuario" << endl;
        cout << "3. Alta Idioma" << endl;
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
        cout << "15. Consultar Notificaciones" << endl;
        cout << "16. Eliminar Suscripciones" << endl;
        cout << "17. Cargar Datos de Prueba" << endl;
        cout << "18. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Realizar la acción correspondiente según la opción seleccionada
        switch (opcion) {
            case 1:
                cout << "Ha seleccionado la opción 1" << endl;
                cout << "Ingrese el Nickname del Usuario";
                string nickname;
                cin >> nickname;
                do{
                    cout << "Ingrese una contraseña (de al menos 6 caracteres)";
                    string contrasenia;
                    cin >> contrasenia;
                    if(contrasenia.size() < 6)
                        cout << "La contraseña debe tener al menos 6 caracteres";
                }while(contrasenia.size() < 6)
                cout << "Ingrese un nombre";
                string nombre;
                cin >> nombre;
                cout << "Ingrese una descripcion";
                string descripcion;
                cin >> descripcion;
                do{
                    cout << "Ingrese el tipo de usuario (1_ Profesor 2_Estudiante) :";
                    int opcion_tipo;
                    cin >> opcion_tipo;
                    if(opcion_tipo < 1 || opcion_tipo > 2)
                    cout << "Ingrese un número dentro de las opciones" << endl;
                }while(opcion_tipo < 1 || opcion_tipo > 2)
                switch (opcion_tipo) {
                    case 1: 
                        TipoUsuario tipo = Profesor;
                        cu->iniciarAltaUsuario(nickname,contrasenia,nombre,descripcion,tipo);
                        cout << "Ingrese el nombre del instituto";
                        string instituto;
                        cin >> instituto;
                        cu->datosAdicionalesProfesor(instituto);
                        cout << "Seleccionar Idiomas (debe seleccionar almenos un idioma)";
                        ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                        vector<DTIdioma> idiomas_a_listar = cu->listarIdiomas();
                        int opcion3;
                        bool es_el_primero = true;
                        do{
                            cout << "Mostrando Idiomas..." << endl;
                            cout << "Ingrese el número 0 cuando haya seleccionado todos los idiomas" << endl;
                            vector<DTIdioma>::iterator it;
                            int i = 1;
                            for(it = idiomas_a_listar.begin() ; it != idiomas_a_listar.end(); ++it){
                                cout << i << ". " << (*it)->getNombre() << endl;
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
                        }while(opcion3 != 0 || es_el_primero)
                    
                    break;

                    case 2: 
                            TipoUsuario tipo = Estudiante;
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
                    break;
                }
                if(cu->altaUsuario()){
                    cout << "El usuario se dio de alta correctamente";
                }else{
                    cout << "El nickname ingresado ya existe en el sistema";
                }

                break;
            case 2:
                cout << "Ha seleccionado la opción 2" << endl;
                // Realizar acción para la opción 2
                break;
            case 3:
                cout << "Ha seleccionado la opción 3" << endl;
                // Realizar acción para la opción 3
                break;
            case 4:
                cout << "Ha seleccionado la opción 4" << endl;
                // Realizar acción para la opción 4
                break;
            case 5:
                cout << "Ha seleccionado la opción 5" << endl;
                break;
            case 6:
                cout << "Ha seleccionado la opción 6" << endl;
                break;
            case 7:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 8:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 9:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 10:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 11:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 12:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 13:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 14:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 15:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 16:
                cout << "Ha seleccionado la opción 4" << endl;
                break;
            case 17:
                cout << "Ha seleccionado la opción 4" << endl;
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