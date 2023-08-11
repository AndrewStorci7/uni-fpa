#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node {
    int d;
    node* n;
};

void addTop(node*&, int);
void addBottom(node*&, int);
void printNode(node*&);
bool denode(node*&, node*&, int);
bool denodeBottom(node*&, node*&);
bool denodeTop(node*&);
void readFile(ifstream&, node*&, char[]);
void clearCString(char[]);
bool is_insideIT(node*&, int);
bool is_insideRC(node*&, int);
bool is_ordered_asc(node*&, int);
void orderlist(node*&);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);
//void countingSort(int*, int, int);
int countOccurency(node*&, int, int);
char* trim(char[], int);

int main() {
    int c = 0;
    do {
        cout << "Scegli un esercizio:\n"
            << "\t1- Liste\n"
            << "\t2- Esercizio File stream:\n"
            << "\t\t- Scrivere un programma che legga un file di interi e li inserisce uno per volta in una\n"
               "\t\t  lista (inserimento in testa). Una volta creata, stampare la lista\n"
               "\t3- Esercizio Liste:\n"
               "\t\t- Scrivere una funzione che prende in input una lista e un valore e controlla se il valore è contenuto\n"
               "\t\t  nella lista (versione iterativa e ricorsiva)"
               "\n\t4- Esercizio Liste:"
               "\n\t\t- Scrivere una funzione che prende in input una lista e determina se è ordinata in maniera crescente"
            << "\t-1 for quit\n"
            << "> ";
        cin >> c;
        switch (c) {
            case 1: {
                cout << "\nIn questo esercizio sono state create le varie funzioni per le liste:\n"
                    << "\t1- addTop(node*&, int) : "
                    << "\n\t\tDescrizione: aggiunge in testa un nuovo nodo"
                    << "\n\t\tParams: [node*&, int]"
                    << "\n\t\tReturn: void"
                    << "\n\t2- addBottom(node*&, int) : "
                    << "\n\t\tDescrizione: aggiunge in coda in maniera ricorsiva \n\t\til dato passato come parametro"
                    << "\n\t\tParams: [node*&, int]"
                    << "\n\t\tReturn: void"
                    << "\n\t3- denode(node*&, node*&, int) : "
                    << "\n\t\tDescrizione: elimina l'elemento passato come parametro \n\t\tin qualsiasi posizione della lista"
                    << "\n\t\tParams: [node*&, node*&, int]"
                    << "\n\t\tReturn: bool {true if exist, false if not}"
                    << "\n\t4- denodeTop(node*&) : "
                    << "\n\t\tDescrizione: elimina l'elemento in testa"
                    << "\n\t\tParams: [node*&]"
                    << "\n\t\tReturn: bool"
                    << "\n\t5- denodeBottom(node*&, node*&) : "
                    << "\n\t\tDescrizione: elimina l'elemento in coda"
                    << "\n\t\tParams: [node*&, node*&]"
                    << "\n\t\tReturn: bool"
                    << "\n\t6- printNode(node*&) : "
                    << "\n\t\tDescrizione: stampa la lista"
                    << "\n\t\tParams: [node*&]"
                    << "\n\t\tReturn: void"
                    << "\n\nEcco un esempio:\n";
                node* n;
                cout << "addTop() : 1" << endl;
                addTop(n, 1);
                cout << "addTop() : 5" << endl;
                addTop(n, 5);
                cout << "addTop() : 10" << endl;
                addTop(n, 10);
                printNode(n);
                cout << "addBottom() : 8" << endl;
                addBottom(n, 8);
                cout << "addBottom() : 3" << endl;
                addBottom(n, 3);
                printNode(n);
                cout << "denodeTop() : 10" << endl;
                cout << denode(n, n, 10) << endl;
                cout << "denode() : 8" << endl;
                cout << denode(n, n, 8) << endl;
                cout << "denodeBottom() : 3" << endl;
                cout << denode(n, n, 3) << endl;
                printNode(n);
            }
                break;
            case 2: {
                node* n = NULL;
                ifstream f1;
                readFile(f1, n, "interi.txt");
                printNode(n);
            }
                break;
            case 3: {
                node* h = NULL;
                for (int i = 0; i < 10; i++)
                    addTop(h, rand() % 31);
                printNode(h);
                cout << "\nIterative:"
                    << "\n4 is inside ? " << is_insideIT(h, 4) << endl;
                cout << "\nRecursive:"
                     << "\n10 is inside ? " << is_insideRC(h, 10) << endl;
            }
                break;
            case 4: {
                node* n = NULL;
                for (int i = 0; i < 8; i++)
                    addBottom(n, i);
                printNode(n);
                char s[5] = "";
                (is_ordered_asc(n, n->d)) ? strcpy(s, "True") : strcpy(s, "False");
                cout << "Is ordered asc ? " << s << endl;

            }
                break;
            case 5: {
                node* n = NULL;
                for (int i = 0; i < 10; i++)
                    addTop(n, rand() % 31);
                printNode(n);
                orderlist(n);
                printNode(n);
            }
                break;
            case 6: {
                node* n = NULL;
                for (int i = 0; i < 10; i++)
                    addTop(n, rand() % 11);
                printNode(n);
                cout << "Occurency of 4: " << countOccurency(n, 4, 0) << endl;
            }
                break;
            default:
                c = -1;
                break;
        }
    } while(c != -1);
    return 0;
}

