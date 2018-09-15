/*  Objetivo: Manejo de una lista simplemente ligada
 Autor: Vargas Chavez Isai
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
struct datos
{
    short int num_jug;
    char nombre_jug[MAXNOM];
};

struct nodo_simple
{
    struct datos data;
    struct nodo_simple *next;
};
#define TAMNS sizeof(struct nodo_simple)
//Prototipos de las funciones para el manejo de datos
void pedir_datos(struct datos *destino);
void asignar_datos(struct datos *destino, struct datos origen);
void desp_datos(struct datos origen);
short int comp_datos(struct datos origen1, struct datos origen2);

//Prototipos de las funciones para el manejo de las estructuras
short int ins_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos origen);
short int ins_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos origen);
short int ins_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen);
short int ins_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen);

short int eli_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos *origen);
short int eli_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos *origen);
short int eli_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen);
short int eli_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos *origen);

short int recorre_simple(struct nodo_simple *inicio);
short int buscar_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos origen);
//funciones para el manejo de las estructuras
//funciones para el manejo de datos


//funcion principal
int main()
{
    int opcion, exito;
    struct datos destino;
    struct nodo_simple *inicio, *fin;
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
                exito=ins_ord_simple(&inicio, &fin, destino);
                switch(exito)
                 {
                case -1: printf("Error en parametros");
                    break;
                case 0: printf("Esta vacio");
                    break;
                case 1: printf("Insertado con exito");
                    break;
                }
                desp_datos(destino);
                break;
                
            case 2:
                printf("Introduce el numero del jugador que deseas eliminar");
                gets(destino.nombre_jug);
                eli_ord_simple(&inicio,&fin,&destino);
                               
                break;
                
            case 3:recorre_simple(inicio);
                
                break;
                
            case 4:
                
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
    printf("%d %s", origen.num_jug, origen.nombre_jug);
    printf("\t");
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



short int recorre_simple(struct nodo_simple *inicio){

    struct nodo_simple *aux;
    aux=inicio;
        while (aux != NULL)
        {
            desp_datos(aux->data);
            aux = aux->next;
        }
    return 1;

}






short int ins_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos origen)
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
            nuevo->next=*inicio;
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
        struct nodo_simple *actual, *anterior = NULL, *nuevo;
        nuevo = (struct nodo_simple *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            actual=*inicio;
            asignar_datos(&(nuevo->data),origen);
            while(comp_datos(origen,actual->data) > 0)
            {
                anterior=actual;
                actual=actual->next;
            }
            nuevo->next=actual;
            anterior->next=nuevo;
            return 1;
        }
    }
}





short int ins_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*fin && comp_datos((*fin)->data, origen) > 0)
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
            nuevo->next=NIL;
            if(*fin)
            {
                (*fin)->next=nuevo;
            }
            (*fin)=nuevo;
            if(!(*inicio))
            {
                *inicio=nuevo;
            }
            return 1;
        }
    }
}



////////////////////////Funciones Eliminar

short int eli_ord_simple(struct nodo_simple **inicio, struct nodo_simple **fin ,struct datos *origen){
    short int exito = 0;
    
      
        
            exito=eli_ini_simple(inicio,fin,origen);
        
    

        
                exito=eli_ini_simple(inicio,fin,origen);
        
                if(comp_datos((*fin)->data,*origen) == 0)
                {
                    exito=eli_fin_simple(inicio,fin,origen);
                }
                else
                {
            
                
                
        
        }
    
    return exito;
    
}



short int eli_ini_simple(struct nodo_simple **inicio, struct nodo_simple **fin,struct datos *origen)
/*Eliminar por el inicio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    printf("Entrro inicio errase\n");
    struct nodo_simple *siguiente =*inicio;
    siguiente=siguiente->next;
    *inicio=siguiente;
    asignar_datos(&(siguiente->data),*origen);
    free(siguiente);
    if(siguiente->next==NULL){
        *fin=siguiente;}
    
    return 1;
}


short int eli_med_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen)
/*intertar por el medio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    struct nodo_simple *actual, *anterior = NULL, *siguiente = NULL;
    actual=*inicio;
    asignar_datos(&(siguiente->data),*origen);
    while(comp_datos(*origen,actual->data) > 0)
    {
        anterior=actual;
        actual=actual->next;
    }
    siguiente->next=actual;
    anterior->next=siguiente;
    return 1;
    
    
}


short int eli_fin_simple(struct nodo_simple **inicio, struct nodo_simple **fin, struct datos *origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    struct nodo_simple *actual,*anterior;
    
    actual=*inicio;
    if((*fin)->next==NULL){
        
        
    }
    
    
    
    
    return 1;
    
}
