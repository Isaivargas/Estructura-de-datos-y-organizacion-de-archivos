//
//  main.c
//  EXAMEN2
//
//  Created by Isaí Vargas on 10/21/17.
//  Copyright © 2017 Isaí Vargas. All rights reserved.
//

#include <stdio.h>
#include "librerialumnos.c"

int main (void){
    short int opcion=0,exito;
    struct datos destino;
    struct datos2 destino2;
    struct nodo_pasajeros *inicio2 = NULL,*fin2;
    struct nodo_vuelos *inicio=NULL,*fin=NULL,*primerpasajero=NULL,*ultimopasajero=NULL;
    
    printf("BIENVENID@ a ISAI AIR-LAINES :) \n");
    do{
        printf("Tecle la opcion deseada \n 1.-VUELOS \n 2.-PASAJEROS\n 0.-SALIR\n");
        scanf("%hd",&opcion);
        switch (opcion){
            case 1: printf("Teclea la opcion deseada \n 1.-Crear vuelo \n 2.-Consultar vuelos \n 3.-Cancelar vuelos \n 0.-SALIR\n");
                scanf("%hd",&opcion);
                switch (opcion) {
                        
                    case 1:
                        
                        pedir_datos(&destino);
                        exito=ins_ord_vuelo(&inicio, &fin, destino);
                        switch(exito)
                    {
                        case -1: printf("Error en parametros");
                            break;
                        case 0: printf("Esta vacio");
                            break;
                        case 1: printf("se creo el vuelo con exito!\n\n");
                            break;
                    }
                        
                        desp_datos(destino,&primerpasajero,&ultimopasajero,destino2);
                        
                        break;
                        
                    case 2:printf("Introduce la opcion deseada\n 1.-Consultar un vuelo 2.-Consultar todos\n");
                        scanf("%hd",&opcion);
                        switch(opcion){
                                
                            case 1:    pedir_datos(&destino);
                                exito=buscar_vuelo(&inicio, &fin, destino, &primerpasajero, &ultimopasajero);
                                if(exito==1){printf("Vuelo ENCONTRADO:\n");
                                    desp_datopasajero(destino2,destino,&primerpasajero,&ultimopasajero);
                                    printf("\n");
                                }
                                else{printf("ERROR Dato NO encontrado\n");}
                                
                                printf("\n\n\n");
                                break;
                                
                                
                            case 2:if ((&destino)->numvuelo==0){
                                printf("ERROR No Hay datos aun!\n");}
                            else{
                                recorre_vuelo(inicio, &primerpasajero, &ultimopasajero, destino2, destino);
                            }
                                
                                break;
                                
                            default:printf("ERROR opcion Invalida\n");
                        }
                        break;
                        
                    case 3:pedir_datos(&destino);
                        exito=eli_ord_vuelo(&inicio,&fin,&destino);
                        switch(exito)
                    {
                        case -1: printf("Error en parametros");
                            break;
                        case 0: printf("Esta vacio");
                            break;
                        case 1: printf("Eliminado con exito");
                            break;
                    }
                        printf("\n");
                        break;
                        
                    default:printf("ERROR OPCION NO VALIDA \n");
                        break;
                }
                
                break;//fin primera opcion
            case 2:     printf("Teclea la opcion deseada \n 1.-Insertar pasajero \n 2.-Consultar pasajeros \n 3.-Cancelar vuelos \n 0.-SALIR\n");
                scanf("%hd",&opcion);
                switch (opcion) {
                    case 1:pedir_datospasajeros(&destino2,&inicio,&inicio,destino,&primerpasajero,&ultimopasajero);
                           ins_fin_pasajero(&inicio2,&fin2,destino2,&primerpasajero,&ultimopasajero);
                           desp_datopasajero(destino2,destino,&primerpasajero,&ultimopasajero);
                        printf("\n\n\n");
                        break;
                        
                    case 2:pedir_datospasajeros(&destino2,&inicio,&inicio,destino,&primerpasajero,&ultimopasajero);
                           exito=buscar_pasajero(&inicio2,&fin2, destino2);
                        if(exito==1){printf("Pasajero ENCONTRADO:\n");}
                        else{printf("ERROR Pasajero NO encontrado\n");}
                        printf("\n");
                        break;
                        
                    case 3:pedir_datospasajeros(&destino2,&inicio,&inicio,destino,&primerpasajero,&ultimopasajero);
                           eli_fin_pasajero(&inicio2, &fin2, &destino2);
                        break;
                        
                    default:printf("ERROR OPCION NO VALIDA \n");
                    break;}
                break;
            default:printf("Adios ESPERAMOS QUE HAYAS TENIDO UN TRATO Y UNA\n EXPERIENCIA AGRADABLE CON NOSOTROS\n,QUE  REGRESES PRONTO Y QUE TENGAS UN BUEN VIAJE \n");
                break;
        }
    }while (opcion!=0);
    
    return 0;
}
