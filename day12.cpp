#include <bits/stdc++.h>

using namespace std;

vector<string> lines;

class Node {
   private:
    vector<Node> neighbors;

   public:
    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Node() : Node(-1, -1) {}

    int x;
    int y;

    auto get_neighbors() {
        if (!neighbors.size())
            for (auto e : {make_pair(x + 1, y), make_pair(x - 1, y), make_pair(x, y + 1), make_pair(x, y - 1)})
                if ((0 <= e.first && e.first < lines[0].length()) && (0 <= e.second && e.second < lines.size()) && (lines[e.second][e.first] <= get_letter() + 1))
                    neighbors.push_back(Node(e.first, e.second));
        return neighbors;
    }

    char get_letter() {
        return lines[y][x];
    }

    auto get_pair() {
        return make_pair(x, y);
    }

    auto keystr() {
        stringstream ss;
        ss << x << " " << y;
        return ss.str();
    }

    string to_string() {
        stringstream ss;
        ss << "(" << x << ", " << y << ") : " << get_letter();
        return ss.str();
    }

    auto operator==(Node other) {
        return x == other.x && y == other.y;
    }
};

int find_path(Node startpos, Node endpos) {
    queue<Node> frontier;
    frontier.push(startpos);
    map<pair<int, int>, Node> came_from;
    came_from[startpos.get_pair()] = Node();

    int found = 0;
    while (!frontier.empty()) {
        auto cur = frontier.front();
        frontier.pop();

        if (cur == endpos) {
            found = 1;
            break;
        }

        for (auto n : cur.get_neighbors()) {
            if (!came_from.count(n.get_pair())) {
                // cout << "\033[2J\033[1;1H" << endl;
                // char tmp = lines[n.y][n.x];
                // lines[n.y][n.x] = ' ';
                // for (auto l : lines) cout << l << '\n';
                // lines[n.y][n.x] = tmp;
                // usleep(0.01 * pow(10, 6));

                frontier.push(n);
                came_from[n.get_pair()] = cur;
            }
        }
    }
    if (found) {
        auto cur = endpos;
        vector<Node> path;
        while (!(cur == startpos)) {
            path.push_back(cur);
            cur = came_from[cur.get_pair()];
        }
        reverse(path.begin(), path.end());

        return path.size();
    } else {
        return INT_MAX;
    }
}

int main(void) {
    ifstream f("inputs/in12.txt");
    string fln;
    Node startpos;
    Node endpos;
    while (getline(f, fln)) {
        lines.push_back(fln);
        auto s = fln.find('S'), e = fln.find('E');
        if (s != string::npos) {
            startpos = Node(s, lines.size() - 1);
            lines[(int)(lines.size() - 1)][s] = 'a';
        }
        if (e != string::npos) {
            endpos = Node(e, lines.size() - 1);
            lines[(int)(lines.size() - 1)][e] = 'z';
        }
    }

    vector<int> lengths;
    for (int y = 0; y < lines.size(); y++) {
        for (int x = 0; x < lines[0].length(); x++) {
            if (lines[y][x] != 'a') continue;
            cout << "(" << x << ", " << y << ")\n";

            lengths.push_back(find_path(Node(x, y), endpos));
        }
    }

    cout << *min_element(lengths.begin(), lengths.end()) << '\n';
}
