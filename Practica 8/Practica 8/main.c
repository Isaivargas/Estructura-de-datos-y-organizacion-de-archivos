//
//  main.c
//  Practica 8 Recursividad.
//  Created by Isaí Vargas on 10/29/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
/*  Objetivo: Manejo de una lista simplemente ligada recursiva.
 Autor: CURSO ESTRUCTURA DE DATOS Y ORGANIZACION DE ARCHIVOS
 Fecha: Nov 2017
 Compilador: CB+GCC
 Version: 1.3
 */

//Bibliotecas estandar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes simbolicas
#define MAXMENU 5
#define MAXNOM 11
#define MAXJUG 10
#define NIL NULL
//Tipos de datos del usuario
struct datos
{
    short int num_jug;
    char nombre_jug[MAXNOM];
};

struct nodo_simple
{
    struct datos data;
    struct nodo_simple *next;
    struct nodo_simple *prev;
    
};


#define TAMNS sizeof(struct nodo_simple)
//Prototipos de las funciones para el manejo de datos
void pedir_datos(struct datos *destino);
void asignar_datos(struct datos *destino, struct datos origen);
void desp_datos(struct datos origen);
short int comp_datos(struct datos origen1, struct datos origen2);

//Prototipos de las funciones para el manejo de las estructuras
// Funciones de insercion
short int ins_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos origen);
short int ins_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen);
short int ins_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen);
short int ins_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen);
// Funciones para eliminar
short int eli_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos *origen);
short int eli_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos *origen);
short int eli_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen);
short int eli_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos *origen);

short int recorre_simple(struct nodo_simple *inicio);
short int recorre_simpleinversa(struct nodo_simple *fin);
short int printReverse(struct nodo_simple *inicio);
short int buscar_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos origen);

//funcion principal
int main(void)
{
    int opcion, exito,op = 0;
    struct datos destino;
    struct nodo_simple *inicio, *fin;
    inicio=NIL;
    fin=NIL;
    do
    {
       
        
        printf("\nTitulo: Lista simplemente ligada");
        printf("\n 1. Insertar ");
        printf("\n 2. Eliminar ");
        printf("\n 3. Recorrer");
        printf("\n 4. Buscar");
        printf("\n %d. Salir", MAXMENU);
        printf("\n\nElige una opcion (1-%d): ", MAXMENU);
        scanf("%d", &opcion);
        getchar();
        switch(opcion)
        {
            case 1:
                pedir_datos(&destino);
                exito=ins_ord_simple(&inicio, &fin, destino);
                switch(exito)
            {
                case -1: printf("Error en parametros1\t");
                    break;
                case -2: printf("Error en parametros2\t");
                    break;
                case -3: printf("Error en parametros3\t");
                    break;
                case 0: printf("Esta vacio\t");
                    break;
                case 1: printf("Insertado con exito \t");
                    break;
            }
                desp_datos(destino);
                break;
                
            case 2:
                pedir_datos(&destino);
                exito=eli_ord_simple(&inicio,&fin,&destino);
                switch(exito)
            {
                case -1: printf("ERROR en parametros\n");
                    break;
                case 1:case 2:case 3:printf("Datos Eliminados con exito!\n");
                    break;
            }
                
                
                break;
                
            case 3:printf("Introduce la opcion deseada para recorrer\t1 recorre simple \t2 recorre inversamente\n");
                scanf("%d",&op);
                switch (op) {
                    case 1:exito=recorre_simple(inicio);
                        break;
                    case 2:printf("NUM\t\tJUGADOR \n");
                           exito=printReverse(inicio);
                        break;
                        
                    default:printf("OPCION no valida\n");
                        break;
                }
                
                break;
                
            case 4:
                pedir_datos(&destino);
                exito=buscar_simple(&inicio,&fin,destino);
                if(exito==1){printf("Valor encontrado\n");}
                else{printf("Dato No encontrado\n");}
                
                break;
                
            case MAXMENU:
                printf("\n\nAdios.");
                break;
                
            default:
                printf("\nError: solo numeros del 1 al %d", MAXMENU);
        }
        getchar();
    }
    while(opcion!=MAXMENU);
}


