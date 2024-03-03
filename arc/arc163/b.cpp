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

ll N, M, A[200001];
int main() {
    cin >> N >> M;
    rep(i,N) cin >> A[i];
    ll s = A[0];
    ll e = A[1];
    stable_sort(A, A+N);
    ll is = -1LL;
    ll ie = -1LL;
    rep(i,N) {
        if (A[i] == s && is == -1LL) is = i;
        if (A[i] == e) ie = i;
    }

    // cout << s << "," << e << endl;
    // cout << is << "," << ie << endl;
    if (ie - is - 1 >= M) {
        cout << 0 << endl;
    } else {
        ll l = max(is-M,0LL);
        ll r = ie+(M-(is-l)-(ie-is-1));
        ll ans = __LONG_LONG_MAX__;
        // cout << l << "," << r << endl;
        while (l <= is && r < N) {
            // printf("log: (l,r) = (%lld, %lld), ans = %lld\n", l, r, (s-A[l]) + (A[r] - e));
            ans = min(ans, (s-A[l]) + (A[r] - e));
            l++; r++;
        }
        cout << ans << endl;
    }
}