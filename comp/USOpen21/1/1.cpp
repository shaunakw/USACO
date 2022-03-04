#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef long long ll;
typedef vector<ll> vll;

ll N;
vll tree;

ll range(ll start, ll end) {
    start += N;
    end += N;
    ll sum = 0;
    while (start <= end) {
        if (start % 2 == 1) sum += tree[start++];
        if (end % 2 == 0) sum += tree[end--];
        start /= 2;
        end /= 2;
    }
    return sum;
}

void add(ll i, ll value) {
    if (i == N) return;
    i += N;
    for (; i > 0; i /= 2) {
        tree[i] += value;
    }
}

int main() {
    cin >> N;
    tree.resize(2*N, 0);

    vll last(N, -1);
    vll nxt(N, N);
    ll dup[N];
    fori(i, N) {
        ll c; cin >> c; --c;
        dup[i] = i == 0 ? 0 : dup[i-1];
        if (last[c] != -1) {
            nxt[last[c]] = i;
            dup[i]++;
        }
        last[c] = i;
    }

    ll total = 0;
    fori(i, N) {
        if (i > 0) {
            add(nxt[i-1], 1);
        }
        total += (nxt[i] - i - 1) - dup[nxt[i] - 1] + range(0, nxt[i] - 1);
    }
    cout << total;
    
    return 0;
}
