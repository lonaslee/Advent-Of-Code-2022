#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define Coord pair<int, int>
#define xof(c) ((c).first)
#define yof(c) ((c).second)

class Cave {
   private:
    int lowest = -1;

    void line_to(Coord a, Coord b) {
        if (xof(a) == xof(b)) {
            if (yof(a) > yof(b)) {
                Coord tmp = a;
                a = b;
                b = tmp;
            }
            for (int y = yof(a); y <= yof(b); y++) grid[y][xof(a)] = '#';
        } else {
            if (xof(a) > xof(b)) {
                Coord tmp = a;
                a = b;
                b = tmp;
            }
            for (int x = xof(a); x <= xof(b); x++) grid[yof(a)][x] = '#';
        }
    }

   public:
    Cave() {
        for (int i = 0; i < 200; i++) grid.push_back(string(1000, '.'));
        grid[0][500] = '+';
    }

    vector<string> grid;

    void add_line(vector<Coord> points) {
        Coord prev = points[0];
        for (auto point : points) {
            line_to(point, prev);
            prev = point;
            lowest = max(lowest, yof(point));
        }
    }

    void add_floor() {
        grid[lowest + 2] = string(1000, '#');
    }

    Coord sand_fall() {
        Coord sand(500, 0);
        while (1) {
            if (at(xof(sand), yof(sand) + 1) == '.') {
                yof(sand)++;
                if (yof(sand) == grid.size() - 1) return sand;
            } else if (at(xof(sand) - 1, yof(sand) + 1) == '.') {
                xof(sand)--;
                yof(sand)++;
            } else if (at(xof(sand) + 1, yof(sand) + 1) == '.') {
                xof(sand)++;
                yof(sand)++;
            } else {
                set(sand, 'o');
                return sand;
            }
        }
    }

    char at(int x, int y) { return grid.at(y).at(x); }
    char at(Coord coord) { return at(xof(coord), yof(coord)); }
    void set(int x, int y, char c) { grid[y][x] = c; }
    void set(Coord coord, char c) { set(xof(coord), yof(coord), c); }

    string to_string() {
        string str;
        for (int i = 0; i < 70; i++) str += grid[i].substr(400, 150) + '\n';
        return str;
    }
};

int main(void) {
    ifstream f("inputs/in14.txt");
    vector<vector<Coord>> lines;
    string ln;
    while (getline(f, ln)) {
        vector<Coord> coords;
        for (int i = 0; i < ln.length(); i++)
            if (!isdigit(ln[i]) && ln[i] != ' ') ln[i] = ' ';
        stringstream ss(ln);
        int x, y;
        while (!ss.eof()) {
            ss >> x >> y;
            coords.emplace_back(x, y);
        }
        lines.push_back(coords);
    }
    Cave cave;
    for (auto ln : lines) cave.add_line(ln);
    cave.add_floor();

    int i;
    for (i = 1;; i++) {
        Coord c = cave.sand_fall();
        // if (yof(c) == cave.grid.size() - 1) break;
        if (c == Coord(500, 0)) break;
    }
    cout << i << '\n';
}
