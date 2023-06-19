CC = g++
CFLAGS = -g

SRCS = completarPalabras.cpp dt_estudiante.cpp controlador_cursos.cpp dt_fecha.cpp idioma.cpp controlador_usuarios.cpp dt_idioma.cpp inscripcion.cpp curso.cpp dt_inscripcion.cpp dt_leccion.cpp lab4.cpp leccion.cpp dt_notificacion.cpp dt_completar_palabras.cpp notificacion.cpp dt_profesor.cpp dt_curso.cpp profesor.cpp dt_traduccion.cpp dt_ejercicio.cpp dt_usuario.cpp dt_est_curso.cpp traduccion.cpp ejercicio.cpp dt_est_estudiante.cpp usuario.cpp estudiante.cpp dt_est_profesor.cpp fabrica.cpp

OBJS = $(SRCS:.cpp=.o)

OUT = lab4

.PHONY: all clean

all: $(OUT)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(OUT)
