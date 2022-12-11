#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    fstream f("inputs/in10.txt");
    vector<int> ops;
    string fln;
    while (getline(f, fln)) ops.push_back(fln == "noop" ? 0 : stoi(fln.substr(5)));
    f.close();

    vector<int> strengths;

    int reg = 1;
    int cycles;
    int i;
    int addxing = 0;
    stringstream ss;
    for (i = 0, cycles = 1; i < ops.size(), cycles <= 240; cycles++) {
        if ((cycles - 20) % 40 == 0) strengths.push_back(reg * cycles);

        int cursor_pos = (cycles % 40) - 1;
        ss << ((cursor_pos == reg || cursor_pos == reg - 1 || cursor_pos == reg + 1) ? '#' : '.');

        if (cycles % 40 == 0) ss << '\n';

        if (ops[i] == 0) {
            i++;
        } else {
            if (addxing) reg += ops[i++];
            addxing = !addxing;
        }
    }

    cout << accumulate(strengths.begin(), strengths.end(), 0);
    cout << '\n'
         << ss.str();

    return 0;
}
