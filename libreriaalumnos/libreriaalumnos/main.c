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
#define MAXNOM 50
#define MAXKEY 10
#define NIL NULL
//Tipos de datos del usuario
struct datos
{
    
    int edad;
    float promedio;
    int grupo;
    short int status;
    int semestre;
    
    char  key[MAXKEY];
    char carrera[MAXNOM];
    char direccion[MAXNOM];
    char nombre_alumnos[MAXNOM];
    char appaterno[MAXNOM];
    char apmaterno[MAXNOM];
};

struct nodo_alumnos
{
    struct datos data;
    struct nodo_alumnos *next;
    struct nodo_alumnos *prev;
    
};


#define TAMNS sizeof(struct nodo_alumnos)
//Prototipos de las funciones para el manejo de datos
void pedir_datos(struct datos *destino,FILE *registroalumnos);
void asignar_datos(struct datos *destino, struct datos origen);
void desp_datos(struct datos origen,FILE *registroalumnos);
short int comp_datos(struct datos origen1, struct datos origen2);

//Prototipos de las funciones para el manejo de las estructuras

//Funciones para agregar alumnos
short int ins_ord_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin ,struct datos origen);
short int ins_ini_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin ,struct datos origen);
short int ins_med_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos origen);
short int ins_fin_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos origen);

//Funciones para eliminar alumnos
short int eli_ord_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin ,struct datos *origen);
short int eli_ini_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin,struct datos *origen);
short int eli_med_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos *origen);
short int eli_fin_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin,struct datos *origen);

short int clave(struct datos *datosalumnos,FILE *registroalumnos);
short int recorre_simple(struct nodo_alumnos *inicio,FILE *registroalumnos);
short int recorre_simpleinversa(struct nodo_alumnos *fin);
short int buscar_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin,struct datos origen,FILE *registroalumnos);

//funcion principal
int main(void)
{
    int opcion, exito,op = 0;
    struct datos destino;
    struct nodo_alumnos *inicio, *fin;
    FILE *registroalumnos = NULL;
    inicio=NIL;
    fin=NIL;
    
    do
    {
        system("cls");
        system("COLOR 4B");
        printf("\nTitulo: Lista simplemente ligada");
        printf("\n 1. Insertar ");
        printf("\n 2. Eliminar ");
        printf("\n 3. Recorrer");
        printf("\n 4. Buscar");
        printf("\n %d. Salir", MAXMENU);
        printf("\n\nElige una opcion (1-%d): ", MAXMENU);
        scanf("%d", &opcion);
        getchar();
        switch(opcion)
        {
            case 1:
                pedir_datos(&destino,registroalumnos);
                exito=ins_ord_simple(&inicio, &fin, destino);
                switch(exito)
            {
                case -1: printf("Error en parametros\n");
                    break;
                case 0: printf("Esta vacio");
                    break;
                case 1: printf("Insertado con exito\n");
                    break;
            }
                desp_datos(destino,registroalumnos);
                break;
                
            case 2:
                pedir_datos(&destino,registroalumnos);
                exito=eli_ord_simple(&inicio,&fin,&destino);
                switch(exito)
            {
                case -1: printf("ERROR en parametros\n");
                    break;
                case 1:case 2:case 3:printf("Datos Eliminados con exito!\n");
                    break;
            }
                
                
                break;
                
            case 3:printf("Introduce la opcion deseada para recorrer\t1 recorre simple \t2 recorre inversamente\n");
                scanf("%d",&op);
                switch (op) {
                   
                        
                    default:printf("OPCION no valida\n");
                        break;
                }
                
                break;
                
            case 4:
                pedir_datos(&destino,registroalumnos);
                exito=buscar_simple(&inicio,&fin,destino,registroalumnos);
                if(exito==1){printf("Valor encontrado\n");}
                else{printf("Dato No encontrado\n");}
                
                break;
                
            case MAXMENU:
                printf("\n\nAdios.");
                break;
                
            default:
                printf("\nError: solo numeros del 1 al %d", MAXMENU);
        }
        getchar();
    }
    while(opcion!=MAXMENU);
}






//funciones para el manejo de las estructuras
//funciones para el manejo de datos


