#include "funcionesExtras.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int menuOpciones(){

    int opcion;

    printf("/--- Menu de opciones ---/\n");
    printf("1. Dar de alta una pelicula\n");
    printf("2. Listar\n");
    printf("3. Salir\n");

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

int validarEntero(char numero[]){

    int retorno;
    int i;

    retorno = -1;

    for (i = 0; i < strlen(numero); i++)
    {
        if(!isdigit(numero[i]) ) {
            retorno = 0;
            break;
        }
    }
}

}
