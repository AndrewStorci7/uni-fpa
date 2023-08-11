#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int val;
    node* next;
};

/**
 * ESERCIZIO 1:
 * Scrivere una funzione hasZeroSum che prenda come parametri un array di numeri interi e la sua
 * lunghezza e ritorna true se esiste una sottosequenza nell’array la cui somma `e pari a zero, altrimenti la funzione ritorna
 * false. Per esempio, se l’array passato come parametro `e [2, 3, -2, 1, -2, 5], la funzione dovr`a ritornare true.
 *
 * @param int[]
 * @param int
 *
 * @return bool
 */

bool hasZeroSum(int a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int y = 0; y < size; y++) {
            if (a[i] + a[y] == 0)
                return true;
        }
    }
    return false;
}

/**
 * ESERCIZIO 2:
 * Scrivere una funzione removeDuplicates che, preso come parametro una stringa C-style str ritorna una nuova
 * stringa ottenuta eliminando tutti i caratteri duplicati da str.
 * I Scrivere una funzione main che legge da tastiera una stringa di massimo 50 caratteri, chiama la funzione removeDuplicates
 * passando come parametro la stringa letta ed infine stampa il risultato ritornato dalla chiamata alla funzione
 * removeDuplicates.
 *
 * @param char*
 *
 * @return char*
 */

char* removeDuplicates(char* str) {
    char* ret = new char[strlen(str)]();
    int i_ret = 0;
    for (int i = 0; i < strlen(str); i++) {
        int y = 0;
        bool add = true;
        while (ret[y] != '\0') {
            if (ret[y] == str[i]) {
                add = false;
                break;
            }
            y++;
        }
        if (add) {
            ret[i_ret] = str[i];
            i_ret++;
        }
    }
    return ret;
}

/**
 * ESERCIZIO 3:
 * Scrivere una funzione di nome concat con tipo di ritorno void che, presi come suoi parametri due
 * liste semplicemente concatenate l1 ed l2 i cui elementi hanno campo informazione di tipo int, concateni la lista l2 alla
 * lista l1. Ad esempio, se l1 = {1,7} e l2 = {5,9,12}, dopo la chiamata alla funzione concat passando come parametri
 * l1 ed l2, la lista l1 diventa {1,7,5,9,12}. Trattare in modo opportuno anche i casi in cui l1 e/o l2 siano liste vuote.
 * Si scriva inoltre il tipo struttura che modella una lista semplicemente concatenata.
 *
 * @param node*&
 * @param node*&
 * @param node*&
 *
 * @return node*&
 */

void add(node* &h, int x) {
    node* newNode = new node;
    newNode->val = x;
    newNode->next = h;
    h = newNode;
}

node* concat(node* &l1, node*&l2, node* &ret) {
    if (l1 == NULL && l2 == NULL)
        return ret;
    if (l1 != NULL) {
        add(ret, l1->val);
        concat(l1->next, l2, ret);
    } else if (l2 != NULL) {
        add(ret, l2->val);
        concat(l1, l2->next, ret);
    } else
        return ret;
}

void printNode(node* &h) {
    if (h == NULL) {
        cout << "Lista vuota";
        return;
    } else {
        cout << h->val << " -> ";
        printNode(h->next);
    }
}

int main() {
    int c = 0;
    do {
        cout << "\nScegli un esercizio dell'esame 30/06/2023:"
        << "\n\t1- bool hasZeroSum(int[], int) : Ritornare true se all'interno dell'array e' presente \n\t\t una coppia di numeri la quale somma fa zero"
        << "\n\t2- char* removeDuplicates(char*) : Rimuovere i caratteri duplicati in una stringa"
        << "\n\t3- node* concat(node*&, node*&, noed*&) : concatena due LinkedList semplici in una nuova"
        << "\n> ";
        cin >> c;
        switch (c) {
            case 1: {
                int a[] = {2, 3, -2, 1, -2, 5};
                for (int i = 0; i < 6; i++)
                    cout << a[i] << "  ";
                // string utilizzata solo per scoi visivi, non è stata utilizzata durante l'esercitazione
                string res = (hasZeroSum(a, 6)) ? "Vero" : "Falso";
                cout << endl << "E' presente una coppia la quale somma e' uguale a 0 ? " << res;
            }
                break;
            case 2: {
                char* str = new char[50]();
                bool valid = false;
                while (!valid) {
                    cout << "Inserisci una stringa: ";
                    cin >> str;
                    if (strlen(str) > 50) {
                        cout << "Error: strlen() > 50" << endl;
                        cin.ignore(10000, '\n');
                        cin.clear();
                    } else if (cin.fail()) {
                        cout << "Error" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    } else
                        valid = true;
                }
                cout << "Stringa originale: " << str
                << "\nStringa dopo removeDuplicates(): " << removeDuplicates(str) << endl;
            }
                break;
            case 3: {
                node* head1 = NULL;
                node* head2 = NULL;
                int a[] = {1, 7};
                int b[] = {5, 9, 12};
                for (int i = 0; i < 2; i++)
                    add(head1, a[i]);
                for (int i = 0; i < 3; i++)
                    add(head2, b[i]);
                cout << "LISTA 1:" << endl;
                printNode(head1);
                cout << "LISTA 2:" << endl;
                printNode(head2);
                cout << "LISTA CONCATENATA:" << endl;
                node* ret = NULL;
                ret = concat(head1, head2, ret);
                printNode(ret);
            }
                break;
            default:
                c = -1;
                break;
        }
    } while (c != -1);
    return 0;
}
