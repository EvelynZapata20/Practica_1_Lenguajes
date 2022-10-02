#include <iostream>
#include "Lista.cpp"
#include "Lista.h"

using namespace std;

int main() {
    Lista* newList = new Lista();
    int option;
    cout << "°|    ------------------------------------------    |°" << endl;
    cout << "°|              BIENVENIDO AL PROGRAMA              |°" << endl;
    cout << "°|    ------------------------------------------    |°" << endl;
    cout << "\nInserte al menos un elemento a la lista para activar el menu " << endl;
    cout << "Insertar: ";
    int first;
    cin>>first;
    newList->insertarAlInicio(first);
    bool flag= true;
    do {
      newList->mostrarMenu();
      cout << "\nOpcion: ";
      cin>>option;

         if(option==1) {  //Inserta los elementos al inicio
            char next;
            do{
                cout<<"\nIngrese el numero que desea insertar"<<endl;
                int dato;
                cin>>dato;
                newList->insertarAlInicio(dato);
                cout<<"\nDesea agregar un nuevo dato(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option==2) { //Inserta elementos al final
            char next;
            do{
                cout<<"\nIngrese el numero que desea insertar"<<endl;
                int dato;
                cin>>dato;
                newList->insertarAlFinal(dato);
                cout<<"\nDesea agregar un nuevo dato(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
         }

        else if(option==3) {  //Muestra los elementos de la lista
            newList->mostrarLista();
        }

        else if(option==4) {
            char next;
            do{
                cout<<"\nIngrese el numero que desea buscar"<<endl;
                int dato;
                cin>>dato;
                newList->buscarElemento(dato);
                cout<<"\nDesea buscar otro elemento(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option==5) {
            char next;
            do{
                cout<<"\nIngrese la posicion que desea ver"<<endl;
                int dato;
                cin>>dato;
                newList->buscarPosicion(dato);
                cout<<"\nDesea ver otra posicion(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option==6) {
            char next;
            do{
                cout<<"\nIngrese el numero que desea eliminar"<<endl;
                int dato;
                cin>>dato;
                newList->eliminarPorValor(dato);
                cout<<"\nDesea eliminar otro elemento(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option==7) {
            char next;
            do{
                cout<<"\nIngrese la posicion que desea eliminar"<<endl;
                int dato;
                cin>>dato;
                newList->elimininarPos(dato);
                cout<<"\nDesea eliminar otra posicion(s/n): "<<endl;
                cin>>next;
            }
            while(next == 's' || next == 'S');
        }

        else if(option==8) {
            newList->sumaPromedioPares();
        }

        else if(option==9){
            newList->sumaPromedioImpares();
        }

        else if(option==10){
            newList->calcularMayor();
        }

         else if(option==11){
             newList->calcularMenor();
         }

        else if(option==12){
             set <int> repetidos = newList -> mostrarRepetidos();
             for(const int &item: repetidos){
                 cout<< "\n"<<item;
             }
        }

        else if(option==13){
            newList->eliminarDuplicados();
        }

        else if(option==14){
            newList->ordenarListaCreciente();
        }

         else if(option==15){
             newList->ordenarListaDecreciente();
         }

        else if(option==16){
            newList->invertirLista();
        }

         else if (option==17){
             flag=false;
             cout << "\n°|    ------------------------------------------    |°" << endl;
             cout << "°|                PROGRAMA FINALIZADO               |°" << endl;
             cout << "°|    ------------------------------------------    |°" << endl;
         }

        else {
            cout<<"El numero ingresado no es valido"<<endl;
        }

    } while (flag==true);

  }
