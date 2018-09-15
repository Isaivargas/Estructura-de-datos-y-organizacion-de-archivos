//
//  main.c
//  LibArbol
//  Created by Isaí Vargas on 11/18/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//  Compilador: CB+GCC
//  VERSION 1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXNOM 50
#define MAXNUM 10
#define MAXKEY 6



struct Datos                            // Estructura para el manejo del archivo
{
    char nombre[MAXNOM];
    int tel_casa[MAXNUM];
    int tel_cel[MAXNUM];
};

struct Nodo {
   bool  leaf;     // Variable para saber si es un nodo o una hoja.
   char key[2];
   struct Nodo *father;
   struct Nodo *right;
};

struct Agenda{
    int   numregistro;
    short int  status;
    struct Nodo  node[MAXKEY];            // Declaracion de numero de nodos de max 6 para la pagina
    struct Agenda *left;
};


// Funciones main
struct Agenda *alta(void);
short int insercion(struct Agenda new,struct Agenda **raiz,int *numkeys);

int main()
{
    int opcion,i = 0;

    struct Agenda new,*raiz=NULL;
     int numkeys=new.numregistro;
 

    
    do
    {
        printf("\t\tMENU");
        printf("\n\t1. ALTA");
        printf("\n\t2. CONSULTA X CLAVE");
        printf("\n\t3. MODIFICA X CLAVE");
        printf("\n\t4. BORRAR X CLAVE");
        printf("\n\t5. REPORTE ORDENADO");
        printf("\n\t6. SALIR");
        printf("\n\t\nINGRESE LA OPCION DESEADA: ");
        scanf("%d", &opcion);

        
        switch(opcion)
        {
                
                
            case 1:
            {
                
                new=*alta();
                insercion(new,&raiz,&numkeys);
                printf("\n");
                break;
            }
                
                
            case 2:
            {
                break;
            }
                
            case 3:
            {
                break;
            }
                
            case 4:
            {
                break;
            }
                
            case 5:
            {
                break;
            }
                
            case 6:
            {
                printf("\nADIOS");
                break;
            }
                
            default:
            {
                printf("\nINGRESE UNA OPCION VALIDA");
                break;
            }
        }
        
    }while(opcion!=6);
}

//Funciones
//struct Agenda *alta(void){
//struct Agenda *alta = NULL;
//    int i= 0;
//    long int longitud=0;
    
//    do{
//        getchar();
//        printf("CLAVE UNICA alumno:\t ");
//        fflush(stdin);
//        gets(alta->node.data[i].key);
 //       longitud=strlen(alta->node.data[i].key);
//    }while(longitud<=0);
    
 //   do{
//        printf("Nombre del alumno:\t ");
//        gets(alta->node.data[i].nombre);
//        longitud=strlen(alta->node.data[i].nombre);
//    }while(longitud<=0);
    
 //   do {
//        printf("Telefono de casa:\t ");
//        scanf("%d",alta->node.data[i].tel_casa);
//    }while(*alta->node.data[i].tel_casa<=8);
    
 //   do{
//        printf("Telefono celular:\t ");
//        scanf("%d",alta->node.data[i].tel_casa);
//    }while(*alta->node.data[i].tel_cel<10);
    
  //  return alta;
//};

struct Nodo *newnew( ){
    struct Nodo *newnodo;
    
    newnodo=(struct Nodo *)malloc(sizeof(struct Nodo));

    
    return newnodo;
}



// Funcion de Insercion de nuevo
short int insercion(struct Agenda new,struct Agenda **raiz,int*numkeys){
    struct Agenda *k=0,*p=0;
    int i = 0,band=0;
    
    for(i=0; i<=6; i++){
        if (strcmp(new.node->key,p->node[i].key)==0){
        band=1;
    }}
    
    if(band==0){
         if (*raiz==NULL){                                                      // Verificacion de que No exita un una raiz previamente.
             (*raiz)->node[i]=*newnew();                                           // llama a una funcion que crea un nuevo vector
             (*raiz)->numregistro++;                                            // Aumenta el numero de registro correpondiente del archivo indexado.
             (*raiz)->status=1;
             (numkeys)++;                                                       // Registra el numero de llaves que se ha creado.
           return 1;
         }
        
        
           p=(*raiz);                                                           // Inicialización.
           k=p;
        
           while (p!=NULL) {                                                    // Busqueda de
               
               
                 if (strcmp(new.node.data[i].key,p->node.data[i].key)<1 && p->node.leaf==true){
                        p->node=*p->node.prev;                                  //hijo izquierdo.
                    }else{
                        p->node=*p->node.next;                                  //hijo derecho.
                }
        
    };
    
          p->node =*newnew();
          p->node.data[i]=new.node.data[i];
          p->numregistro++;
          p->status=1;                                                         //Activacion del Nodo.
    
             if (strcmp(new.node.data[i].key,k->node.data[i].key)<1){
                 k->node.prev=&p->node;                                        //hijo izquierdo.
               }else{
                 k->node.next=&p->node;                                        //hijo derecho.
                 
               }
    }else {printf("ERROR llave existente\n");}
    
    return -1;
}


