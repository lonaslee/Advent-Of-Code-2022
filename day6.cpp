#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string inp;
    ifstream f("inputs/in6.txt");
    getline(f, inp);
    f.close();

    /*
    char a = inp[0], b = inp[1], c = inp[2], d = inp[3];
    for (int i = 4; i < inp.length(); i++) {
        char ch = inp[i];
        /*
        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            cout << "==> " << i << "\n";
            cout << "==> " << a << b << c << d << "\n";
            break;
        }
        a = b;
        b = c;
        c = d;
        d = ch;
    }
    */

    string ft = inp.substr(0, 14);
    for (int i = 14; i < inp.length(); i++) {
        for (int k = 0; k < ft.length(); k++) {
            char c = ft[k];
            for (int j = k + 1; j < ft.length(); j++)
                if (c == ft[j]) goto cont;
        }
        cout << i;
        break;
    cont:
        ft = inp.substr(i - 13, 14);
    }
    return 0;
}
