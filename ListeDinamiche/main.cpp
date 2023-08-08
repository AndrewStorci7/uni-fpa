#include <iostream>
using namespace std;

struct node {
    int d;
    node* n;
};

void addTop(node*&, int);
void addBottom(node*, int);
node* concat(node*, node*, node*);
bool is_inside(node*, int);
void print(node*);

int main() {
    node* l = NULL;
    addTop(l, 7);
    addTop(l, 2);
    addTop(l, 2);
    addTop(l, 1);
    node* l2 = NULL;
    addTop(l2, 5);
    addTop(l2, 3);
    addTop(l2, 1);
    cout << "Lista 1: "; print(l);
    cout << "Lista 2: "; print(l2);
    node* r = NULL;
    concat(l, l2, r);
    print(r);
    return 0;
}

void addTop(node* &n, int i) {
    node* newN = new node;
    newN->d = i;
    newN->n = n;
    n = newN;
}

void print(node* n) {
    if (n->n == NULL) {
        cout << n->d << endl;
        return;
    } else {
        cout << n->d << " -> ";
        print(n->n);
    }
}

void addBottom(node* n, int i) {
    if (n == NULL) {
        addTop(n, i);
        return;
    }
    if (n->n == NULL) {
        node* r = new node;
        r->d = i;
        r->n = NULL;
        n->n = r;
    } else
        addBottom(n->n, i);
}

node* concat(node* f, node* s, node* r) {
    if (f->n == NULL && s->n == NULL)
        return r;
    else {
        if (f->d <= s->d) {
            if (!is_inside(r, f->d))
                addTop(r, f->d);
            return concat(f->n, s, r);
        } else {
            if (!is_inside(r, s->d))
                addTop(r, s->d);
            return concat(f, s->n, r);
        }
    }
}

bool is_inside(node* n, int i) {
    if (n == NULL)
        return false;
    if (n->d == i)
        return true;
    else if (n->n != NULL)
        is_inside(n->n, i);

    return false;
}