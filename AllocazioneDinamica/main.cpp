/**
 * PROBLEMA:
 * memorizzare in un array dinamico una serie indefinita di interi
 * positivi inseriti dall’utente (inserimento termina quando l’utente digita -1). L’array
 * inizialmente contiene 5 elementi.
 *
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void resize(int*, int&);
void printArrayDinamic(int*, int, int = 0);
bool is_inside(vector<int>, int&, int = 0);

/*
 * Prova
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int* _cnt = 0;
    int* _c   = 0;
public:
    int numComponents(ListNode* head, vector<int> nums) {
        if (head != nullptr && head != NULL) {
            if (is_inside(nums, head->val))
                _c + 1;
            else
                (*_c >= 1) ? _cnt + 1, _c = 0 : _c = 0;
        } else
            return *_cnt;

        return numComponents(head->next, nums);
    }
};


// Complexity Worst Case: O(n)
// Complexity Avarage Case: O(n)
// Complexity Best Case: O(1)
bool is_inside(vector<int> A, int& v, int _i) {
    if (_i >= A.size())
        return false;
    if (A[_i] == v)
        return true;
    else
        return is_inside(A, v, _i + 1);
}

int main() {
    vector<int> v = {0, 1, 3};
    Solution s;
    ListNode l = ListNode(3);
    ListNode l1 = ListNode(2, &l);
    ListNode l2 = ListNode(1, &l1);
    ListNode l3 = ListNode(0, &l2);
    cout << s.numComponents(&l3, v) << endl;
    /*
    int dim = 5;
    int* A = new int[dim]();
    int n = 0, _i = 0, _c = 0;
    while (n != -1) {
        // cin.ignore(1000000, '\n');
        cout << "Insert a integer (-1 to quit): ";
        cin >> n;
        _c++;
        if (_c > dim)
            resize(A, dim);

        A[_i] = n;
        _i++;
    }
    --_i;
    printArrayDinamic(A, dim);
     */
    return 0;
}

void resize(int* A, int& d) {
    int* cpy = new int[d * 2]();
    for (int i = 0; i < d; i++)
        cpy[i] = A[i];

    A = cpy;
    d *= 2;
    cout << "New DIM: " << d << endl;
    delete []A;
}

void printArrayDinamic(int* A, int d, int i) {
    if (i == 0)
        cout << "Array [" << A[i];
    else if (i < d - 1)
        cout << ", " << A[i];
    else if (A[i] == -1) {
        cout << "]" << endl;
        return;
    }
    printArrayDinamic(A, d, i + 1);
}
