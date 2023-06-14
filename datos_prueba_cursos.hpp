#include <string>
#include <vector>

using namespace std;

vector<vector<string>> datos_prueba_cursos = {
    {"Ingles para principiantes","Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.","Principiante","langMaster","Ingles","Si"},
    {"Curso de ingles basico","Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.","Principiante","langMaster","Ingles","No"},
    {"Ingles intermedio: mejora tu nivel","Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.","Medio","linguaPro","Ingles","Si","Ingles para principiantes"},
    {"Curso avanzado de ingles","Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.","Avanzado","linguaPro","Ingles","Si","Ingles para principiantes/Ingles intermedio"},
    {"Portugues intermedio","Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.","Medio","linguaPro","Portugues","Si"},
    {"Portugues avanzado","Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.","Avanzado","lingoSensei","Portugues","No","Portugues intermedio"}
};

vector<vector<string>> datos_prueba_lecciones = {
    {"Ingles para principiantes","Saludos y Presentaciones","Aprender a saludar y despedirse"},
    {"Ingles para principiantes","Artículos y Plurales","Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos"},
    {"Curso de ingles basico","Actividades Cotidianas","Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos"},
    {"Curso de ingles basico","Presente Simple","Aprender el uso del presente simple"},
    {"Ingles intermedio: mejora tu nivel","Conversaciones cotidianas","Aprender a hacer preguntas y respuestas en situaciones comunes"},
    {"Curso avanzado de ingles","Uso de modales avanzados","Explorar el uso de los modales complejos"},
    {"Portugues intermedio","Lectura y comprension de textos","Analizar el contenido, vocabulario y estructuras gramaticales utilizadas"},
};

vector<vector<string>> datos_prueba_ejercicios = {
    {"Ingles para principiantes","Saludos y Presentaciones","T","Presentaciones","Mucho gusto en conocerte","Nice to meet you"},
    {"Ingles para principiantes","Saludos y Presentaciones","","R","Presentaciones formales","Please --- me to introduce ---","allow, myself"},
    {"Ingles para principiantes","Artículos y Plurales","T","Plurales regulares","I have two brothers and three sisters","Tengo dos hermanos y tres hermanas"},
    {"Ingles para principiantes","Artículos y Plurales","R","Sustantivos contables en plural","Can I have --- water, please?","some"},
    {"Curso de ingles basico","Actividades Cotidianas","R","Actividades diarias","Wake ---","up"},
    {"Ingles intermedio: mejora tu nivel","Conversaciones cotidianas","R","Consultas de la hora","Q: Do you --- the time?, A: Yes, it is half --- 4","have, past"},
    {"Curso avanzado de ingles","Uso de modales avanzados","T","Dar consejos o expresar obligacion"," You should visit that museum","Deberias visitar ese museo"},
    {"Portugues intermedio","Lectura y comprension de textos","T","Imperativo","Fale comigo","Habla conmigo"}
};

vector<vector<string>> datos_prueba_inscripciones = {
    {"jpidiom","Ingles para principiantes","01/01/2022","N1"},
    {"jpidiom","Ingles intermedio: mejora tu nivel","12/06/2022","N2"},
    {"jpidiom","Curso avanzado de ingles","02/03/2023","N3"},
    {"marsilva","Ingles para principiantes","02/01/2022","N4"},
    {"pero12","Ingles para principiantes","02/01/2022","N5"},
    {"laugu","Ingles para principiantes","03/01/2023","N6"},
    {"laugu","Portugues intermedio","03/01/2023","N7"},
    {"carlo22","Portugues intermedio","05/01/2023","N8"}
};

vector<vector<string>> datos_prueba_aprobaciones = {
    {"jpidiom","Ingles para principiantes","Presentaciones"},
    {"jpidiom","Ingles para principiantes","Presentaciones formales"},
    {"jpidiom","Ingles para principiantes","Plurales regulares"},
    {"jpidiom","Ingles para principiantes","Sustantivos contables en plural"},
    {"jpidiom","Ingles intermedio: mejora tu nivel","Consultas de la hora"},
    {"marsilva","Ingles para principiantes","Presentaciones"},
    {"marsilva","Ingles para principiantes","Presentaciones formales"},
    {"pero12","Ingles para principiantes","Presentaciones"},
    {"pero12","Ingles para principiantes","Presentaciones formales"},
    {"pero12","Ingles para principiantes","Sustantivos contables en plural"}
};


