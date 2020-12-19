#include <bits/stdc++.h>

#define fori(i, end) for(int i = 0; i < end; i++)

using namespace std;

int A;
int B;
int X;
int Y;

int main() {
    cin >> A >> B >> X >> Y;
	
    int d1 = abs(A - B);
    int d2 = abs(A - X) + abs(B - Y);
    int d3 = abs(A - Y) + abs(B - X);
    cout << min(d1, min(d2, d3));
    
    return 0;
}
