

//  main.c
//  Practica9Grafos1.2
//
//  Created by Isaí Vargas on 11/3/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define sizename 0

struct grafo *bornmatrix(int *sizematriz,int *road[]);
short int showmatrix(struct grafo *matrix,struct grafo *actual,int sizematrix,int **numnodo);
short int showmatrix1(struct grafo *matrix,struct grafo *actual,int sizematrix,int **numnodo);
struct grafo *weightvertices(struct grafo **matrix,int **actual,int sizematrix);
short int enumnodos(struct grafo **matrix,struct grafo *actual,int sizematrix,int *numeracion);
short int inserciondeuniones(struct grafo **matriz,int numeracion,int sizematriz);
int mapa(struct grafo **matriz ,struct grafo *actual,int **road[],int sizematriz,int ndorigen,int ndestino,int i, int j);

struct grafo{
    int weight;
    int status;
    int Name;
    char nombre;
};
int main()
{
    int i =0,j = 0,band=0,numeracion=0;//cadena de nombres para los nodos
    int i1=0,j1=0;
    int  *numnodo = NULL,sizematriz = 0;
    int ndorigen,ndestino;
    struct grafo *matrizadyacente = NULL ,*actual;//actual es la posicion del recorrido de la matriz
    short int opcion;
    int *road=NULL; // vector dinamico de rutas
    actual=matrizadyacente;
    
    do{
        printf("Introduce la opcion deseada\n 1.- Crear Matriz de adyacencia \n 2.- Insertar Nodos \n 3.- Insertar uniones \n 4.- Desplegar Nodos \n 5.- Recorrer\n 6.- SALIR\n");
        scanf("%hd",&opcion);
        switch(opcion){
                
            case 1:
                if (band==0){
                    matrizadyacente = bornmatrix(&sizematriz,&road);
                      }else{printf("ERROR matriz existente!\n");}
                
                    if(matrizadyacente==0){
                    //inicializacion de matriz!
                    for (i=0; i<=sizematriz; i++){
                        for (j=0; j<=sizematriz; j++){
                            ((matrizadyacente+(i*sizematriz)+j)->weight)=0;
                        }}
                        band=1;}

                break;
                
            case 2: enumnodos(&matrizadyacente, actual,sizematriz,&numeracion);
                break;
                
            case 4:
                if(numeracion==1){
                    showmatrix(matrizadyacente, actual,sizematriz,&numnodo);
                }else{
                    showmatrix1(matrizadyacente, actual,sizematriz,&numnodo);}
                break;
            case 3:
                inserciondeuniones(&matrizadyacente,numeracion,sizematriz);
                /*printf("Introduce el numero del nodo que deseas unir:\t");
                scanf( "%d", &nodoa);
                printf("Introduce el numero del segundo nodo que deseas unir:\t");
                scanf( "%d", &nodob);
                ((matrizadyacente+(nodoa*sizematriz)+nodob)->weight)=1;*/
                
                break;
                
            case 5:
                printf("Introduce el nodo de origen:\t");
                scanf("%d",&ndorigen);
                printf("Introduce el nodo de destino:\t");
                scanf("%d",&ndestino);
                mapa(&matrizadyacente,actual,road,sizematriz,ndorigen,ndestino,i,j);
                printf("Las posibles rutas son las siguientes\n");
                for(i=0; i<sizematriz; i++)
                {
                    printf("%d -> ",road[i]);
                }
                printf("\n");
                break;
                
            default:printf("ERROR opcion Invalida!\n\n");
        }
    }while (opcion!=6);
    return 0;
}

