# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/camilo/Documents/P4/lab4/Laboratorio_4_P4-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/camilo/Documents/P4/lab4/Laboratorio_4_P4-main

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/camilo/Documents/P4/lab4/Laboratorio_4_P4-main/CMakeFiles /home/camilo/Documents/P4/lab4/Laboratorio_4_P4-main//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/camilo/Documents/P4/lab4/Laboratorio_4_P4-main/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lab4

# Build rule for target.
lab4: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 lab4
.PHONY : lab4

# fast build rule for target.
lab4/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/build
.PHONY : lab4/fast

completarPalabras.o: completarPalabras.cpp.o
.PHONY : completarPalabras.o

# target to build an object file
completarPalabras.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/completarPalabras.cpp.o
.PHONY : completarPalabras.cpp.o

completarPalabras.i: completarPalabras.cpp.i
.PHONY : completarPalabras.i

# target to preprocess a source file
completarPalabras.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/completarPalabras.cpp.i
.PHONY : completarPalabras.cpp.i

completarPalabras.s: completarPalabras.cpp.s
.PHONY : completarPalabras.s

# target to generate assembly for a file
completarPalabras.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/completarPalabras.cpp.s
.PHONY : completarPalabras.cpp.s

controlador_cursos.o: controlador_cursos.cpp.o
.PHONY : controlador_cursos.o

# target to build an object file
controlador_cursos.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_cursos.cpp.o
.PHONY : controlador_cursos.cpp.o

controlador_cursos.i: controlador_cursos.cpp.i
.PHONY : controlador_cursos.i

# target to preprocess a source file
controlador_cursos.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_cursos.cpp.i
.PHONY : controlador_cursos.cpp.i

controlador_cursos.s: controlador_cursos.cpp.s
.PHONY : controlador_cursos.s

# target to generate assembly for a file
controlador_cursos.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_cursos.cpp.s
.PHONY : controlador_cursos.cpp.s

controlador_usuarios.o: controlador_usuarios.cpp.o
.PHONY : controlador_usuarios.o

# target to build an object file
controlador_usuarios.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_usuarios.cpp.o
.PHONY : controlador_usuarios.cpp.o

controlador_usuarios.i: controlador_usuarios.cpp.i
.PHONY : controlador_usuarios.i

# target to preprocess a source file
controlador_usuarios.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_usuarios.cpp.i
.PHONY : controlador_usuarios.cpp.i

controlador_usuarios.s: controlador_usuarios.cpp.s
.PHONY : controlador_usuarios.s

# target to generate assembly for a file
controlador_usuarios.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/controlador_usuarios.cpp.s
.PHONY : controlador_usuarios.cpp.s

curso.o: curso.cpp.o
.PHONY : curso.o

# target to build an object file
curso.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/curso.cpp.o
.PHONY : curso.cpp.o

curso.i: curso.cpp.i
.PHONY : curso.i

# target to preprocess a source file
curso.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/curso.cpp.i
.PHONY : curso.cpp.i

curso.s: curso.cpp.s
.PHONY : curso.s

# target to generate assembly for a file
curso.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/curso.cpp.s
.PHONY : curso.cpp.s

dt_completar_palabras.o: dt_completar_palabras.cpp.o
.PHONY : dt_completar_palabras.o

# target to build an object file
dt_completar_palabras.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_completar_palabras.cpp.o
.PHONY : dt_completar_palabras.cpp.o

dt_completar_palabras.i: dt_completar_palabras.cpp.i
.PHONY : dt_completar_palabras.i

# target to preprocess a source file
dt_completar_palabras.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_completar_palabras.cpp.i
.PHONY : dt_completar_palabras.cpp.i

dt_completar_palabras.s: dt_completar_palabras.cpp.s
.PHONY : dt_completar_palabras.s

# target to generate assembly for a file
dt_completar_palabras.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_completar_palabras.cpp.s
.PHONY : dt_completar_palabras.cpp.s

dt_curso.o: dt_curso.cpp.o
.PHONY : dt_curso.o

# target to build an object file
dt_curso.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_curso.cpp.o
.PHONY : dt_curso.cpp.o

dt_curso.i: dt_curso.cpp.i
.PHONY : dt_curso.i

# target to preprocess a source file
dt_curso.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_curso.cpp.i
.PHONY : dt_curso.cpp.i

dt_curso.s: dt_curso.cpp.s
.PHONY : dt_curso.s

