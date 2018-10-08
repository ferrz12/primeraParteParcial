#include "funcionesExtras.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int menuOpciones()
{

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

int getInt(char texto[])
{

    int numero;

    printf("%s", texto);
    scanf("%d", &numero);

    return numero;

}


int validarCadena(char listado[])
{

    int retorno;

    retorno = -1;

    int i;
    for(i = 0; i < strlen(listado); i++)
    {
        if(isdigit(listado[i]) || strlen(listado) >= 50)
        {
            retorno = 0;
            while(retorno == 0)
            {
                printf("Error, esta ingresando numeros o el nombre es muy largo, reingrese el dato por favor\n");
                fflush(stdin);
                if(isdigit(gets(listado)) || strlen(listado) >= 50)
                {
                    retorno = 0;
                }
                else
                {
                    retorno = 2;
                }
            }
        }
    }

}

int validaRango(int numero, int max, int min)
{
    while(numero < min || numero > max)
    {
        printf("Fuera de rango. Ingrese nuevamente: ");
        scanf("%d", &numero);
    }

    return numero;
}

int subMenuOpciones()
{

    int opcion;

    printf("/--- Menu de opciones ---/\n");
    printf("1. Listar peliculas\n");
    printf("2. Listar director\n");
    printf("3. Listar las mas viejas\n");
    printf("4. Listar cada pelicula con su director\n");
    printf("5. Salir\n");

    opcion = getInt("Ingrese opcion: \n");

    system("cls"); //limpio la pantalla despues de seleccionar opcion cada opcion

    return opcion;
}

/*

int validarEntero(char numero[]){

    int retorno;

    int i;
    for(i = 0; i < strlen(numero); i++){
        if(!isdigit(numero[i])){
            retorno = 0;
            while(retorno == 0){
                printf("Error, esta ingresando letras, reingrese el dato por favor\n");
                fflush(stdin);
                if(!isdigit(gets(numero))){
                   retorno = 0;
                }else{
                    retorno = 2;
                }
            }
        }
}

}

*/



