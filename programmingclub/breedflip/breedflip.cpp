#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
}

int main() {
    setIO();
    cin >> n >> a >> b;
    int flips = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i] && a[i-1] != b[i-1]) {
            flips++;
        }
    }
    if (a[n-1] != b[n-1]) {
        flips++;
    }
    cout << flips;

    return 0;
}