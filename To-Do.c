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
void MostrarPendReal(lista *L1, lista *L2);
int TareaPendienteRealizada(lista *Lpendiente, lista *LRealizado);
int longitud(lista L);
void BuscarPorId(lista *Lpendiente, lista *LRealizado);
void BuscarPorClave(lista *Lpendiente, lista *LRealizado);
void ElegirBuscador(lista *Lpendiente, lista *LRealizado);

int main()
{
    lista Lpendiente = NULL;
    lista LRealizado = NULL;
    Lpendiente = crearNodo(&Lpendiente);
    TareaPendienteRealizada(&Lpendiente, &LRealizado);
    MostrarPendReal(&Lpendiente, &LRealizado);
    ElegirBuscador(&Lpendiente, &LRealizado);
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
    getchar();
    gets(desc);
    (*nuevo)->T.Descripcion = (char *)malloc((strlen(desc) + 1) * sizeof(char));
    strcpy((*nuevo)->T.Descripcion, desc);
    (*nuevo)->T.Duracion = dur;
    (*nuevo)->T.TareaID = ID;
}

int TareaPendienteRealizada(lista *Lpendiente, lista *LRealizado)
{

    int opcion = -1;

    lista aux;
    lista anterior;
    anterior = NULL;
    do
    {
        if (*Lpendiente == NULL)
        {
            puts("No hay tareas pendientes a realizar");
            return 0;
        }
        aux = *Lpendiente;
        puts("Elija y escriba el número de tarea pendiente que fue realizada");
        MostrarLista(Lpendiente);
        printf("\n0. Salir\n");
        scanf("%d", &opcion);

        if (opcion > 0 && opcion <= longitud(*Lpendiente))
        {
            for (int i = 1; i < opcion; i++)
            {
                anterior = aux;
                aux = aux->Siguiente;
            }
            if (anterior == NULL)
            {
                *Lpendiente = aux->Siguiente;
            }
            else
            {
                anterior->Siguiente = aux->Siguiente;
            }
            aux->Siguiente = *LRealizado;
            *LRealizado = aux;
        }

    } while (opcion != 0);
    return 0;
}

void MostrarLista(lista *L)
{
    int i = 1;

    lista aux = *L;
    while (aux != NULL)
    {
        printf("%d. %s\n", i, aux->T.Descripcion);
        aux = aux->Siguiente;
        i++;
    }
}

int longitud(lista L)
{
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

void MostrarPendReal(lista *L1, lista *L2)
{
    puts("\n------Tareas pendientes-----");
    MostrarLista(L1);
    puts("\n------Tareas Realizadas-----");
    MostrarLista(L2);
}

void BuscarPorId(lista *Lpendiente, lista *LRealizado)
{
    int buscar, encontrado = 0, encontrado2 = 0;

    puts("Ingresar ID a buscar");
    scanf("%d", &buscar);
    lista aux = *Lpendiente;

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            if (aux->T.TareaID == buscar)
            {
                encontrado = 1;
                printf("----Elemento encontrado----\n ID: %d\n Descripción: %s\n Duración: %d\n Estado: Pendiente\n", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
                break;
            }
            aux = aux->Siguiente;
        }
    }

    aux = *LRealizado;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            if (aux->T.TareaID == buscar)
            {
                encontrado = 1;
                printf("----Elemento encontrado----\n ID: %d\n Descripción: %s\n Duración: %d\n Estado: Realizado\n", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
                break;
            }
            aux = aux->Siguiente;
        }
    }
    if (!encontrado)
    {
        printf("\n--Elemento NO ENCONTRADO--\n");
    }
}

void BuscarPorClave(lista *Lpendiente, lista *LRealizado)
{
    int encontrado = 0, encontrado2 = 0;
    char buscar[50];
    puts("\nIngresar Palabra clave a buscar");
    scanf("%s", buscar);
    lista aux = *Lpendiente;

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            if (strstr(aux->T.Descripcion, buscar) != NULL)
            {
                encontrado = 1;
                printf("----Elemento encontrado----\n ID: %d\n Descripción: %s\n Duración: %d\n Estado: Pendiente\n", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
                break;
            }
            aux = aux->Siguiente;
        }
    }

    aux = *LRealizado;
    if (aux != NULL)
    {
        while (aux != NULL)
        {
            if (strstr(aux->T.Descripcion, buscar) != NULL)
            {
                encontrado = 1;
                printf("----Elemento encontrado----\n ID: %d\n Descripción: %s\n Duración: %d\n Estado: Realizado\n", aux->T.TareaID, aux->T.Descripcion, aux->T.Duracion);
                break;
            }
            aux = aux->Siguiente;
        }
    }
    if (!encontrado)
    {
        printf("\n--Elemento NO ENCONTRADO--\n");
    }
}

void ElegirBuscador(lista *Lpendiente, lista *LRealizado)
{
    int opcion;
    do
    {
        puts("Elegir como buscar elemento");
        puts("1. Por ID (identificador Único)");
        puts("2. Por Palabra Clave");
        puts("3. Salir buscador");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            BuscarPorId(Lpendiente, LRealizado);
        }
        else if (opcion == 2)
        {
            BuscarPorClave(Lpendiente, LRealizado);
        }
        else
        {
            puts("Cerrando buscador...");
        }
    } while (opcion < 3);
}