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
struct datos
{
    int edad;
    int  status;
    char origen[MAXNOM];
    char destino[MAXNOM];
    int numasiento;
    char nombrepasajero[MAXNOM];

};


int main(){
short int opcion;
struct datos datospasajeros;
struct datos aux;
FILE *document = NULL;


do {
    printf("Teclea la opcion deseada\n1.-Alta de datos\n2.-Busqueda por campo\n3.-Desplegar todo el archivo\n4.-Modificar un registro\n5.-Borrar registro\n");
    scanf("%hd",&opcion);

switch(opcion){

       case 1:printf("Introduce los siguientes datos\n");
              printf("\n  \t Origen ");
              fflush(stdin);
              gets(datospasajeros.origen);
              printf("\n  \t Destino ");
              gets(datospasajeros.destino);
              fflush(stdin);
              printf("\n  \t Numero-de-asiento ");
              scanf("%d",&datospasajeros.numasiento);
              printf("\n  \t Edad\t");
              scanf("%d",&datospasajeros.edad);
              printf("\n   \t Nombre del pasajero ");
              fflush(stdin);
              gets(datospasajeros.nombrepasajero);
              printf("\n\n");
              document=fopen("archivito.txt" , "wb");
              fwrite(&datospasajeros,sizeof(datospasajeros),1,document);
              fclose(document);
              break;

       case 2:

               break;

       case 3:
               fread(&datospasajeros,sizeof(datospasajeros), 1,document);
               printf("%s\t",datospasajeros.origen);
               printf("%s\t",datospasajeros.destino);
               printf("%d\t",datospasajeros.numasiento);
               printf("%d\t",datospasajeros.edad);
               printf("%s\t",datospasajeros.nombrepasajero);
               fclose(document);
               break;

        case 4:

               break;

        case 5:

               break;



        default:printf("ERROR opcion No valida");
}


}while(opcion<6);

return 0;
};
