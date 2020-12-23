#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

int N;

bool bit(int i, int bit) {
    return (i >> bit) % 2;
}

int main() {
    cin >> N;
    pi cows[N];
    fori(i, N) cin >> cows[i].first >> cows[i].second;

    int total = 0;
    for (int i = 0; i < pow(2, N); i++) {

        int minX = INT_MAX, minY = INT_MAX, maxX = 0, maxY = 0;
        fori(j, N) {
            if (bit(i, j)) {
                pi c = cows[j];
                minX = min(minX, c.first);
                minY = min(minY, c.second);
                maxX = max(maxX, c.first);
                maxY = max(maxY, c.second);
            }
        }

        bool var = maxX - minX < maxY - minY; // whether variable distance is x
        int space = var ? (maxY - minY - maxX + minX) : (maxX - minX - maxY + minY);
        int varMin = (var ? minX : minY) - space;
        int varMax = (var ? maxX : maxY) + space;
        fori(j, N) {
            if (!bit(i, j)) {
                pi c = cows[j];
                if ((minY <= c.second && c.second <= maxY) && (minX <= c.first && c.first <= maxX)) {
                    goto end;
                }
                if (var) {
                    if (c.first >= varMin) {
                        varMin = c.first + 1;
                    } else if (c.first <= varMax) {
                        varMax = c.first - 1;
                    }
                } else {
                    if (c.second >= varMin) {
                        varMin = c.second + 1;
                    } else if (c.second <= varMax) {
                        varMax = c.second - 1;
                    }
                }
                if ((varMax - varMin) < (var ? maxY - minY : maxX - minX)) goto end;
            }
        }
        total++;
        end:;
    }
    cout << total;
    
    return 0;
}
