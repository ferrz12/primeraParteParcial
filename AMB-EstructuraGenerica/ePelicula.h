#ifndef EPELICULA_H_INCLUDED
#define EPELICULA_H_INCLUDED
#define TAMANIO 50
#define OCUPADO 0
#define LIBRE 1
#include "eDirector.h"

typedef struct
{
    int idPelicula;
    char titulo[TAMANIO];
    char nacionalidad[TAMANIO];
    int anio;
    int idDirector;
    int estado;

}ePelicula;
#endif // EPELICULA_H_INCLUDED

int ePelicula_init(ePelicula[],int limite);
int ePelicula_buscarPorId(ePelicula[] ,int limite, int id);
int ePelicula_siguienteId(ePelicula[] ,int limite);
int ePelicula_buscarLugarLibre(ePelicula listado[],int limite);

void ePelicula_mostrarUno(ePelicula parametro);
int ePelicula_mostrarListado(ePelicula[] ,int limite);
int ePelicula_mostrarListadoConBorrados(ePelicula[] ,int limite);

int ePelicula_alta(ePelicula[] ,int limite);
int ePelicula_baja(ePelicula[] ,int limite, int id);
int ePelicula_modificacion(ePelicula[] ,int limite, int id);
int ePelicula_cargarPelicula(ePelicula[], int);
void inicializarPeliculaHardCode(ePelicula[]);

int ePelicula_ordenar(ePelicula[] ,int limite, int orden);
