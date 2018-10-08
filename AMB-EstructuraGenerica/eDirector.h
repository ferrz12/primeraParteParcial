#ifndef EDIRECTOR_H_INCLUDED
#define EDIRECTOR_H_INCLUDED
#define TAMANIO 50
#define OCUPADO 0
#define LIBRE 1

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;


typedef struct
{
    int idDirector;
    char nombre[TAMANIO];
    eFecha fechaDeNacimiento;
    char paisDeOrigen[TAMANIO];
    int estado;

} eDirector;


#endif // EDIRECTOR_H_INCLUDED

int eDirector_init(eDirector[],int limite);
int eDirector_buscarPorId(eDirector[],int limite, int id);
int eDirector_siguienteId(eDirector[],int limite);
int eDirector_buscarLugarLibre(eDirector listado[],int limite);

void eDirector_mostrarUno(eDirector parametro);
int eDirector_mostrarListado(eDirector[],int limite);
int eDirector_mostrarListadoConBorrados(eDirector[],int limite);

int eDirector_alta(eDirector[],int limite);
int eDirector_baja(eDirector[], int limite);
int eDirector_modificacion(eDirector[],int limite);
int eDirector_cargarDirector(eDirector[], int);

int eDirector_ordenar(eDirector[],int limite, int orden);
int directoresHardcodeo(eDirector[]);
//int eDirector_mostrarDirectorConSusPeliculas(ePelicula[], eDirector[], int);
