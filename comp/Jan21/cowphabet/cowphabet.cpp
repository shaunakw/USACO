#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

string abc = "abcdefghijklmnopqrstuvwxyz";

vi parent;

bool isAnc(int anc, int cld) {
    if (parent[anc] == -1) return false;
    if (anc == cld) return true;
    while (parent[cld] != cld) {
        cld = parent[cld];
        if (anc == cld) return true;
    }
    return false;
}

int main() {
    string s1;
    cin >> s1;
    int N = s1.size();

    int s[N];
    fori(i, N) s[i] = abc.find(s1[i]);

    parent.resize(26, -1);
    parent[s[0]] = s[0];

    for(int i = 1; i < N; ++i) {
        if (!isAnc(s[i], s[i-1])) {
            parent[s[i]] = s[i-1];
        }
    }

    int ans = 1;
    for (int i = 1; i < N; ++i) {
        if (isAnc(s[i], s[i-1])) ans++;
    }
    cout << ans;
    return 0;
}
