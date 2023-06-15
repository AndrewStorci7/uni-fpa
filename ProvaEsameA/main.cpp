#include <iostream>
using namespace std;

/* FUNZIONA */
void reverse( int[], int );
void print( int[], int );

int main() {
    int array[] = { 1, 2, 3, 4, 5 };
    print( array, 5 );
    reverse( array, 5 );
    print( array, 5 );
    return 0;
}

void reverse( int A[], int l ) {
    int tmp = 0;
    for ( int i = 0; i < (l / 2); i++ ) {
        tmp = A[i];
        A[i] = A[(l - 1) - i];
        A[(l - 1) - i] = tmp;
    }
}

void print( int A[], int l ) {
    for ( int i = 0; i < l; i++ )
        cout << A[i] << " ";
    cout << endl;
}