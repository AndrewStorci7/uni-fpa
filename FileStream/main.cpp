#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node {
    int d;
    node* n;
};

void addTop(node*, int&);

int main() {
    ifstream f1;
    f1.open("interi.txt");
    if (f1.fail()) {
        cout << "Impossibile aprire il file!" << endl;
        return -1;
    }

    char c = f1.get();
    node head;
    char s[10] = "";
    while (!f1.eof()) {
        if (c == ' ') {

        }
        c = f1.get();
    }

    return 0;
}

void addTop(node* h, int& x) {
    node n;
    n.d = x;
    n.n = h;
}