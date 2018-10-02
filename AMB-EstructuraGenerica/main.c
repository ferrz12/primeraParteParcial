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
            ePelicula_mostrarListado(listadoDePeliculas, CANTIDAD);
            break;
        case 3:
            opcion = 3;
            break;
        default:
            printf("Ingrese opcion valida!");
            break;
    }


    }while(opcion != 3);

    return 0;
}
