#include <stdio.h>
#include <stdlib.h>
#include "ePelicula.h"
#include "funcionesExtras.h"
#define CANTIDAD 2

int main()
{
    int opcion;

    ePelicula listadoDePeliculas[CANTIDAD];
    ePelicula_init(listadoDePeliculas, CANTIDAD);
    inicializarPeliculaHardCode(listadoDePeliculas);

    do{

    opcion = menuOpciones();

    switch(opcion){
        case 1:
            ePelicula_alta(listadoDePeliculas, CANTIDAD);
            break;
        case 2:
            ePelicula_modificacion(listadoDePeliculas, CANTIDAD);
            break;
        case 3:
            ePelicula_baja(listadoDePeliculas, CANTIDAD);
            break;
        case 4:
        case 5:
        case 6:
            ePelicula_mostrarListado(listadoDePeliculas, CANTIDAD);
        case 7:
            opcion = 7;
        default:
            printf("Ingrese opcion valida!");
            break;
    }


    }while(opcion != 7);

    return 0;
}
