/**
 * PROVA ESAME: FONDAMENTI DI PROGRAMMAZIONE A
 *
 * ESERCIZIO 1:
 *  Scrivere una funzione reverse con tipo di ritorno void che, presi come parametri un array di interi a e la sua dimensione length,
 *  inverta, l'ordine degli elementi dell'array a. Per esempio se l'array a è [1, 5, 3, 2, 8],
 *  dopo la chiamata a funzione reverse, l'array sarà [8, 2, 3, 5, 1].
 *
 * ESERCIZIO 2:
 *  · Scrivere una funzione trim che, presi come parametri una stringa C-style str e un carattere c, ritorna una nuova
 *    stringa ottenuta eliminando tutte le occorrenze del carattere c.
 *  · Scrivere una funzione main che legge da tastiera una stringa di massimo 100 caratteri, chiama la funzione trim
 *    passando come parametro la stringa letta e il carattere ’a’, ed infine stampa il risultato ritornato dalla chiamata
 *    alla funzione trim
 *
 * ESERCIZIO 3:
 *  Scrivere una funzione di nome union che, presi come suoi parametri due liste concatenate semplici
 *  l1 ed l2 i cui elementi hanno campo informazione di tipo int, ritorni come risultato l’unione delle due liste, ovvero una
 *  nuova lista contenente tutti gli elementi delle liste l1 e l2 senza ripetizioni. Ad esempio, se l1 = 1 → 2 → 2 → 7
 *  e l2 = 1 → 3 → 5, la chiamata a funzione union(l1, l2) ritorner`a la lista 1 → 2 → 7 → 3 → 5. Gestire in modo
 *  opportuno i casi in cui l1 e/o l2 sono vuote.
 */

#include <iostream>
#include <cstring>
#define MAX_STR 100
#define MAX_IGN 1000000
using namespace std;

struct node {
    int d;
    node* n;
};

void reverse(int[], int);
void print(int[], int);
char* trim(char[], char);
node* unione(node*&, node*&, node*&);
void print_node(node*&);


int main() {
    cout << "-------------- ESERCIZIO 1 --------------" << endl;
    bool v = false;
    int A[] = {1, 5, 3, 2, 8};
    print(A, 5);
    reverse(A, 5);
    print(A, 5);

    cout << "-------------- ESERCIZIO 2 --------------" << endl;
    char* s = new char[MAX_STR]();
    char* r = new char[MAX_STR]();
    while (!v) {
        cout << "Inserisci una stringa: ";
        cin.getline(s, MAX_STR, '\n');
        if (cin.fail() || strlen(s) > MAX_IGN) {
            cin.clear();
            cin.ignore(MAX_IGN, '\n');
        } else
            v = true;
    }
    cout << "Before TRIM: " << s << endl;
    if (v)
        r = trim(s, 'a');
    cout << "After TRIM: " << r << endl;

    cout << "-------------- ESERCIZIO 3 --------------" << endl;
    // TODO

    return 0;
}

void reverse(int A[], int l) {
    int t = A[0];
    for (int i = 0; i < l / 2; i++) {
        t = A[i];
        A[i] = A[(l - 1) - i];
        A[(l - 1) - i] = t;
    }
}

void print(int A[], int l) {
    for (int i = 0; i < l; i++)
        cout << A[i] << " ";
    cout << endl;
}

char* trim(char* str, char c) {
    char* r = new char[strlen(str)]();
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != c) {
            r[j] = str[i];
            j++;
        }
    }
    return r;
}

void print_node(node* &n) {
    if (n->n == NULL)
        return;
    cout << n->d << " -> ";
    print_node(n->n);
}

node* unione(node* &l1, node* &l2, node* &r) {
    if (l1 == NULL || l2 == NULL)
        return r;
    if (l1->d > l2->d) {
        r->d = l2->d;
        r->n = NULL;
        unione(l1->n, l2, r->n);
    } else if (l2->d > l1->d) {
        r->d = l1->d;
        r->n = NULL;
        unione(l1, l2->n, r->n);
    } else if (l2->d == l1->d)
        unione(l1->n, l2->n, r);
    return r;
}