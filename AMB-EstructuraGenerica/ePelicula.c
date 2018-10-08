#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePelicula.h"
#include "funcionesExtras.h"

int ePelicula_init( ePelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idPelicula= 0;
        }
    }
    return retorno;
}

int ePelicula_buscarLugarLibre(ePelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePelicula_siguienteId(ePelicula listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idPelicula>retorno)
                    {
                         retorno=listado[i].idPelicula;
                    }

            }
        }
    }

    return retorno+1;
}


int ePelicula_buscarPorId(ePelicula listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idPelicula == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



void ePelicula_mostrarUno(ePelicula unaPelicula)
{
     printf("Id:     Titulo:     Nacionalidad:     Anio:     Director:   \n");
     printf("%d        %s              %s       %d         %d   \n", unaPelicula.idPelicula, unaPelicula.titulo, unaPelicula.nacionalidad, unaPelicula.anio, unaPelicula.idDirector);
}

int ePelicula_mostrarListado(ePelicula listado[],int limite)
{
    int retorno = -1;
    int i;

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {

                ePelicula_mostrarUno(listado[i]);
            }
        }

    system("pause");
    system("cls");

    return retorno;

}


int ePelicula_mostrarListadoConBorrados(ePelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            ePelicula_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int ePelicula_alta(ePelicula  listado[],int limite)
{

    int retorno;

    retorno = ePelicula_cargarPelicula(listado, limite);

    if(retorno == 0){

        printf("Carga de pelicula satisfactoria!\n");
        system("pause");
        system("cls");

    }else{
        printf("No se pudo dar el alta de pelicula!\n");
        system("pause");
        system("cls");
    }

    return retorno;
}

int ePelicula_cargarPelicula(ePelicula listado[], int limite){

    int indice;
    int retorno;


    retorno = -1;

    indice = ePelicula_buscarLugarLibre(listado, limite);

    if(indice >= 0){

      listado[indice].idPelicula = ePelicula_siguienteId(listado, limite);

      printf("Ingrese titulo: ");
      fflush(stdin);
      validarCadena(gets(listado[indice].titulo));

      printf("Ingrese anio: ");
      //validarEntero(gets(listado[indice].anio));
      scanf("%d", &listado[indice].anio);
      listado[indice].anio = validaRango(listado[indice].anio, 2018, 1900);


      printf("Ingrese nacionalidad: ");
      fflush(stdin);
      validarCadena(gets(listado[indice].nacionalidad));

      listado[indice].estado = OCUPADO;

      retorno = 0;

      system("cls");

    }else{
        printf("No se pueden cargar mas peliculas!\n");
        system("pause");
    }

    return retorno;

    system("cls");

}



int ePelicula_baja(ePelicula listado[] ,int limite){

    int i;
    int idPeliculaBuscada;
    int retorno;
    char decision;


    retorno = -1;

    printf("Ingrese identificador de la pelicula que desea dar de baja: ");
    scanf("%d", &idPeliculaBuscada);

    while(idPeliculaBuscada == 0){
        printf("No existe el identificador 0, por favor reingrese el identificador: ");
        scanf("%d", &idPeliculaBuscada);
    }

    for(i = 0; i < limite; i++){
        if(listado[i].estado == OCUPADO && listado[i].idPelicula == idPeliculaBuscada){
            printf("\nPelicula encontrada: \n\n");
            ePelicula_mostrarUno(listado[i]);
            printf("\nEsta seguro que desea dar de baja esta pelicula?, s/n : ");
            fflush(stdin);
            scanf("%c", &decision);

            if(decision == 's'){
                listado[i].estado = LIBRE;
                retorno = 0;
                system("cls");
            }

        }
    }

    system("cls");

    return retorno;
}

int ePelicula_modificacion(ePelicula listado[] ,int limite){

    int idPeliculaBuscada;
    int opcion;
    int i;
    int retorno;

    printf("Ingrese identificador de la pelicula que desea dar de baja: ");
    scanf("%d", &idPeliculaBuscada);

    while(idPeliculaBuscada == 0){
        printf("No existe el identificador 0, por favor reingrese el identificador: ");
        scanf("%d", &idPeliculaBuscada);
    }

    for(i = 0; i < limite; i++){
        if(listado[i].idPelicula == idPeliculaBuscada){
            printf("\nPelicula encontrada: \n\n");
            ePelicula_mostrarUno(listado[i]);
            printf("\nQue desea modificar?\n\n");
            printf("1. Titulo\n");
            printf("2. Anio\n");
            printf("3. Nacionalidad\n");
            printf("4. Director\n\n");
            printf("Ingrese opcion: ");
            scanf("%d", &opcion);

            switch(opcion){
                case 1:
                    printf("Ingrese titulo nuevo: ");
                    fflush(stdin);
                    validarCadena(gets(listado[i].titulo));
                    system("cls");
                    printf("Titulo cambiado satisfactoriamente!\n");
                    system("pause");
                    break;
                case 2:
                    printf("Ingrese anio: ");
                    scanf("%d", &listado[i].anio);
                    listado[i].anio = validaRango(listado[i].anio, 2018, 1900);
                    system("cls");
                    printf("Anio cambiado satisfactoriamente!\n");
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese nacionalidad nueva: ");
                    fflush(stdin);
                    validarCadena(gets(listado[i].nacionalidad));
                    system("cls");
                    printf("Nacionalidad cambiada satisfactoriamente!\n");
                    system("pause");
                    break;
                case 4:
                default:
                    printf("Ingrese un valor de 1 a 4 por favor");
                    break;
            }
        }
    }

}



