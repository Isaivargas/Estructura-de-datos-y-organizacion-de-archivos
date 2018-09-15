//VERSION 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOM 50

struct Agenda
{
    char clave[2];
    char nombre[MAXNOM];
    long int tel_casa;
    long int tel_cel;
    short int status;
};

// Funciones main
struct Agenda alta(void);

void main()
{
    struct Agenda A;
    int op;

    do
    {
        printf("\t\tMENU");
        printf("\n\t1. ALTA");
        printf("\n\t2. CONSULTA X CLAVE");
        printf("\n\t3. MODIFICA X CLAVE");
        printf("\n\t4. BORRAR X CLAVE");
        printf("\n\t5. REPORTE ORDENADO");
        printf("\n\t6. SALIR");
        printf("\n\t\nINGRESE LA OPCION DESEADA: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {    A=alta();
                break;
            }

            case 2:
            {
                break;
            }

            case 3:
            {
                break;
            }

            case 4:
            {
                break;
            }

            case 5:
            {
                break;
            }

            case 6:
            {
                printf("\nADIOS");
                break;
            }

            default:
            {
                printf("\nINGRESE UNA OPCION VALIDA");
                break;
            }
        }

    }while(op!=6);
}



// Funcion que recibe los datos a registrar en la Agenda
struct Agenda  alta(void){
    struct Agenda alta;
    int longitud;
do{
printf("CLAVE UNICA alumno:\t ");
fflush(stdin);
gets(alta.clave);
longitud=strlen(alta.clave);
}while(longitud>0);
do{
printf("Nombre del alumno:\t ");
gets(alta.nombre);
}while(alta.nombre!=NULL);
do {
printf("Telefono de casa:\t ");
scanf("%ld",alta.tel_casa);
}while(alta.tel_casa<8);
do{
printf("Telefono celular:\t ");
scanf("%ld",alta.tel_cel);
}while(alta.tel_cel);

};
