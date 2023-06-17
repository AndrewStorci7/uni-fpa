/**
 * LINKED LIST
 * - Ogni elemento è collegato al suo successore
 * - La sua dimensione può aumentare/diminuire a runtime
 * - Ogni nodo della lista contiene un dato (es: un intero) e un puntatore al suo successore
 * - Accesso sequenziale
 *
 * Formalmente una lista è:
 * - (Caso base) Una lista VUOTA
 * - (Caso ricorsivo) Un nodo seguito da una LISTA
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int dato;
    node* next;
};

void addAtTheBeginning( node*&, int );  // Aggiunta di un nuovo nodo in Testa
void addAtTheEnd( node*&, int );        // Aggiunta di un nuovo nodo in Coda
void printRec( node* );                 // Stampa della lista in maniera Ricorsiva
void printIt( node* );                  // Stampa della lista in maniera Iterativa

int main() {

    node *list = NULL;
    /**
     * Aggiunta di un nuovo nodo in TESTA
     */
    addAtTheBeginning(list, 11);
    addAtTheBeginning(list, 42);
    addAtTheBeginning(list, 7);
    addAtTheBeginning(list, 4);
    addAtTheBeginning(list, 1);
    printRec(list);

    /**
     * Aggiunta di un nuovo nodo in CODA
     */
    addAtTheEnd(list, 34);
    printRec(list);

    addAtTheBeginning(list, 9);
    printRec(list);
    return 0;
}

void addAtTheBeginning( node* &n, int i ) {
    node* new_node = new node;
    new_node->dato = i;
    new_node->next = n;
    n = new_node;
}



void printRec( node* n ) {
    cout << n->dato << " ";
    if ( n->next == NULL )
        cout << endl;
    else
        printRec(n->next);
}

void printIt( node* l ) {
    if ( l == NULL )
        cout << "Empty list" << endl;
    else {
        while ( l != NULL ) {
            cout << l->dato << " ";
            l = l->next;
        }
        cout << endl;
    }
}

void addAtTheEnd( node* &n, int i ) {
    if ( n == NULL )
        addAtTheBeginning(n, i);
    else {
        if ( n->next != NULL )
            addAtTheEnd(n->next, i);
        else {
            node* new_node = new node;
            new_node->dato = i;
            new_node->next = NULL;
            n->next = new_node;
        }
    }
}