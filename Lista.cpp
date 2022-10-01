#include "Lista.h"
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

Node::Node() {
    this -> dato = NULL;
    this -> siguiente = nullptr;
}

Node::Node(int dato) {
    this -> dato = dato;
    this -> siguiente = nullptr;
}


Node *Node::getNext() {
    return this -> siguiente;
}

void Node::setNext(Node *siguiente) {
    this -> siguiente = siguiente;
}

int Node::getDato() {
    return this -> dato;
}

void Node::setDato(int dato) {
    this -> dato = dato;
}

Lista::Lista() {
    this -> cabeza = nullptr;
}

void Lista::insertarAlInicio(int dato) {
    Node* nuevaHead = new Node(dato);
    nuevaHead -> setNext(this -> cabeza);
    this -> cabeza = nuevaHead;
}

void Lista::insertarAlFinal(int dato) {
    Node* nuevo= new Node(dato);
    Node* aux;
    if (this->cabeza == nullptr){
        this->cabeza = nuevo;
    }
    else{
        aux= this-> cabeza;
        while (aux -> getNext() != nullptr){
            aux= aux->getNext();
        }
        aux->setNext(nuevo);
    }
    cout << "Elemento " << dato <<" agregado a la lista correctamente\n";
}

void Lista::mostrarLista() {
    Node* temp = this -> cabeza;

    if(temp == nullptr){
        cout<<"lista vacia"<<endl;
    }
    while (temp != nullptr){
        cout<<temp -> getDato()<< " -> ";
        if (temp -> getNext() == nullptr){
            cout<<"NULL";
            break;
        }
        temp = temp -> getNext();
    }
}

void Lista::buscarElemento(int busca) {
    int pos=0, cont=0;
    Node *lista= this->cabeza;
    while (lista!=nullptr){
        if(lista->getDato()!= busca){
            lista= lista->getNext();
            pos++;
        }
        else {
            cont ++;
            break;
        }
    }
    if (cont != 0) {
        cout << "\nEl elemento " << busca << " se encuentra en la posicion " << pos+1 << " de la lista" <<endl;
    }
    else {
        cout << "\nEl elemento " << busca<< " no se encuentra" << endl;
    }
}

void Lista::buscarPosicion(int pos) {
    int original=pos;
    Node* actual=this->cabeza;
    while (pos-1>0 && actual != nullptr){
        actual= actual->getNext();
        pos--;
    }
    if (pos!=1){
        cout << "No existe esa posicion" << endl;
    }
    else {
        cout << "El elemento de la posicion " << original << " es " << actual->getDato() << endl;
    }
}

void Lista::sumaPromedioPares() {
    int contador = 0;
    double suma = 0;
    Node* actual = this -> cabeza;
    while (actual != nullptr){
        if (actual->getDato() % 2 == 0){
            contador++;
            suma += actual -> getDato();
        }
        if (actual -> getNext() == nullptr) {
            break;
        }
        actual = actual -> getNext();
    }
    cout<<"Promedio pares: "<<suma/contador<<endl;
    cout<<"Suma pares: "<<suma<<endl;
}

void Lista::sumaPromedioImpares() {
    Node* temp = this -> cabeza;
    double suma = 0;
    double contador = 0;
    while(temp != nullptr){
        if(temp -> getNext() == nullptr){
            break;
        }
        if(temp -> getDato() % 2 != 0){
            contador++;
            suma += temp -> getDato();
        }
        temp = temp -> getNext();
    }
    cout<<"Promedio impares: "<<suma/contador<<endl;
    cout<<"Suma impares: "<<suma<<endl;
}


void Lista::calcularMenorMayor() {
    Node* temp = this -> cabeza;
    Node* temp1 = this -> cabeza;
    int menor = temp -> getDato();
    int mayor = temp -> getDato();
    while(temp != nullptr){
        if(temp ->getNext() == nullptr){
            break;
        }
        if(temp -> getNext() -> getDato() < menor){
            menor = temp -> getNext() -> getDato();
        }
        if(temp -> getNext() -> getDato() > mayor){
            mayor = temp -> getNext() -> getDato();
        }
        temp = temp -> getNext();
    }
    cout<<"Menor: "<<menor<<endl;
    cout<<"Mayor: "<<mayor<<endl;
}

void Lista::eliminarPorValor(int borrar) {
    Node* actual = this -> cabeza;
    Node* anterior = nullptr;
    if (actual->getDato()==borrar){
        this -> cabeza = actual -> getNext();
        cout<<"Elemento "<< borrar << " eliminado correctamente"<< endl;
    }
    else{
        while(actual != nullptr && actual->getDato()!=borrar){
            anterior = actual;
            actual = actual->getNext();
        }
        if (actual==nullptr){
            cout<<"El elemento no existe"<< endl;
        }
        else{
            anterior->setNext(actual->getNext());
            delete actual;
            cout<<"Elemento "<< borrar << " eliminado correctamente"<< endl;
        }
    }
}

void Lista::elimininarPosI(int posEliminar) {
    Node* actual= this -> cabeza;
    Node* anterior= nullptr;
    Node* siguiente = actual -> getNext();
    if(posEliminar == 1){
        this -> cabeza = siguiente;
    }
    else{
        while(posEliminar-1 > 0 && actual != nullptr){
            anterior = actual;
            actual = anterior -> getNext();
            posEliminar --;
        }
        anterior->setNext(actual->getNext());
        delete actual;
    }
}

void Lista::eliminar_duplicados() {
    set <int> repetidos;
    Node* actual = this -> cabeza;
    Node* anterior = nullptr;
    while(actual != nullptr){ //recorremos hasta el final de la lista
        if(repetidos.find(actual -> getDato()) != repetidos.end()){ //busca el valor hasta llegar al final del set y si lo encuentra:
            anterior -> setNext(actual -> getNext());
            delete actual;
        }
        else{//si no lo encuentra en el set, lo agrega al set
            repetidos.insert(actual -> getDato());
            anterior = actual;//
        }
        actual = anterior -> getNext();
    }
    cout<<"elementos repetidos eliminados correctamente"<<endl;
}


set <int> Lista::mostrar_repetidos() {
    priority_queue <int> queue1;
    set <int> sinrepetir;
    Node* actual = this -> cabeza;
    while(actual != nullptr){
        queue1.push(actual -> getDato());//inserta el dato en la queue
        if(actual -> getNext() == nullptr){
            break;
        }
        actual = actual -> getNext();
    }
    int temporal = queue1.top();
    queue1.pop();
    while(!queue1.empty()){
        if(temporal == queue1.top()){
            sinrepetir.insert(temporal);
        }
        temporal = queue1.top();
        queue1.pop();
    }
    return sinrepetir;
}

void Lista::ordenarLista() {
    Node *actual = this->cabeza;
    Node *aux = nullptr;
    int dato;
    while (actual != nullptr) {
        aux = actual->getNext();
            while (aux != nullptr) {
                if (actual->getDato() > aux->getDato()) {
                    dato = actual->getDato();
                    actual->setDato(aux->getDato());
                    aux->setDato(dato);
                }
            aux = aux->getNext();
        }

        actual = actual->getNext();
    }
    cout << "Lista ordenada correctamente" << endl;
}