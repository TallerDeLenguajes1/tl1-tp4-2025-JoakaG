#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} typedef tarea;

struct Nodo
{
    tarea T;
    struct Nodo *Siguiente;
} typedef nodo;

typedef nodo *lista;
lista crearNodo(lista *Lpendiente);
void cargarTareas(lista *nuevo, int ID);
void MostrarLista(lista *L);
int TareaPendienteRealizada(lista *Lpendiente, lista *LRealizado);
int longitud(lista L);
int main()
{
    lista Lpendiente = NULL;
    lista LRealizado = NULL;
    Lpendiente = crearNodo(&Lpendiente);
    TareaPendienteRealizada(&Lpendiente, &LRealizado);
    return 0;
}

lista crearNodo(lista *Lpendiente)
{
    int opcion;
    nodo *nuevo;
    int ID = 1000;
    do
    {
        puts("1. Cargar Tarea a pendientes");
        puts("2. Salir");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            nuevo = (nodo *)malloc(sizeof(nodo));
            cargarTareas(&nuevo, ID);
            nuevo->Siguiente = *Lpendiente;
            *Lpendiente = nuevo;
            ID++;
        }
    } while (opcion == 1);
    puts("------Finalizacion de la Carga-------");
    return nuevo;
}

void cargarTareas(lista *nuevo, int ID)
{
    int dur;
    char desc[100];
    puts("Ingrese duración de la tarea (cant de dias)");
    scanf("%d", &dur);
    puts("Ingrese descripción de la tarea");
    scanf("%s", desc);
    (*nuevo)->T.Descripcion = (char *)malloc((strlen(desc) + 1) * sizeof(char));
    strcpy((*nuevo)->T.Descripcion, desc);
    (*nuevo)->T.Duracion = dur;
    (*nuevo)->T.TareaID = ID;
}

int TareaPendienteRealizada(lista *Lpendiente, lista *LRealizado)
{
    if (*Lpendiente == NULL)
    {
        puts("No hay tareas pendientes a realizar");
        return 0;
    }

    int opcion = -1;
    int i;
    lista aux = *Lpendiente;
    lista aux2;
    do
    {
         i = 1;
        puts("Elija y escriba el número de tarea pendiente que fue realizada");
        MostrarLista(&aux);
        printf("\n0. Salir\n");
        scanf("%d", &opcion);
        for (int j = 1; j < opcion; j++)
        {
            aux = aux->Siguiente;
        }
        
    } while (opcion < longitud(aux));
    return 0;
}

void MostrarLista(lista *L){
    int i=1;
        
        lista aux = *L;
        while (aux != NULL)
        {
            printf("\n%d. %s", i, aux->T.Descripcion);
            aux = aux->Siguiente;
            
        }
}


   int longitud(lista L){
       if (L == NULL)
       {
           return 0;
       }
       int aux = 0;
       while (L != NULL)
       {
           aux++;
           L = (L)->Siguiente;
       }
       return aux;
   };
