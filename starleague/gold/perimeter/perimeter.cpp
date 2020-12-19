#include <bits/stdc++.h>

#define fori(i, end) for(int i = 0; i < end; i++)
#define trav(i, a) for(auto& i : a)
#define point pair<int, int>

#define up 0
#define right 1
#define down 2
#define left 3

using namespace std;

int N;
set<point> field;
bool visitedStart;
int startX;
int startY;
int perimeter;

bool contains(int x, int y) {
    return field.find(point(x, y)) != field.end();
}

void trace(int x, int y, int dir) {
    if (x == startX && y == startY && dir == up) {
        if (visitedStart) {
            return;
        } else {
            visitedStart = true;
        }
    }
    perimeter++;
    if (dir == up) {
        if (contains(x - 1, y + 1)) {
            trace(x - 1, y + 1, left);
        } else if (contains(x, y + 1)) {
            trace(x, y + 1, up);
        } else {
            trace(x, y, right);
        }
    } else if (dir == right) {
        if (contains(x + 1, y + 1)) {
            trace(x + 1, y + 1, up);
        } else if (contains(x + 1, y)) {
            trace(x + 1, y, right);
        } else {
            trace(x, y, down);
        }
    } else if (dir == down) {
        if (contains(x + 1, y - 1)) {
            trace(x + 1, y - 1, right);
        } else if (contains(x, y - 1)) {
            trace(x, y - 1, down);
        } else {
            trace(x, y, left);
        }
    } else {
        if (contains(x - 1, y - 1)) {
            trace(x - 1, y - 1, down);
        } else if (contains(x - 1, y)) {
            trace(x - 1, y, left);
        } else {
            trace(x, y, up);
        }
    }
}

int main() {
    cin >> N;

    fori(i, N) {
        int x, y; cin >> x >> y;
        field.emplace(x, y);
    }

    trav(i, field) {
        if (i.first < startX || startX == 0) {
            startX = i.first;
            startY = i.second;
        }

    }

    trace(startX, startY, up);
    cout << perimeter;

    return 0;
}
