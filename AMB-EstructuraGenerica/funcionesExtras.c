#include "funcionesExtras.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int menuOpciones(){

    int opcion;

    printf("/--- Menu de opciones ---/\n");
    printf("1. Altas peliculas\n");
    printf("2. Modificar datos de una pelicula\n");
    printf("3. Baja de una pelicula\n");
    printf("4. Nuevo director\n");
    printf("5. Eliminar director\n");
    printf("6. Listar\n");
    printf("7. Salir\n");

    opcion = getInt("Ingrese opcion: \n");

    system("cls"); //limpio la pantalla despues de seleccionar opcion cada opcion

    return opcion;

}

int getInt(char texto[]){

    int numero;

    printf("%s", texto);
    scanf("%d", &numero);

    return numero;

}


int validarCadena(char listado[]){

    int retorno;

    retorno = -1;

    int i;
    for(i = 0; i < strlen(listado); i++){
        if(isdigit(listado[i])){
            retorno = 0;
    }

    return retorno;

}

}
