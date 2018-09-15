
//  main.c
//  airlaines
//
//  Created by Isaí Vargas on 10/5/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//

/*  Objetivo: Manejo de una lista simplemente ligada
 Autor: CURSO ESTRUCTURA DE DATOS Y ORGANIZACION DE ARCHIVOS
 Fecha: SEP 2017
 Compilador: CB+GCC
 Version: 1.0
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

struct datos2{  //PASAJEROS
    int edad;
    int numasiento;
    char nombrepasajero[MAXNOM];
};

struct datos   //AEROLINEA
{
    short int numvuelo;
    char destino[MAXNOM];
    char aerolinea[MAXNOM];
};

struct nodo_pasajeros
{
    struct datos2 datapasajeros;
    struct nodo_pasajeros *next;
    struct nodo_pasajeros *prev;
    
};

struct nodo_vuelos
{
    struct datos datavuelos;
    struct nodo_vuelos *next;
    struct nodo_vuelos *prev;
    struct nodo_pasajeros ndpassanger;
    struct nodo_vuelos *primerpasajero;
    struct nodo_vuelos *ultimopasajero;
};


#define TAMNS sizeof(struct nodo_vuelos)
//Prototipos de las funciones para el manejo de datos
void pedir_datos(struct datos *destino);
void asignar_datos(struct datos *destino, struct datos origen);
void desp_datos(struct datos origen,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero);
short int comp_datos(struct datos origen1, struct datos origen2);

//Prototipos de las funciones para el manejo de las estructuras
short int ins_ord_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin ,struct datos origen);
short int ins_ini_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin ,struct datos origen);
short int ins_med_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos origen);
short int ins_fin_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos origen);

short int eli_ord_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin ,struct datos *origen);
short int eli_ini_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin,struct datos *origen);
short int eli_med_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos *origen);
short int eli_fin_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin,struct datos *origen);

short int recorre_vuelo(struct nodo_vuelos *inicio,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero);
short int recorre_vueloinversa(struct nodo_vuelos *fin,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero);
short int buscar_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin,struct datos origen,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero);


////////////////////////////////////////////////////////////////////////Funcione PASAJEROS//////////////////////////////////////////////////////////////////////////////////////////////////

void pedir_datospasajeros(struct datos2 *destino);
void asignar_pasajero(struct datos2 *destino, struct datos2 origen);
void desp_datopasajero(struct datos2 origen);
short int comp_datospasajero(struct datos2 origen1, struct datos2 origen2);

short int ins_ord_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin ,struct datos2 origen);
short int ins_ini_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin ,struct datos2 origen);
short int ins_med_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 origen);
short int ins_fin_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 origen);

short int eli_ord_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin ,struct datos2 *origen);
short int eli_ini_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin,struct datos2 *origen);
short int eli_med_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 *origen);
short int eli_fin_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin,struct datos2 *origen);


short int recorre_pasajero(struct nodo_pasajeros *inicio);
short int recorre_pasajeroinversa(struct nodo_pasajeros *fin);
short int buscar_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin,struct datos2 origen);


//funcion principal
int main(void)
{
    int opcion, exito,op = 0;
    struct datos destino;
    struct nodo_vuelos *inicio, *fin;
    struct nodo_vuelos *primerpasajero ;
    struct nodo_vuelos *ultimopasajero ;
    
    inicio=NIL;
    fin=NIL;
    do
    {
        system("cls");
        system("COLOR 4B");
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
                exito=ins_ord_vuelo(&inicio, &fin, destino);
                switch(exito)
            {
                case -1: printf("Error en parametros");
                    break;
                case 0: printf("Esta vacio");
                    break;
                case 1: printf("Insertado con exito");
                    break;
            }
                desp_datos(destino,&primerpasajero,&ultimopasajero);
                break;
                
            case 2:
                pedir_datos(&destino);
                exito=eli_ord_vuelo(&inicio,&fin,&destino);
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
                    case 1:exito=recorre_vuelo(inicio,&primerpasajero,&ultimopasajero);
                        break;
                    case 2:exito=recorre_vueloinversa(fin,&primerpasajero,&ultimopasajero);
                        break;
                        
                    default:printf("OPCION no valida\n");
                        break;
                }
                
                break;
                
            case 4:
                pedir_datos(&destino);
                exito=buscar_vuelo(&inicio,&fin,destino,&primerpasajero,&ultimopasajero);
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


short int recorre_vuelo(struct nodo_vuelos *inicio,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero){
    struct nodo_vuelos *aux;
    aux=inicio;
    printf("NUM VUELO\t\t\tDESTINO\t\t\t AEROLINEA");
    while (aux != NIL)
    {
        desp_datos(aux->datavuelos,primerpasajero,ultimopasajero);
        aux = aux->next;
        
    }
    return 1;
    
}

short int recorre_vueloinversa(struct nodo_vuelos *fin,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero){
    
    struct nodo_vuelos *aux;
    aux=fin;
    printf("NUM VUELO\t\t\tDESTINO\t\t\t AEROLINEA");
    while (aux != NIL)
    {
        if (aux->datavuelos.numvuelo==0){
            aux=aux->prev;
            desp_datos(aux->datavuelos,primerpasajero,ultimopasajero);
        }else{
            desp_datos(aux->datavuelos,primerpasajero,ultimopasajero);}
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
   
        printf("\nNumero de vuelo: ");
        scanf("%hd", &(destino->numvuelo));
        getchar();
    for(i=0; i<MAXNOM; destino->destino[i]='\0', i++);
    printf("\nDestino: ");
    gets(destino->destino);
    //inicializar la cadena
    for(i=0; i<MAXNOM; destino->aerolinea[i]='\0', i++);
    printf("\nNombre de Aerolinea: ");
    gets(destino->aerolinea);
}

short int buscar_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin,struct datos origen,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero){
    /*Recorre la estructura del nodo mientras que su valor no sea nulo y ecuentre el valor */
    struct nodo_vuelos *aux=*inicio;
    int band=0;
    while (aux != NULL && band !=1)
    {
        desp_datos(aux->datavuelos,primerpasajero,ultimopasajero);
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




void desp_datos(struct datos origen,struct nodo_vuelos **primerpasajero,struct nodo_vuelos **ultimopasajero)
/*Desplegar los datos de una estructura
 Recibe: la estructura con los datos
 Envia: ---*/
{
    
    printf("\t\t\t\t %d\t\t\t\t%s\t\t\t%s\n", origen.numvuelo,origen.destino,origen.aerolinea);
    if((primerpasajero==NULL && ultimopasajero==NULL)){
        printf("El vuelo esta vacio");
    }
    printf("\n");
}


short int comp_datos(struct datos origen1, struct datos origen2)
/*Comparar los datos del origen1 con origen1
 Recibe: las dos estructuras a comparar
 Envia: -1 origen1<origen2,
 0 origen1=origen2
 1 origen1>origen2
 */
{
    if(origen1.numvuelo<origen2.numvuelo)
        return -1;
    else if(origen1.numvuelo>origen2.numvuelo)
        return 1;
    else
        return(strcmp(origen1.aerolinea, origen2.aerolinea));
}



short int ins_ord_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin ,struct datos origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
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
            exito=ins_ini_vuelo(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->datavuelos, origen) > 0)
            {
                exito=ins_ini_vuelo(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->datavuelos, origen) < 0)
                {
                    exito=ins_fin_vuelo(inicio,fin,origen);
                }
                else
                {
                    exito=ins_med_vuelo(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}

short int ins_ini_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos origen)
/*intertar por el inicio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*inicio && comp_datos((*inicio)->datavuelos, origen) < 0)
        return -1;
    else
    {
        struct nodo_vuelos *nuevo;
        nuevo=(struct nodo_vuelos *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            asignar_datos(&(nuevo->datavuelos), origen);
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

short int ins_med_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos origen)
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
    else if(comp_datos((*inicio)->datavuelos, origen) > 0)
        return -1;
    else if(comp_datos((*fin)->datavuelos, origen) < 0)
        return -1;
    else
    {
        struct nodo_vuelos *actual, *anterior, *nuevo;
        nuevo = (struct nodo_vuelos *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            actual=*inicio;
            asignar_datos(&(nuevo->datavuelos),origen);
            nuevo->next=anterior->next;
            anterior->next=nuevo;
            nuevo->prev=anterior;
            return 1;
        }
    }
}

short int ins_fin_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*fin && comp_datos((*fin)->datavuelos, origen) > 0)
        return -1;
    else
    {
        struct nodo_vuelos *nuevo;
        nuevo=(struct nodo_vuelos *)malloc(TAMNS);
        
        if(!(*inicio))
        {
            nuevo->prev=NIL;
            *inicio=nuevo;
        }
        else{
            
            asignar_datos(&(nuevo->datavuelos), origen);
            nuevo->next=NIL;
            while((*fin)->next!=NIL)
            {
                (*fin)=(*fin)->next;
            }
            (*fin)->next=nuevo;
            nuevo->prev=*fin;
            
            (*fin)=nuevo;
            
            
        }
        return 1;
        
    }
}
//////////////////////Funciones Eliminar////////////////////

short int eli_ord_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin ,struct datos *origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a eliminar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    struct nodo_vuelos *aux;
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
            exito=eli_ini_vuelo(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->datavuelos,*origen) == 0 && aux->datavuelos.numvuelo==origen->numvuelo)
            {
                exito=eli_ini_vuelo(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->datavuelos, *origen )==0 && aux->datavuelos.numvuelo==origen->numvuelo )
                {
                    exito=eli_fin_vuelo(inicio,fin,origen);
                }
                else
                {
                    exito=eli_med_vuelo(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}





short int eli_ini_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos *origen){
    
    struct nodo_vuelos *aux=*inicio;
    
    if(*inicio != *fin){
        *inicio = (*inicio)->next;
        (*inicio)->prev=NULL;
        
        if(!aux){
            return 1;
        }
    }else { free(*inicio);
        *inicio=NULL;
        free(*fin);
        *fin=NULL;}
    return 0;
}








short int eli_fin_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos *origen)
{
    struct nodo_vuelos *aux;
    aux=(*fin);
    
    (aux)->prev=NULL;
    asignar_datos(&(aux->datavuelos),*origen);
    free(aux);
    free(fin);
    return 2;
    
}




short int eli_med_vuelo(struct nodo_vuelos **inicio, struct nodo_vuelos **fin, struct datos *origen){
    struct nodo_vuelos *actual,*anterior;
    actual=(*inicio)->next;
    anterior=*inicio;
    
    while (actual!=NULL) {
        
        if(strcmp(actual->datavuelos.aerolinea,origen->aerolinea)==0 && actual->datavuelos.numvuelo == origen->numvuelo){
            anterior->next=anterior->next->next;
            actual->next=anterior->prev;
            asignar_datos(&(actual->datavuelos),*origen);
            free(actual);
            return 3;
        }else
            
            anterior=actual;
        actual=actual->next;
    }
    
    
    
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
short int recorre_pasajero(struct nodo_pasajeros *inicio){
    struct nodo_pasajeros
    
    *aux;
    aux=inicio;
    printf("NUM\t\tJUGADOR \n");
    while (aux != NIL)
    {
        desp_datopasajero(aux->datapasajeros);
        aux = aux->next;
        
    }
    return 1;
    
}

short int recorre_pasajeroinversa(struct nodo_pasajeros *fin){
    
    struct nodo_pasajeros *aux;
    aux=fin;
    printf("NUM\t\tJUGADOR \n");
    while (aux != NIL)
    {
        if (aux->datapasajeros.numasiento==0){
            aux=aux->prev;
            desp_datopasajero(aux->datapasajeros);
        }else{
            desp_datopasajero(aux->datapasajeros);}
        aux = aux->prev;
    }
    return 1;
    
}

//funciones para el manejo de las estructuras
//funciones para el manejo de datos


void pedir_datospasajeros(struct datos2 *destino)
/*Solicitar datos al usuario y validarlos
 Recibe: --
 Envia los datos que dio el usuario
 */
{
    register short int i;
    
    printf("\nEdad: ");
    scanf("%d", &(destino->edad));
    getchar();
    printf("\nDestini: ");
    scanf("%d", &(destino->numasiento));
    getchar();
    //inicializar la cadena
    for(i=0; i<MAXNOM; destino->nombrepasajero[i]='\0', i++);
    printf("\nNombre de jugador: ");
    gets(destino->nombrepasajero);
}

