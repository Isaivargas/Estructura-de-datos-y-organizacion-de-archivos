//
//  Practica #3
//  Listas ligadas.
//  Created by Isaí Vargas on 9/2/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//  Objetivo: Manejo de una lista simplemente ligada.
//  Compilador GNU GCC.
//  version 1.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXNOM     0
#define MAXPLAYERS 0


struct datos
{
    short int *num_jug[MAXPLAYERS];
    char *nombre_jug[MAXNOM];
};

//Estructura de Nodo
struct Node
{
    int data;
    struct Node *next;
};typedef struct Node Node;


//Funciones
//Funciones de insercion
int pushf(Node** head,int data);       //Insercion al inicio
int pushm(Node* lastnode,int data);   //Insercion en medio
int pushl(Node** head,int data);      //Insercion al final
//Funcion de existencia
bool searchnode(Node *head,int data,int posicion);
//Funcion Busqueda de Nodo
int getnode(Node *head,int data);
//Funcion de borrado
int popf(Node** head,int data);      //Eliminar al inicio
int popm(Node** head,int data);      //Eliminar en medio
int popl(Node** head,int data);      //Eliminar al final
//Funcion de impresion
int printList(Node *lista);


int main() {
    
    struct Node  *head = NULL;
    short int opcion,validacion;
    int data = 0,posicion=0;
    
    do {
    printf(" Teclea la opcion deseada\n 1.-Insertar dato. \n 2.-Eliminar dato. \n 3.-Impresion de lista. \n 4.-Buscar dato. \n 5.- Salir");
    scanf("%hd",&opcion);
    
    switch (opcion) {
        case 1:
             
              validacion=getnode(head,data);
              if(validacion==1){
                printf("Incersion Exitosa\n");
              }else {printf("ERROR en la insercion\n");}
            
            break;
            
        case 2:
    
            
            break;
        
        case 3:
              validacion=printList(head);
              if(validacion==1){
                 printf("Impresion Exitosa\n");
              }else {printf("ERROR\n");}
            
            break;
        
        case 4:
              searchnode(head,data,posicion);
            break;
            
        default:printf("! ERROR Opcion No valida ! \n");
            break;
    }}while(opcion<5);
    
          }//End main.

//Funcion de asignacion

int getnode(Node *head,int data){


    return 1;
}


int printList(struct Node *lista)
{
    while (lista != NULL){
        printf(" %d ", lista->data);
        lista = lista->next; }
        printf("\n");
    return 1;
}
