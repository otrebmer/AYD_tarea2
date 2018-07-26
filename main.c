#include <stdio.h>
#include <stdlib.h>
/***
UNIVERSIDAD DE SAN CARLOS DE GUATEMALA
FACULTAD DE INGENIERIA
ESCUELA DE CIENCIAS Y SISTEMAS

JOSE MOREJON
24/07/2018
***/

//Se define un nombre alternativo al tipo de dato int
typedef int Item;
//Aqui el tipo de dato es struct nodo, donde Nodo es el alias
typedef struct nodo
{
    Item dato;
    struct nodo* siguiente;
}Nodo;

Nodo* crearNodo(Item d);
void insertar(Nodo** primero,Item d);
void imprimir(Nodo* p);
void eliminar(Nodo **p);
/**********************************************************
*****************Tarea Practica 1**************************
**********************************************************/
/***
    Implementar la eliminacion de un nodo
    por Item
    Ejemplo
    Lista inicial
    1->2->3->4
    Eliminar el 3 con este metodo.
    Resultado de lista
    1->2->4
***/
void eliminarItem(Nodo **p, Item d);

/***
    Implementar de forma recursiva
**/
//Recordar que para este metodo solo necesitamos recorrerlo
//no modificar el valor del parametro

void imprimirR(Nodo ***p);


int main()
{

    Nodo* primero =  NULL;
    int n =10;

    while(n>0){
    insertar(&primero,n);
    n=n-1;
    }
    imprimir(primero);
    eliminar(&primero);
    printf("\n\n");
    imprimir(primero);
    return 0;
}
/***
Pasos de insercion
1. Crear Nodo con el dato Item d, que llamaremos nuevo
2. Al nodo nuevo apunta a la variable primero
3. Al nodo primero se le asigna el nodo nuevo
***/
void insertar(Nodo** primero,Item d){
    Nodo* nuevo = crearNodo(d);
    nuevo->siguiente = *primero;
    *primero=nuevo;
}
/***
    Se crea el espacio en memoria del tipo struct nodo, con el alias Nodo.
    Se debe de guardar el dato Item en el nodo.
    El apuntador se debe de asignar NULL
***/
Nodo* crearNodo(Item d){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente=NULL;
    return nuevo;
}
/***
    Eliminacion al inicio de la lista
    Para eliminar un nodo, se debe de verificar
    1. Si el nodo no es igual a NULL
    2. si no es NULL, el nodo p es igual al nodo p siguiente
    Si en una lista se tiene
    1->2->3->4
    se llama al metodo, pasando como parametro el puntero
    que contiene al dato "1"
    la lista queda de la siguiente forma
    2->3->4
***/
void eliminar(Nodo ** p){

    if(*p!=NULL) *p = (*p)->siguiente;


}
/***
Para imprimir el contenido de los nodos
1. Se debe crear una copia del nodo que entra como
    parametro, que es el nodo p.
2. Se debe entrar en un bucle hasta que el nodo
    siguiente sea igual a NULL
3. Antes de asignar el nodo copia el siguiente,
    se debe de imprimir su contenido
***/
void imprimir(Nodo*p){
    Nodo* aux = p;
    while (aux != NULL){
        printf("dato %d\n",aux->dato);
        aux= aux->siguiente;
    }
}