short int recorre_simple(struct nodo_simple *inicio){
    struct nodo_simple *aux;
    aux=inicio;
    printf("NUM\t\tJUGADOR \n");
    while (aux != NIL)
    {
        printf("\t");
        desp_datos(aux->data);
        aux = aux->next;
        
    }
    return 1;
    
}

short int recorre_simpleinversa(struct nodo_simple *fin){
    
    struct nodo_simple *aux;
    aux=fin;
    printf("NUM\t\tJUGADOR \n");
    while (aux != NIL)
    {
        if (aux->data.num_jug==0){
            aux=aux->prev;
            desp_datos(aux->data);
        }else{
            desp_datos(aux->data);}
        aux = aux->prev;
    }
    return 1;
    
}

//funciones para el manejo de las estructuras
//funciones para el manejo de datos
void pedir_datos(struct datos *destino)
/*Solicitar datos al usuario y validarlos
 Recibe: --
 Envia los datos que dio el usuario
 */
{
    register short int i;
    do
    {
        printf("\nNumero de jugador: ");
        scanf("%hd", &(destino->num_jug));
        getchar();
    }
    while((destino->num_jug < 1) || (destino->num_jug > MAXJUG));
    //inicializar la cadena
    for(i=0; i<MAXNOM; destino->nombre_jug[i]='\0', i++);
    printf("\nNombre de jugador: ");
    gets(destino->nombre_jug);
}

short int buscar_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos origen){
    /*Recorre la estructura del nodo mientras que su valor no sea nulo y ecuentre el valor */
    struct nodo_simple *aux=*inicio;
    int band=0;
    while (aux != NULL && band !=1)
    {
        desp_datos(aux->data);
        band=1;
        aux = aux->next;
    }
    return 1;
}



void asignar_datos(struct datos *destino, struct datos origen)
/*Asignar los datos de una estructura origen a una estructura destino.
 Recibe: la estructura origen.
 Envia: la estructura destino */
{
    *destino=origen;
}




void desp_datos(struct datos origen)
/*Desplegar los datos de una estructura
 Recibe: la estructura con los datos
 Envia: ---*/
{
    
    printf("%d \t\t%s ", origen.num_jug, origen.nombre_jug);
    printf("\n");
}

short int printReverse(struct nodo_simple *inicio)
{
    // Caso Base
    if (inicio == NULL)
        return 1;
    printReverse(inicio->next);
    printf("%d /t/t %s", inicio->data.num_jug,inicio->data.nombre_jug);
    printf("\n");
    return 1;
}

short int comp_datos(struct datos origen1, struct datos origen2)
/*Comparar los datos del origen1 con origen1
 Recibe: las dos estructuras a comparar
 Envia: -1 origen1<origen2,
 0 origen1=origen2
 1 origen1>origen2
 */
{
    if(origen1.num_jug<origen2.num_jug)
        return -1;
    else if(origen1.num_jug>origen2.num_jug)
        return 1;
    else
        return(strcmp(origen1.nombre_jug, origen2.nombre_jug));
}


