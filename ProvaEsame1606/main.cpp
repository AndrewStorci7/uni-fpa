#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int val;
    node* next;
};

int mostFrequent(int[], int);
char* noVowels(char*);
void remove(node*&, int);
void printNode(node*&);
void addTop(node*&, int);
void removeOnTop(node*&);
void removeOnBottom(node*&, node*&);

int main() {
    cout << "------------------ ESERCIZIO 1 ------------------" << endl;
    int a[20];
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 21;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "The most frequent element is: " << mostFrequent(a, 20) << endl;

    cout << "\n------------------ ESERCIZIO 2 ------------------" << endl;
    char* str = new char[20]();
    str = "AEIhjseoalksi";
    char* ret = noVowels(str);
    cout << "Stringa originale: " << str << endl;
    cout << "Stringa modificata: " << ret << endl;

    cout << "\n------------------ ESERCIZIO 3 ------------------" << endl;
    node* head = NULL;
    for (int i = 0; i < 20; i++)
        addTop(head, rand() % 11);
    printNode(head);
    cout << endl;
    remove(head, 4);
    printNode(head);
    cout << endl;
    return 0;
}

int mostFrequent(int a[], int s) {
    int n = 0; // Elemento con più frequenza nell'array
    int c = 0; // Conteggio globale
    for (int i = 0; i < s; i++) {
        int c_i = 0; // Conteggio locale al for
        for (int y = 0; y < s; y++) {
            if (a[i] == a[y])
                c_i++;
        }
        if (c_i > c) {
            c = c_i;
            n = a[i];
        }
    }
    return n;
}

char* noVowels(char* str) {
    char* r = new char[strlen(str)]();
    int y = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
            && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            r[y] = str[i];
            y++;
        }
    }
    return r;
}

void remove(node* &l, int e) {
    if (l == NULL || l == nullptr)
        return;
    else {
        node* cpy = l;
        node* prev = l;
        while (cpy != NULL || cpy != nullptr) {
            if (cpy == prev && cpy->val > e) {
                removeOnTop(cpy);
                prev = cpy;
                cpy = cpy;
            } else if (cpy->val > e) {
                node* del = cpy;
                prev->next = del->next;
                prev = cpy;
                cpy = cpy->next;
                // delete del;
            } else if (cpy->next == NULL) {
                removeOnBottom(cpy, prev);
                prev = cpy;
                cpy = cpy->next;
            } else {
                prev = cpy;
                cpy = cpy->next;
            }
        }
        l = cpy;
        delete cpy;
        delete prev;
    }
}

void printNode(node* &h) {
    if (h == NULL)
        cout << "Lista vuota!" << endl;
    else if (h->next == NULL)
        cout << h->val << endl;
    else {
        cout << h->val << " -> ";
        printNode(h->next);
    }
}

void addTop(node* &h, int x) {
    node* n = new node;
    n->val = x;
    n->next = h;
    h = n;
}

void removeOnTop(node* &h) {
    if (h == NULL)
        return;
    else {
        node* d = h;
        h = d->next;
        delete d;
    }
}

void removeOnBottom(node* &h, node* &p) {
    node* d = h;
    p->next = NULL;
    delete d;
}