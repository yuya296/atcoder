#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

int N;
string S[11];
int main() {
    cin >> N;
    repe(i,N) cin >> S[i];
    for (int i = N; i > 0; i--) cout << S[i] << endl;
}