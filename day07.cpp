#include <bits/stdc++.h>

using namespace std;

int dir_size();

int linenum = 0;
vector<string> lines;
vector<int> dirs;

int main(int argc, char const *argv[]) {
    ifstream f("inputs/in7.txt");
    string ln;
    while (getline(f, ln)) lines.push_back(ln);
    f.close();

    int all = dir_size();

    /*
    int sum = 0;
    for (auto &&e : dirs)
        if (e <= 100000) sum += e;
    cout << sum;
    */

    int required = 30000000 - (70000000 - all);

    sort(dirs.begin(), dirs.end(), less<int>());
    for (auto &&e : dirs)
        if (e >= required) {
            cout << e;
            break;
        }

    return 0;
}

int dir_size() {
    int size = 0;
    for (; linenum < lines.size(); linenum++) {
        string ln = lines[linenum];
        if (ln[0] == 'd') continue;
        if (ln[2] == 'c') {
            if (ln[5] == '.') {
                return size;
            } else {
                linenum += 2;
                int subdir = dir_size();
                dirs.push_back(subdir);
                size += subdir;
            }
            continue;
        }
        size += stoi(ln);
    }

    return size;
}
