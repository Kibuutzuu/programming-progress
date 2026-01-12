#include <iostream>
#include <stack>
#include <queue>

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *ant;

};

struct NodoLista {
    int dato;
    NodoLista* siguiente;
};

Nodo *CrearNodo(int num){
    Nodo *nuevonodo = new Nodo();
    nuevonodo -> dato = num;
    nuevonodo -> sig = nullptr;
    nuevonodo -> ant = nullptr;
    return nuevonodo;
}

void InsertarNodo(Nodo*&raiz, int numero){
    if (raiz == nullptr){
        Nodo *nuevonodo = CrearNodo(numero);
        raiz = nuevonodo;
    }else{
        if(numero < raiz->dato){
            InsertarNodo(raiz->ant, numero);
        }else if (numero > raiz->dato){
            InsertarNodo(raiz->sig, numero);
        } else{
            std::cout<<"Ese numero ya se encuentra en el arbol, por favor escoja otro"<<std::endl;
        }
    }
}

void InOrder(Nodo*raiz){
    if(raiz != nullptr){
        InOrder(raiz->ant);
        std::cout<<raiz->dato<<std::endl;
        InOrder(raiz->sig);
    }
}

void funcionprincipal(){
    Nodo *raiz = nullptr; //raiz del arbol
    int n;
    while (true){
        std::cout<<"Introduzca un numero, al introducir 0 este programa se detiene: ";
        std::cin>>n;
        if (n != 0){
            InsertarNodo(raiz, n);
        } else{
            break;
        }
    }

    InOrder(raiz);
}


void verificarexpresión(){
    std::stack <char> pila;
    std::string expresion;
    std::cout<<"dame una expresion matematica para verificar si está balanceada o no"<<std::endl;
    std::cout<<"-> ";
    getline(std::cin, expresion);

    for (int i = 0; i < expresion.length(); i++){
        if (expresion[i] == '('){
            pila.push('(');
        } else if (expresion[i] == ')'){
            if (pila.empty()){
                std::cout<<"Esta desbalanceada, hay un '(' de más"<<std::endl;
                break;
            }
            pila.pop();
        }
    }

    if (pila.empty()){
        std::cout<<"Felicidades!, tu expresion esta balanceada"<<std::endl;
    }else{
        std::cout<<"No esta balanceada"<<std::endl;
    }
}

void crearListaDesdeStack(std::stack<int>& pila, NodoLista* &cabeza) {
    NodoLista* actual = nullptr;

    while (!pila.empty()) {
        int datoor = pila.top();
        pila.pop();

        NodoLista* nuevo = new NodoLista();
        nuevo -> dato = datoor;
        nuevo -> siguiente = nullptr;

        if (cabeza == nullptr) {
            cabeza = nuevo;
            actual = nuevo;
        } else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }
    }
}

Nodo* minimoDesdeNodo(Nodo* n) {
    while (n && n->ant) n = n->ant;
    return n;
}

Nodo* borrarNodoArbol(Nodo* raiz, int v) {
    if (raiz == nullptr) return raiz;
    if (v < raiz->dato) raiz->ant = borrarNodoArbol(raiz->ant, v);
    else if (v > raiz->dato) raiz->sig = borrarNodoArbol(raiz->sig, v);
    else {
        if (raiz->ant == nullptr) { Nodo* t = raiz->sig; delete raiz; return t; }
        if (raiz->sig == nullptr) { Nodo* t = raiz->ant; delete raiz; return t; }
        Nodo* t = minimoDesdeNodo(raiz->sig);
        raiz->dato = t->dato;
        raiz->sig = borrarNodoArbol(raiz->sig, t->dato);
    }
    return raiz;
}

//para objeto

class Objeto{
    public: //esto siempre debe estar
    int año;
    std::string nombre;

    //constructores se hacen asi

    // Objeto(int a, std::string b){
    //     año = a;
    //     nombre = b;
    // }

    //comportamientos se hacen con void asi

    void presentarse(){
        std::cout<<"Soy "<<nombre<<" y tengo "<<año<<" años";
    }
}; // siempre con ;


int main(){
    //para crear un nodo de lista enlazada
    NodoLista *head = new NodoLista();
    //para recorrerla en una lista simple es Nodo*actual = head / while(actual != nullptr)

    //para crear un objeto
    Objeto objetoacrear;
    //para modificar un valor del objeto
    objetoacrear.año = 20;
    objetoacrear.nombre = "Joaquin";
    return 0;
}
