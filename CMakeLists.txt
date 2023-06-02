project(lab4)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} main.cpp controlador_cursos.cpp dt_completar_palabras.cpp dt_ejercicio.cpp dt_estudiante.cpp dt_leccion.cpp dt_traduccion.cpp fabrica.cpp controlador_usuarios.cpp dt_curso.cpp dt_est_curso.cpp dt_idioma.cpp dt_profesor.cpp dt_usuario.cpp) # Aca se ponen los archivos .cpp

