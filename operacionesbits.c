//  PRACTICA #1
//  Uso de operadores a nivel de bits
//  Created by Isaí Vargas on 8/13/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//  compilador GNU GCC
//  version 1

#include <stdio.h>
#include <stdlib.h>
#define maxopcion 5
#define maxband   8

//Funciones
int bitprint(unsigned char *string);
int onbit(unsigned short int nband,unsigned char *string,short int *valorband);
int offbit(unsigned short int nband,unsigned char *string,short int *valorband);
int tof(unsigned short int nband,unsigned char *string);


int main(int argc, const char * argv[]) {
    unsigned char string = '\0';//mask es un arreglo temporal para poder realizar las operaciones
    short int opcion =0;//en n guardamos el valor que desea el usuario encender o apagar
    unsigned short int nband=0;
    short int valorband=0;
    int x;
    
    do {
        printf("Teclea la opcion deseada\n1.-Encender una locacion\n2.-Apagar la bandera                                                                                                                              \n3.-Comprobar bandera\n4.-Imprime todas las locaciones\n");
        scanf("%hd",&opcion);
        switch (opcion) {
            case 1:printf("Teclea la posicion deseada\n");
                   scanf("%hd",&nband);
                   getchar();
                onbit(nband,&string,&valorband);
                x=onbit(nband,&string,&valorband);
                if(x==1){printf("Encendido\n");}
                else printf("Error\n");
                break;
                
            case 2:printf("Teclea la posicion que deseas apagar\n");
                   scanf("%hd",&nband);
                   getchar();
                   offbit(nband,&string,&valorband);
                break;
                
            case 3:printf("Introduce el numero de bandera que deseas verificar\n");
                   scanf("%hd",&nband);
                   getchar();
                   tof(nband,&string);
                break;
                
            case 4:printf("El arreglo de la cadena es el siguiente\n");
                bitprint(&string);
                
                break;
                
                
                
            default: printf("Opcion No valida\nAdios\n");
                
                break;
        }
        
    }while(opcion<maxopcion);
    
    
    
    
    return 0;
}



int bin( unsigned short int nband,unsigned char *string){
    short int i;
    int val ;
    
    if (nband<=2){
        val=nband;
        return val;
    }else
        
        for (val=2,i=3; i<=nband; i++){
            val*=2;
        }
    
    return val;
    
}



//Enciede la bandera deseada
int onbit(unsigned short int nband,unsigned char *string,short int *valorband){
    if (nband>0&&nband<maxband){
        *valorband=bin(nband,string);
        *string = (*string|*valorband);
        return 1;}else return 0;
    
}

int offbit(unsigned short int nband,unsigned char *string,short int *valorband){
    *valorband=bin(nband,string);
    *string = (*string|*valorband);
    *string = *string^*valorband;
    return 1;
}

int tof(unsigned short int nband,unsigned char *string){
    int r = 0;
    for (int i=0; i<maxband; i++){
    if (nband&*string){
        r=1;
    }else
        r=0;
    }
    if(r==1){
    printf("La bandera esta encendida\n\n");
    }else
    printf("La bandera esta apagada\n\n");

    return 1;
}

int bitprint(unsigned char *string){
    short int x=0;
    
    for (x=128; x>0; x>>=1){
        if (x&*string){
            printf("1");
        }else
            printf("0");
        
    }
    printf("\n");
    
    return 1;
}




