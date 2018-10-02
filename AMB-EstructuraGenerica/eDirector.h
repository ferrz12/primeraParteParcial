#ifndef EDIRECTOR_H_INCLUDED
#define EDIRECTOR_H_INCLUDED
#define TAMANIO 50
#define OCUPADO 0
#define LIBRE 1
#include "efecha.h"

typedef struct
{
    int idDirector;
    char nombre[TAMANIO];
    eFecha fechaDeNacimiento;
    char paisDeOrigen[TAMANIO];
    int estado;

}eDirector;
#endif // EDIRECTOR_H_INCLUDED
