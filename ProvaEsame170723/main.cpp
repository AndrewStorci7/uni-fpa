#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int val;
    node* next;
};

/**
 * ESERCIZIO 1:
 * Scrivere una funzione getZeroSubsequences che prenda come parametri un array di numeri interi e
 * la sua lunghezza e ritorna il numero di sottosequenze nell’array la cui somma `e pari a zero. Per esempio, se l’array passato
 * come parametro `e [2, 3, -2, 1, -2, 5], la funzione dovr`a ritornare 1.
 *
 * @param int[]
 * @param int
 *
 * @return int
 */

bool is_inside(int x, int a[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] == x)
            return true;
    }
    return false;
}

int getZeroSubsequences(int a[], int size) {
     int ret = 0;                           // Valore di ritorno della funzione
     int* b = new int[size * 2]{-1};     // Array che contine gl'indici dei numeri la quale somma = 0
     for (int h = 0; h < size * 2; h++)
         b[h] = -1;
     int i_b = 0;                           // Indice per l'array b
     for (int i = 0; i < size; i++) {
         for (int y = 0; y < size; y++) {
             if (is_inside(a[y], b, size * 2))
                 continue;
             else if (a[i] + a[y] == 0) {
                 ret++;
                 b[i_b] = a[y];
                 i_b++;
             }
         }
     }
     return ret / 2;
 }



/**
 * ESERCIZIO 2:
 * Scrivere una funzione countUnique che, preso come parametro una stringa C-style str ritorna il numero di caratteri
 * unici presenti nella stringa. Per esempio, se la stringa `e "hello", la funzione dovr`a ritornare 3.
 * I Scrivere una funzione main che legge da tastiera una stringa di massimo 50 caratteri, chiama la funzione countUnique
 * passando come parametro la stringa letta ed infine stampa il risultato ritornato dalla chiamata alla funzione
 * countUnique. Nel caso in cui la lunghezza della stringa inserita dall’utente sia maggiore di 50 caratteri, la fun-
 * zione main deve ritornare -1.
 *
 * @param char*
 *
 * @return int
 */


int countUnique(char* str) {
    int ret = 0;       // Valore di ritorno della funzione
    int count = 0;     // Variabile contatore per ripetizioni carattere
    for (int i = 0; i < strlen(str); i++) {
        count = 0;
        for (int y = 0; y < strlen(str); y++) {
            if (str[i] == str[y])
                count++;
        }
        if (count == 1)
            ret++;
    }
    return ret;
}

/**
 * ESERCIZIO 3:
 * Scrivere una funzione che preso come argomento una lista semplicemente concatenata lst i cui
 * elementi hanno campo informazione di tipo int ritorni una nuova lista che contiene solamente gli elementi di lst
 * strettamente maggiori di zero. Ad esempio, se lst = {1,7, -2, 1, -3, 5}, la funzione dovr`a ritornare la lista {1, 7,
 * 1, 5}. Trattare in modo opportuno i casi in cui lst sia vuota. Si scriva inoltre il tipo struttura che modella una lista
 * semplicemente concatenata.
 *
 * @param node*&
 * @param node*&
 *
 * @return node*
 */

void addTop(node* &h, int x) {
    node* newNode = new node;
    newNode->val = x;
    newNode->next = h;
    h = newNode;
}

node* upperZero(node* &h, node* &r) {
    if (h == NULL || h == nullptr)
        return r;
    else if (h->val > 0) {
        addTop(r, h->val);
        upperZero(h->next, r);
    } else if (h->val <= 0)
        upperZero(h->next, r);
}

void printNode(node* &h) {
    if (h == NULL || h == nullptr) {
        cout << "Lista vuota" << endl;
        return;
    } else
        cout << h->val << " -> ";

    printNode(h->next);
}

int main() {
    int c = 0;
    do {
        cout << "Scegli un esercizio:\n"
            << "\t1- getZeroSubsequences()\n"
            << "\t2- countUnique()\n"
            << "\t3- upperZero()\n"
            << "> ";
        cin >> c;
        switch (c) {
            case 1: {
                int a[] = {2, 3, -2, 1, -2, 5};
                cout << "[ ";
                for (int i = 0; i < 6; i++)
                    cout << a[i] << " ";
                cout << "]" << endl;
                cout << getZeroSubsequences(a, 6) << endl;
            }
                break;
            case 2: {
                char* str = new char[50]{""};
                cout << "Inserisci una stringa di lunghezza inferiore o uguale a 50: \n";
                cin >> str;
                if (strlen(str) > 50)
                    return -1;
                cout << "La stringa " << str << " ha " << countUnique(str) << " caratteri unici\n";
            }
                break;
            case 3: {
                node* head = NULL;
                int a[6] = {1, 7, -2, 1, -3, 5};
                for (int i = 0; i < 6; i++)
                    addTop(head, a[i]);
                printNode(head);
                cout << endl;
                node* ret = NULL;
                ret = upperZero(head, ret);
                printNode(ret);
                cout << endl;
            }
                break;
            default:
                c = -1;
                break;
        }
    } while (c != -1);
    return 0;
}
