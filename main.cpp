#include <iostream>
#include "Lista.cpp"
#include "Lista.h"
int main() {
    Lista* newList = new Lista();

    newList->insertarAlInicio(2);
    newList->insertarAlInicio(2);
    newList->insertarAlInicio(4);
    newList->insertarAlInicio(5);
    newList->insertarAlInicio(5);
    newList->insertarAlInicio(7);
    newList->insertarAlInicio(8);
    newList->insertarAlInicio(9);
    newList -> mostrarLista();
    /*newList -> mostrarLista();
    //newList -> eliminar_duplicados();
    newList -> mostrarLista();
    newList -> sumaPromedioPares();
    //newList -> ordenarLista();
    newList -> mostrarLista();
    newList -> eliminar_duplicados();
    newList -> mostrarLista();
*/
    set <int> repetidos = newList -> mostrar_repetidos();
    for(const int &item: repetidos){
        cout<< "\n"<<item;
    }


    /*vector<int> repetidos = newList -> mostrar_repetidos();
    for (const int &item : repetidos) {
        cout << "\n" <<item;
    }*/



    /*newList -> calcularMenorMayor();
    newList -> sumaPromedioPares();
    newList -> sumaPromedioImpares();

    cout<<"Los elementos de la lista son: ";
    newList->mostrarLista();
    cout<<endl;

    newList ->buscarPosicion(11);
    newList -> ordenarLista();
    newList -> mostrarLista();
    newList -> mostrar_repetidos();



*/
}