short int buscar_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin,struct datos2 origen){
    /*Recorre la estructura del nodo mientras que su valor no sea nulo y ecuentre el valor */
    struct nodo_pasajeros *aux=*inicio;
    int band=0;
    while (aux != NULL && band !=1)
    {
        desp_datopasajero(aux->datapasajeros);
        band=1;
        aux = aux->next;
    }
    return 1;
}



void asignar_pasajero(struct datos2 *destino, struct datos2 origen)
/*Asignar los datos de una estructura origen a una estructura destino.
 Recibe: la estructura origen.
 Envia: la estructura destino */
{
    *destino=origen;
}




void desp_datopasajero(struct datos2 origen)
/*Desplegar los datos de una estructura
 Recibe: la estructura con los datos
 Envia: ---*/
{
    
    printf("%d \t\t %d \t\t %s ", origen.edad,origen.numasiento,origen.nombrepasajero);
    printf("\n");
}


short int comp_datospasajero(struct datos2 origen1, struct datos2 origen2)
/*Comparar los datos del origen1 con origen1
 Recibe: las dos estructuras a comparar
 Envia: -1 origen1<origen2,
 0 origen1=origen2
 1 origen1>origen2
 */
{
    if(origen1.numasiento<origen2.numasiento)
        return -1;
    else if(origen1.numasiento>origen2.numasiento)
        return 1;
    else
        return(strcmp(origen1.nombrepasajero, origen2.nombrepasajero));
}



