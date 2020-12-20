#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; ++i)
#define trav(i, a) for(auto& i : a)

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("times17.in", "r", stdin);
    freopen("times17.out", "w", stdout);
}



int main() {
    setIO();
    
    string s; cin >> s;
    if (s.size() < 5) {
        string temp = s;
        s.resize(4, '0');
        cout << s + temp;
    } else {
        int n[s.size()];
        fori(i, s.size()) n[i] = s[s.size() - 1 - i] == '1';

        int carry = 0;
        string out;
        fori(i, s.size() + 4) {
            int b1 = i < s.size() ? n[i] : 0;
            int b2 = i < 4 ? 0 : n[i - 4];
            int b3 = carry;
            int sum = b1 ^ b2 ^ b3;
            out = (sum == 0 ? '0' : '1') + out;
            carry = (b1 & b2) | (b2 & b3) | (b3 & b1);
        }
        if (carry == 1) out = '1' + out;
        cout << out;
    }
    
    return 0;
}
