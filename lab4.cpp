#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "tipo_usuario.hpp"
#include "dt_idioma.hpp"
#include "dt_fecha.hpp"
#include "controlador_usuarios.hpp"
#include "estudiante.hpp"
#include "profesor.hpp"
#include "dt_idioma.hpp"
#include "controlador_cursos.hpp"
#include "fabrica.hpp"
#include "icontrolador_cursos.hpp"
#include "dt_inscripcion.hpp"
#include "completarPalabras.hpp"
#include "traduccion.hpp"
#include "dt_est_estudiante.hpp"
#include "dt_est_curso.hpp"
#include "dt_est_profesor.hpp"
#include "dt_completar_palabras.hpp"
#include "dt_traduccion.hpp"
#include <fstream>
#include <sstream>
#include "datos_prueba_usuarios.hpp"
#include "datos_prueba_cursos.hpp"
 

using namespace std;

Fabrica fabrica;

int main(){
    int opcion;

    do {
        cout << "------------------------------------------------" << endl;
        cout << "-------------------   MENU   -------------------" << endl;
        cout << "------------------------------------------------" << endl;
        cout << " 1. Alta de Usuario" << endl;
        cout << " 2. Consulta de Usuario" << endl;
        cout << " 3. Alta de Idioma" << endl;
        cout << " 4. Consultar Idiomas" << endl;
        cout << " 5. Alta de Curso" << endl;
        cout << " 6. Agregar Leccion" << endl;
        cout << " 7. Agregar Ejercicio" << endl;
        cout << " 8. Habilitar Curso" << endl;
        cout << " 9. Eliminar Curso" << endl;
        cout << "10. Consultar Curso" << endl;
        cout << "11. Inscribirse a Curso" << endl;
        cout << "12. Realizar Ejercicio" << endl;
        cout << "13. Consultar Estadísticas" << endl;
        cout << "14. Suscribirse a Notificaciones" << endl;
        cout << "15. Consulta de Notificaciones" << endl;
        cout << "16. Eliminar Suscripciones" << endl;
        cout << "17. Cargar Datos de Prueba" << endl;
        cout << "18. Salir" << endl;
        cout << "Seleccione una opcion: ";
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
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese una descripcion: ";
                string descripcion;
                getline(cin, descripcion);
                int opcion_tipo;
                do{
                    cout << "Ingrese el tipo de usuario: "<< endl
                    << "1. Profesor "<<endl<<"2. Estudiante "<< endl;
                    cin >> opcion_tipo;
                    if(opcion_tipo < 1 || opcion_tipo > 2)
                    cout << "Ingrese un número dentro de las opciones: " << endl;
                }while(opcion_tipo < 1 || opcion_tipo > 2);
                ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                TipoUsuario tipo;
                bool selecciono_idioma = false;
                switch (opcion_tipo) {
                case 1:
                    {
                        tipo = Prof;
                        cu->iniciarAltaUsuario(nickname,contrasenia,nombre,descripcion,tipo);
                        cout << "Ingrese el nombre del instituto: ";
                        string instituto;
                        cin.ignore();
                        getline(cin, instituto);
                        cu->datosAdicionalesProfesor(instituto);
                        cout << "Seleccionar Idiomas (debe seleccionar almenos un idioma)"<<endl;
                        vector<DTIdioma> idiomas_a_listar = cu->listarIdiomas();
                        int opcion3;
                        bool es_el_primero = true;
                        if(idiomas_a_listar.size() > 0){
                            do{
                                cout << "Mostrando Idiomas..." << endl;
                                cout << "Ingrese el número 0 cuando haya seleccionado todos los idiomas" << endl;
                                vector<DTIdioma>::iterator it;
                                int i = 1;
                                for(it = idiomas_a_listar.begin() ; it != idiomas_a_listar.end(); ++it){
                                    cout << i << ". " << it->getNombre() << endl;
                                    i++;
                                }
                                cout << "Ingrese el idioma seleccionado: ";
                                cin >> opcion3;
                                if(opcion3 != 0){
                                    DTIdioma idioma_seleccionado = idiomas_a_listar[opcion3-1];
                                    cu->seleccionarIdioma(idioma_seleccionado);
                                    selecciono_idioma = true;
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
                            } while(opcion3 != 0 || es_el_primero);
                        } else {
                            cout << "---------------------------------------------------"
                                 << endl << "No hay ningun idioma disponible en el sistema..."
                                 << endl << "Asegurese de que haya algun idioma disponible antes de ingresar un profesor."
                                 << endl <<"---------------------------------------------------";
                        }
                        break;
                    }
                case 2:
                    {
                        tipo = Est;
                        cu->iniciarAltaUsuario(nickname,contrasenia,nombre,descripcion,tipo);
                        cout << "Ingrese el pais de Residencia: ";
                        string pais;
                        cin.ignore();
                        getline(cin, pais);
                        cout << "Ingrese la fecha de nacimiento separados por espacios: dia mes año en formato numerico: ";
                        int dia;
                        int mes;
                        int anio;
                        cin >> dia >> mes >> anio;
                        DTFecha fecha = DTFecha(dia,mes,anio);
                        cu->datosAdicionalesEstudiante(pais,fecha);
                    }
                    break;
                }
                if(tipo == Est || (selecciono_idioma && tipo == Prof)){
                    if(cu->altaUsuario()){
                        cout << "El usuario se dio de alta correctamente"<<endl;
                    }else{
                        cout << "El nickname ingresado ya existe en el sistema"<<endl;
                    }
                }
            }
            break;
        case 2:
            {
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
                int ind_selecc;
                string usuario_seleccionado;
                do{
                    cout << "Ingrese la opcion correspondiente al usuario que desea consultar: ";
                    cin >> ind_selecc;
                    if(ind_selecc > nicknames.size() || ind_selecc <= 0 ){
                        cout << "Ingrese un número dentro de las opciones." << endl;  
                    } else {
                        usuario_seleccionado = nicknames[ind_selecc-1];
                    }
                }while(ind_selecc <= 0 || ind_selecc > nicknames.size());

                cout << "Informacion del usuario: " << endl;
                DTUsuario* us = cu->getDataUsuario(usuario_seleccionado);
                cout << "Nombre: " << us->getNombre() << endl;
                cout << "Descripcion: " << us->getDescripcion() << endl;
                DTProfesor* dtp = dynamic_cast<DTProfesor*>(us);
                if(dtp == nullptr){
                    DTEstudiante* dte = dynamic_cast<DTEstudiante*>(us);
                    cout << "Pais de residencia: " << dte->getPais() << endl;
                    cout<< "Fecha de nacimiento: "<< dte->getDTFecha() <<endl;
                }else{
                    cout << "Instituto donde trabaja: " << dtp->getInstituto() << endl;
                    vector<DTIdioma>::iterator iter2;
                    cout << "Idiomas en los que se especializa: " << endl;
                    vector<DTIdioma> idiomas = dtp->getIdiomas();
                    for(iter2 = idiomas.begin();iter2 != idiomas.end(); iter2++){
                       cout << "\t" << iter2->getNombre() << endl;
                       //cout << iter2->getNombre();
                    }
                }
                delete us;
            }
            break;
        case 3:
            {
                cout << "Ha seleccionado la opción 3: Alta de Idioma" << endl;
                bool error;
                do{
                    cout << "Ingrese el nombre del idioma a dar de alta: ";
                    string i;
                    cin.ignore();
                    getline(cin, i);
                    DTIdioma dti = DTIdioma(i);
                    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                    error = cu->iniciarAltaIdioma(dti);
                    if (error){
                        cout << "Ya existe un idioma con ese nombre" << endl;
                    }else{
                        cout << "El idioma fue dado de alta correctamente" << endl;
                    }
                }while(error);
            }
            break;
        case 4:
            {
                cout << "Ha seleccionado la opción 4: Consultar Idiomas" << endl;
                vector<DTIdioma> dtidiomas;
                do{
                    cout << "Idiomas disponibles: " << endl;
                    ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                    dtidiomas = cu->listarIdiomas();
                    vector<DTIdioma>::iterator it;
                    if(dtidiomas.size() > 0){
                        int i = 1;
                        for(it = dtidiomas.begin();it != dtidiomas.end(); it++){
                            cout << i << ". " << it->getNombre() << endl;
                            i++;
                        }
                    }else {
                        cout << "No hay ningun idioma en el sistema" << endl;
                    }
                }while(dtidiomas.empty());
            }
            break;
        case 5:
            {
                cout << "Ha seleccionado la opción 5: Alta de Curso" << endl;
                ControladorUsuarios* cu = ControladorUsuarios::getInstance();
                vector<string> profes = cu->listarProfesores();
                if(profes.empty()){
                    cout << "No existen profesores en el sistema, le recomendamos cargar un profesor seleccionando la opcion 1" << endl;
                }else{
                    cout << "Ingrese el profesor que quiere seleccionar para el curso" << endl;
                    cout << "Profesores disponibles:" << endl;
                    vector<string>::iterator it;
                    int i = 1;
                    for(it = profes.begin(); it != profes.end(); it++){
                        cout << i << ". " << *it << endl;
                        i++;
                    }
                    int ind_selecc;
                    cin >> ind_selecc;
                    bool esta_en_rango = true;
                    do{
                        esta_en_rango = (ind_selecc > 0) && (ind_selecc < i);
                        if(!esta_en_rango){
                            cout << "Ingrese un numero dentro del rango: ";
                            cin >> ind_selecc;
                        }
                    }while(!esta_en_rango);
                    string profe_selecc = profes.at(ind_selecc-1);
                    cout << "Ingrese el nombre del curso: ";
                    string nom;
                    cin.ignore();
                    getline(cin, nom);
                    cout << "Ingrese la descripcion del curso: ";
                    string desc;
                    getline(cin, desc);
                    bool difbien;
                    Dificultad d;
                    do{
                        cout << "Ingrese la dificultad del curso: "<< endl
                         << "1. Principiante "<<endl<<"2. Medio "<< endl <<"3. Avanzado "<<endl;
                        int dificult;
                        cin >> dificult;
                        if(dificult == 1){
                            d = Principiante;
                            difbien = true;
                        }else if(dificult == 2){
                            d = Medio;
                            difbien = true;
                        }else if(dificult == 3){
                            d = Avanzado;
                            difbien = true;
                        }else{
                            difbien = false;
                            cout << "No existe esa dificultad, por favor elija entre las opciones disponibles" << endl;
                        }
                    }while(!difbien);
                    IControladorCursos* cc = fabrica.getIControladorCursos();
                    cc->iniciarAltaCurso(profe_selecc,nom,desc,d);
                    cout << "Listando los idiomas en los que se especializa el profesor:" << endl;
                    vector<DTIdioma> idiomasProf = cc->listaIdiomasProfesor(profe_selecc);
                    if(idiomasProf.empty()){
                        cout << "El profesor no tiene cargado ningun idioma, agregue un idioma al profesor y vuelva a empezar con el alta del curso" << endl;
                    }else{
                        cout << "Seleccione el idioma en el cual se dictara el curso: "<<endl;
                        vector<DTIdioma>::iterator i;
                        int j = 1;
                        for(i = idiomasProf.begin(); i != idiomasProf.end(); i++){
                            cout << j << ". " << i->getNombre() << endl;
                            j++;
                        }
                        int indice_selecc;
                        cin >> indice_selecc;
                        esta_en_rango = true;
                        do{
                            esta_en_rango = (indice_selecc > 0) && (indice_selecc <= j);
                            if(!esta_en_rango){
                                cout << "Ingrese un numero que este en el rango: ";
                                cin >> indice_selecc;
                            }
                        }while(!esta_en_rango);
                        string idiom = idiomasProf.at(indice_selecc - 1).getNombre();
                        DTIdioma dtidioma = DTIdioma(idiom);
                        cc->seleccionarIdiomaCurso(dtidioma);
                        cout << "¿Desea que este curso tenga cursos previos?(responda con si o no): ";
                        string respuesta;
                        cin >> respuesta;
                        if(respuesta == "si"){
                            cout << "Listando cursos habilitados:" << endl;
                            vector<DTCurso> cursos = cc->listarCursosHabilitados();
                            if(cursos.empty()){
                                cout << "No existen cursos disponibles en el sistema" << endl;
                            }else{
                                bool salir = true;
                                do{
                                    vector<DTCurso>::iterator iter;
                                    int i = 1;
                                    for(iter = cursos.begin(); iter != cursos.end(); iter++){
                                        cout << i << ". " << iter->getNombre() << endl;
                                        i++;
                                    }
                                    cout << "Indique la opcion correspondiente al curso: ";
                                    int previa;
                                 
                                    do{
                                        cin >> previa;
                                        if(!(previa <= 0 || previa > cursos.size())){
                                            cc->seleccionarCursosPrevios(cursos[previa-1].getNombre());
                                            cout << "¿Desea agregar otro curso?: ";
                                            string respuesta2;
                                            bool respondioBien;
                                            do{
                                                cin >> respuesta2;
                                                if(respuesta2 == "si"){
                                                    salir = false;
                                                    respondioBien = true;
                                                }else if (respuesta2 == "no"){
                                                    salir = true;
                                                    respondioBien = true;
                                                }else{
                                                    cout << "ingrese si o no";
                                                    respondioBien = false;
                                                }
                                            }while(!respondioBien);
                                        }else{
                                            cout << "Ingrese un numero dentro del rango."<<endl;
                                        }
                                        
                                    }while(previa <= 0 || previa > cursos.size());
                                    
                                }while(!salir);
                            }
                        }
                        cc->crearCurso();
                        cout << "¿Desea agregar lecciones? (responda con si o no): ";
                        string resp;
                        cin >> resp;
                        if(resp == "si"){
                            do {
                                //cc->seleccionarCurso(nom);
                                cout << "Indique el nombre del tema a tratar en la leccion: ";
                                string tema;
                                cin.ignore();
                                getline(cin, tema);
                                cout << "Indique el objetivo de la leccion: ";
                                string objetivo;
                                getline(cin, objetivo);
                           
                                cc->crearLeccion(tema,objetivo);
                         
                                cout << "¿Desea agregar un ejercicio? (indique si o no): ";
                                string resp2;
                                cin >> resp2;
                                if (resp2 == "si"){
                                    do{
                                        int opcion_tipo;
                                        do{
                                            cout << "Ingrese el tipo de ejercicio (1: Completar palabras 2: Traduccion): ";
                                            cin >> opcion_tipo;
                                            if(opcion_tipo < 1 || opcion_tipo > 2)
                                                cout << "Ingrese un número dentro de las opciones" << endl;
                                        }while(opcion_tipo < 1 || opcion_tipo > 2);
                                        cout << "Ingrese una descripcion: ";
                                        cin.ignore();
                                        string descripcion;
                                        getline(cin, descripcion);
                                        //ingresar mas datos del ejercicio (segun el tipo)
                                        TipoEjercicio tipo_ej;
                                        switch (opcion_tipo){
                                            case 1:
                                                {
                                                    tipo_ej = CompPalabras;
                                                    cc->crearEjercicio(tipo_ej, descripcion);
                                                    cout << "Ingrese la frase a completar, representando las palabras faltantes mediante 3 guiones"<< endl;
                                                    string frase;
                                                    getline(cin, frase);
                                                    cout << "Ingrese el conjunto ordenado de palabras que conforman la solución, separandolas con una coma" << endl;
                                                    string solucion;
                                                    getline(cin, solucion);
                                                    cc->agregarDatosCP(frase, solucion); //ya queda en el ejercicio seleccionado??
                                                }
                                                break;
                                            case 2:
                                                {
                                                    tipo_ej = Trad;
                                                    cc->crearEjercicio(tipo_ej, descripcion);
                                                    cout << "Ingrese la frase a traducir" << endl;
                                                    string frase;
                                                    getline(cin, frase);
                                                    cout << "Ingrese la frase traducida" << endl;
                                                    string solucion;
                                                    getline(cin, solucion);
                                                    cc->agregarDatosTR(frase, solucion);
                                                }    
                                                break;
                                        }
                                        cc->altaEjercicio();
                                        cout << "Ejercicio agregado correctamente"<< endl;
                                        cout << "¿Desea agregar otro ejercicio? (indique si o no): ";
                                        cin >> resp2;
                                    }while(resp2 == "si");
                                }
                                cc->altaLeccion();
                                cout << "La leccion fue creada con éxito" << endl;
                                cout << "¿Desea agregar otra lección? (responda con si o no): ";
                                cin >> resp;
                            } while(resp == "si");
                        }
                        cc->darAltaCurso();
                    }
                 cout << "El curso se dio de alta correctamente" << endl;
                }
            }
            break;
        case 6:
            {
                cout << "Ha seleccionado la opción 6: Agregar Leccion" << endl;
                IControladorCursos *cc = fabrica.getIControladorCursos();
                vector<DTCurso> cursosNoHabilitados = cc->listarCursosNoHabilitados();
                cout << "Cursos no habilitados:" << endl;
                vector<DTCurso>::iterator iter;
                int indice = 1;
                for(iter = cursosNoHabilitados.begin(); iter != cursosNoHabilitados.end(); iter++){
                    cout << indice << ". " << iter->getNombre() << endl;
                    indice++;
                }
                bool estaEnRango;
                int indice_selecc;
                do{
                    cout << "Seleccione el curso al cual le quiere agregar la leccion: ";
                    cin >> indice_selecc;
                    if((indice_selecc < indice)&&(indice_selecc > 0)){
                        estaEnRango = true;
                    }else{
                        cout << "Seleccione un numero dentro del rango: " << endl;
                        cin >> indice_selecc;
                        estaEnRango = false;
                    }
                }while(!estaEnRango);
                cc->seleccionarCurso(cursosNoHabilitados[indice_selecc-1].getNombre());
                cout << "Indique el nombre del tema a tratar en la leccion: ";
                string tema;
                cin.ignore();
                getline(cin, tema);
                cout << "Indique el objetivo de la leccion: ";
                string objetivo;
                getline(cin, objetivo);
                cc->crearLeccion(tema,objetivo);
                cout << "¿Desea agregar un ejercicio?(indique si o no): ";
                string resp;
                cin >> resp;
                if (resp == "si"){
                    do{
                        int opcion_tipo;
                        do{
                            cout << "Ingrese el tipo de ejercicio (1: Completar palabras 2: Traducción): ";
                            cin >> opcion_tipo;
                            if(opcion_tipo < 1 || opcion_tipo > 2)
                                cout << "Ingrese un número dentro de las opciones" << endl;
                        }while(opcion_tipo < 1 || opcion_tipo > 2);
                        cout << "Ingrese una descripción: ";
                        cin.ignore();
                        string descripcion;
                        getline(cin, descripcion);
                        //ingresar mas datos del ejercicio (segun el tipo)
                        TipoEjercicio tipo_ej;
                        switch (opcion_tipo){
                            case 1:
                                {
                                    tipo_ej = CompPalabras;
                                    cc->crearEjercicio(tipo_ej, descripcion);
                                    cout << "Ingrese la frase a completar, representando las palabras faltantes mediante 3 guiones"<< endl;
                                    string frase;
                                    getline(cin, frase);
                                    cout << "Ingrese el conjunto ordenado de palabras que conforman la solución, separandolas con una coma" << endl;
                                    string solucion;
                                    getline(cin, solucion);
                                    cc->agregarDatosCP(frase, solucion); //ya queda en el ejercicio seleccionado??
                                }
                                break;
                            case 2:
                                {
                                    tipo_ej = Trad;
                                    cc->crearEjercicio(tipo_ej, descripcion);
                                    cout << "Ingrese la frase a traducir" << endl;
                                    string frase;
                                    getline(cin, frase);
                                    cout << "Ingrese la frase traducida" << endl;
                                    string solucion;
                                    getline(cin, solucion);
                                    cc->agregarDatosTR(frase, solucion);
                                }    
                                break;
                        }
                        cc->altaEjercicio();
                        cout << "Ejercicio agregado correctamente"<< endl;
                        cout << "¿Desea agregar otro ejercicio? (indique si o no): ";
                        cin >> resp;
                    }while(resp == "si");
                }
                cc->altaLeccion();
                cout << "La leccion fue creada con éxito" << endl;
            }
            break;
        case 7:
            {
                cout << "Ha seleccionado la opción 7: Agregar Ejercicio" << endl;
                IControladorCursos *cc = fabrica.getIControladorCursos();
                //listar cursos no habilitados
                vector<DTCurso> cursos = cc->listarCursosNoHabilitados();
                cout << "Cursos No Habilitados:" << endl;
                vector<DTCurso>::iterator it_curso;
                int i = 1;
                for(it_curso = cursos.begin(); it_curso != cursos.end(); it_curso++) {
                    /* 1. [Ingles] - Curso Introductorio Ingles - En este curso se enseña... */
                    cout << i << ". [" << it_curso->getIdioma().getNombre() << "] - "
                         << it_curso->getNombre() << endl
                         << "\t" << it_curso->getDescripcion() << endl;
                    i++;
                }
                //seleccionar un curso
                int curso_seleccionado;
                bool esta_dentro_del_rango;
                do {
                    cout << "Seleccione un curso: ";
                    cin >> curso_seleccionado;
                    esta_dentro_del_rango = curso_seleccionado >= 1 && curso_seleccionado < i;
                    if(!esta_dentro_del_rango) {
                        cout << "Seleccione un numero dentro del rango." << endl;
                    }
                } while(!esta_dentro_del_rango);
                DTCurso curso_sel = cursos[curso_seleccionado-1];
                cc->seleccionarCurso(curso_sel.getNombre());
                //listar las lecciones de forma ordenada
                vector<DTLeccion> lecciones = cc->listarLeccionesOrdenado();
                cout << "Lecciones definidas:" << endl;
                vector<DTLeccion>::iterator it_leccion;
                i = 1;
                for(it_leccion = lecciones.begin(); it_leccion != lecciones.end(); it_leccion++) {
                    cout << i <<". Tema: " << it_leccion->getNombreTema() 
                         << " - Objetivo: " << it_leccion->getObjetivo()
                         << " - Cantidad de ejercicios: " << it_leccion->getTotalDeEjercicios() << endl;
                    i++;
                }
                //seleccionar una leccion
                int leccion_seleccionada;
                do {
                    cout << "Seleccione una leccion: ";

                    cin >> leccion_seleccionada;
                    esta_dentro_del_rango = leccion_seleccionada >= 1 && leccion_seleccionada <= i;
                    if(!esta_dentro_del_rango) {
                        cout << "Seleccione un numero dentro del rango." << endl;
                    }
                } while(!esta_dentro_del_rango);
                DTLeccion leccion_sel = lecciones[leccion_seleccionada-1];
                cc->seleccionarLeccion(leccion_sel.getNombreTema());
                //ingresar tipo ejercicio y descripcion
                int opcion_tipo;
                do{
                    cout << "Ingrese el tipo de ejercicio (1: Completar palabras 2: Traduccion): ";
                    cin >> opcion_tipo;
                    if(opcion_tipo < 1 || opcion_tipo > 2)
                        cout << "Ingrese un número dentro de las opciones" << endl;
                }while(opcion_tipo < 1 || opcion_tipo > 2);
                cout << "Ingrese una descripcion: ";
                cin.ignore();
                string descripcion;
                getline(cin, descripcion);
                //ingresar mas datos del ejercicio (segun el tipo)
                TipoEjercicio tipo_ej;
                switch (opcion_tipo){
                    case 1:
                        {
                            tipo_ej = CompPalabras;
                            cc->crearEjercicio(tipo_ej, descripcion);
                            cout << "Ingrese la frase a completar, representando las palabras faltantes mediante 3 guiones"<< endl;
                            string frase;
                            getline(cin, frase);
                            cout << "Ingrese el conjunto ordenado de palabras que conforman la solución, separandolas con una coma" << endl;
                            string solucion;
                            getline(cin, solucion);
                            cc->agregarDatosCP(frase, solucion);
                        }
                        break;
                    case 2:
                        {
                            tipo_ej = Trad;
                            cc->crearEjercicio(tipo_ej, descripcion);
                            cout << "Ingrese la frase a traducir" << endl;
                            string frase;
                            getline(cin, frase);
                            cout << "Ingrese la frase traducida" << endl;
                            string solucion;
                            getline(cin, solucion);
                            cc->agregarDatosTR(frase, solucion);
                        }    
                        break;
                }
                cc->altaEjercicio();
                cout << "Ejercicio agregado correctamente"<< endl;
            }
            break;
        case 8:
            {
                int indice_curso;
                IControladorCursos *cc = fabrica.getIControladorCursos();
                cout << "Ha seleccionado la opción 8: Habilitar Curso" << endl;
                vector<DTCurso> cursos = cc->listarCursosNoHabilitados();
                if (cursos.empty()) {
                    cout << "No hay cursos no habilitados." << endl;
                    break;
                }
                cout << "Cursos No Habilitados:" << endl;
                vector<DTCurso>::iterator it;
                int index = 1;
                for(it = cursos.begin(); it != cursos.end(); it++) {
                    /* 1. [Ingles] - Curso Introductorio Ingles - En este curso se enseña... */
                    cout << index++ << ". [" << it->getIdioma().getNombre() << "] - "
                         << it->getNombre() << endl << "\t" << it->getDescripcion() << endl;
                }
                bool esta_dentro_del_rango;
                do {
                    cout << "Seleccione un curso: ";
                    cin >> indice_curso;
                    esta_dentro_del_rango = indice_curso >= 1 && indice_curso < index;
                    if(!esta_dentro_del_rango) {
                        cout << "Seleccione un numero dentro del rango." << endl;
                    }
                } while(!esta_dentro_del_rango);

                DTCurso curso_seleccionado = cursos[indice_curso-1];
                cc->seleccionarCurso(curso_seleccionado.getNombre());
                if(cc->habilitarCurso()) {
                    cout << "El curso no pudo ser habilitado." << endl
                         << "El curso puede ser habilitado solamente si tiene al menos una "
                            "leccion y todas sus lecciones tienen al menos un curso." << endl;
                } else {
                    cout << "El curso fue habilitado." << endl;
                }

            }
            break;
        case 9:
            {
                IControladorCursos *cc = fabrica.getIControladorCursos();
                int indice_curso;
                cout << "Ha seleccionado la opción 9: Eliminar Curso" << endl;
                cout << "Cursos: " << endl;

                vector<DTCurso> cursos = cc->listarCursos();
                vector<DTCurso>::iterator it;
                int index = 1;
                for(it = cursos.begin(); it != cursos.end(); it++) {
                    /* 1. [Ingles] - Curso Introductorio Ingles - En este curso se enseña... */
                    cout << index++ << ". [" << it->getIdioma().getNombre() << "] - "
                         << it->getNombre() << endl << "\t" << it->getDescripcion() << endl;
                }
                bool esta_dentro_del_rango;
                do {
                    cout << "Seleccione un curso: ";
                    cin >> indice_curso;
                    esta_dentro_del_rango = indice_curso >= 1 && indice_curso < index;
                    if(!esta_dentro_del_rango) {
                        cout << "Seleccione un numero dentro del rango." << endl;
                    }
                } while(!esta_dentro_del_rango);
                DTCurso curso_seleccionado = cursos[indice_curso-1];
                cc->eliminarCurso(curso_seleccionado.getNombre());
                cout << "El curso fue eliminado." << endl;

            }
            break;
        case 10:
            {
                IControladorCursos *cc = fabrica.getIControladorCursos();
                int indice_curso;
                cout << "Ha seleccionado la opción 10: Consultar Curso" << endl;
                cout << "Cursos: " << endl;

                // Listo cursos
                vector<DTCurso> cursos = cc->listarCursos();
                vector<DTCurso>::iterator it_curso;
                int index = 1;
                for(it_curso = cursos.begin(); it_curso != cursos.end(); it_curso++) {
                    cout << index++ << ". " << it_curso->getNombre() << endl;
                }
                bool esta_dentro_del_rango;

                // Seleccion de curso
                do {
                    cout << "Seleccione un curso: ";
                    cin >> indice_curso;
                    esta_dentro_del_rango = indice_curso >= 1 && indice_curso < index;
                    if(!esta_dentro_del_rango) {
                        cout << "Seleccione un numero dentro del rango." << endl;
                    }
                } while(!esta_dentro_del_rango);
                DTCurso curso_seleccionado = cursos[indice_curso-1];

                // Imprimo datos curso
                cout << "Informacion del Curso:" << endl
                     << "----------------------------------------------------" << endl
                     << "Nombre: " << curso_seleccionado.getNombre() << endl
                     << "Descripción: " << curso_seleccionado.getDescripcion() << endl
                     << "Dificultad: "
                     << ((curso_seleccionado.getDificultad() == Principiante) ? "Principiante" :
                        (curso_seleccionado.getDificultad() == Medio) ? "Medio" :
                        (curso_seleccionado.getDificultad() == Avanzado) ? "Avanzado" : "")
                     << endl
                     << "Idioma: " << curso_seleccionado.getIdioma().getNombre() << endl
                     << "Nombre del Profesor: " << curso_seleccionado.getProfesor()->getNombre()
                     << endl
                     << "Esta Habilitado: " << (curso_seleccionado.getEstaHabilitado() ? "Si":"No")
                     << endl;

                cout << "Lecciones: " << endl
                     << "----------------------------------------------------" << endl;

                // Listo lecciones
                vector<DTLeccion> lecciones = curso_seleccionado.getLecciones();
                vector<DTLeccion>::iterator it_leccion;
                int num_leccion = 1;
                for(it_leccion = lecciones.begin(); it_leccion != lecciones.end(); it_leccion++) {
                    cout << "\tLeccion " << num_leccion++ << ":" << endl
                         << "\tTema: " << it_leccion->getNombreTema() << endl
                         << "\tObjetivo: " << it_leccion->getObjetivo() << endl;
                    vector<DTEjercicio*> ejercicios = it_leccion->getEjercicios();
                    vector<DTEjercicio*>::iterator it_ejercicio;
                    int num_ejercicio = 1;
                    for(it_ejercicio = ejercicios.begin();
                                    it_ejercicio != ejercicios.end(); it_ejercicio++) {
                        DTCompletarPalabras *cp = dynamic_cast<DTCompletarPalabras*>(*it_ejercicio);
                        if(cp) {
                            cout << "\t\tEjercicio " << num_ejercicio++ 
                                 << " (Completar Palabras):" << endl
                                 << "\t\tDescripcion: " << (*it_ejercicio)->getDescripcion() << endl;
                            cout << "\t\tFrase: " << cp->getFrase() << endl
                                 << "\t\tSolución (Palabras Faltantes): " << cp->getPalabrasFaltantes() << endl;
                        } else {
                            DTTraduccion *t = dynamic_cast<DTTraduccion*>(*it_ejercicio);
                            cout << "\t\tEjercicio " << num_ejercicio++
                                 << " (Traducción):" << endl
                                 << "\t\tDescripcion: " << (*it_ejercicio)->getDescripcion() << endl;
                            cout << "\t\tFrase: " << t->getFraseTraducir() << endl
                                 << "\t\tSolución (Traducción): " << t->getTraduccionFrase() << endl;
                        }
                        cout << "\t\t------------------------------------" << endl;
                    }
                    cout << "\t--------------------------------------------" << endl;
                }

                cout << "Inscripciones: " << endl
                     << "----------------------------------------------------" << endl;

                // Listo inscripciones
                vector<DTInscripcion> inscripciones = curso_seleccionado.getInscripciones();
                vector<DTInscripcion>::iterator it_inscripcion;
                for(it_inscripcion = inscripciones.begin(); 
                                    it_inscripcion != inscripciones.end(); it_inscripcion++) {
                    DTFecha f = it_inscripcion->getFechaInscripcion();
                    cout << "\tNombre Estudiante: " << it_inscripcion->getNombreEstudiante() << endl
                         << "\tFecha Inscripcion: " << f.getDia() << "/" << f.getMes() << "/"
                         << f.getAnio() << endl
                         << "\t--------------------------------------------" << endl;
                }
            }
            break;
        case 11: 
            {
                cout << "Ha seleccionado la opción 11: Inscribirse a Curso" << endl;
                cout << "Ingrese el Nickname del Usuario: ";
                string nickname;
                cin >> nickname;
                int indice_curso;
                IControladorCursos* cc = fabrica.getIControladorCursos();
                vector<DTCurso> cursosDisponibles = cc->listarCursosDisponibles(nickname);
                if (cursosDisponibles.empty()) {
                    cout << "No hay cursos disponibles." << endl;
                    break;
                }
                vector<DTCurso>::iterator it1;
                int i_12 = 1;
                cout << "Cursos Disponibles:" << endl;
                for(it1 = cursosDisponibles.begin(); it1 != cursosDisponibles.end(); ++it1){
                    cout << i_12 << ". " << (*it1).getNombre() << endl;
                    i_12++;
                }
                cout << "-------------------------" << endl;
                int opcion_12 = 0;
                do{
                    cout << "Ingrese la opcion correspondiente a el curso seleccionado: ";
                    cin >> opcion_12;
                    if(opcion_12 > cursosDisponibles.size() || opcion_12 <= 0 ){
                        cout << "Ingrese un número dentro de las opciones" << endl;  
                    } else {
                        cc->inscribirseACurso(cursosDisponibles[opcion_12-1]);
                    }
                }while(opcion_12 <= 0 || opcion_12 > cursosDisponibles.size());
                cout << "Se incribio al curso correctamente." << endl;
            }
            break;
        case 12: {
            cout << "Ha seleccionado la opción 12: Realizar Ejercicio" << endl;
            cout << "Ingrese el Nickname del Usuario: ";
            string nickname;
            cin >> nickname;
            IControladorCursos* cc = fabrica.getIControladorCursos();
            vector<DTCurso> cursosNoAprobados = cc->listarCursosNoAprobados(nickname);
            if (cursosNoAprobados.empty()) {
                cout << "No tiene cursos no aprobados." << endl;
                break;
            }
            vector<DTCurso>::iterator it1;
            int i_12 = 1;
            cout << "Cursos No Aprobados:" << endl; 
            for(it1 = cursosNoAprobados.begin(); it1 != cursosNoAprobados.end(); ++it1){
                cout << i_12 << ". " << (*it1).getNombre() << endl;
                i_12++;
            }
            cout << "-------------------------" << endl;
            int opcion_12 = 0;
            do{
                cout << "Ingrese la opcion correspondiente a el curso seleccionado: ";
                cin >> opcion_12;
                if(opcion_12 > cursosNoAprobados.size() || opcion_12 <= 0 ){
                    cout << "Ingrese un número dentro de las opciones" << endl;  
                }
            }while(opcion_12 > cursosNoAprobados.size() || opcion_12 <= 0);

            string nomCurso = cursosNoAprobados[opcion_12-1].getNombre();
            vector<DTEjercicio*> ejerciciosPendientes = cc->listarEjerciciosPendientes(nomCurso);
            vector<DTEjercicio*>::iterator it2;
            if (ejerciciosPendientes.empty()) {
                cout << "No tiene ejercicios pendientes." << endl;
                break;
                // libero ejerciciosPendientes
                for(it2 = ejerciciosPendientes.begin(); it2 != ejerciciosPendientes.end(); ++it2){
                    delete *it2;
                }
            }
            i_12 = 1;
            cout << "Ejercicios Pendientes: " << endl;
            for(it2 = ejerciciosPendientes.begin(); it2 != ejerciciosPendientes.end(); ++it2){
                cout << i_12 << ". " << (*it2)->getDescripcion() << endl;
                i_12++;
            }
            cout << "-------------------------" << endl;
            opcion_12 = 0;
            do{
                cout << "Ingrese la opcion correspondiente a el ejercicio seleccionado: ";
                cin >> opcion_12;
                if(opcion_12 > ejerciciosPendientes.size() || opcion_12 <= 0 ){
                    cout << "Ingrese un número dentro de las opciones" << endl;  
                }
            }while(opcion_12 > ejerciciosPendientes.size() || opcion_12 <= 0 );

            cc->seleccionarEjercicio(*ejerciciosPendientes[opcion_12-1]);
            
            DTCompletarPalabras* objetoDerivado = dynamic_cast<DTCompletarPalabras*>(ejerciciosPendientes[opcion_12-1]);
            string solucion;
            if (objetoDerivado) {
                cout << "Frase: "
                     << objetoDerivado->getFrase() << endl
                     << "Ingrese las palabras que conforman la solución, separandolas con una coma: " << endl;
                cin.ignore();
                getline(cin, solucion);
                cc->ingresarSolucionCP(solucion);
            } else {
                DTTraduccion *dtt = dynamic_cast<DTTraduccion*>(ejerciciosPendientes[opcion_12-1]);
                cout << "Frase:"
                     << dtt->getFraseTraducir() << endl
                     << "Ingrese traducción: " << endl;
                cin.ignore();
                getline(cin, solucion);
                cc->ingresarSolucionT(solucion);
            }

            // libero ejerciciosPendientes
            for(it2 = ejerciciosPendientes.begin(); it2 != ejerciciosPendientes.end(); ++it2){
                delete *it2;
            }

            bool ejAprobado = cc->ejercicioAprobado();
            if(ejAprobado){
                cout << "Ejercicio Aprobado ";
            }
            else{
                cout << "Ejercicio no Aprobado";
            }
        }
        break;
        case 13:{
            cout << "Ha seleccionado la opción 13: Consultar Estadísticas" << endl;

            IControladorUsuarios* cu = fabrica.getIControladorUsuarios();
            IControladorCursos* cc = fabrica.getIControladorCursos();

            int opcion_tipo_est;
            do {
                cout << "Ingrese el numero del tipo de estadisticas que desea consultar: " << endl
                     << "1. Consultar estadisticas estudiante." << endl
                     << "2. Consultar estadisticas profesor." << endl
                     << "3. Consultar estadisticas curso." << endl;
                cin >> opcion_tipo_est;

                if (opcion_tipo_est <= 0 || opcion_tipo_est > 3) {
                     cout << "Ingrese un numero dentro de las opciones." << endl;
                }
            } while (opcion_tipo_est <= 0 || opcion_tipo_est > 3);

            switch (opcion_tipo_est) {
            case 1:
                {
                    vector<string> listarEstudiantes = cu->listarEstudiantes();
                    if (listarEstudiantes.empty()) {
                        cout << "No hay estudiantes." << endl;
                        break;
                    }
                    vector<string>::iterator it;
                    int indice_estudiante;
                    do {
                        cout << "Estudiantes" << endl;
                        int i = 1;
                        for(it = listarEstudiantes.begin(); it != listarEstudiantes.end(); ++it){
                            cout << i++ << ". " << *it << endl;
                        }
                        cout << "Ingrese la opcion correspondiente al estudiante: ";
                        cin >> indice_estudiante;
                        if (indice_estudiante <= 0 || indice_estudiante > listarEstudiantes.size()) {
                            cout << "Ingrese un numero dentro de las opciones." << endl;
                        }
                    } while (indice_estudiante <= 0 || indice_estudiante > listarEstudiantes.size());
                    vector<DTEstEstudiante> est_estudiante = cu->listarEstEstudiante(listarEstudiantes[indice_estudiante-1]);
                    if(est_estudiante.empty()) {
                        cout << "El estudiante no tiene estadisticas." << endl;
                    }
                    vector<DTEstEstudiante>::iterator it2;
                    for(it2 = est_estudiante.begin(); it2 != est_estudiante.end(); it2++) {
                        cout << *it2 << endl
                             << "---------------------------" << endl;
                    }
                }
                break;
            case 2:
                {
                    vector<string> profesores = cu->listarProfesores();
                    if (profesores.empty()) {
                        cout << "No hay profesores." << endl;
                        break;
                    }
                    vector<string>::iterator it;
                    int indice_profesor;
                    do {
                        cout << "Profesores: " << endl;
                        int i = 1;
                        for(it = profesores.begin(); it != profesores.end(); ++it){
                            cout << i++ << ". " << *it << endl;
                        }
                        cout << "Ingrese la opcion correspondiente al profesor: ";
                        cin >> indice_profesor;
                        if (indice_profesor <= 0 || indice_profesor > profesores.size()) {
                            cout << "Ingrese un numero dentro de las opciones" << endl;
                        }
                    } while (indice_profesor <= 0 || indice_profesor > profesores.size());
                    vector<DTEstProfesor> est_profesor = cu->listarEstProfesor(profesores[indice_profesor-1]);
                    if(est_profesor.empty()) {
                        cout << "El profesor no tiene estadisticas." << endl;
                    }
                    vector<DTEstProfesor>::iterator it2;
                    for(it2 = est_profesor.begin(); it2 != est_profesor.end(); it2++) {
                        cout << *it2 << endl
                             << "---------------------------" << endl;
                    }
                }
                break;
            case 3:
                {
                    vector<DTCurso> cursos = cc->listarCursos();
                    if (cursos.empty()) {
                        cout << "No hay cursos." << endl;
                        break;
                    }
                    vector<DTCurso>::iterator it;
                    int indice_curso;
                    do {
                        cout << "Cursos: " << endl;
                        int i = 1;
                        for(it = cursos.begin(); it != cursos.end(); ++it){
                            cout << i++ << ". " << it->getNombre() << endl;
                        }
                        cout << "Ingrese la opcion correspondiente al curso: ";
                        cin >> indice_curso;
                        if (indice_curso <= 0 || indice_curso > cursos.size()) {
                            cout << "Ingrese un numero dentro de las opciones" << endl;
                        }
                    } while (indice_curso <= 0 || indice_curso > cursos.size());
                    DTEstCurso est_curso = cc->listarEstCurso(cursos[indice_curso-1].getNombre());
                    cout << est_curso << endl
                         << "---------------------------" << endl;
                }
                break;
            }
        }
        break;
        case 14:
            {
                IControladorUsuarios* cu = fabrica.getIControladorUsuarios();
                cout << "Ha seleccionado la opción 14: Suscribirse a Notificaciones" << endl;
                cout << "Ingrese el nickname del usuario que desea suscribirse" << endl;
                string nickname_us;
                cin >> nickname_us;
                if(!cu->existeUsuario(nickname_us)){
                    cout << "El nickname ingresado no corresponde a ningún usuario del sistema.." << endl;
                    cout << "Por favor intente nuevamente." << endl;
                }else{
                    vector<DTIdioma> idiomas_a_listar = cu->listarIdiomasNoSuscritos(nickname_us);
                    vector<DTIdioma> idiomas_seleccionados;
                    cout << "Listando idiomas a los que no esta suscrito..." << endl;
                    cout << "-------------------------" << endl;
                    vector<DTIdioma>::iterator it;
                    int i = 1;
                    for(it = idiomas_a_listar.begin(); it != idiomas_a_listar.end(); ++it){
                        cout << i << ". " << (*it).getNombre() << endl;
                        i++;
                    }
                    int opcion;
                    do{
                        cout << "Ingrese el número 0 cuando haya seleccionado todos los idiomas" << endl;
                        cout << "Ingrese el numero correspondiente al idioma seleccionado: ";
                        cin >> opcion;
                        if(opcion > idiomas_a_listar.size() || opcion < 0 ){
                            cout << "Ingrese un número dentro de las opciones" << endl;  
                        } else if(opcion != 0) {
                            idiomas_seleccionados.push_back(idiomas_a_listar[opcion-1]);
                        }
                    } while(opcion != 0); 
                    cu->suscribir(idiomas_seleccionados);
                    cout << "Suscripciones realizadas con exito" << endl;
                }
            }
            break;
        case 15:
            {
                IControladorUsuarios* cu_15 = fabrica.getIControladorUsuarios();
                cout << "Ha seleccionado la opción 15: Consulta de Notificaciones" << endl;
                cout << "Por favor ingrese el nickname del usuario a consultar: " << endl;
                string nick_user_15;
                cin >> nick_user_15;
                if(!cu_15->existeUsuario(nick_user_15)){
                    cout << "El nickname ingresado no corresponde a ningún usuario del sistema.." << endl;
                    cout << "Por favor intente nuevamente." << endl;
                    
                }else{
                    vector<DTNotificacion> notificaciones_a_listar = cu_15->listarNotificaciones(nick_user_15);
                    if (notificaciones_a_listar.empty()) {
                        cout << "No tiene notificaciones." << endl;
                        break;
                    } else {
                        cout << "Listando Notificaciones..." << endl;
                        cout << "-------------------------" << endl;
                        vector<DTNotificacion>::iterator it_15;
                        for(it_15 = notificaciones_a_listar.begin();
                                it_15 != notificaciones_a_listar.end();++it_15){
                            cout << (*it_15) << endl
                                 << "-------------------------" << endl;
                        }
                    }
                }
            }
            break;
        case 16:
            {
                IControladorUsuarios* cu_16 = fabrica.getIControladorUsuarios();
                cout << "Ha seleccionado la opción 16: Eliminar Suscripciones" << endl;
                cout << "Por favor ingrese el nickname del usuario correspondiente: " << endl;
                string nick_user_16;
                cin >> nick_user_16;
                if(!cu_16->existeUsuario(nick_user_16)){
                    cout << "El nickname ingresado no corresponde a ningún usuario del sistema.." << endl;
                    cout << "Por favor intente nuevamente." << endl;
                }else{
                    vector<DTIdioma> idiomas_seleccionados;
                    vector<DTIdioma> idiomas_suscritos = cu_16->listarIdiomasSuscritos(nick_user_16);
                    cout << "Listando idiomas suscritos..." << endl;
                    cout << "-------------------------" << endl;
                    vector<DTIdioma>::iterator it_16;
                    int i_16 = 1;
                    for(it_16 = idiomas_suscritos.begin(); it_16 != idiomas_suscritos.end();++it_16){
                        cout << i_16 << ". " << (*it_16).getNombre() << endl;
                        i_16++;
                    }
                    cout << "-------------------------" << endl;
                    int opcion_16 = 0;
                     do{
                        cout << "Ingrese el número 0 cuando haya seleccionado todos los idiomas" << endl;
                        cout << "Ingrese la opcion correspondiente a el idioma seleccionado: ";
                        cin >> opcion_16;
                        if(opcion_16 > idiomas_suscritos.size() || opcion_16 < 0 ){
                            cout << "Ingrese un número dentro de las opciones" << endl;  
                        }else if(opcion_16 != 0){
                            idiomas_seleccionados.push_back(idiomas_suscritos[opcion_16-1]);
                        }
                    }while(opcion_16 != 0);
                    cu_16->eliminarSuscripcion(idiomas_seleccionados);
                    cout << "Las suscripciones se eliminaron con exito." << endl;
                }
            }
            break;
        case 17:
            {
                cout << "Ha seleccionado la opción 17: Cargar Datos de Prueba" << endl;
                IControladorCursos *cc = fabrica.getIControladorCursos();
                IControladorUsuarios *cu = fabrica.getIControladorUsuarios();

                // Agrego idiomas
                for (const string& nombreIdioma : datos_prueba_idiomas) {
                    cu->iniciarAltaIdioma(DTIdioma(nombreIdioma));
                }
                
                // Agrego estudiantes
                for (const vector<string>& datos : datos_prueba_estudiantes) {
                    cu->iniciarAltaUsuario(datos[0],datos[1],datos[2],datos[3], Est);
                    string fecha = datos[4];
                    stringstream ss(fecha);
                    int dia, mes, anio;
                    char delimiter = '/';
                    ss >> dia >> delimiter >> mes >> delimiter >> anio;
                    cu->datosAdicionalesEstudiante(datos[5], DTFecha(dia, mes, anio));
                    cu->altaUsuario();
                }

                // Agrego profesores
                for (const vector<string>& values3 : datos_prueba_profesores) {
                    cu->iniciarAltaUsuario(values3[0],values3[1],values3[2],values3[3],Prof);
                    cu->datosAdicionalesProfesor(values3[4]);
                    string idiomas = values3[5];
                    stringstream ss(idiomas);
                    string value4;
                    while (getline(ss,value4,'/')) {
                        cu->seleccionarIdioma(DTIdioma(value4));
                    }
                    cu->altaUsuario();
                }
                
                // Agrega cursos
                for (const vector<string>& values3 : datos_prueba_cursos) {
                    cc->iniciarAltaCurso(values3[3],values3[0],values3[1],
                            (values3[2] == "Principiante") ? Principiante :
                            (values3[2] == "Medio") ? Medio :
                            Avanzado);
                    cc->seleccionarIdiomaCurso(DTIdioma(values3[4]));
                    cc->crearCurso();
                    cc->darAltaCurso();
                }

                // Agrega Lecciones
                for (const vector<string>& values3 : datos_prueba_lecciones) {
                    cc->seleccionarCurso(values3[0]);
                    cc->crearLeccion(values3[1], values3[2]);
                    cc->altaLeccion();
                }

                // Agrega Ejercicios
                for (const vector<string>& values3 : datos_prueba_ejercicios) {
                    cc->seleccionarCurso(values3[0]);
                    cc->seleccionarLeccion(values3[1]);
                    cc->crearEjercicio((values3[2] == "T") ? Trad : CompPalabras,
                                       values3[3]);
                    if (values3[2] == "T") {
                        cc->agregarDatosTR(values3[4],values3[5]);
                    } else {
                        cc->agregarDatosCP(values3[4], values3[5]);
                    }
                    cc->altaEjercicio();
                }

                // Habilita cursos
                for (const vector<string>& datos : datos_prueba_cursos) {
                    if (datos[5] == "Si") {
                        cc->seleccionarCurso(datos[0]);
                        cc->habilitarCurso();
                    }
                }
                
                // Agregar cursos Previos
                for (const vector<string>& datos : datos_prueba_cursos) {
                    if (datos.size() == 7) {
                        string previos = datos[6];
                        stringstream ss(previos);
                        string value4;
                        while (getline(ss,value4,'/')) {
                            cc->agregarCursoPrevio(datos[0], value4);
                        }
                    }
                }

                for (const vector<string>& values3 : datos_prueba_inscripciones) {
                    vector<DTCurso> cursos = cc->listarCursosDisponibles(values3[0]);
                    vector<DTCurso>::iterator it = cursos.begin();
                    if (it != cursos.end() && it->getNombre() == values3[1]) {
                        cc->inscribirseACurso(*it);
                    } else {
                        while (it != cursos.end() && it->getNombre() != values3[1]) {
                            it++;
                            if (it != cursos.end() && it->getNombre() == values3[1]) {
                                cc->inscribirseACurso(*it);
                            }
                        }
                    }

                    for (const vector<string>& datos_aprobacion : datos_prueba_aprobaciones) {
                        if (datos_aprobacion[0] == values3[0]
                                && datos_aprobacion[1] == values3[1]) {
                            cc->listarCursosNoAprobados(datos_aprobacion[0]);
                            vector<DTEjercicio*> ejercicios = cc->listarEjerciciosPendientes(datos_aprobacion[1]);
                            vector<DTEjercicio*>::iterator it = ejercicios.begin();
                            for(vector<DTEjercicio*>::iterator iter = ejercicios.begin();
                                            iter != ejercicios.end(); iter++) {
                                if ((*iter)->getDescripcion() == datos_aprobacion[2]) {
                                    cc->seleccionarEjercicio(**iter);
                                    it = iter;
                                }
                            }
                            DTCompletarPalabras *cp = dynamic_cast<DTCompletarPalabras*>(*it);
                            if(cp) {
                                cc->ingresarSolucionCP(cp->getPalabrasFaltantes());
                            } else {
                                DTTraduccion *t = dynamic_cast<DTTraduccion*>(*it);
                                cc->ingresarSolucionT(t->getTraduccionFrase());
                            }
                            cc->ejercicioAprobado();
                            for(DTEjercicio *ej : ejercicios) {
                                delete ej;
                            }
                        }
                    }    
                }

                cout <<"------------------------------------------------"<<endl;
                cout <<"--------Datos Cargados de forma exitosa---------"<<endl;
                cout <<"------------------------------------------------"<<endl
                     << endl;
            }
            break;
        case 18:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
        
        
    } while (opcion != 18);

    return 0;
}
