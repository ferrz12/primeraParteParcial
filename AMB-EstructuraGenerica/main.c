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
    eDirector listadoDeDirectores[CANTIDAD];
    eDirector_init(listadoDeDirectores, CANTIDAD);

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
            eDirector_alta(listadoDeDirectores, CANTIDAD);
            break;
        case 5:
            eDirector_baja(listadoDeDirectores, CANTIDAD);
            break;
        case 6:
            ePelicula_mostrarListado(listadoDePeliculas, CANTIDAD);
            eDirector_mostrarListado(listadoDeDirectores, CANTIDAD);
            break;
        case 7:
            opcion = 7;
        default:
            printf("Ingrese opcion valida!");
            break;
    }


    }while(opcion != 7);

    return 0;
}
