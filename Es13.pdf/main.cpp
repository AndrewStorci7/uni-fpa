#include <iostream>
#include <cstdlib>
#define RANGE 255
using namespace std;

void print_array(int*, int, int);
void print_matrix(int**, int, int);
void countingSort(int*, int);
void searchOccurs(int*, int, int*, int);
bool is_inside(int*, int, int, int);
int* concat(int*, int, int*, int);
void init_dinamic_matrix(int**, int, int);
void init_dinamic_m_cin(int**, int, int);
int** sum_two_matrix(int**, int**, int, int, int, int);
int* find_occur(int**, int, int);

int main() {
    int c = 0;
    do {
        cout << "Scegli l'esercizio: \n"
             << "\t1- Esercizio 1: Chiedere all’utente la lunghezza di un array di interi\n"
             << "\t\tLeggere uno alla volta gli interi\n"
             << "\t\tVerificare che l’array sia ordinato in modo crescente, ovvero che ciascun\n"
             << "\t\tnumero sia minore o uguale del successivo"
             << "\n\t2- Esercizio 2: Chiedere all’utente x ed y (entrambi >=0), la lunghezza di due array a1 ed a2\n"
             << "\t\tLeggere uno alla volta gli elementi da inserire in a1 ed a2\n"
             << "\t\tTrovare l’intersezione tra a1 ed a2 e stamparne gli elementi"
             << "\n\t3- Esercizio 3: Prendere due array di lunghezza x ed y (definiti all’interno del programma,\n"
             << "\t\tnon da input) e creare un terzo array che ne rappresenti la concatenazione,\n"
             << "\t\tovvero che sia formato dagli elementi del primo array seguito dagli elementi\n"
             << "\t\tdel secondo array"
             << "\n\t4- Esercizio 4: Realizzare una matrice una matrice 10x10 che contenga le tabelline dall’1 al 10"
             << "\n\t5- Esercizio 5: Date due matrici 4×4 calcolarne la somma (la somma tra matrici si calcola\n"
             << "\t\tsommando i contenuti delle celle nella stessa posizione) ed è a sua volta una\n"
             << "\t\tmatrice 4x4"
             << "\n\t6- Esercizio 6: Leggere i valori di una matrice nxm e verificare se all’interno delle righe sue\n"
             << "\t\trighe ci sono valori che si ripetono, riportando poi il risultato per ciascuna riga"
             << "\n> ";
        cin >> c;
        switch (c) {
            case 1: {
                int l = 0;
                cout << "Inserire la lunghezza della'array: ";
                cin >> l;
                cin.ignore(100000, '\n');
                int* A = new int[l]();
                for (int i = 0; i < l; i++) {
                    cout << "Posizione dell'array " << i << ": ";
                    cin >> A[i];
                }
                countingSort(A, l);
                print_array(A, 0, l);
            }
            break;
            case 2: {
                int x = 0, y = 0, n = 0;
                bool v = false;
                while (!v) {
                    cout << "Giocatore " << n << " inserisci la lunghezza del tuo array: ";
                    cin >> x;
                    if (x > 0 )
                        v = true;
                    else if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                    }
                }
                int* A = new int[x]();
                for (int i = 0; i < x; i++) {
                    cout << "Posizione " << i << ": ";
                    cin >> A[i];
                }
                v = false;
                while (!v) {
                    cout << "Giocatore " << ++n << " inserisci la lunghezza del tuo array: ";
                    cin >> y;
                    if (y > 0 )
                        v = true;
                    else if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100000, '\n');
                    }
                }
                int* B = new int[y]();
                for (int i = 0; i < y; i++) {
                    cout << "Posizione " << i << ": ";
                    cin >> B[i];
                }
                searchOccurs(A, x, B, y);
            }
            break;
            case 3: {
                int* A = new int[3]();
                A[0] = 2; A[1] = 3; A[2] = 4;
                print_array(A, 0, 3);
                int* B = new int[2]();
                B[0] = 8; B[1] = 4;
                print_array(B, 0, 2);
                int* C = concat(A, 3, B, 2);
                cout << "Concat A e B" << endl;
                print_array(C, 0, 5);
            }
            break;
            case 4: {
                int** M = new int*[10]();
                init_dinamic_matrix(M, 10, 10);
                print_matrix(M, 10, 10);
            }
            break;
            case 5: {
                int** Ma = new int*[4]();
                cout << "Inizializza la prima matrice: \n";
                init_dinamic_m_cin(Ma, 4, 4);
                int** Mb = new int*[4]();
                cout << "Inizializza la seconda matrice: \n";
                init_dinamic_m_cin(Mb, 4, 4);
                int** Mr = sum_two_matrix(Ma, Mb, 4, 4, 4, 4);
                cout << "Result: \n";
                print_matrix(Mr, 4, 4);
            }
            break;
            case 6: {
                int** M = new int*[4]();
                cout << "Inizializzazione della matrice: \n";
                init_dinamic_m_cin(M, 5, 4);
                find_occur(M, 5, 4);
            }
            break;
        }
    } while(c > 6 || c < 1);
    return 0;
}

