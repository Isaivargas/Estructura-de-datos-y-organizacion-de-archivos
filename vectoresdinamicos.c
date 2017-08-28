//
//  main.c
//  vectores dinamicos
//  Created by Isaí Vargas on 8/21/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones
char *newnew(short int *dimvector,char *vector);
char showdata(char **actual,char *ultimo,char *vector);
short int errasedata(char **vector,char dato);
char newdata(char dato,char **actual,char *vector,char *ultimo,char *in,char *fin,short int *cont);

int main(int argc, const char * argv[]) {
    short int opcion,dimvector=0,cont=0,y=0;
    char dato,*vector=NULL;
    char *actual = NULL;
    char *in=NULL,*ultimo = NULL,*fin=NULL;
    char *x = NULL;
    actual=vector;
   
    do {
    printf("Teclea la opción deseada\n1.-Crear vector\n2.-Insertar un dato en la posición deseada\n3.-Eliminar un dato\n4.-Mostrar la ubicacion del vector\n5.-Desplegar contenido\n6.-Liberar el contenido del vector\n7.-Salir\n");
    scanf("%hd",&opcion);
    switch (opcion) {
        case 1:
            if(!x){
               printf("Introduce la dimension del vector que deseas crear\t");
               scanf("%hd",&dimvector);
               //Función crear vector
               x=newnew(&dimvector,vector);
            printf("vector exitosamente creado\n");
            }else if (x==NULL){printf("\nError,Vcetor No creado\n");}
            else { printf("vector existente");}
            printf("\n");
            break;
            
        case 2:
            
             printf("Introduce el dato que deseas Introducir\n");
             scanf("%c",&dato);
             getchar();
             y=newdata(dato,&actual,vector,ultimo,in,fin,&cont);
             printf("\n");
            //Funcion newdata
            
            printf("\n");
            break;

        case 3:
             printf("Introduce el dato que deseas Eliminar\n");
             scanf("%s",&dato);
             getchar();
             //Funcion errasedata
            
            printf("\n");
            break;
        
        case 4:printf("Introduce el dato que deseas Buscar\n");
            scanf("%s",&dato);
            getchar();

          
            printf("\n");
            break;
            
        case 5:showdata(&actual,ultimo,vector);
            
            
            printf("\n");
            break;
            
        case 6:
            
            
            
            break;
            
            
        default: printf("Hasta luego\n");
            break;
    }
    }while(opcion!=7);
    return 0;
}

//Función para crear un vector dinamico
char *newnew(short int *dimvector,char *vector){
 vector = (char*)malloc(*dimvector*sizeof(char));
    if (vector!=NULL){
        return vector;
    }else{
        return NULL;}
}




//Recorre los valores iniciales del vector
char inicio(char **actual,char dato,char *ultimo,char *in){
     char rinicio ;
     while (*actual<=in){
        if (*actual==in){
            *actual=&dato;
        }else{
            *(in+1)=*in;
            *in =*in-1;}
    }       **actual=dato;

    rinicio=**actual;
  return rinicio;
}

char eraseinicio(char **actual,char dato,char *ultimo,char *in){
    char rinicio ;
    while (*actual<=in){
        if (*actual==in){
;
        }else{
            *(in+1)=*in;
            *in =*in-1;}
    }      **actual=dato;
    
    rinicio=**actual;
    return rinicio;
}


//Recorre los valores finales del vector
char final(char **actual,char dato,char *ultimo,char **fin,char *in){
     char rfinial;
     while (*actual<=in){
        if (*actual==in){
            *actual=&dato;
            
        }else{
            *(in-1)=*in;
            *in =*in+1;}
    }      **actual=dato;
    rfinial=**actual;
    return rfinial;
}


char search(char dato,char *actual,char *vector,char *ultimo,char *in,char *fin,int s){
    char posicion1 ,posicion2,posicione1,posicione2;
    char rsearch=0;
    
    if (s==0){
     posicion1= inicio(&actual,dato,ultimo,in);
     posicion2= final(&actual,dato,ultimo,&fin,in);
    
    if(dato<posicion1){
       inicio(&actual,dato,ultimo,in);
       rsearch=posicion1;
    } else if (dato>posicion2){
       final(&actual,dato,ultimo,&fin,in);}
    }
    else{
       
    
    }
    return rsearch;
}


//Funcion
char newdata(char dato,char **actual,char *vector,char *ultimo,char *in,char *fin,short int *cont){
    int s=0;
    while(*actual<=ultimo){
    search(dato,*actual,vector,ultimo,in,fin,s);
    *actual=*actual+1;
    }
    *cont+=1;
    return 1;
}

char erasedata(char dato,char **actual,char *vector,char *ultimo,char *in,char *fin,short int *cont,int s){
    s=1;
    while(*actual<=ultimo){
        search(dato,*actual,vector,ultimo,in,fin,s);
        *actual=*actual+1;
    }
    *cont+=1;
    return 1;
}

char showdata(char **actual,char *ultimo,char *vector){
    
 
    
    return 1;
}

