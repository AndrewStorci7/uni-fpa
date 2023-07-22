#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int d;
    node* n;
};

int maxRicorsive(int[], int, int, int);

int main() {
    int A[7] = {2, 5, 7, 1, 9, 7, 5};
    int n = 543214123123;
    cout << "Max of Array: " << maxRicorsive(A, 0, 0, 7) << endl;
    cout << "Size of " << n << ": " <<  << endl;
    return 0;
}

int maxRicorsive(int A[], int i, int t, int l) {
    if (i == l)
        return t;
    else
        t = (A[i] > t) ? A[i] : t;
    maxRicorsive(A, i + 1, t, l);
}

int reverseRicorsive(int n, int i) {
    if(n >= 10)
        reverseRicorsive(n / 10, );

    int digit = n % 10;
}
/*
int prova(int n) {
    for (int i = 0; i < (8*sizeof(int)-1) * log10(2); i++)
        n.;
}*/