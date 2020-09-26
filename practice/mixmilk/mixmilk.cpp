#include <bits/stdc++.h>

#define fori(n) for(int i = 0; i < n; i++)

using namespace std;

int N = 3;
int buckets[3];
int milk[3];

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    fori(N) cin >> buckets[i] >> milk[i];

    fori(100) {
        int b1 = i % 3;
        int b2 = (b1 + 1) % 3;
        int total = milk[b1] + milk[b2];
        milk[b2] = min(buckets[b2], total);
        milk[b1] = total - milk[b2];
    }

    fori(N) cout << milk[i] << endl;

    return 0;
}