short int inserciondeuniones(struct grafo **matriz,int numeracion,int sizematriz){
    int nodoa=0,nodob=0;
    char nodoa1=0,nodob1=0;;
    if(matriz!=NULL){
    if (numeracion==1){
    printf("Introduce el numero del nodo que deseas unir:\t");
    scanf( "%d", &nodoa);
    printf("Introduce el numero del segundo nodo que deseas unir:\t");
        scanf( "%d", &nodob);
        *(&(*matriz+(nodoa*sizematriz)+nodob)->weight)=1;
    }else if (numeracion==2){
        printf("Introduce el numero del nodo que deseas unir:\t");
        scanf( "%c", &nodoa1);
        printf("Introduce el numero del segundo nodo que deseas unir:\t");
        scanf( "%c", &nodob1);
        *(&(*matriz+(nodoa1*sizematriz)+nodob1)->weight)=1;
    }}else {printf("ERROR primero debes de crear una matriz !\n\n");}
    return 1;
}


//Funcion que crea la matrizadyacente que representacion de los nodos
struct grafo *bornmatrix(int *sizematriz,int *road[]){
    struct grafo *matrix = NULL;
    int renglones,columnas;
    printf("Introduce el tamano de tu matriz:\t");
    scanf("%d",sizematriz);
    if(*(sizematriz) %2==0){
        renglones=(*sizematriz);
        columnas=(*sizematriz);
        matrix=(struct grafo*)malloc((renglones*columnas)*sizeof(struct grafo));
        *road=(int*)malloc((renglones)*sizeof(int));
        return matrix;
    }else{printf("ERROR la matriz debe de ser cuadrada\n");}//creacion de la matriz dinamica
        return 0;
}
/*char *Namenodo(int *sizematriz){
 
 return nombresnodos;
 }
 */
short int enumnodos(struct grafo **matrix,struct grafo *actual,int sizematrix,int *numeracion){
    int opcion=0,i,count=0;
    char a;
    printf("Eligue un tipo de enumeracion\n1.-Enumeracion normal \n 2.-Enumeracion con letras\n");
    scanf("%d",&opcion);
    *numeracion=opcion;
    switch(opcion){
        case 1: printf("Teclea la opcion deseada\n 1.-Enumeracion secuencial \n 2.- Enumeracion propia\n");
            scanf("%d",&opcion);
            switch(opcion){
                case 1: for (i=1; i<=sizematrix; i++){
                    *(&(*matrix)->Name+(i*sizematrix))=i;
                }
                    break;
                case 2: for (i=1; i<=sizematrix; i++){
                    printf("Introduce el numero de nodo correspondiente:");
                    scanf("%d",&count);
                    *(&(*matrix)->Name+(i*sizematrix))=count;
                }
                    break;
            }
            break;
        case 2: printf("Teclea la opcion deseada\n 1.-Letras secuenciales \n \2.-Letras propias\n");
                  scanf("%d",&opcion);
            switch(opcion){
                case 1:for (a='a'; a<=sizematrix; a++){
                       *(&(*matrix)->nombre+(a*sizematrix))=a;
                      }
                    break;
            }
            break;
    }
    
    return 1;
};