short int ins_ord_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin ,struct datos2 origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
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
            exito=ins_ini_pasajero(inicio,fin,origen);
        }
        else
        {
            if(comp_datospasajero((*inicio)->datapasajeros, origen) > 0)
            {
                exito=ins_ini_pasajero(inicio,fin,origen);
            }
            else
            {
                if(comp_datospasajero((*fin)->datapasajeros, origen) < 0)
                {
                    exito=ins_fin_pasajero(inicio,fin,origen);
                }
                else
                {
                    exito=ins_med_pasajero(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}

short int ins_ini_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 origen)
/*intertar por el inicio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*inicio && comp_datospasajero((*inicio)->datapasajeros, origen) < 0)
        return -1;
    else
    {
        struct nodo_pasajeros *nuevo;
        nuevo=(struct nodo_pasajeros *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            
            asignar_pasajero(&(nuevo->datapasajeros),origen);
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

short int ins_med_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 origen)
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
    else if(comp_datospasajero((*inicio)->datapasajeros, origen) > 0)
        return -1;
    else if(comp_datospasajero((*fin)->datapasajeros, origen) < 0)
        return -1;
    else
    {
        struct nodo_pasajeros *actual, *anterior, *nuevo;
        nuevo = (struct nodo_pasajeros *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            actual=*inicio;
            asignar_pasajero(&(nuevo->datapasajeros),origen);
            
            nuevo->next=anterior->next;
            anterior->next=nuevo;
            nuevo->prev=anterior;
            return 1;
        }
    }
}

short int ins_fin_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*fin && comp_datospasajero((*fin)->datapasajeros, origen) > 0)
        return -1;
    else
    {
        struct nodo_pasajeros *nuevo;
        nuevo=(struct nodo_pasajeros *)malloc(TAMNS);
        
        if(!(*inicio))
        {
            nuevo->prev=NIL;
            *inicio=nuevo;
        }
        else{
            
            asignar_pasajero(&(nuevo->datapasajeros),origen);
            nuevo->next=NIL;
            while((*fin)->next!=NIL)
            {
                (*fin)=(*fin)->next;
            }
            (*fin)->next=nuevo;
            nuevo->prev=*fin;
            
            (*fin)=nuevo;
            
            
        }
        return 1;
        
    }
}
//////////////////////Funciones Eliminar////////////////////

short int eli_ord_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin ,struct datos2 *origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a eliminar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    struct nodo_pasajeros *aux;
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
            exito=eli_ini_pasajero(inicio,fin,origen);
        }
        else
        {
            if(comp_datospasajero((*inicio)->datapasajeros,*origen) == 0 && aux->datapasajeros.numasiento==origen->numasiento)
            {
                exito=eli_ini_pasajero(inicio,fin,origen);
            }
            else
            {
                if(comp_datospasajero((*fin)->datapasajeros, *origen )==0 && aux->datapasajeros.numasiento==origen->numasiento )
                {
                    exito=eli_fin_pasajero(inicio,fin,origen);
                }
                else
                {
                    exito=eli_med_pasajero(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}





short int eli_ini_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 *origen){
    
    struct nodo_pasajeros *aux=*inicio;
    
    if(*inicio != *fin){
        *inicio = (*inicio)->next;
        (*inicio)->prev=NULL;
        
        if(!aux){
            return 1;
        }
    }else { free(*inicio);
        *inicio=NULL;
        free(*fin);
        *fin=NULL;}
    return 0;
}








short int eli_fin_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 *origen)
{
    struct nodo_pasajeros *aux;
    aux=(*fin);
    
    (aux)->prev=NULL;
    asignar_pasajero(&(aux->datapasajeros),*origen);
    free(aux);
    free(fin);
    return 2;
    
}




short int eli_med_pasajero(struct nodo_pasajeros **inicio, struct nodo_pasajeros **fin, struct datos2 *origen){
    struct nodo_pasajeros *actual,*anterior;
    actual=(*inicio)->next;
    anterior=*inicio;
    
    while (actual!=NULL) {
        
        if(strcmp(actual->datapasajeros.nombrepasajero,origen->nombrepasajero)==0 && actual->datapasajeros.numasiento == origen->numasiento){
            anterior->next=anterior->next->next;
            actual->next=anterior->prev;
            asignar_pasajero(&(actual->datapasajeros),*origen);
            free(actual);
            return 3;
        }else
            
            anterior=actual;
        actual=actual->next;
    }
    
    
    
    
    return 0;
}

