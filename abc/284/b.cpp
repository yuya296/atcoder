#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

int T, N, A;
int main() {
    cin >> T;
    vector<ll> vec;
    repe(i,T) {
        cin >> N;
        ll count = 0LL;
        repe(i,N) {
            cin >> A;
            if(A%2 == 1) count++;
        }
        vec.push_back(count);
    }
    for (auto v : vec) cout << v << endl;
}