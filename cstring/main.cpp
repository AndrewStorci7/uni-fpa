/**
 * CSTRING
 * <cstring>
 */

#include <iostream>
#define MAX_STR 100
#define MAX_IGN 1000000
using namespace std;

int countVowels(char[]);
void codifyString(char[]);

int main() {
    int c = 0;
    do {
        cout << "Scegli un esercizio:"
             << "\n\t1- Esercizio 1: Data in input una stringa , calcolare e stampare il numero di vocali presenti ins s"
             << "\n\t2- Esercizio 2: Codifica di una frase: si scriva un programma che legga una frase da tastiera lunga al\n"
             << "\t\tpiù 100 caratteri. Il programma deve\n"
             << "\t\t• Stampare la frase letta\n"
             << "\t\t• Costruire una codifica della frase tale che:\n"
             << "\t\t• ogni vocale della frase è seguita dalla lettera ‘f’ (se la vocale è minuscola) oppure\n"
             << "\t\t‘F’ (se la vocale è maiuscola)"
             << "\n> ";
        cin >> c;
        switch (c) {
            case 1: {
                cin.ignore(MAX_IGN, '\n');
                char s[MAX_STR] = "";
                cout << "Insert a string: ";
                cin.getline(s, MAX_STR, '\n');
                cout << "Number of vowels inside of '" << s << "': "
                     << countVowels(s) << endl;
            }
            break;
            case 2: {
                cin.ignore(MAX_IGN, '\n');
                char s[] = "";
                cout << "Insert a string: ";
                cin.getline(s, MAX_STR, '\n');
                codifyString(s);
            }
            break;
        }
    } while(c <= 0 || c > 3);
    return 0;
}

int countVowels(char s[]) {
    int c = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            c++;
        ++i;
    }
    return c;
}

void codifyString(char s[]) {
    cout << "String not crypted: " << s << endl;
    char r[MAX_STR] = "";
    int i = 0, y = -1;
    while (s[i] != '\0') {
        r[++y] = s[i];
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            r[++y] = 'F';
        else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            r[++y] = 'f';
        ++i;
    }
    cout << "String crypted: " << r << endl;
}