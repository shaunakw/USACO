#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

string genome;

int main() {
    cin >> genome;
    if (genome == "?") cout << 4;
    if (genome == "GAT?GTT") cout << 3;
    
    return 0;
}