void pedir_datos(struct datos *destino,FILE *registroalumnos){
/*Solicitar datos al usuario y validarlos
 Recibe: --
 Envia los datos que dio el usuario
 */
registroalumnos=fopen("archivito.bin" ,"ab+"); //apertura de archivo
    long int lngcadn = 0;
    register short int i;
    printf("Introduce los siguientes datos con MAYUSCULAS...\n");
    do{
        for(i=1; i<MAXNOM; destino->carrera[i]='\0', i++);
        printf("\t\t  Carrera:\t ");
        gets(destino->carrera);
        lngcadn=strlen(destino->carrera);
        if((lngcadn)<10){printf("ERROR se requiere el nombre completo de la carrera\n");
            printf("Porfavor Introduce el nombre de la carrera de forma adecuada\n\n");
        }
    }while(lngcadn<10);
    printf("\t\t  Semestre:\t");
    scanf("%d",&destino->semestre);
    if (destino->semestre<=0){
        printf("ERROR No existen semestres menores a el primero!\n");
        printf("Por favor vuelve a introducir un semestre valido!\n");
    }{
    printf("\t\t  Grupo:\t");
    scanf("%d",&destino->grupo);
    //inicializar la cadena

         for(i=0; i<MAXNOM; destino->nombre_alumnos[i]='\0', i++);
         printf("\t\t  Nombre-s :\t");
         getchar();
         gets(destino->nombre_alumnos);
         printf("\t\t  Apellido Paterno:\t");
         gets(destino->appaterno);
         printf("\t\t  Apellido Materno:\t");
         gets(destino->apmaterno);
        
       
      printf("\t\t  Edad:\t");
      scanf("%d",&destino->edad);
           if (destino->edad<=18){printf("Error Se requiere ser mayor de edad!\n\n");}
           else{
      printf("\t\t  Promedio:\t");
      scanf("%f",&destino->promedio);
           if (destino->promedio<=5){printf("Error Se requiere de un promedio APROBATORIO!\n\n");}
           else{
             for(i=0; i<MAXNOM; destino->direccion[i]='\0',i++);
             printf("\t\t  Direccion:\t");
             getchar();
             gets(destino->direccion);
             destino->status=1;}}}
     clave(destino,registroalumnos);//Funcion que genera la llave unica de identificacion
     fwrite(&destino,sizeof(destino),1,registroalumnos);//Escritura en disco
     fclose(registroalumnos);//Cierre de archivo
}

short int clave(struct datos *datosalumnos,FILE *registroalumnos){
     registroalumnos=fopen("archivito.bin" ,"ab+"); //apertura de archivo
     datosalumnos->key[0] =  datosalumnos->carrera[0];
     datosalumnos->key[1] =  datosalumnos->appaterno[0];
     datosalumnos->key[2] =  datosalumnos->appaterno[2];
     datosalumnos->key[3] =  datosalumnos->appaterno[1];
     datosalumnos->key[4] =  datosalumnos->apmaterno[1];
     datosalumnos->key[5] =  datosalumnos->nombre_alumnos[0];
     fwrite(&datosalumnos,sizeof(datosalumnos),1,registroalumnos);
    fclose(registroalumnos);
    return 0;
}



short int buscar_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin,struct datos origen,FILE *registroalumnos){
    /*Recorre la estructura del nodo mientras que su valor no sea nulo y ecuentre el valor */
    struct nodo_alumnos *aux=*inicio;
    int band=0;
    while (aux != NULL && band !=1)
    {
        desp_datos(aux->data,registroalumnos);
        band=1;
        aux = aux->next;
    }
    return 1;
}

