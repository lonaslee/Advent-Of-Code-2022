#include <bits/stdc++.h>

using namespace std;

#define Coord pair<int, int>
#define signum(n) ((n) == 0 ? 0 : (n) > 0 ? 1 \
                                          : -1)

void update_rope(Coord *rope) {
    int px = rope[0].first, py = rope[0].second;
    for (int i = 1; i < 10; i++) {
        Coord &knot = rope[i];
        if (abs(px - knot.first) == 2 && abs(py - knot.second) == 2) {
            knot.first += signum(px - knot.first);
            knot.second += signum(py - knot.second);
        } else if (abs(px - knot.first) == 2) {
            knot.second = py;
            knot.first += signum(px - knot.first);
        } else if (abs(py - knot.second) == 2) {
            knot.first = px;
            knot.second += signum(py - knot.second);
        } else {
            break;
        }
        px = knot.first;
        py = knot.second;
    }
}

int main(int argc, char const *argv[]) {
    ifstream f("inputs/in9.txt");
    vector<pair<char, int>> lines;
    string fln;
    while (getline(f, fln)) lines.push_back(pair<char, int>(fln[0], stoi(fln.substr(2))));
    f.close();

    set<Coord> walked = {Coord()};
    Coord rope[10];

    for (auto &&p : lines) {
        for (int t = 0; t < p.second; t++) {
            switch (p.first) {
                case 'U': {
                    rope[0].second++;
                    update_rope(rope);
                    walked.emplace(rope[9]);
                } break;
                case 'D': {
                    rope[0].second--;
                    update_rope(rope);
                    walked.emplace(rope[9]);
                } break;
                case 'R': {
                    rope[0].first++;
                    update_rope(rope);
                    walked.emplace(rope[9]);
                } break;
                case 'L': {
                    rope[0].first--;
                    update_rope(rope);
                    walked.emplace(rope[9]);
                } break;
            }
        }
    }

    cout << walked.size() << '\n';

    /*
    int hx = 0, hy = 0;
    int tx = 0, ty = 0;
    for (auto &&p : lines) {
        for (int i = 0; i < p.second; i++)
            switch (p.first) {
                case 'U': {
                    hy++;
                    if (abs(hy - ty) != 2) continue;
                    ty++;
                    tx = hx;
                    walked.emplace(pair<int, int>(tx, ty));
                } break;
                case 'D': {
                    hy--;
                    if (abs(hy - ty) != 2) continue;
                    ty--;
                    tx = hx;
                    walked.emplace(pair<int, int>(tx, ty));
                } break;
                case 'R': {
                    hx++;
                    if (abs(hx - tx) != 2) continue;
                    tx++;
                    ty = hy;
                    walked.emplace(pair<int, int>(tx, ty));
                } break;
                case 'L': {
                    hx--;
                    if (abs(hx - tx) != 2) continue;
                    tx--;
                    ty = hy;
                    walked.emplace(pair<int, int>(tx, ty));
                } break;
            }
    }

    cout << "\nsize: " << walked.size() << '\n';
    */

    return 0;
}