short int ins_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito */
{
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else
    {
        short int exito;
        if(!(*inicio))
        {
            exito=ins_ini_simple(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->data, origen) > 0)
            {
                exito=ins_ini_simple(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->data, origen) < 0)
                {
                    exito=ins_fin_simple(inicio,fin,origen);
                }
                else
                {
                    exito=ins_med_simple(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}


short int ins_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen)
/*intertar por el inicio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*inicio && comp_datos((*inicio)->data, origen) < 0)
        return -1;
    else
    {
        struct nodo_simple *nuevo;
        nuevo=(struct nodo_simple *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            asignar_datos(&(nuevo->data), origen);
            nuevo->prev=NULL;
            nuevo->next=*inicio;
            if(*inicio!=NULL)
                (*inicio)->prev=nuevo;
            *inicio=nuevo;
            if(!(*fin))
                *fin=nuevo;
            return 1;
        }
    }
}

short int ins_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen)
/*intertar por el medio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if (*fin == NIL)
        return 0;
    else if(*inicio == NIL)
        return 0;
    else if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(!(*inicio)->next)
        return -1;
    else if(comp_datos((*inicio)->data, origen) > 0)
        return -1;
    else if(comp_datos((*fin)->data, origen) < 0)
        return -1;
    else
    {
        struct nodo_simple *actual, *anterior, *nuevo;
        nuevo = (struct nodo_simple *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            actual=*inicio;
            asignar_datos(&(nuevo->data),origen);
            nuevo->next=anterior->next;
            anterior->next=nuevo;
            nuevo->prev=anterior;
            return 1;
        }
    }
}


short int ins_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if(!(*inicio) && *fin)//Validacion de existencia del nodo de  inicio.
        return -1;
    else if(!(*fin) && *inicio)//Validacion de existencia del nodo de fin.
        return -2;
    else if(*fin && comp_datos((*fin)->data, origen) > 0)
        return -3;
    else{
        // Creacion del nuevo nodo.
        struct nodo_simple *nuevo;
        nuevo=(struct nodo_simple *)malloc(TAMNS);
       
        if(!(*inicio)){
            *inicio=nuevo;
            *fin=nuevo;
            nuevo->next=NULL;
            asignar_datos(&(nuevo->data), origen);
        }else{
                      while((*fin)->next!=NULL){
                      ins_fin_simple(inicio,&(*fin)->next, origen); //Llamada Recursiva.
                      }
            if((*fin)->next==NULL){
                               asignar_datos(&(nuevo->data), origen);
                               (*fin)->next=nuevo;
                               nuevo->next=NULL;
                               nuevo->prev=*fin;
                               (*fin)=nuevo;}
        }
        return 1;
    }
}


/* Given a reference (pointer to pointer) to the head
 of a list and an int, appends a new node at the end  */

//////////////////////Funciones Eliminar////////////////////

short int eli_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos *origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a eliminar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    struct nodo_simple *aux;
    aux=*inicio;
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else
    {
        short int exito;
        if((*inicio)==*fin)
        {
            exito=eli_ini_simple(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->data,*origen) == 0 && aux->data.num_jug==origen->num_jug)
            {
                exito=eli_ini_simple(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->data, *origen )==0 && aux->data.num_jug==origen->num_jug )
                {
                    exito=eli_fin_simple(inicio,fin,origen);
                }
                else
                {
                    exito=eli_med_simple(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}





short int eli_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen){
    
    struct nodo_simple *aux=*inicio;
    
    if(*inicio != *fin){
        *inicio = (*inicio)->next;
        (*inicio)->prev=NULL;
        
        if(!aux){
            return 1;
        }
    }else { free(*inicio);
        *inicio=NULL;
        *fin=NULL;}
    return 0;
}








short int eli_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen)
{
    struct nodo_simple *aux;
    aux=(*fin);
    
    (aux)->prev=NULL;
    asignar_datos(&(aux->data),*origen);
    free(aux);
    free(fin);
    return 2;
    
}




short int eli_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen){
    struct nodo_simple *actual,*anterior;
    actual=(*inicio)->next;
    anterior=*inicio;
    
    while (actual!=NULL) {
        
        if(strcmp(actual->data.nombre_jug,origen->nombre_jug)==0 && actual->data.num_jug == origen->num_jug){
            anterior->next=anterior->next->next;
            actual->next=anterior->prev;
            asignar_datos(&(actual->data),*origen);
            free(actual);
            return 3;
        }else
            
            anterior=actual;
        actual=actual->next;
    }
    
    
    
    
    return 0;
}



