#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream f("inputs/in8.txt");
    vector<string> lines;
    string fln;
    while (getline(f, fln)) {
        lines.push_back(fln);
    }
    vector<string> lines2(lines);
    f.close();

    int visible = 2 * lines[0].length() + 2 * lines.size() - 4;
    for (int j = 1; j < lines.size() - 1; j++) {
        string &ln = lines[j];
        int max = ln[0] - '0';
        for (int i = 1; i < ln.length() - 2; i++) {
            if (ln[i] - '0' > max) {
                visible++;
                max = ln[i] - '0';
                ln[i] += 49;
                if (max == 9) break;
            }
        }
        max = ln[ln.length() - 1] - '0';
        for (int i = ln.length() - 2; i > 0; i--) {
            if (!isdigit(ln[i])) break;
            if (ln[i] - '0' > max) {
                visible++;
                max = ln[i] - '0';
                ln[i] += 49;
                if (max == 9) break;
            }
        }
    }

    for (int v = 1; v < lines[0].length() - 1; v++) {
        int max = lines[0][v] - '0';
        for (int i = 1; i < lines.size() - 1; i++) {
            if (isdigit(lines[i][v])) {
                if (lines[i][v] - '0' > max) {
                    visible++;
                    max = lines[i][v] - '0';
                    if (max == 9) break;
                }
            } else {
                if ((lines[i][v] - 49) - '0' > max) {
                    max = (lines[i][v] - 49) - '0';
                    if (max == 9) break;
                }
            }
        }
        max = lines[lines.size() - 1][v] - '0';
        for (int i = lines.size() - 2; i > 0; i--) {
            if (isdigit(lines[i][v])) {
                if (lines[i][v] - '0' > max) {
                    visible++;
                    max = lines[i][v] - '0';
                    if (max == 9) break;
                }
            } else {
                if ((lines[i][v] - 49) - '0' > max) {
                    max = (lines[i][v] - 49) - '0';
                    if (max == 9) break;
                }
            }
        }
    }

    int highscore = 0;
    for (int y = 1; y < lines2.size() - 1; y++) {
        for (int x = 1; x < lines[0].length() - 1; x++) {
            short cur = lines2[y][x] - '0';
            int u = 0, d = 0, l = 0, r = 0;
            do u++;
            while (y - u > 0 && lines2[y - u][x] - '0' < cur);
            do d++;
            while (y + d < lines2.size() - 1 && lines2[y + d][x] - '0' < cur);
            do l++;
            while (x - l > 0 && lines2[y][x - l] - '0' < cur);
            do r++;
            while (x + r < lines2[0].length() - 1 && lines2[y][x + r] - '0' < cur);

            int score = u * d * l * r;
            if (score > highscore) highscore = score;
        }
    }

    cout << visible << "\n";
    cout << highscore << "\n";
    return 0;
}
