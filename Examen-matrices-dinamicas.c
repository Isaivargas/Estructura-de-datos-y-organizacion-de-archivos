//  PRACTICA #3
//  Matrices dinamicas
//  Created by Isaí Vargas on 09/01/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//  compilador GNU GCC
//  version 1

#include <stdio.h>
#include <stdlib.h>


//FUNCIONES

//Funcion liberar arreglo
int *apocalipsis(int **matrix);
//Funcion crear
int *genesis(int renglones,int columnas);
//LLenado por renglon en forma de viborita
int fillsnake(int *matrix,int **actual,int renglones,int columnas);
//llenado por columna
int fillcolum(int *matrix,int **actual,int renglones,int columnas);
//llenado en espiral
int *fillspiral(int *matrix,int **actual,int renglones,int columnas);
//impresion del contenido del arreglo
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
                }else if (matrix!=NULL){printf("¡ERROR \nYa existe una matriz !\n\n");}
                printf("\n");
                break;

            case 2:
                fillcolum(matrix,&actual,renglones,columnas);

                break;

            case 3:
                fillsnake(matrix,&actual,renglones,columnas);

                break;

            case 4:
                fillspiral(matrix,&actual,renglones,columnas);

                break;


            case 7:
                showmatrix(matrix,&actual,renglones,columnas);

                break;

            case 8:apocalipsis(&matrix);

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
        return matrix;
}

int *apocalipsis(int **matrix){
    free(*matrix);
    *matrix=NULL;
    return *matrix;
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

int fillsnake(int *matrix,int **actual,int renglones,int columnas){
    int i=0,j,count=1;
    *actual=matrix;
     if(*actual!=NULL){
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
     }else{printf("ERROR primero debes de crear una matriz\n");}

    return 1;
}//end zickzack




int *fillspiral(int *matrix,int **actual,int renglones,int columnas){
    int i=0,j = 0,count=1,cambio=0;
    int iaux=renglones-1,jaux=columnas-1,auxi=0,auxj=0;
 //   auxi-auxfi=0,auxj-auxci=0;
 // auxff=iaux auxcf=jaux
    *actual=matrix;

if(*actual!=NULL){
//->
i=iaux;
for (j=auxj; j<=jaux; j++){
    *(*actual+(i*renglones)+j)=count;
                    count++;
}
iaux--;

//^
j=jaux;
for (i=iaux; i>=auxi; i--){
    *(*actual+(i*renglones)+j)=count;
                    count++;
}
jaux--;

//<-
i=auxi;
for (j=jaux; j>=auxj; j--){
    *(*actual+(i*renglones)+j)=count;
                    count++;
}
auxi++;
//
j=auxj;
for (i=auxi; i<=iaux; i++){
    *(*actual+(i*renglones)+j)=count;
                    count++;

}
auxj++;



    }else{printf("ERROR primero debes de crear una matriz\n");}

    return actual;
}//end






int showmatrix(int *matrix,int **actual,int renglones,int columnas){
    short int i,j=0;
    if(*actual!=NULL){
    for (i=0; i<renglones; i++){
        printf("\t");
        for (j=0; j<columnas; j++){
            printf("| %2d |",*(matrix+(i*columnas)+j));
        }printf("\n");}
    }else{printf("¡ERROR Primero debes de crear una matriz!\n");}
    printf("\n");
    return 1;
}



