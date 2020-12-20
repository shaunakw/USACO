#include <bits/stdc++.h>

#define fori(n) for(int i = 0; i < n; i++)

using namespace std;

int cows[3];

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    auto i = cows + 3;
    
    cin >> cows[0] >> cows[1] >> cows[2];
    sort(cows, cows + 3);

    if (cows[2] - cows[1] == 1 && cows[1] - cows[0] == 1) {
        cout << 0;
    } else if (cows[2] - cows[1] == 2 || cows[1] - cows[0] == 2) {
        cout << 1;
    } else {
        cout << 2;
    }

    cout << endl << max(cows[2] - cows[1], cows[1] - cows[0]) - 1;
    
    return 0;
}
