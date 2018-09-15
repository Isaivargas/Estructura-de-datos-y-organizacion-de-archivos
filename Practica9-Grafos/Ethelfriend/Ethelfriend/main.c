
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int numerodecalificaciones,calificacion[100];
    int i,opcion=0;
    
    srand (time(NULL));
    
    while(opcion<2){
        cout <<"Introduce la opcion deseada"<<"\n";
        cout <<"1.-Calificaciones Par o impar"<<"\n"<<"2.-SALIR"<<"\n";
        cin >>opcion;
        switch(opcion){
                
            case 1:
                cout << "Introduce el numero de materias:"<<"\t";
                cin >>numerodecalificaciones;
                
                for(i=0; i<numerodecalificaciones; i++){
                    calificacion[i]= rand() % 100 + 1;
                }
                
                cout <<"| Calificaiones |"<<endl;
                for(i=0; i<numerodecalificaciones; i++){
                    if(calificacion[i]%2==0){
                        cout <<"|" <<"  Si....."<<calificacion[i]<<"    |"<< endl;
                    }else{
                        cout <<"|" <<"  No....."<<calificacion[i]<<"    | "<< endl;
                    }
                }
                cout << "\n\n";
                break;
                
            default: cout <<"HASTA LUEGO =D "<<endl;
                
                
        }
    }
    return 0;
}