void countingSort(int* A, int l) {
    int* B = new int[l]();
    int count[RANGE + 1] = {};
    for (int i = 0; A[i]; ++i)
        ++count[A[i]];
    for (int i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (int i = 0; A[i]; ++i) {
        B[count[A[i]] - 1] = A[i];
        --count[A[i]];
    }
    for (int i = 0; A[i]; ++i)
        A[i] = B[i];
}

void print_array(int* A, int i, int l) {
    if (i >= l) {
        cout << " ]" << endl;
        return;
    }

    if (i == 0)
        cout << "Array [ " << A[i];
    else
        cout << ", " << A[i];

    print_array(A, i + 1, l);
}

void searchOccurs(int* A, int _a, int* B, int _b) {
    int m = (_b > _a) ? _b : _a;
    int* C = new int[m]();
    int _i = -1;
    for (int i = 0; i < _a; i++) {
        for (int y = 0; y < _b; y++) {
            if (A[i] == B[y]) {
                if (!is_inside(C, 0, m, A[i]))
                    C[++_i] = A[i];
            }
        }
    }
    print_array(C, 0, m);
}

bool is_inside(int* A, int s, int e, int f) {
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (A[m] == f)
            return true;
        if (A[m] < f)
            s = m + 1;
        else
            e = m - 1;
    }
    return false;
}

int* concat(int* A, int _a, int* B, int _b) {
    int* C = new int[_a + _b]();
    for (int i = 0; i < _a; i++)
        C[i] = A[i];
    int y = _a - 1;
    for (int i = 0; i < _b; i++) {
        C[++y] = B[i];
    }
    return C;
}

void init_dinamic_matrix(int** M, int row, int col) {
    for (int i = 0; i < row; i++) {
        M[i] = new int[col]();
        for (int y = 0; y < row; y++)
            M[i][y] = (i + 1) * (y + 1);
    }
}

void init_dinamic_m_cin(int** M, int r, int c) {
    for (int i = 0; i < c; i++) {
        M[i] = new int[c]();
        for (int y = 0; y < r; y++) {
            M[i][y] = rand() % 10;
            // cout << "Posizione [" << i << "][" << y << "]: ";
            // cin >> M[i][y];
        }
    }
    print_matrix(M, r, c);
}

void print_matrix(int** M, int r, int c) {
    for (int i = 0; i < c; i++) {
        for (int y = 0; y < r; y++)
            cout << M[i][y] << "\t";
        cout << endl;
    }
}

int** sum_two_matrix(int** A, int** B, int _ra, int _ca, int _rb, int _cb) {
    int** C = new int*[_ca]();
    for (int i = 0; i < _ca; i++) {
        C[i] = new int[_ra]();
    }
    for (int i = 0; i < _ca && i < _cb; i++) {
        for (int y = 0; y < _ra && y < _rb; y++)
            C[i][y] = A[i][y] + B[i][y];
    }
    return C;
}

int* find_occur(int** M, int r, int c) {
    int* R = new int[r * c]();
    int _r = 0, _c = 0;
    // int _t = M[0][0];
    int count = 0;
    int _i = 0;
    for (int i = 0; i < c; i++) {
        for (int y = 0; y < r; y++) {
            if (M[_r][_c] == M[i][y])
                count++;
        }
        (count > 1) ? R[_i] = M[_r][_c] : count = 0;
        
    }
    print_array(R, 0, r * c);
    return R;
}