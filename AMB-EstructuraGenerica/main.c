#include <stdio.h>
#include <stdlib.h>
#include "ePelicula.h"
#include "funcionesExtras.h"
#define CANTIDAD 4


int main()
{
    int opcion;
    int opcion_2;
    int bandera = 0;

    ePelicula listadoDePeliculas[CANTIDAD];
    ePelicula_init(listadoDePeliculas, CANTIDAD);
    eDirector listadoDeDirectores[CANTIDAD];
    eDirector_init(listadoDeDirectores, CANTIDAD);
    directoresHardcodeo(listadoDeDirectores);
    peliculasHardcodeo(listadoDePeliculas);

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

            do{

            opcion_2 = subMenuOpciones();

            switch(opcion_2){
            case 1:
                ePelicula_mostrarListado(listadoDePeliculas, CANTIDAD);
                break;
            case 2:
                eDirector_mostrarListado(listadoDeDirectores, CANTIDAD);
                break;
            case 3:
                ePelicula_buscarPeliculaMasVieja(listadoDePeliculas, CANTIDAD);
                break;
            case 4:
                ePelicula_mostrarPeliculaConSuDirector(listadoDePeliculas, listadoDeDirectores, CANTIDAD);
                break;
            case 5:
                opcion_2 = 5;
            default:
                printf("Ingrese un valor valido");
                break;
            }

            }while(opcion_2 != 5);


            break;
        case 7:
            opcion = 7;
            break;
        default:
            printf("Ingrese opcion valida!");
    }

    }while(opcion != 7);

    return 0;
}
