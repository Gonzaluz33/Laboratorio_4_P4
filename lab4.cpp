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

using namespace std;

Fabrica fabrica;

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
                bool esta_en_rango;
                cout << "Seleccione un usuario: ";
                cin >> ind_selecc;
                string usuario_seleccionado = nicknames.at(ind_selecc-1);
                do{
                    esta_en_rango = (ind_selecc > 0) && (ind_selecc < i);
                    if(!esta_en_rango){
                        cout << "Ingrese un numero dentro del rango: ";
                        cin >> ind_selecc;
                        usuario_seleccionado = nicknames.at(i-1);
                    }
                }while(!esta_en_rango);
                cout << "informacion del usuario:" << endl;
                DTUsuario* us;
                *us = cu->getDataUsuario(usuario_seleccionado);
                cout << "Nombre: " << us->getNombre() << endl;
                cout << "Descripcion: " << us->getDescripcion() << endl;
                DTProfesor* dtp = dynamic_cast<DTProfesor*>(us);
                if(dtp == nullptr){
                    DTEstudiante* dte = dynamic_cast<DTEstudiante*>(us);
                    cout << "Pais de residencia: " << dte->getPais() << endl;
                }else{
                    cout << "Instituto donde trabaja: " << dtp->getInstituto() << endl;
                    vector<DTIdioma>::iterator iter2;
                    cout << "Idiomas en los que se especializa: " << endl;
                    for(iter2 = dtp->getIdiomas().begin();iter2 != dtp->getIdiomas().end(); iter2++){
                       cout << iter2->getNombre() << endl;
                    }
                }
            }
            break;
        case 3:
            {
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
            }
            break;
        case 4:
            {
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
                    i = 1;
                    for(it = profes.begin(); it != profes.end(); it++){
                        cout << i << ". " << *it << endl;
                        i++;
                    }
                    int ind_selecc;
                    cin >> ind_selecc;
                    esta_en_rango = true;
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
                    cin >> nom;
                    cout << "Ingrese la descripcion del curso: ";
                    string desc;
                    cin >> desc;
                    bool difbien;
                    Dificultad d;
                    do{
                        cout << "Ingrese la dificultad del curso: ";
                        string dificult;
                        cin >> dificult;
                        if(dificult == "Principiante"){
                            d = Principiante;
                            difbien = true;
                        }else if(dificult == "Medio"){
                            d = Medio;
                            difbien = true;
                        }else if(dificult == "Avanzado"){
                            d = Avanzado;
                            difbien = true;
                        }else{
                            difbien = false;
                            cout << "No existe esa dificultad, por favor elija entre Principiante, Medio o Avanzado" << endl;
                        }
                    }while(!difbien);
                    ControladorCursos cc = ControladorCursos();
                    cc.iniciarAltaCurso(profe_selecc,nom,desc,d);
                    cout << "Listando los idiomas en los que se especializa el profesor:" << endl;
                    vector<DTIdioma> idiomasProf = cc.listaIdiomasProfesor(profe_selecc);
                    if(idiomasProf.empty()){
                        cout << "El profesor no tiene cargado ningun idioma, agregue un idioma al profesor y vuelva a empezar con el alta del curso" << endl;
                    }else{
                        cout << "Seleccione el idioma en el cual se dictara el curso: ";
                        vector<DTIdioma>::iterator i;
                        int j = 1;
                        for(i = idiomasProf.begin(); i != idiomasProf.end(); i++){
                            cout << j << ". " << i->getNombre() << endl;
                        }
                        int indice_selecc;
                        cin >> indice_selecc;
                        esta_en_rango = true;
                        do{
                            esta_en_rango = (indice_selecc < 0) && (indice_selecc > j);
                            if(!esta_en_rango){
                                cout << "Ingrese un numero que este en el rango: ";
                                cin >> indice_selecc;
                            }
                        }while(!esta_en_rango);
                        string idiom = idiomasProf.at(indice_selecc - 1).getNombre();
                        DTIdioma dtidioma = DTIdioma(idiom);
                        cc.seleccionarIdiomaCurso(dtidioma);
                        cout << "¿Desea que este curso tenga cursos previos?(responda con si o no): ";
                        string respuesta;
                        cin >> respuesta;
                        if(respuesta == "si"){
                            cout << "Listando cursos habilitados:" << endl;
                            vector<DTCurso> cursos = cc.listarCursosHabilitados();
                            if(cursos.empty()){
                                cout << "No existen cursos disponibles en el sistema" << endl;
                            }else{
                                bool salir;
                                do{
                                    vector<DTCurso>::iterator iter;
                                    for(iter = cursos.begin(); iter != cursos.end(); it++){
                                        cout << iter->getNombre() << endl;
                                    }
                                    cout << "Seleccione el curso que quiere como previa con su nombre: ";
                                    string previa;
                                    cin >> previa;
                                    iter = cursos.begin();
                                    while(iter->getNombre() != previa || iter != cursos.end()){
                                        it++;
                                    }
                                    if(iter != cursos.end()){
                                        cc.seleccionarCursosPrevios(previa);
                                        cout << "¿Desea agregar otro curso?: ";
                                        string respuesta2;
                                        cin >> respuesta2;
                                        bool respondioBien;
                                        do{
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
                                        cout << "El nombre de curso que escribió no existe, intentelo devuelta" << endl;
                                        salir = false;
                                    }
                                }while(!salir);
                            }
                        }
                        cc.crearCurso();
                        cout << "¿Desea agregar lecciones? (responda con si o no): ";
                        string resp;
                        cin >> resp;
                        if(resp == "si"){
                            cc.seleccionarCurso(nom);
                            cout << "Indique el nombre del tema a tratar en la leccion: ";
                            string tema;
                            cin >> tema;
                            cout << "Indique el objetivo de la leccion: ";
                            string objetivo;
                            cin >> objetivo;
                            cc.crearLeccion(tema,objetivo);
                            cout << "¿Desea agregar un ejercicio?(indique si o no): ";
                            string resp;
                            cin >> resp;
                            if (resp == "si"){
                                do{
                                    //Copio las instrucciones para agregar ejercicio
                                }while(resp == "si");
                            }
                            cc.altaLeccion();
                            cout << "La leccion fue creada con éxito" << endl;
                        }
                        cc.darAltaCurso();
                    }
                }
            }
            break;
        case 6:
            {
                cout << "Ha seleccionado la opción 6: Agregar Leccion" << endl;
                ControladorCursos cc = ControladorCursos();
                vector<DTCurso> cursosNoHabilitados = cc.listarCursosNoHabilitados();
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
                cc.seleccionarCurso((cursosNoHabilitados.at(indice-1)).getNombre());
                cout << "Indique el nombre del tema a tratar en la leccion: ";
                string tema;
                cin >> tema;
                cout << "Indique el objetivo de la leccion: ";
                string objetivo;
                cin >> objetivo;
                cc.crearLeccion(tema,objetivo);
                cout << "¿Desea agregar un ejercicio?(indique si o no): ";
                string resp;
                cin >> resp;
                if (resp == "si"){
                    do{
                        //Copio las instrucciones para agregar ejercicio
                    }while(resp == "si");
                }
                cc.altaLeccion();
                cout << "La leccion fue creada con éxito" << endl;
            }
            break;
        case 7:
            cout << "Ha seleccionado la opción 7: Agregar Ejercicio" << endl;
            break;
        case 8:
            {
                int indice_curso;
                IControladorCursos *cc = fabrica.getIControladorCursos();
                cout << "Ha seleccionado la opción 8: Habilitar Curso" << endl;
                vector<DTCurso> cursos = cc->listarCursosNoHabilitados();
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
                    cout << index++ << it_curso->getNombre() << endl;
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
                     << "Nombre: " << curso_seleccionado.getNombre() << endl
                     << "Descripción: " << curso_seleccionado.getDescripcion() << endl
                     << "Dificultad: "
                     << ((curso_seleccionado.getDificultad() == Principiante) ? "Principiante" :
                        (curso_seleccionado.getDificultad() == Medio) ? "Medio" :
                        (curso_seleccionado.getDificultad() == Avanzado) ? "Avanzado" : "")
                     << endl
                     << "Idioma: " << curso_seleccionado.getIdioma().getNombre() << endl
                     << "Nombre del Profesor: " << curso_seleccionado.getProfesor().getNombre()
                     << endl
                     << "Esta Habilitado: " << (curso_seleccionado.getEstaHabilitado() ? "Si":"No")
                     << endl;

                // Listo lecciones
                vector<DTLeccion> lecciones = curso_seleccionado.getLecciones();
                vector<DTLeccion>::iterator it_leccion;
                for(it_leccion = lecciones.begin(); it_leccion != lecciones.end(); it_leccion++) {
                    cout << "\tTema: " << it_leccion->getNombreTema() << endl
                         << "\tObjetivo: " << it_leccion->getObjetivo() << endl;
                    vector<DTEjercicio> ejercicios = it_leccion->getEjercicios();
                    vector<DTEjercicio>::iterator it_ejercicio;
                    for(it_ejercicio = ejercicios.begin();
                                    it_ejercicio != ejercicios.end(); it_ejercicio++) {
                        cout << "\t\tEjercicio: " << endl
                             << "\t\tDescripcion: " << it_ejercicio->getDescripcion() << endl;
                        // ACA TENGO QUE IMPRIMIR LOS DATOS DEL TIPO ESPECIFICO DE EJERCICIO
                        // CUANDO SEPA COMO TENER LOS DATOS (LO MISMO PASA CON DTUsuario y
                        // DTProfesor, DTEstudiante)
                    }   
                }

                // Listo inscripciones
                vector<DTInscripcion> inscripciones = curso_seleccionado.getInscripciones();
                vector<DTInscripcion>::iterator it_inscripcion;
                for(it_inscripcion = inscripciones.begin(); 
                                    it_inscripcion != inscripciones.end(); it_inscripcion++) {
                    DTFecha f = it_inscripcion->getFechaInscripcion();
                    cout << "\tNombre Estudiante: " << it_inscripcion->getNombreEstudiante() << endl
                         << "\tFecha Inscripcion: " << f.getDia() << "/" << f.getMes() << "/"
                         << f.getAnio() << endl;
                }

            }
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
            {
                ControladorUsuarios* cu_15 = ControladorUsuarios::getInstance();
                cout << "Ha seleccionado la opción 15: Consulta de Notificaciones" << endl;
                cout << "Por favor ingrese el nickname del usuario a consultar: " << endl;
                string nick_user_15;
                cin >> nick_user_15;
                Usuario* user_15 = cu_15->buscarUsuario(nick_user_15);
                if(user_15 == nullptr){
                    cout << "El nickname ingresado no corresponde a ningún usuario del sistema.." << endl;
                    cout << "Por favor intente nuevamente." << endl;
                    
                }else{
                     cout << "Listando Notidicaciones..." << endl;
                    vector<DTNotificacion> notificaciones_a_listar = user_15->getDTNotificaciones();
                    vector<DTNotificacion>::iterator it_15;
                    for(it_15 = notificaciones_a_listar.begin(); it_15 != notificaciones_a_listar.end();++it_15){
                        cout << (*it_15) << endl;
                    }
                }
            }
            break;
        case 16:
            {
                ControladorUsuarios* cu_16 = ControladorUsuarios::getInstance();
                cout << "Ha seleccionado la opción 16: Eliminar Suscripciones" << endl;
                cout << "Por favor ingrese el nickname del usuario correspondiente: " << endl;
                string nick_user_16;
                cin >> nick_user_16;
                Usuario* user_16 = cu_16->buscarUsuario(nick_user_16);
                if(user_16 == nullptr){
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
                            if(opcion_16 > idiomas_suscritos.size() + 1 || opcion_16 < 0 ){
                                cout << "Ingrese un número dentro de las opciones" << endl;  
                            }else{
                                if(opcion_16 != 0){
                                    idiomas_seleccionados.push_back(idiomas_suscritos[opcion_16-1]);
                                }
                            }
                            
                        }while(opcion_16 != 0);
                        vector<Idioma*> idiomas_a_eliminar;
                        map<string, Idioma*> todos_los_idiomas = cu_16->getIdiomas();
                        map<string, Idioma*>::iterator it_aux;
                        string nombre_del_idioma;
                         for(it_16 = idiomas_seleccionados.begin(); it_16 != idiomas_seleccionados.end();++it_16){
                            nombre_del_idioma = (*it_16).getNombre();
                            it_aux = todos_los_idiomas.find(nombre_del_idioma);
                            if(it_aux->second != nullptr){
                                idiomas_a_eliminar.push_back(it_aux->second);
                            }
                        }
                    cu_16->eliminarSuscripcion(idiomas_a_eliminar);
               
                }
            }
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
