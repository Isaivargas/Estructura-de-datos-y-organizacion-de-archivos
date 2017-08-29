//
//  main.c
//  practica3
//
//  Created by Isaí Vargas on 8/26/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONES

int genesis(int renglones,int columnas,int *matrix);
int fillcolum(int *matrix,int renglones,int columnas);
int showmatrix(int renglones,int columnas,int *matrix);

int main(int argc, const char * argv[]) {
    // insert code here...
    short int opcion=0;
    int dimatriz=0;
    int renglones=0,columnas=0;
    int *matrix=0,v=0;
    printf("Bienvenido\n");
    do {
    printf("Teclea la opcion deseada\n1.-Crear nueva matriz\n2.-LLenar por columna\n3.-Llenado viborita\n4.-llenar en espiral\n5.-Cuadrado magico\n6.-Comprobar Cuadrado magico\n7.-Imprimir matriz\n8.-Vaciar Matriz\n9.-Salir\n");
    scanf("%hd",&opcion);

    switch (opcion) {

        case 1:
            if (!v){
            printf("Introduce el tamaño de los rengloes\t");
            scanf("%d",&renglones);
            printf("columnas\t");
            scanf("%d",&columnas);


            //Funcion crear matriz
            v=genesis(renglones,columnas,matrix);
            printf("Matriz creada\n");
            }else if (v==0){printf("ERROR al crear vector\n");}
            else {printf("¡Error al crear la matriz\nYa existe una Matriz!\n");}
            printf("\n");
            break;

        case 2:
            fillcolum(&matrix,renglones,columnas);
            printf("\n\n\n");
            break;

        case 7:
            showmatrix(renglones,columnas,&matrix);
            printf("\n");
            break;

        default: printf("Opcion NO valida !");
            break;

    }}while (opcion<=9);



    return 0;
}

//Funcion crear matriz
int genesis(int renglones,int columnas,int *matrix){
    matrix=(int *)malloc((renglones*columnas)*sizeof(int));

    if (matrix!=0){
    return 1;
    }else
    { return 0;}
}

int fillcolum(int *matrix,int renglones,int columnas){
              short int i,j=0,count=0;

            for (i=0; i<renglones; i++){
            for (j=0; j<columnas; j++){
                   *(matrix+i*columnas+j)=count;
                   count++;
        }}

    return 1;
}

int showmatrix(int renglones,int columnas,int *matrix){
    short int i=0,j=0;

    for (i=0; i<renglones; i++){
        for (j=0; j<columnas; j++){
    printf("%d\t",*(matrix+i*renglones+j));
    }printf("\n");  }
    return 1;
}
