#ifndef PROYECTO_CIA_H
#define PROYECTO_CIA_H
#include "../AList.h"
#include <iostream>

using namespace std;

class Proyecto_cia
{
    private:
        struct Datos{
            char nombre_proyecto[255];
            char ruta_proyecto[2048];
            const short int codigo_archivos = 1;
            int num_archivos_incluidos;
        };

        struct Archivos{
            char nombre_archivo[255];
            char ruta_archivo[2048];
            int codigo_archivo;
            const short int codigo_archivos = 1;
        };

        Datos datos;
        Archivos archivos;
        AList<Archivos> lista_archivos;
        FILE *archi;

        /*'''''''''''''''''''''''''' Funciones privada '''''''''''''''''''''''''''''''''''*/
        int obtener_siguienteCodigoArchivo(const char* nombreArchivo);
        /*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
    public:
        Proyecto_cia();
        virtual ~Proyecto_cia();

        std::string get_nombreArchivo();
        std::string get_rutaArchivo();
        bool nuevo_proyecto(const char* nombre_proyecto, const char* nombre_archivo, const char* directorio);

};

#endif // PROYECTO_CIA_H
