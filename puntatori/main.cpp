#include <iostream>
using namespace std;

struct Persona {
    char n[35];
    char c[55];
    int e;
};

void initF();
void initS();
void printPersona(Persona&);
int calcolatrice(int, int, int);

int main() {
    int c = 0;
    do {
        cout << "\nScegli una tipologia di esercizi: "
             << "\n\t1-  Puntatori"
             << "\n\t2-  Funzioni"
             << "\n> ";
        cin >> c;
        switch (c) {
            case 1: {
                initF();
            }
                break;
            case 2: {
                initS();
            }
                break;
        }
    } while (c > 0 && c < 5);
    return 0;
}

void initF() {
    int c = 0;
    do {
        cout << "\nScegli un esercizio per vedere il risultato: "
             << "\n\t1-  int V [10] = {5, 11, 20, 17, 8, 4, 9, 13, 5, 12};\n"
             << "\t\tint i = 5;\n"
             << "\t\tcout << *V + *(V + i + 1) + 1;"
             << "\n\t2-  int x = 5 , y = 5;\n"
             << "\t\tint * p1 = &x;\n"
             << "\t\tint * p2 = &y;\n"
             << "\t\t*p1 = *p2 + 1;\n"
             << "\t\tcout << x << \" \" << y << endl;"
             << "\n\t3-  int a1 [3] = {2, 7, 8};\n"
             << "\t\tint a2 [3] = {3 ,5 ,9};\n"
             << "\t\tcout << *(a1 + 1) + *a2;"
             << "\n> ";
        cin >> c;
    } while (c > 0 && c < 4);
    switch (c) {
        case 1: {
            int V [10] = {5 ,11 ,20 ,17 ,8 ,4 ,9 ,13 ,5 ,12};
            int i = 5;
            cout << *V + *(V + i + 1) + 1;
        }
            break;
        case 2: {
            int x = 5 , y = 5;
            int* p1 = &x;
            int* p2 = &y;
            *p1 = *p2 + 1;
            cout << x << " " << y << endl;
        }
            break;
        case 3: {
            int a1 [3] = {2 ,7 ,8};
            int a2 [3] = {3 ,5 ,9};
            cout << *(a1 + 1) + *a2;
        }
            break;
    }
}

void initS() {
    int c1 = 0;
    do {
        cout << "Scegli un esercizio: "
             << "\n\t1-  Calcolatrice"
             << "\n\t2-  Stampa Persona"
             << "\n>> ";
        cin >> c1;
        cin.ignore(10000000, '\n');
    } while (c1 < 1 || c1 > 2);
    switch (c1) {
        case 1: {
            cin.ignore(100000, '\n');
            int f = 0, n = 0, n1 = 0;
            cout << "\n---- CALCOLATRICE ----"
                 << "\n1- CALCOLA QUADRATO"
                 << "\n2- SOMMA"
                 << "\n3- FATTORIALE"
                 << "\nc> ";
            cin >> f;

            if (f == 1) {
                cout << "Inserisci la base: ";
                cin >> n;
                cout << "Inserisci l'esponente: ";
                cin >> n1;
            } else if (f == 2) {
                cout << "Inserisci il primo numero: ";
                cin >> n;
                cout << "Inserisci il secondo numero: ";
                cin >> n1;
            } else if (f == 3) {
                cout << "Inserisci il numero: ";
                cin >> n;
            }
            cout << "Risultato: " << calcolatrice(n, n1, f) << endl;
        }
            break;
        case 2: {
            Persona p = {"Andrea", "Storci", 21};
            printPersona(p);
        }
            break;
    }
}

void printPersona(Persona &p) {
    cout << "\nPersona {"
         << "\n\tNome: " << p.n
         << "\n\tCognome: " << p.c
         << "\n\tEtà: " << p.e
         << "\n}" << endl;
}

int calcolatrice(int n, int n2, int f) {
    int r = 0;
    switch (f) {
        case 1: {
            // QUADRATO
            r = 1;
            while (n2 > 0) {
                r *= n;
                --n2;
            }
        }
            break;
        case 2:
            // SOMMA
            r = n + n2;
            break;
        case 3: {
            // FATTORIALE
            r = 1;
            for (int i = 1; i <= n; i++)
                r *= i;
        }
            break;
    }
    return r;
}