void addTop(node* &h, int x) {
    node* newNode = new node;
    newNode->d = x;
    newNode->n = h;
    h = newNode;
}

void addBottom(node* &h, int x) {
    if (h == NULL)
        addTop(h, x);
    else if (h->n == NULL) {
        node* newNode = new node;
        newNode->d = x;
        newNode->n = NULL;
        h->n = newNode;
    } else
        addBottom(h->n, x);
}

void printNode(node* &h) {
    if (h == NULL)
        cout << "Lista vuota!" << endl;
    else if (h->n == NULL)
        cout << h->d << endl;
    else {
        cout << h->d << " -> ";
        printNode(h->n);
    }
}

bool denode(node* &h, node* &p, int x) {
    if (h == NULL)
        return false;
    else if (h == p && h->d == x)
        return denodeTop(h);
    else if (h->d == x) {
        node* t = h;
        if (t->n != NULL) {
            p->n = t->n;
            delete t;
            return true;
        } else
            return denodeBottom(h, p);
    } else if (h->n == NULL && h->d != x) {
        cout << "Elem Not Found" << endl;
        return false;
    } else
        denode(h->n, h, x);
}

bool denodeBottom(node* &h, node* &p) {
    node* d = h;
    p->n = NULL;
    delete d;
    return true;
}

bool denodeTop(node* &h) {
    if (h == NULL)
        return false;
    else {
        node* d = h;
        h = d->n;
        delete d;
        return true;
    }
}

void readFile(ifstream &f, node* &h, char s[]) {
    f.open(s);
    if (f.fail()) {
        cout << "Error: Impossibile aprire il file!" << endl;
        return;
    } else {
        char c = f.get();
        char c1[10] = "";
        int i = 0;
        while (!f.eof()) {
            if (c == '\n') {
                addTop(h, stoi(c1));
                clearCString(c1);
                c1[i] = '\0';
                i = 0;
            } else {
                c1[i] = c;
                ++i;
            }
            c = f.get();
        }
    }
}

void clearCString(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = 0;
        i++;
    }
}

bool is_insideIT(node* &h, int x) {
    if (h == NULL)
        return false;
    node* c = h;
    while (c->n != NULL && c->d == x) {
        if (c->d == x) {
            delete c;
            return true;
        }
        c = c->n;
    }
    return false;
}

bool is_insideRC(node* &h, int x) {
    if (h == NULL || (h->n == NULL && h->d != x))
        return false;
    else if (h->d == x)
        return true;
    else
        is_insideRC(h->n, x);
}

bool is_ordered_asc(node* &h, int x) {
    if (h == NULL)
        return false;
    if (h->n == NULL && h->d >= x)
        return true;
    else if (h->d >= x)
        is_ordered_asc(h->n, h->d);
    else
        return false;
}

void orderlist(node* &h) {
    int i = 0;
    int* a = new int[10]();
    node* c = h;
    node* r = h;
    while (c != NULL) {
        a[i] = c->d;
        c = c->n;
        ++i;
    }
    delete c;
    mergeSort(a, 0, 9);
    i = 0;
    while (r != NULL) {
        r->d = a[i];
        ++i;
        r = r->n;
    }
    delete r;
}

// DA RIVEDERE
void merge(int arr[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int leftArr[len1], rightArr[len2];
    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = start;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void countingSort(int* a, int k, int n) {
    int b[n], c[k + 1];
    for (int i = 0; i <= k; i++)
        c[i] = 0;
    for (int j = 0; j < n; j++)
        c[a[j]]++;
    for (int i = 1; i < k + 1; i++)
        c[i] += c[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
}

int countOccurency(node* &h, int x, int c) {
    if (h == NULL)
        return c;
    else if (h->d == x)
        c++;
    countOccurency(h->n, x, c);
}

char[] trim(char s[], ) {
    return "Ciao";
}