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
int TareaPendienteRealizada(lista Lpendiente);

int main()
{
    lista Lpendiente = NULL;
    lista LRealizado = NULL;
    Lpendiente = crearNodo(&Lpendiente);
    TareaPendienteRealizada(Lpendiente);
    return 0;
}

lista crearNodo(lista *Lpendiente)
{
    int opcion;
    lista nuevo = NULL;
    int ID = 1000;
    do
    {
        puts("1. Cargar Tarea a pendientes");
        puts("2. Salir");
        scanf("%d", &opcion);
        nuevo = (lista *)malloc(sizeof(lista *));
        lista aux;
        if (opcion == 1)
        {
            if (Lpendiente == NULL)
            {
                cargarTareas(&nuevo, ID);
                nuevo->Siguiente = NULL;
            }else{
                aux = nuevo->Siguiente;
                Lpendiente = aux;
                nuevo->Siguiente = NULL;
                cargarTareas(&nuevo, ID);
            }
            
           
            nuevo->Siguiente = NULL;
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
    scanf("%s", &desc);
    (*nuevo)->T.Descripcion = (char *)malloc((strlen(desc) + 1) * sizeof(char));
    strcpy((*nuevo)->T.Descripcion, desc);
    (*nuevo)->T.Duracion = dur;
    (*nuevo)->T.TareaID;
}

//  int longitud(lista L){
//      if (L == NULL)
//      {
//          return 0;
//      }
//      int aux = 0;
//      while (L != NULL)
//      {
//          aux++;
//          L = L->Siguiente;
//      }
//      return aux;
//  };

int TareaPendienteRealizada(lista Lpendiente)
{
    if (Lpendiente == NULL)
    {
        puts("No hay tareas pendientes a realizar");
        return 0;
    }

    int opcion;
    lista aux = Lpendiente;
    while (opcion != 0)
    {
        int i = 1;
        puts("Porfavor, elija y escriba el número de tarea pendiente que fue realizada");
        while (aux != NULL)
        {
            printf("%d. %s", i, aux->T.Descripcion);
            i++;
            aux = aux->Siguiente;
        }
        printf("0. Salir");
        scanf("%d", &opcion);
    }
    return 0;
}