# target to generate assembly for a file
dt_curso.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_curso.cpp.s
.PHONY : dt_curso.cpp.s

dt_ejercicio.o: dt_ejercicio.cpp.o
.PHONY : dt_ejercicio.o

# target to build an object file
dt_ejercicio.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_ejercicio.cpp.o
.PHONY : dt_ejercicio.cpp.o

dt_ejercicio.i: dt_ejercicio.cpp.i
.PHONY : dt_ejercicio.i

# target to preprocess a source file
dt_ejercicio.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_ejercicio.cpp.i
.PHONY : dt_ejercicio.cpp.i

dt_ejercicio.s: dt_ejercicio.cpp.s
.PHONY : dt_ejercicio.s

# target to generate assembly for a file
dt_ejercicio.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_ejercicio.cpp.s
.PHONY : dt_ejercicio.cpp.s

dt_est_curso.o: dt_est_curso.cpp.o
.PHONY : dt_est_curso.o

# target to build an object file
dt_est_curso.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_curso.cpp.o
.PHONY : dt_est_curso.cpp.o

dt_est_curso.i: dt_est_curso.cpp.i
.PHONY : dt_est_curso.i

# target to preprocess a source file
dt_est_curso.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_curso.cpp.i
.PHONY : dt_est_curso.cpp.i

dt_est_curso.s: dt_est_curso.cpp.s
.PHONY : dt_est_curso.s

# target to generate assembly for a file
dt_est_curso.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_curso.cpp.s
.PHONY : dt_est_curso.cpp.s

dt_est_estudiante.o: dt_est_estudiante.cpp.o
.PHONY : dt_est_estudiante.o

# target to build an object file
dt_est_estudiante.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_estudiante.cpp.o
.PHONY : dt_est_estudiante.cpp.o

dt_est_estudiante.i: dt_est_estudiante.cpp.i
.PHONY : dt_est_estudiante.i

# target to preprocess a source file
dt_est_estudiante.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_estudiante.cpp.i
.PHONY : dt_est_estudiante.cpp.i

dt_est_estudiante.s: dt_est_estudiante.cpp.s
.PHONY : dt_est_estudiante.s

# target to generate assembly for a file
dt_est_estudiante.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_estudiante.cpp.s
.PHONY : dt_est_estudiante.cpp.s

dt_est_profesor.o: dt_est_profesor.cpp.o
.PHONY : dt_est_profesor.o

# target to build an object file
dt_est_profesor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_profesor.cpp.o
.PHONY : dt_est_profesor.cpp.o

dt_est_profesor.i: dt_est_profesor.cpp.i
.PHONY : dt_est_profesor.i

# target to preprocess a source file
dt_est_profesor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_profesor.cpp.i
.PHONY : dt_est_profesor.cpp.i

dt_est_profesor.s: dt_est_profesor.cpp.s
.PHONY : dt_est_profesor.s

# target to generate assembly for a file
dt_est_profesor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_est_profesor.cpp.s
.PHONY : dt_est_profesor.cpp.s

dt_estudiante.o: dt_estudiante.cpp.o
.PHONY : dt_estudiante.o

# target to build an object file
dt_estudiante.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_estudiante.cpp.o
.PHONY : dt_estudiante.cpp.o

dt_estudiante.i: dt_estudiante.cpp.i
.PHONY : dt_estudiante.i

# target to preprocess a source file
dt_estudiante.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_estudiante.cpp.i
.PHONY : dt_estudiante.cpp.i

dt_estudiante.s: dt_estudiante.cpp.s
.PHONY : dt_estudiante.s

# target to generate assembly for a file
dt_estudiante.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_estudiante.cpp.s
.PHONY : dt_estudiante.cpp.s

dt_fecha.o: dt_fecha.cpp.o
.PHONY : dt_fecha.o

# target to build an object file
dt_fecha.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_fecha.cpp.o
.PHONY : dt_fecha.cpp.o

dt_fecha.i: dt_fecha.cpp.i
.PHONY : dt_fecha.i

# target to preprocess a source file
dt_fecha.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_fecha.cpp.i
.PHONY : dt_fecha.cpp.i

dt_fecha.s: dt_fecha.cpp.s
.PHONY : dt_fecha.s

# target to generate assembly for a file
dt_fecha.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_fecha.cpp.s
.PHONY : dt_fecha.cpp.s

dt_idioma.o: dt_idioma.cpp.o
.PHONY : dt_idioma.o

# target to build an object file
dt_idioma.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_idioma.cpp.o
.PHONY : dt_idioma.cpp.o

