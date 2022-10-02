#ifndef LEN_LISTA_H
#define LEN_LISTA_H

#include <set>
#include <vector>
#include "iostream"
#include "string"
using namespace std;

class Node{
private:
    int dato;
    Node* siguiente;
public:
    Node();
    Node(int dato);
    void setDato(int dato);
    void setNext(Node* siguiente);
    int getDato();
    Node* getNext();
};

class Lista {
private:
    Node* cabeza;
public:
    Lista();
    void mostrarMenu();
    void insertarAlInicio(int dato);
    void insertarAlFinal(int dato);
    void mostrarLista();
    void buscarElemento(int busca);
    void buscarPosicion(int pos);
    void sumaPromedioPares();
    void sumaPromedioImpares();
    void calcularMenor();
    void calcularMayor();
    void eliminarPorValor(int borrar);
    void elimininarPos(int num);
    void eliminarDuplicados();
    set <int> mostrarRepetidos();
    void ordenarListaCreciente();
    void ordenarListaDecreciente();
    void invertirLista();
};


#endif //LEN_LISTA_H
