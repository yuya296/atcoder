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
template <typename T> void printvec(vector<T> v) {cout<<"vector[";rep(i,v.size()-1)cout<<v[i]<<", ";cout<<v[v.size()-1]<<"]"<<endl;}
template <typename T> inline void printarr(T a[], int f, int t) {cout<<"array[";for(int i=f;i<t;i++)cout<<a[i]<<", ";cout<<a[t]<<"]"<<endl;}
inline int sign(ll i) {return i/abs(i);}

ll N, K, D, A[101];
ll dp[101][101][101];
int main() {
    cin >> N >> K >> D;
    reps(i,N) cin >> A[i];

    // dp[i][j][k] := A[1],...,A[i] から j 個選ばれていて、余りが k のときの最大値

    // dpの初期化
    rep(i,N+1) rep(j,K+1) rep(k,D) dp[i][j][k] = -1;
    dp[1][1][A[1]%D] = A[1];
    // reps(i,N) chmax(dp[i][1][A[i]%D],A[i]);

    reps(i,N) {
        reps(j,K) {
            if (i == 1 && j == 1) continue;
            rep(k,D) {
                ll l1 = dp[i-1][j][k];
                ll l2 = dp[i-1][j-1][(k+D-A[i]%D)%D];
                if (l2 > -1) l2 += A[i];
                dp[i][j][k] = max(l1, l2);

                printf("l1 = dp[%d][%d][%d] = %lld\n", i-1, j, k, l1);
                printf("l2 = dp[%d][%d][%lld] = %lld\n", i-1, j-1, (k+D-A[i]%D)%D, l2);
                printf("dp[%d][%d][%d] = max(%lld, %lld) = %lld\n\n", i, j, k, l1, l2, dp[i][j][k]);
            }
        }
    }
    cout << dp[N][K][0] << endl;



}