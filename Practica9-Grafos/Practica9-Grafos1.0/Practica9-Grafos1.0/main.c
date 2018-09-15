//
//  main.c
//  Practica9Grafos1.2
//
//  Created by Isaí Vargas on 11/3/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define sizename 0

//Estructuras principales

//funcion que crea la matriz
int *bornmatrix(int *sizematriz);
short int verticesnum(int *matrix,int **actual,int sizematrix,int **numnodo);
short int showmatrix(int *matrix,int **actual,int sizematrix,int **numnodo);
short int Numeronodo(int *sizematriz,int **numnodo);
int fillcolum(int *matrix,int **actual,int renglones,int columnas);

int i;
int main()
{
    char *namenodo;//cadena de nombres para los nodos
    int  *numnodo = NULL,sizematriz = 0;
    int  *matrizadyacente = NULL,*actual = NULL;//actual es la posicion del recorrido de la matriz
    short int opcion;
    
    do{
        printf("Introduce la opcion deseada\n 1.- Crear Matriz de adyacencia \n 2.- Insertar Nodos \n 3.- Insertar uniones \n 4.- Desplegar Nodos \n 5.- Recorrer\n 6.- SALIR\n");
        scanf("%hd",&opcion);
        switch(opcion){
                
                
            case 1: matrizadyacente = bornmatrix(&sizematriz);
                if (matrizadyacente==0){
                    printf("ERROR la matriz debe de ser cuadrada!\n\n");
                }
                break;
                
            case 2: printf("Teclea la opcion deseada para los nombres de tus nodos \n\t\t1.-Numeros\n\t\t2.-Letras o Palabras\n");
                scanf("%hd",&opcion);
                switch (opcion) {
                    case 1:
                        Numeronodo(matrizadyacente, &numnodo);
                       
                        printf("\n");
                        break;
                        
                        
                    case 2:
                        
                        break;
                        
                        
                    default:printf("ERRor Opcion invalida!");
                        break;
                }
                break;
                
                
            case 4:
                if(numnodo!=0){
                    showmatrix(matrizadyacente,&actual,sizematriz,&numnodo);}
                else{
                    printf("ERROR primerdo debes de insertas los nodos correspondientes!\n\n");
                }
                break;
          case 3:
                verticesnum(matrizadyacente,&actual,sizematriz,&numnodo);
                break;
            default:printf("ERROR opcion Invalida!\n\n");
        }
    }while (opcion!=6);
    return 0;
}

//Funcion que crea la matrizadyacente que representacion de los nodos
int *bornmatrix(int *sizematriz){
    int *matrix = NULL,renglones,columnas;
    printf("Introduce el tamano de tu matriz:\t");
    scanf("%d",sizematriz);
    if(*(sizematriz) %2==0){
        renglones=(*sizematriz);
        columnas=(*sizematriz);
        matrix=(int *)malloc((renglones*columnas)*sizeof(int));
        return matrix;
    }else//creacion de la matriz dinamica
        return 0;
}

/*char *Namenodo(int *sizematriz){
 
 
 return nombresnodos;
 }
 */

short int Numeronodo(int *sizematriz,int **numnodo){
    int opcion=0,i,count=0;
    printf("Teclea 1.-Si deseas tener una enumeracion consecutiva\n\t\t2.-Si deseas crear tu propia enumeracion \n");
    scanf("%d",&opcion);
    switch (opcion) {
        case 1: *numnodo=(int *)malloc(*(sizematriz)*sizeof(int)); //llena al vector de numero de nodo con numeros consecutivos
            count=1;
            for (i=0; i<(*sizematriz); i++) {
                *(*numnodo+i*(*sizematriz))=count;
                count=count+1;
            }
            
            
            break;
            
        case 2:*numnodo=(int *)malloc(*(sizematriz)*sizeof(int)); //llena al vector de numero de nodo con numeros introducidos por el usuario
            printf("Introduce el numero deseado para el nodo correspondiente;\n");
            for (i=0; i<(*sizematriz); i++) {
                printf("\tNodo %d: \t",i);
                scanf("%d",&count);
                *(*numnodo+i*(*sizematriz))=count;
            }
            break;
            
        default:printf("ERROR opcion invalida!");
            break;
    }
    
    return 1;
}

short int verticesnum(int *matrix,int **actual,int sizematrix,int **numnodo){
    short int nodoa,nodob,i,j = 0;
    int renglones=sizematrix,columnas=sizematrix;
    printf("Introduce el numero del nodo que deseas unir:\t");
    scanf( "%hd", &nodoa);
    printf("Introduce el numero del segundo nodo que deseas unir:\t");
    scanf( "%hd", &nodob);
    
    for (i=0; i<renglones; i++){
        if (*(matrix)+i*columnas+j==nodoa){
        for (j=0; j<columnas; j++){
            if (*(matrix)+i*columnas+j==nodob){
                *(matrix+(i*columnas)+j)=1;
            }}
        }
        }
    showmatrix(matrix,actual,sizematrix,numnodo);
    return 1;
}

int fillcolum(int *matrix,int **actual,int renglones,int columnas){
    short int i,j=0,count=1;
    *actual=matrix;
    if(*actual!=NULL){
        for (j=0; j<columnas; j++){
            for (i=0; i<renglones; i++){
                *(*actual+i*columnas+j)=count;
                count=count+1;
            }
        }}else{printf("ERROR Primero debes de crear una matriz\n");}
    return 1;
}

short int showmatrix(int *matrix,int **actual,int sizematrix,int **numnodo){
    int renglones=sizematrix,columnas=sizematrix;
    short int i = 0,j=0,aux1=0;
    if(*actual==0){
        for (aux1=0; aux1<(sizematrix); aux1++) { //Numeros nodos
            printf("\t\t");
            printf(" Nodo %d", *(*numnodo+aux1*(sizematrix)));
        }
        //Numeros nodos
        for (i=0; i<renglones; i++){
            printf("\n");
            printf("Nodo %d", *(*numnodo+i*(sizematrix)));
            printf(" \t");
        for (j=0; j<columnas; j++){
                printf("\t %d \t\t",*(matrix));
               }
         printf("\n");
        }
    }
    printf("\n");
    return 1;
}