dt_idioma.i: dt_idioma.cpp.i
.PHONY : dt_idioma.i

# target to preprocess a source file
dt_idioma.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_idioma.cpp.i
.PHONY : dt_idioma.cpp.i

dt_idioma.s: dt_idioma.cpp.s
.PHONY : dt_idioma.s

# target to generate assembly for a file
dt_idioma.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_idioma.cpp.s
.PHONY : dt_idioma.cpp.s

dt_leccion.o: dt_leccion.cpp.o
.PHONY : dt_leccion.o

# target to build an object file
dt_leccion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_leccion.cpp.o
.PHONY : dt_leccion.cpp.o

dt_leccion.i: dt_leccion.cpp.i
.PHONY : dt_leccion.i

# target to preprocess a source file
dt_leccion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_leccion.cpp.i
.PHONY : dt_leccion.cpp.i

dt_leccion.s: dt_leccion.cpp.s
.PHONY : dt_leccion.s

# target to generate assembly for a file
dt_leccion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_leccion.cpp.s
.PHONY : dt_leccion.cpp.s

dt_notificacion.o: dt_notificacion.cpp.o
.PHONY : dt_notificacion.o

# target to build an object file
dt_notificacion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_notificacion.cpp.o
.PHONY : dt_notificacion.cpp.o

dt_notificacion.i: dt_notificacion.cpp.i
.PHONY : dt_notificacion.i

# target to preprocess a source file
dt_notificacion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_notificacion.cpp.i
.PHONY : dt_notificacion.cpp.i

dt_notificacion.s: dt_notificacion.cpp.s
.PHONY : dt_notificacion.s

# target to generate assembly for a file
dt_notificacion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_notificacion.cpp.s
.PHONY : dt_notificacion.cpp.s

dt_profesor.o: dt_profesor.cpp.o
.PHONY : dt_profesor.o

# target to build an object file
dt_profesor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_profesor.cpp.o
.PHONY : dt_profesor.cpp.o

dt_profesor.i: dt_profesor.cpp.i
.PHONY : dt_profesor.i

# target to preprocess a source file
dt_profesor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_profesor.cpp.i
.PHONY : dt_profesor.cpp.i

dt_profesor.s: dt_profesor.cpp.s
.PHONY : dt_profesor.s

# target to generate assembly for a file
dt_profesor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_profesor.cpp.s
.PHONY : dt_profesor.cpp.s

dt_traduccion.o: dt_traduccion.cpp.o
.PHONY : dt_traduccion.o

# target to build an object file
dt_traduccion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_traduccion.cpp.o
.PHONY : dt_traduccion.cpp.o

dt_traduccion.i: dt_traduccion.cpp.i
.PHONY : dt_traduccion.i

# target to preprocess a source file
dt_traduccion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_traduccion.cpp.i
.PHONY : dt_traduccion.cpp.i

dt_traduccion.s: dt_traduccion.cpp.s
.PHONY : dt_traduccion.s

# target to generate assembly for a file
dt_traduccion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_traduccion.cpp.s
.PHONY : dt_traduccion.cpp.s

dt_usuario.o: dt_usuario.cpp.o
.PHONY : dt_usuario.o

# target to build an object file
dt_usuario.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_usuario.cpp.o
.PHONY : dt_usuario.cpp.o

dt_usuario.i: dt_usuario.cpp.i
.PHONY : dt_usuario.i

# target to preprocess a source file
dt_usuario.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_usuario.cpp.i
.PHONY : dt_usuario.cpp.i

dt_usuario.s: dt_usuario.cpp.s
.PHONY : dt_usuario.s

# target to generate assembly for a file
dt_usuario.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/dt_usuario.cpp.s
.PHONY : dt_usuario.cpp.s

ejercicio.o: ejercicio.cpp.o
.PHONY : ejercicio.o

# target to build an object file
ejercicio.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/ejercicio.cpp.o
.PHONY : ejercicio.cpp.o

ejercicio.i: ejercicio.cpp.i
.PHONY : ejercicio.i

# target to preprocess a source file
ejercicio.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/ejercicio.cpp.i
.PHONY : ejercicio.cpp.i

ejercicio.s: ejercicio.cpp.s
.PHONY : ejercicio.s

# target to generate assembly for a file
ejercicio.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/ejercicio.cpp.s
.PHONY : ejercicio.cpp.s

estudiante.o: estudiante.cpp.o
.PHONY : estudiante.o

