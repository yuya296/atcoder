#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

ll N;
int T;

int main() {
    cin >> T;

    vector<ll> vp, vq;

    repe(t,T) {
        cin >> N;
        ll i, p, q;
        for (i=2; i*i<=N/2; i++) if (N % i == 0) break;
        if (N % (i*i) == 0) {
            p = i;
            q = (ll)(N / (i * i));
        } else {
            q = i;
            p = (ll)(sqrtl(N/i));
        }

        vp.push_back(p);
        vq.push_back(q);
    }

    rep(i,T) cout << vp[i] << " " << vq[i] << endl;
}