/**
 * ESERCIZI RICORSIVI:
 */

#include <iostream>
using namespace std;

/**
 * Esercizio REVERSE:
 * Si scriva una funzione ricorsiva reverse che inverta le cifre di un numero naturale n
 * preso come parametro (e.g., se l'input di reverse è il valore intero 5431, la funzione
 * dovrà ritornare l'intero 1345). Si pensi prima una soluzione iterativa e
 * successivamente quella ricorsiva. La funzione reverse può avere parametri aggiuntivi
 *
 * @param int
 * @return int
 */
int reverse(int, int);
int reverse(int);

/**
 *
 * @return
 */
bool is_inside(int[], int, int, int = 0);

int main() {
    int n = 1876;
    cout << "Numero originale: " << n << endl;
    cout << "Numero inveritto: " << reverse(n) << endl;

    int A[] = {3, 5, 1, 7, 3, 9, 7, 8, 2, 6};
    int item_to_search = 0;
    string res = (is_inside(A, item_to_search, (sizeof(A)/sizeof(A[0])))) ? "True" : "False";
    cout << item_to_search << " is inside the array ? " << res << endl;
    return 0;
}

int reverse(int n, int reversed) {
    if (n == 0) {
        return reversed;
    } else {
        int lastDigit = n % 10;
        reversed = reversed * 10 + lastDigit;
        return reverse(n / 10, reversed);
    }
}

int reverse(int n) {
    return reverse(n, 0);
}

bool is_inside(int A[], int e, int l, int i) {
    if (i == l)
        return false;
    if (A[i] == e)
        return true;
    else
        is_inside(A, e, l, i + 1);
}