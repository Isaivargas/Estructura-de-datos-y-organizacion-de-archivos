//
//  main.c
//  practica3
//
//  Created by Isaí Vargas on 8/26/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//FUNCIONES

int *genesis(int renglones,int columnas);
int fillsnake(int *matrix,int **actual,int renglones,int columnas);
int fillcolum(int *matrix,int **actual,int renglones,int columnas);
int fillspiral(int *matrix,int **actual,int renglones,int columnas);
int showmatrix(int *matrix,int **actual,int renglones,int columnas);

int main(int argc, const char * argv[]) {
    short int opcion=0;
    int renglones=0,columnas=0;
    int *matrix = NULL,*actual = NULL;
     do {
        printf("\tTeclea la opcion deseada\n 1.-Crear nueva matriz\n 2.-LLenar por columna\n 3.-Llenado viborita\n 4.-llenar en espiral\n 5.-Cuadrado magico\n 6.-Comprobar Cuadrado magico\n 7.-Imprimir matriz\n 8.-Vaciar Matriz\n 9.-Salir\n");
        scanf("%hd",&opcion);
        
        switch (opcion) {
                
            case 1:
                if (!matrix){
                    printf("Introduce el tamaño de los renglones\t");
                    scanf("%d",&renglones);
                    printf("columnas\t");
                    scanf("%d",&columnas);
                    
                    
                    //Funcion crear matriz
                    matrix=genesis(renglones,columnas);
                    printf("Matriz creada\n");
                }else if (matrix!=NULL){printf("¡ERROR \nYa existe una matriz !\n");}
                printf("\n");
                break;
                
            case 2:
                fillcolum(matrix,&actual,renglones,columnas);
                printf("\n");
                break;
                
            case 3:
                fillsnake(matrix,&actual,renglones,columnas);
                printf("\n");
                break;
                
            case 4:
                fillspiral(matrix,&actual,renglones,columnas);
                printf("\n");
                break;

                
            case 7:
                showmatrix(matrix,&actual,renglones,columnas);
                printf("\n");
                break;
                
            case 8:
                
                break;
                
                
                
            default: printf("Opcion NO valida !");
                break;
                
        }}while (opcion<=9);
    
    
    
    return 0;
}

//Funcion crear matriz
int *genesis(int renglones,int columnas){
    int *matrix;
    matrix=(int *)malloc((renglones*columnas)*sizeof(int));
    
    if (matrix!=NULL){
        return matrix;
    }else
    { return 0;}
}

int apocalipsis(){
    
    return 1;
}

int fillcolum(int *matrix,int **actual,int renglones,int columnas){
    short int i,j=0,count=1;
    *actual=matrix;
    
    for (j=0; j<columnas; j++){
        for (i=0; i<renglones; i++){
            *(*actual+i*columnas+j)=count;
            count=count+1;
        }
    }
        return 1;
}

int fillsnake(int *matrix,int **actual,int renglones,int columnas){
    int i=0,j,count=1;
    *actual=matrix;
    
    if (count<=(renglones*columnas)){
    for (i=0; i<renglones; i++){
        if(i%2==0){
            for (j=0; j<columnas; j++){
                *(matrix+(i*columnas)+j)=count;
                count++;
            }
        }else{
            
            for (j=columnas-1; j>=0; j--){
                *(matrix+(i*columnas)+j)=count;
                count=count+1;
            } }
           }
          }
    

    return 1;
}//end zickzack




int fillspiral(int *matrix,int **actual,int renglones,int columnas){
    int i=0,j,count=1,cambio=0;
    *actual=matrix;
    
        for (i=renglones-1; i>0; i--){// primer ciclo llenado
            if(cambio==0){
               for (j=0; j<columnas; j++){
               **(actual+(i*columnas)+j)=count;
               count++;
               }}//end primer ciclo
            if(cambio==1){
                for (j=0; j<columnas; j++){
                    *(matrix+(i*columnas)+j)=count;
                    count++;
                }}//end segundo ciclo
            
        
    }
    
    return 1;
}//end zickzack






int showmatrix(int *matrix,int **actual,int renglones,int columnas){
    short int i,j=0;
   
    for (i=0; i<renglones; i++){
         printf("\t");
        for (j=0; j<columnas; j++){
            printf("| %2d |",*(matrix+(i*columnas)+j));
        }printf("\n");}
    
    return 1;
}



