#include <iostream>
using namespace std;

class Semaforo {
public:
// Proprietà
    // bool acceso;
    int colore; // 0 -> Rosso, 1 -> Arancione, 3 -> Verde

// Metodi
    bool valid( int c ) {
        if ( c < 0 || c > 2 )
            return false;
        return true;
    }

    void cambioColore( int c ) {
        if ( valid(c) )
            this->colore = c;
        else {
            cout << "Colore invalido" << endl;
            this->colore = 0;
        }
    }

    void stampaSemaforo() {
        if ( colore == 0 )
            cout << "Rosso" << endl;
        else if ( colore == 1 )
            cout << "Arancione" << endl;
        else
            cout << "Verde" << endl;
    }
};

int main() {
    Semaforo s;
    Semaforo s2;
    Semaforo s3;

    s.cambioColore(1);
    s.stampaSemaforo();
    s2.cambioColore(2);
    s2.stampaSemaforo();
    s3.cambioColore(0);
    s3.stampaSemaforo();

    return 0;
}
