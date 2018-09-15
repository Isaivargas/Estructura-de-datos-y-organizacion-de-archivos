/*  Objetivo: Manejo de archivos
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
    int  edad;
    char key[10];
    int  status;
    char origen [MAXNOM];
    char destino[MAXNOM];
    int  numasiento;
    char nombrepasajero[MAXNOM];
    char appaterno[MAXNOM];
    char apmaterno[MAXNOM];
    char dia[2],mes[2],ano[4];
    char *vocal;
};

//Funciones
short int pedirdatos(struct datos *datospasajeros);
short int mostrardatos(FILE *document);
short int busqueda(char id[],FILE *document);
short int eliminardatos(char id[],FILE *document);

void RFC(struct datos *datospasajeros);

int main(){
    short int opcion,resultado,i = 0;
    char id[10]={0};
    struct datos datospasajeros ;
    FILE *document = NULL;


    do {
        printf("Teclea la opcion deseada\n1.-Alta de datos\n2.-Busqueda por RFC\n3.-Desplegar todo el archivo\n4.-Modificar un registro\n5.-Borrar registro\n");
        scanf("%hd",&opcion);

        switch(opcion){

            case 1:

                document=fopen("archivito.bin" ,"ab+");
                resultado=pedirdatos(&(datospasajeros));
                RFC(&(datospasajeros));
                if (resultado==1){
                    printf("\n\tAlta Exitosa\n");}
                else {printf("ERROR de Alta de datos\n");}
                if (document!=NULL){
                     printf("\tArchivo de registros creado exitosamente\n\n");}
                else {printf("ERROR al crear archivo\n\n");}
                fwrite(&datospasajeros,sizeof(datospasajeros),1,document);
                fclose(document);
                break;

            case 2:
                if (datospasajeros.key[0]!=0){

                printf("introduce el ID que deseas buscar\n");
                getchar();
                gets(id);
                resultado=busqueda(id, document);
                if (resultado==0){printf("ERROR datos NO Encontados!\n");
                }
                else if(resultado==1){
                    printf("Datos encontrados!\n\n");
                    mostrardatos(document);}
                    printf("\n");}else{printf("ERROR Primero debes de crear un registro!\n\n");}

                break;

            case 3:
                if(document!=NULL){
                    document=fopen("archivito.bin" ,"rb");
                    resultado=mostrardatos(document);
                    fclose(document);
                }
                else{printf("ERROR!\n");}
                printf("\n");
                break;

            case 4: resultado=pedirdatos(&(datospasajeros));
                   resultado=pedirdatos(&(datospasajeros));

                break;

            case 5:if(document!=NULL){
                   printf("Introduce el rfc que deseas eliminar\n");
                   getchar();
                   gets(id);
                   document=fopen("archivito.bin" ,"rb");
                   resultado=eliminardatos(id,document);
                            fclose(document);
                  } else{printf("Error Primero debes de hacer un resgitro!\n\n");}

                break;



            default:printf("ERROR opcion No valida");
        }


    }while(opcion<6);

    return 0;
};

short int pedirdatos(struct datos *datospasajeros){
    printf("INTRODUCE LOS SIGUIENTES DATOS EN MAYUSCULAS\n");
    printf("\n  \t Origen ");
    getchar();
    gets(datospasajeros->origen);
    printf("\n  \t Destino");
    gets(datospasajeros->destino);
    fflush(stdin);
    printf("\n  \t Numero-de-asiento ");
    scanf("%d",&datospasajeros->numasiento);
    printf("\n  \t Edad\t");
    scanf("%d",&datospasajeros->edad);
    if(datospasajeros->edad<=18){
        printf("Necesita viajar acompañado de un adulto!\n");}
    else{
        printf("\n   \t Nombre del pasajero ");
        getchar();
        gets(datospasajeros->nombrepasajero);
        printf("\n  \tApellido paterno: ");
        scanf("%s",datospasajeros->appaterno);
        printf("\n  \tApellido materno: ");
        scanf("%s",datospasajeros->apmaterno);
        printf("\n  \tDia: ");
        scanf("%s",datospasajeros->dia);
        if(datospasajeros->dia<=0){
            printf("Lo sentimos no puede volar con nosotros");}
        else{
            printf("\n  \tMes: ");
            scanf("%s",datospasajeros->mes);
            if(datospasajeros->mes<=0){
                printf("Lo sentimos no puede volar con nosotros");}
            else{
                printf("\n  \tAno: ");
                scanf("%s",datospasajeros->ano);
                if(datospasajeros->ano<=0){
                    printf("Lo sentimos no puede volar con nosotros");}
                else{
                    fflush(stdin);}}}}
    datospasajeros->status=1;
    return 1;
}

short int mostrardatos(FILE *document){
struct datos datospasajeros;
    while (!feof(document) ){
     fread(&datospasajeros,sizeof(datospasajeros), 1,document);
     if(datospasajeros.status==1){
    printf("\tORIGEN\t\t DESTINO\tNumAsiento \tEDAD\t NOMBRE-PASAJERO\t ID \n");
    printf("\t%2s\t ",datospasajeros.origen);
    printf(" \t%2s\t",datospasajeros.destino);
    printf("\t%4d\t ",datospasajeros.numasiento);
    printf(" \t%4d\t ",datospasajeros.edad);
    printf("%4s %s\t ",datospasajeros.nombrepasajero,datospasajeros.appaterno);
    printf("  %.9s",datospasajeros.key);
    printf("\n");}}
    fclose(document);
    return 1;
}

void RFC(struct datos *datospasajeros){
    datospasajeros->key[0] = datospasajeros->appaterno[0];
    datospasajeros->key[1] = datospasajeros->apmaterno[0];
    datospasajeros->key[2] = datospasajeros->nombrepasajero[0];
    datospasajeros->key[3] = datospasajeros->ano[2];
    datospasajeros->key[4] = datospasajeros->ano[3];
    datospasajeros->key[5] = datospasajeros->mes[0];
    datospasajeros->key[6] = datospasajeros->mes[1];
    datospasajeros->key[7] = datospasajeros->dia[0];
    datospasajeros->key[8] = datospasajeros->dia[1];
}


//short int busqueda(struct datos datospasajeros[],char *id){
   // short int band=0;
   // int i = 0 ,result;

   // while(band==0|| i<10){
      //  if ((strcmp((datospasajeros[i]).key,id)==0)){
       //     band=1;
     //   }else{ band=0;}
      //  i++;

    //}

  //  printf("%hd",band);
 //   return band;
//}

short int busqueda(char id[],FILE *document){
     short int band=0;
     struct datos datasearch;
     int i = 0 ,result;
     document=fopen("archivito.bin" ,"rb");
     fread(&datasearch,sizeof(datasearch), 1,document);
     while (!feof(document) && band!=1) {

     if(strcmp(id,datasearch.key)==0){
            band=1;
     }else {
     fread(&datasearch,sizeof(datasearch), 1,document);
     }
    }
    printf("%hd",band);
     fclose(document);
    return band;
}

short int eliminardatos(char id[],FILE *document){

    struct datos d1;

     int band=0;

     fread(&d1,sizeof(d1),1,document);
     while (!feof(document) && band==0) {
     if(strcmp(id,d1.key)==0){
         printf("entro strcmp");
            d1.status=0;
            fseek(document,-1*sizeof(d1),SEEK_CUR);
            fwrite(&d1,sizeof(d1),1,document);
            band=1;
            return band;
     }
      else {
      fread(&d1,sizeof(d1), 1,document);
      }
      }
     printf("%hd",band);

    return band;
}


short int renamedatos(struct datos *datospasajeros){





    return 1;
}
