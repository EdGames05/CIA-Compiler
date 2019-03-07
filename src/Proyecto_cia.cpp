#define ARCHI_ESCRITURA_BINARIA "rb+"
#define ARCHI_LECTURA_BINARIA "rb"
#define CREAR_ARCHIVO "a"


#include "Proyecto_cia.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <io.h>

//using namespace std;

Proyecto_cia::Proyecto_cia()
{
    //ctor
}

Proyecto_cia::~Proyecto_cia()
{
    //dtor
}

/*''''''''''''''''''''''''''''''''' Funciones publicas '''''''''''''''''''''''''''''''''''''''''''''''*/

int Proyecto_cia::obtener_siguienteCodigoArchivo(const char* nombreArchivo){
    archi = fopen(nombreArchivo,ARCHI_LECTURA_BINARIA);

    if(archi == NULL){
        fclose(archi);
        return -1;
    }
    else{
        unsigned int codigo = 0;
        fseek(archi,0,SEEK_SET);
        fread(&archivos,sizeof(archivos),1,archi);
        while(!feof(archi)){
            codigo = archivos.codigo_archivo + 1;
            fread(&archivos,sizeof(archivos),1,archi);
        }

        fclose(archi);
        return codigo;
    }
}

/*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

/*''''''''''''''''''''''''''''''''' Funciones publicas '''''''''''''''''''''''''''''''''''''''''''''''*/
std::string Proyecto_cia::get_nombreArchivo(){
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}

std::string Proyecto_cia::get_rutaArchivo(){
    std::string archivo = this->get_nombreArchivo();
    return archivo.substr(0,archivo.find_last_of("\\/"));
}

bool Proyecto_cia::nuevo_proyecto(const char* nombre_proyecto, const char* nombre_archivo, const char* directorio){

    string archivo_completo(directorio);
    archivo_completo += string("/") + string(nombre_proyecto);

    archi = fopen(archivo_completo.c_str(), CREAR_ARCHIVO);
    fclose(archi);

    this->archi = fopen(archivo_completo.c_str(), ARCHI_ESCRITURA_BINARIA);

    if(this->archi == NULL){
        fclose(archi);
        return false;
    }

    strcpy(datos.ruta_proyecto,directorio);
    strcpy(datos.nombre_proyecto,nombre_proyecto);
    datos.num_archivos_incluidos = 1;
    strcpy(archivos.nombre_archivo,nombre_archivo);
    strcpy(archivos.ruta_archivo,directorio);
    archivos.codigo_archivo = 1;

    fwrite(&datos, sizeof(datos),1,archi);
    fclose(archi);

    this->archi = fopen(archivo_completo.c_str(), ARCHI_ESCRITURA_BINARIA);

    if(this->archi == NULL){
        fclose(archi);
        archi = fopen(archivo_completo.c_str(), CREAR_ARCHIVO);
        fclose(archi);
        return false;
    }

    fwrite(&archivos, sizeof(archivos), 1, archi);
    fclose(archi);

    string archivo_textoPlano(directorio);
    archivo_textoPlano += "/" + string(nombre_archivo);
    archi = fopen(archivo_textoPlano.c_str(),"a+t");

    fputs("// Función principal \n \nprincipal(){ \n",archi);
    fputs("\t print(\"Hola mundo de CIA...\") \n",archi);
    fputs("}",archi);

    fclose(archi);
    return true;
}
/*''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
