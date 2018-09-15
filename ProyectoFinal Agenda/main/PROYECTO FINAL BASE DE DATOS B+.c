//VERSION 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNOM 50

struct agenda
{
    char clave[2];
    char nombre[MAXNOM];
    long int tel_casa;
    long int tel_cel;
    short int status;
};

void main()
{
    int op;

    do
    {
        printf("MENU\n");
        printf("\n1. ALTA");
        printf("\n2. CONSULTA X CLAVE");
        printf("\n3. MODIFICA X CLAVE");
        printf("\n4. BORRAR X CLAVE");
        printf("\n5. REPORTE ORDENADO");
        printf("\n6. SALIR");
        printf("\n\nINGRESE UNA OPCION: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {
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
