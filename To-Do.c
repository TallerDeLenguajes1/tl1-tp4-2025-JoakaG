#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef tarea;


struct Nodo{
tarea T;
nodo *Siguiente;
}typedef nodo;

typedef nodo *lista;

int main(){
lista LP = NULL;
lista LR = NULL;


    return 0;
}