short int busqueda(char id[],FILE *document){
    short int band=0;
    struct datos datasearch;
    int result;
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


void asignar_datos(struct datos *destino, struct datos origen)
/*Asignar los datos de una estructura origen a una estructura destino.
 Recibe: la estructura origen.
 Envia: la estructura destino */
{
    *destino=origen;
}




void desp_datos(struct datos origen,FILE *registroalumnos)
/*Desplegar los datos de una estructura
 Recibe: la estructura con los datos
 Envia: ---*/
{
    
    registroalumnos=fopen("archivito.bin" ,"rb");
    while (!feof(registroalumnos) ){
        fread(&origen,sizeof(origen), 1,registroalumnos);
    printf("\tID \t\t NOMBRE ALUMNO \t\t\t  CARRERA \t\t\t\t\tSEMESTRE \t\tGRUPO \t\t PROMEDIO  \t\t DIRECCION\n");
        printf(" %s \t %s %s %s\t\t%s \t\t\t\t\t\t%d \t\t\t\t %d \t\t\t %3f\t\t%s", origen.key, origen.nombre_alumnos, origen.appaterno, origen.apmaterno,origen.carrera,origen.semestre,origen.grupo,origen.promedio,origen.direccion);}
    printf("\n");
    fclose(registroalumnos);
}


short int comp_datos(struct datos origen1, struct datos origen2)
/*Comparar los datos del origen1 con origen1
 Recibe: las dos estructuras a comparar
 Envia: -1 origen1<origen2,
 0 origen1=origen2
 1 origen1>origen2
 */
{
    if(origen1.key<origen2.key)
        return -1;
    else if(origen1.key>origen2.key)
        return 1;
    else
        return(strcmp(origen1.nombre_alumnos, origen2.nombre_alumnos));
}



short int ins_ord_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin ,struct datos origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else
    {
        short int exito;
        if(!(*inicio))
        {
            exito=ins_ini_simple(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->data, origen) > 0)
            {
                exito=ins_ini_simple(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->data, origen) < 0)
                {
                    exito=ins_fin_simple(inicio,fin,origen);
                }
                else
                {
                    exito=ins_med_simple(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}

short int ins_ini_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos origen)
/*intertar por el inicio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*inicio && comp_datos((*inicio)->data, origen) < 0)
        return -1;
    else
    {
        struct nodo_alumnos *nuevo;
        nuevo=(struct nodo_alumnos *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            asignar_datos(&(nuevo->data), origen);
            nuevo->prev=NULL;
            nuevo->next=*inicio;
            if(*inicio!=NULL)
                (*inicio)->prev=nuevo;
            *inicio=nuevo;
            if(!(*fin))
                *fin=nuevo;
            return 1;
        }
    }
}

short int ins_med_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos origen)
/*intertar por el medio en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if (*fin == NIL)
        return 0;
    else if(*inicio == NIL)
        return 0;
    else if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(!(*inicio)->next)
        return -1;
    else if(comp_datos((*inicio)->data, origen) > 0)
        return -1;
    else if(comp_datos((*fin)->data, origen) < 0)
        return -1;
    else
    {
        struct nodo_alumnos *actual, *anterior, *nuevo;
        nuevo = (struct nodo_alumnos *)malloc(TAMNS);
        if(!nuevo)
            return 0;
        else
        {
            actual=*inicio;
            asignar_datos(&(nuevo->data),origen);
            nuevo->next=anterior->next;
            anterior->next=nuevo;
            nuevo->prev=anterior;
            return 1;
        }
    }
}

short int ins_fin_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos origen)
/*intertar por el final en una lista simplemente ligada
 Recibe: apuntador al inicio de la lista, datos a insertar
 Envia: 0=overflow, 1=exito*/
{
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else if(*fin && comp_datos((*fin)->data, origen) > 0)
        return -1;
    else
    {
        struct nodo_alumnos *nuevo;
        nuevo=(struct nodo_alumnos *)malloc(TAMNS);
        
        if(!(*inicio))
        {
            nuevo->prev=NIL;
            *inicio=nuevo;
        }
        else{
            
            asignar_datos(&(nuevo->data), origen);
            nuevo->next=NIL;
            while((*fin)->next!=NIL)
            {
                (*fin)=(*fin)->next;
            }
            (*fin)->next=nuevo;
            nuevo->prev=*fin;
            
            (*fin)=nuevo;
            
            
        }
        return 1;
        
    }
}
//////////////////////Funciones Eliminar////////////////////

short int eli_ord_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin ,struct datos *origen)
/*intertar ordenadamente
 Recibe: apuntador al inicio de la lista, datos a eliminar
 Envia: -1=error en parametros, 0=overflow, 1=exito*/
{
    
    struct nodo_alumnos *aux;
    aux=*inicio;
    
    if(!(*inicio) && *fin)
        return -1;
    else if(!(*fin) && *inicio)
        return -1;
    else
    {
        short int exito;
        if((*inicio)==*fin)
        {
            exito=eli_ini_simple(inicio,fin,origen);
        }
        else
        {
            if(comp_datos((*inicio)->data,*origen) == 0 && aux->data.key==origen->key)
            {
                exito=eli_ini_simple(inicio,fin,origen);
            }
            else
            {
                if(comp_datos((*fin)->data, *origen )==0 && aux->data.key==origen->key )
                {
                    exito=eli_fin_simple(inicio,fin,origen);
                }
                else
                {
                    exito=eli_med_simple(inicio,fin,origen);
                }
                
            }
        }
        return exito;
    }
}





short int eli_ini_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos *origen){
    
    struct nodo_alumnos *aux=*inicio;
    
    if(*inicio != *fin){
        *inicio = (*inicio)->next;
        (*inicio)->prev=NULL;
        
        if(!aux){
            return 1;
        }
    }else { free(*inicio);
        *inicio=NULL;
        free(*fin);
        *fin=NULL;}
    return 0;
}








short int eli_fin_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos *origen)
{
    struct nodo_alumnos *aux;
    aux=(*fin);
    
    (aux)->prev=NULL;
    asignar_datos(&(aux->data),*origen);
    free(aux);
    free(fin);
    return 2;
    
}




short int eli_med_simple(struct nodo_alumnos **inicio, struct nodo_alumnos **fin, struct datos *origen){
    struct nodo_alumnos *actual,*anterior;
    actual=(*inicio)->next;
    anterior=*inicio;
    
    while (actual!=NULL) {
        
        if(strcmp(actual->data.nombre_alumnos,origen->nombre_alumnos)==0 && actual->data.key == origen->key){
            anterior->next=anterior->next->next;
            actual->next=anterior->prev;
            asignar_datos(&(actual->data),*origen);
            free(actual);
            return 3;
        }else
            
            anterior=actual;
        actual=actual->next;
    }
    
    
    
    
    return 0;
}



