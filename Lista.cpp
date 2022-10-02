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

void Lista::mostrarMenu(){
    cout << "\nIngrese 0 para mostrar el menu" << endl;
    char mostrar;
    cin>>mostrar;
    if (mostrar=='0') {
        cout << "\n°|    ------------------------------------------    |°" << endl;
        cout << "°|       ELIJA UNA DE LAS SIGUIENTES OPCIONES       |°" << endl;
        cout << "°|    ------------------------------------------    |°" << endl;
        cout << "°|          1. INSERTAR ELEMENTO Al INICIO          |°" << endl;
        cout << "°|           2. INSERTAR ELEMENTO Al FINAL          |°" << endl;
        cout << "°|               3. MOSTRAR ELEMENTOS               |°" << endl;
        cout << "°|                4. BUSCAR ELEMENTO                |°" << endl;
        cout << "°|                5. BUSCAR POSICION                |°" << endl;
        cout << "°|               6. ELIMINAR ELEMENTO               |°" << endl;
        cout << "°|               7. ELIMINAR POSICION               |°" << endl;
        cout << "°|          8. MOSTRAR SUMA PROMEDIO PARES          |°" << endl;
        cout << "°|         9. MOSTRAR SUMA PROMEDIO IMPARES         |°" << endl;
        cout << "°|                 10. MOSTRAR MAYOR                |°" << endl;
        cout << "°|                 11. MOSTRAR MENOR                |°" << endl;
        cout << "°|          12. MOSTRAR ELEMENTOS REPETIDOS         |°" << endl;
        cout << "°|         13. ELIMINAR ELEMENTOS DUPLICADOS        |°" << endl;
        cout << "°|          14. ORDENAR DE MANERA CRECIENTE         |°" << endl;
        cout << "°|         15. ORDENAR DE MANERA DECRECIENTE        |°" << endl;
        cout << "°|                   16. INVERTIR                   |°" << endl;
        cout << "°|                    17. SALIR                     |°" << endl;
        cout << "° -------------------------------------------------- °" << endl;
    }
    else {
        cout<<"\nCaracter no valido" << endl;
        return mostrarMenu();
    }
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
        cout<<"Lista vacia"<<endl;
    }
    else {
        cout << "Los elementos de la lista son: " <<endl;
        while (temp != nullptr) {
            cout << temp->getDato() << " -> ";
            if (temp->getNext() == nullptr) {
                cout << "NULL";
                break;
            }
            temp = temp->getNext();
        }
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
    cout<<"La suma total de numeros pares es: "<<suma<<endl;
    cout<<"El promedio de los numeros pares es: "<<suma/contador<<endl;
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
    cout<<"La suma total de numeros impares es: "<<suma<<endl;
    cout<<"El promedio de los numeros impares es: "<<suma/contador<<endl;
}

void Lista::calcularMenor() {
    Node* temp = this -> cabeza;
    int menor = temp -> getDato();
    while(temp != nullptr){
        if(temp ->getNext() == nullptr){
            break;
        }
        if(temp -> getNext() -> getDato() < menor){
            menor = temp -> getNext() -> getDato();
        }
        temp = temp -> getNext();
    }
    cout<<"El numero menor es: "<<menor<<endl;
}

void Lista::calcularMayor() {
    Node* temp = this -> cabeza;
    int mayor = temp -> getDato();
    while(temp != nullptr){
        if(temp ->getNext() == nullptr){
            break;
        }
        if(temp -> getNext() -> getDato() > mayor){
            mayor = temp -> getNext() -> getDato();
        }
        temp = temp -> getNext();
    }
    cout<<"\n El numero mayor es: "<<mayor<<endl;
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

void Lista::elimininarPos(int posEliminar) {
    Node* actual= this -> cabeza;
    Node* anterior= nullptr;
    Node* siguiente = actual -> getNext();
    int original=posEliminar;
    if(posEliminar == 1){
        this -> cabeza = siguiente;
        cout<<"Posicion "<< original << " eliminada correctamente"<< endl;
    }
    else{
        while(posEliminar-1 > 0 && actual != nullptr){
            anterior = actual;
            actual = anterior -> getNext();
            posEliminar --;
        }
        if(posEliminar>1){
            cout<<"La posicion no existe"<< endl;
        }
        else {
            anterior->setNext(actual->getNext());
            delete actual;
            cout << "Posicion " << original << " eliminada correctamente" << endl;
        }
    }
}

void Lista::eliminarDuplicados() {
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
    cout<<"Elementos duplicados eliminados correctamente\n"<<endl;
}

void Lista::ordenarListaCreciente() {
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
    cout << "Lista ordenada crecientemente\n" << endl;
}

void Lista::ordenarListaDecreciente(){
    Node *actual = this->cabeza;
    Node *aux = nullptr;
    int dato;
    while (actual != nullptr) {
        aux = actual->getNext();
        while (aux != nullptr) {
            if (actual->getDato() < aux->getDato()) {
                dato = actual->getDato();
                actual->setDato(aux->getDato());
                aux->setDato(dato);
            }
            aux = aux->getNext();
        }

        actual = actual->getNext();
    }
    cout << "Lista ordenada decrecientemente\n" << endl;
}

void Lista::invertirLista() {
    Lista* auxList = new Lista();
    Node* actual = this->cabeza;
    while (actual != nullptr) {
        Node* auxHead = new Node(actual->getDato());
        auxHead -> setNext(auxList -> cabeza);
        auxList -> cabeza = auxHead;
        actual=actual->getNext();
    }
    Node* nuevo = auxList->cabeza;
    Node* actual2 = this->cabeza;
    while (nuevo!= nullptr) {
        actual2->setDato(nuevo->getDato());
        nuevo= nuevo->getNext();
        actual2=actual2->getNext();
    }
    cout << "Lista invertida correctamente\n" << endl;
}

set <int> Lista::mostrarRepetidos() {
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
