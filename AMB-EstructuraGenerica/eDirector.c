#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eDirector.h"

int eDirector_init( eDirector listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idDirector= 0;
        }
    }
    return retorno;
}

int eDirector_buscarLugarLibre(eDirector listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
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

int eDirector_buscarPorId(eDirector listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idDirector == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eDirector_siguienteId(eDirector listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idDirector>retorno)
                {
                    retorno=listado[i].idDirector;
                }

            }
        }
    }

    return retorno+1;
}

void eDirector_mostrarUno(eDirector parametro)
{
    printf("%d        %s        %d/%d%/%d         %s        \n", parametro.idDirector, parametro.nombre, parametro.fechaDeNacimiento.dia, parametro.fechaDeNacimiento.mes, parametro.fechaDeNacimiento.anio, parametro.paisDeOrigen );
}

int eDirector_mostrarListado(eDirector listado[],int limite)
{
    int retorno = -1;
    int i;

    printf("Id:     Nombre:     Fecha de Nacimiento:     Pais de origen   \n");
    for(i=0; i<limite; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            eDirector_mostrarUno(listado[i]);
        }
    }

    system("pause");
    system("cls");

    return retorno;

}

int eDirector_alta(eDirector  listado[],int limite)
{

    int retorno;

    retorno = eDirector_cargarDirector(listado, limite);

    if(retorno == 0)
    {

        printf("Carga de director satisfactoria!\n");
        system("pause");
        system("cls");

    }
    else
    {
        printf("No se pudo dar el alta de Director!\n");
        system("pause");
        system("cls");
    }

    return retorno;
}

int eDirector_cargarDirector(eDirector listado[], int limite)
{

    int indice;
    int retorno;
    int bandera = 0;
    int i;

    retorno = -1;

    indice = eDirector_buscarLugarLibre(listado, limite);

    eDirector_mostrarListado(listado, limite);

    if(indice >= 0)
    {

        printf("Ingrese nombre: ");
        fflush(stdin);
        validarCadena(gets(listado[indice].nombre));

        for(i = 0; i < limite; i++)
        {

            if(stricmp((listado[indice].nombre), listado[i].nombre) == 0)
            {

                printf("Ese nombre ya existe!\n");
                printf("Ingrese nuevamente un director\n");
                fflush(stdin);
                validarCadena(gets(listado[indice].nombre));
            }
        }
        printf("Ingrese dia de nacimiento: ");
        //validarEntero(gets(listado[indice].anio));
        scanf("%d", &listado[indice].fechaDeNacimiento.dia);
        listado[indice].fechaDeNacimiento.dia = validaRango(listado[indice].fechaDeNacimiento.dia, 31, 1);

        printf("Ingrese mes de nacimiento: ");
        //validarEntero(gets(listado[indice].anio));
        scanf("%d", &listado[indice].fechaDeNacimiento.mes);
        listado[indice].fechaDeNacimiento.mes = validaRango(listado[indice].fechaDeNacimiento.mes, 12, 1);

        printf("Ingrese anio de nacimiento: ");
        //validarEntero(gets(listado[indice].anio));
        scanf("%d", &listado[indice].fechaDeNacimiento.anio);
        listado[indice].fechaDeNacimiento.anio = validaRango(listado[indice].fechaDeNacimiento.anio, 2010, 1800);

        printf("Ingrese pais de origen: ");
        fflush(stdin);
        validarCadena(gets(listado[indice].paisDeOrigen));

        listado[indice].idDirector = eDirector_siguienteId(listado, limite);

        listado[indice].estado = OCUPADO;

        retorno = 0;

    }
    else
    {
        printf("No hay mas espacio para cargar mas directores!");
        system("pause");
    }

    return retorno;

    system("cls");


}

int eDirector_baja(eDirector listado[] ,int limite)
{

    int i;
    int idDirectorBuscada;
    int retorno;
    char decision;
    char nombre[TAMANIO];

    retorno = -1;

    eDirector_mostrarListado(listado, limite);

    printf("Ingrese nombre del  Director que desea dar de baja: ");
    fflush(stdin);
    validarCadena(gets(nombre));

    for(i = 0; i < limite; i++)
    {
             if(listado[i].estado == OCUPADO && (stricmp((listado[i].nombre), nombre) == 0))
            {
                printf("\nDirector encontrado: \n\n");
                eDirector_mostrarUno(listado[i]);
                printf("\nEsta seguro que desea dar de baja esta Director?, s/n : ");
                fflush(stdin);
                scanf("%c", &decision);

                if(decision == 's')
                {
                    listado[i].estado = LIBRE;

                    retorno = 0;
                    system("cls");
                }

            }

        }
    system("cls");

    return retorno;
}

int directoresHardcodeo(eDirector lista[])
{

    char nombres[3][100] = {"Martin Scorcese", "David Lynch", "Steven Spielberg"};
    char paises[3][50] = {"EEUU", "EEUU", "EEUU"};
    int dias [3] = {2,5,6};
    int meses[3] = {12,5, 4};
    int anios[3] = {1960, 1954, 1932};
    int id[3] = {3, 2, 6};

    int i;
    for(i = 0; i < 3; i++)
    {
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].paisDeOrigen, paises[i]);
        lista[i].fechaDeNacimiento.dia = dias[i];
        lista[i].fechaDeNacimiento.mes = meses[i];
        lista[i].fechaDeNacimiento.anio = anios[i];
        lista[i].idDirector = id[i];
        lista[i].estado = OCUPADO;
    }
    return 0;
}

/*

int eDirector_mostrarDirectorConSusPeliculas(ePelicula listado[], eDirector directores[], int limite){
int i;
    int j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(listado[i].idDirector.idDirector == directores[j].idDirector)
            {
                printf("Nombre de director: %s \n", directores[j].nombre);
                printf("Id:     Titulo:     Nacionalidad:     Anio:     Director:   \n");
                ePelicula_mostrarUno(listado[i]);

            }

        }

    }

    system("pause");
    system("cls");
}


*/



