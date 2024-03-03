#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define fore(i,a,b) for (int i=(a); i<=(b); i++)
#define YES(b) ((b)?"YES":"NO")
#define Yes(b) ((b)?"Yes":"No")

int A,B;
int n;
int main() {
    cin >> A >> B;
    n = 1;
    rep(i,B) n *= A;
    cout << n << endl;
}