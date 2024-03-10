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
ll LL_MAX = __LONG_LONG_MAX__;

ll N,A;
string T,S[101][11];
ll dp[105][105];

ll minOfPos(ll a, ll b) {
    if (a < 0 && b < 0) return 0;
    if (a < 0) return b;
    if (b < 0) return a;
    if (a < b) return a;
    return b;
}

int main() {
    cin >> T >> N;
    // iでt-1文字目に到達するためのコスト dp[i][t]
    // dp[i][0] = 0
    for_(i,0,105) for_(j,1,105) dp[i][j] = -1;
    reps(i,N) {
        cin >> A;
        // reps(j,A[i]) cin >> S[i][j];
        for_(j,1,105) dp[i][j] = dp[i-1][j];

        reps(j,A) {
            string s;
            cin >> s;
            ll len = s.length();
            for (ll idx = 0; idx <= (ll)(T.length())-len; idx++) {
                string subs = T.substr(idx,len);
                if (s != subs) continue;
                if (dp[i-1][idx] > -1) {
                    dp[i][idx+len] = minOfPos(dp[i-1][idx] + 1, dp[i][idx+len]);
                }
            }
        }
    }

    // debug
    //     cout << "idx:\t" ;
    //     for_(j,0,T.length()) cout << j << "\t";
    //     cout << endl;
    // for_(i,0,N+1) {
    //     cout << i << ":\t";
    //     for_(j,0,T.length()+1) {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][T.length()] << endl;
}