# target to build an object file
estudiante.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/estudiante.cpp.o
.PHONY : estudiante.cpp.o

estudiante.i: estudiante.cpp.i
.PHONY : estudiante.i

# target to preprocess a source file
estudiante.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/estudiante.cpp.i
.PHONY : estudiante.cpp.i

estudiante.s: estudiante.cpp.s
.PHONY : estudiante.s

# target to generate assembly for a file
estudiante.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/estudiante.cpp.s
.PHONY : estudiante.cpp.s

fabrica.o: fabrica.cpp.o
.PHONY : fabrica.o

# target to build an object file
fabrica.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/fabrica.cpp.o
.PHONY : fabrica.cpp.o

fabrica.i: fabrica.cpp.i
.PHONY : fabrica.i

# target to preprocess a source file
fabrica.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/fabrica.cpp.i
.PHONY : fabrica.cpp.i

fabrica.s: fabrica.cpp.s
.PHONY : fabrica.s

# target to generate assembly for a file
fabrica.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/fabrica.cpp.s
.PHONY : fabrica.cpp.s

idioma.o: idioma.cpp.o
.PHONY : idioma.o

# target to build an object file
idioma.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/idioma.cpp.o
.PHONY : idioma.cpp.o

idioma.i: idioma.cpp.i
.PHONY : idioma.i

# target to preprocess a source file
idioma.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/idioma.cpp.i
.PHONY : idioma.cpp.i

idioma.s: idioma.cpp.s
.PHONY : idioma.s

# target to generate assembly for a file
idioma.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/idioma.cpp.s
.PHONY : idioma.cpp.s

inscripcion.o: inscripcion.cpp.o
.PHONY : inscripcion.o

# target to build an object file
inscripcion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/inscripcion.cpp.o
.PHONY : inscripcion.cpp.o

inscripcion.i: inscripcion.cpp.i
.PHONY : inscripcion.i

# target to preprocess a source file
inscripcion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/inscripcion.cpp.i
.PHONY : inscripcion.cpp.i

inscripcion.s: inscripcion.cpp.s
.PHONY : inscripcion.s

# target to generate assembly for a file
inscripcion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/inscripcion.cpp.s
.PHONY : inscripcion.cpp.s

lab4.o: lab4.cpp.o
.PHONY : lab4.o

# target to build an object file
lab4.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/lab4.cpp.o
.PHONY : lab4.cpp.o

lab4.i: lab4.cpp.i
.PHONY : lab4.i

# target to preprocess a source file
lab4.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/lab4.cpp.i
.PHONY : lab4.cpp.i

lab4.s: lab4.cpp.s
.PHONY : lab4.s

# target to generate assembly for a file
lab4.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/lab4.cpp.s
.PHONY : lab4.cpp.s

leccion.o: leccion.cpp.o
.PHONY : leccion.o

# target to build an object file
leccion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/leccion.cpp.o
.PHONY : leccion.cpp.o

leccion.i: leccion.cpp.i
.PHONY : leccion.i

# target to preprocess a source file
leccion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/leccion.cpp.i
.PHONY : leccion.cpp.i

leccion.s: leccion.cpp.s
.PHONY : leccion.s

# target to generate assembly for a file
leccion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/leccion.cpp.s
.PHONY : leccion.cpp.s

notificacion.o: notificacion.cpp.o
.PHONY : notificacion.o

# target to build an object file
notificacion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/notificacion.cpp.o
.PHONY : notificacion.cpp.o

notificacion.i: notificacion.cpp.i
.PHONY : notificacion.i

# target to preprocess a source file
notificacion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/notificacion.cpp.i
.PHONY : notificacion.cpp.i

notificacion.s: notificacion.cpp.s
.PHONY : notificacion.s

# target to generate assembly for a file
notificacion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/notificacion.cpp.s
.PHONY : notificacion.cpp.s

profesor.o: profesor.cpp.o
.PHONY : profesor.o

# target to build an object file
profesor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/profesor.cpp.o
.PHONY : profesor.cpp.o

profesor.i: profesor.cpp.i
.PHONY : profesor.i

# target to preprocess a source file
profesor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/profesor.cpp.i
.PHONY : profesor.cpp.i

profesor.s: profesor.cpp.s
.PHONY : profesor.s

# target to generate assembly for a file
profesor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/profesor.cpp.s
.PHONY : profesor.cpp.s

traduccion.o: traduccion.cpp.o
.PHONY : traduccion.o

