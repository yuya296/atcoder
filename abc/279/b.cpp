#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

string S, T;
int nS, nT;

bool check(string s, string t) {
    int ns = s.length();
    int nt = t.length();
    outer:for (int i=0; i<ns-nt+1; i++) {
        for (int j=0; j<nt; j++) {
            if (s[i+j]!=t[j])
                goto outer;
        }
        return true;
    }
    return false;

}

int main() {
    cin >> S >> T;
    cout << (Yes(check(S,T))) << endl;
}