short int showmatrix(struct grafo *matrix,struct grafo *actual,int sizematrix,int **numnodo){
    int renglones=sizematrix,columnas=sizematrix;
    short int i = 0,j=0,aux1=0;
    actual=matrix;
    for (aux1=1; aux1<=(sizematrix); aux1++) { //Numeros nodos
        printf("\t\t");
        printf("Nodo %d \t", *(&((matrix)->Name)+aux1*(sizematrix)));
    }
    //Numeros nodos
    for (i=1; i<=renglones; i++){
        printf("\n");
        printf("Nodo %d", *(&(matrix)->Name+i*(sizematrix)));
        printf(" \t");
        for (j=1; j<=columnas; j++){
            printf("\t%d \t\t\t",((actual+(i*sizematrix)+j)->weight));
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}


int ruta(struct grafo **G, int origen, int destino, int vec_ruta[10], int c, int x)/*FUNCION QUE RECIBE UNA MATRIZ DE ESTRUCTURAS TIPO GRAFO, UN VECTOR DE CADENAS CON EL NOMBRE
                                                                                    DE LOS NODOS, EL NODO ORIGEN n1, EL NODO DESTINO n2 Y UN VECTOR DE CADENAS PARA AHÍ ALOJAR LA RUTA*/
{
    int i, aux;
    //printf("\nORIGEN: %d\nDESTINO: %d\nC: %d\nX: %d", origen, destino, c, x);
    
    if(((*G)+(origen*x)+origen)->status==0)
    {
        
        ((*G)+(origen*x)+origen)->status=1;//MARCAR EL ORIGEN COMO VISITADO
        vec_ruta[c]=origen;//GUARDAR EL ORIGEN EN EL VECTOR EN LA POSICION DEL CONTADOR
        //printf("\nVECTOR: %d", vec_ruta[c]);
        c++;
        //printf("\nC: %d", c);
        
        if(origen==destino)
        {
            printf("\n");
            for(i=0; i<10; i++)
            {
                printf("%d ", vec_ruta[i]);
            }
            return vec_ruta[10];
        }
        else
        {
            for(i=0; i<x; i++)
            {
                if((((*G)+(origen*x)+i)->weight)!=0)
                {
                    if((((*G)+(origen*x)+i)->weight)==0)
                    {
                        ((*G)+(origen*x)+i)->status=1;
                        return ruta(G, i, destino, vec_ruta, c, x);
                    }
                }
            }
            ((*G)+(origen*x)+origen)->status=0;//MARCAR EL ORIGEN COMO NO VISITADO
        }
    }
    return 1;
}

 int mapa(struct grafo **matriz ,struct grafo *actual,int **road[],int sizematriz,int ndorigen,int ndestino,int i1,int j1){
    
     /* if (band==sizematriz && (actual+(ndorigen*sizematriz)+ndestino)->status==1 && ndorigen==ndestino){*/
     
     ((*matriz)+(ndorigen*sizematriz)+ndorigen)->status=1;
          printf("%d",ndorigen);
     *road[j1]=ndorigen;

        if(ndorigen==ndestino && i1==sizematriz){
          for(i1=0; i1<sizematriz; i1++)
          {
              printf("%d -> ",**road[i1]);
          }
        return 1;
      }else{
 //incrementamos el valor de la bandera para identificar el limite del grafo.
        /*  *(&(*matriz+(ndorigen*sizematriz)+i)->status)=1; // marcamos como visitado el status del nodo.
               printf(" status \t%d",*(&(*matriz+(ndestino*sizematriz)+j)->status));
          if(*(&(*matriz+(ndorigen*sizematriz)+i)->weight)!=0){
              printf("%d",*(&(*matriz+(ndestino*sizematriz)+j)->Name));
              **road=(&(*matriz+(ndestino*sizematriz)+j)->Name); // guardamos el nodo de la ruta a seguir
          }
          
          return mapa(matriz,actual, road, sizematriz,ndorigen,ndestino);
          */
          for(i1=0; i1<sizematriz; i1++)
          {
              if((((*matriz)+(ndorigen*sizematriz)+i1)->weight)!=0)
              {
                  if((((*matriz)+(ndorigen*sizematriz)+i1)->weight)==0)
                  {
                      ((*matriz)+(ndorigen*sizematriz)+i1)->status=1;
                      return mapa(matriz,actual, road, sizematriz,ndorigen,ndestino,i1,j1);
                  }
              }
          }
          ((*matriz)+(ndorigen*sizematriz)+ndorigen)->status=1;
      }

    
     return 1;
}

short int showmatrix1(struct grafo *matrix,struct grafo *actual,int sizematrix,int **numnodo){
    int renglones=sizematrix,columnas=sizematrix;
    short int i = 0,j=0;
    char aux;
    actual=matrix;
    for (aux='a'; aux<=(sizematrix); aux++) { //Numeros nodos
        printf("\t\t");
        printf("Nodo %c \t", *(&((matrix)->nombre)+aux*(sizematrix)));
    }
    //Numeros nodos
    for (i=1; i<=renglones; i++){
        printf("\n");
        printf("Nodo %c", *(&(matrix)->nombre+i*(sizematrix)));
        printf(" \t");
        for (j=1; j<=columnas; j++){
            printf("\t%d \t\t\t",((actual+(i*sizematrix)+j)->weight));
        }
        printf("\n");
    }
    printf("\n");
    return 1;
}