# target to build an object file
traduccion.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/traduccion.cpp.o
.PHONY : traduccion.cpp.o

traduccion.i: traduccion.cpp.i
.PHONY : traduccion.i

# target to preprocess a source file
traduccion.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/traduccion.cpp.i
.PHONY : traduccion.cpp.i

traduccion.s: traduccion.cpp.s
.PHONY : traduccion.s

# target to generate assembly for a file
traduccion.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/traduccion.cpp.s
.PHONY : traduccion.cpp.s

usuario.o: usuario.cpp.o
.PHONY : usuario.o

# target to build an object file
usuario.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/usuario.cpp.o
.PHONY : usuario.cpp.o

usuario.i: usuario.cpp.i
.PHONY : usuario.i

# target to preprocess a source file
usuario.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/usuario.cpp.i
.PHONY : usuario.cpp.i

usuario.s: usuario.cpp.s
.PHONY : usuario.s

# target to generate assembly for a file
usuario.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/usuario.cpp.s
.PHONY : usuario.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... lab4"
	@echo "... completarPalabras.o"
	@echo "... completarPalabras.i"
	@echo "... completarPalabras.s"
	@echo "... controlador_cursos.o"
	@echo "... controlador_cursos.i"
	@echo "... controlador_cursos.s"
	@echo "... controlador_usuarios.o"
	@echo "... controlador_usuarios.i"
	@echo "... controlador_usuarios.s"
	@echo "... curso.o"
	@echo "... curso.i"
	@echo "... curso.s"
	@echo "... dt_completar_palabras.o"
	@echo "... dt_completar_palabras.i"
	@echo "... dt_completar_palabras.s"
	@echo "... dt_curso.o"
	@echo "... dt_curso.i"
	@echo "... dt_curso.s"
	@echo "... dt_ejercicio.o"
	@echo "... dt_ejercicio.i"
	@echo "... dt_ejercicio.s"
	@echo "... dt_est_curso.o"
	@echo "... dt_est_curso.i"
	@echo "... dt_est_curso.s"
	@echo "... dt_est_estudiante.o"
	@echo "... dt_est_estudiante.i"
	@echo "... dt_est_estudiante.s"
	@echo "... dt_est_profesor.o"
	@echo "... dt_est_profesor.i"
	@echo "... dt_est_profesor.s"
	@echo "... dt_estudiante.o"
	@echo "... dt_estudiante.i"
	@echo "... dt_estudiante.s"
	@echo "... dt_fecha.o"
	@echo "... dt_fecha.i"
	@echo "... dt_fecha.s"
	@echo "... dt_idioma.o"
	@echo "... dt_idioma.i"
	@echo "... dt_idioma.s"
	@echo "... dt_leccion.o"
	@echo "... dt_leccion.i"
	@echo "... dt_leccion.s"
	@echo "... dt_notificacion.o"
	@echo "... dt_notificacion.i"
	@echo "... dt_notificacion.s"
	@echo "... dt_profesor.o"
	@echo "... dt_profesor.i"
	@echo "... dt_profesor.s"
	@echo "... dt_traduccion.o"
	@echo "... dt_traduccion.i"
	@echo "... dt_traduccion.s"
	@echo "... dt_usuario.o"
	@echo "... dt_usuario.i"
	@echo "... dt_usuario.s"
	@echo "... ejercicio.o"
	@echo "... ejercicio.i"
	@echo "... ejercicio.s"
	@echo "... estudiante.o"
	@echo "... estudiante.i"
	@echo "... estudiante.s"
	@echo "... fabrica.o"
	@echo "... fabrica.i"
	@echo "... fabrica.s"
	@echo "... idioma.o"
	@echo "... idioma.i"
	@echo "... idioma.s"
	@echo "... inscripcion.o"
	@echo "... inscripcion.i"
	@echo "... inscripcion.s"
	@echo "... lab4.o"
	@echo "... lab4.i"
	@echo "... lab4.s"
	@echo "... leccion.o"
	@echo "... leccion.i"
	@echo "... leccion.s"
	@echo "... notificacion.o"
	@echo "... notificacion.i"
	@echo "... notificacion.s"
	@echo "... profesor.o"
	@echo "... profesor.i"
	@echo "... profesor.s"
	@echo "... traduccion.o"
	@echo "... traduccion.i"
	@echo "... traduccion.s"
	@echo "... usuario.o"
	@echo "... usuario.i"
	@echo "... usuario.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

