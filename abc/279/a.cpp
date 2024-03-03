#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

string S;
int main() {
    cin >> S;
    int cnt = S.length();
    for (int i=0; i<S.length(); i++) if (S[i]=='w') cnt++;
    cout << cnt << endl;
}