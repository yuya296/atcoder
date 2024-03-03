#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using P=pair<ll,ll>;
#define pb push_back
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
template <typename T> inline bool chmin(T& a, const T& b) {bool c=a>b; if (a>b) a=b; return c;}
template <typename T> inline bool chmax(T& a, const T& b) {bool c=a<b; if (a<b) a=b; return c;}
template <typename T> inline T gcd(T a, T b) {if (b==0)return a; else return gcd(b,a%b);}
template <typename T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template <typename T> inline T ceil(T a,T b) {return (a+(b-1))/b;}
template <typename T> inline T floor(T a,T b) {return a/b;}
template <typename itr> inline void print(itr b,itr e){for(itr p=begin; p<end; p++) cout<<*p<<' ';cout<<endl;}
inline int sign(ll i) {return i/abs(i);}


ll L, v,l;
int N1, N2;

int main() {
    cin >> L >> N1 >> N2;

    deque<P> dq1, dq2;
    reps(i,N1) {
        cin >> v >> l;
        dq1.push_back(P(v,l));
    }

    reps(i,N2) {
        cin >> v >> l;
        dq2.push_back(P(v,l));
    }

    ll ans = 0;
    while(!dq1.empty() && !dq2.empty()) {
        ll v1 = dq1.front().first;
        ll l1 = dq1.front().second;
        ll v2 = dq2.front().first;
        ll l2 = dq2.front().second;

        if (l1 == l2) {
            if (v1 == v2) ans += l1;
            dq1.pop_front();
            dq2.pop_front();
        } else if (l1 < l2) {
            if (v1 == v2) ans += l1;
            dq1.pop_front();
            dq2.front().second = l2 - l1;
        } else if (l1 > l2) {
            if (v1 == v2) ans += l2;
            dq2.pop_front();
            dq1.front().second = l1 - l2;
        }
    }

    cout << ans << endl;
}