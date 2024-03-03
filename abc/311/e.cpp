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

int H, W, N;

void log(string s) {
    cout << "LOG: " << s << endl;
}

int main() {
    cin >> H >> W >> N;
    vector<vector<bool>> A(H+1, vector<bool>(W+1,false));
    vector<vector<bool>> dp(H+1, vector<bool>(W+1,false));
    reps(i,N) {
        int a,b;
        cin >> a >> b;
        A[a][b] = true;
    }

    // dp[i][j]:= (i,j)を右下とする穴のない正方形のうち、一辺の長さnの最大値
    // 答えは すべてのi,jのときのdpの和
    // dp[1][1] = (1,1) ? 1:0
    // dp[1][2] = (1,2) ? 1:0 
    // dp[2][2] = (2,2) ? min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 : 0

    reps(i,H) reps(j,W) {
        if (i * j <= 2) continue;
        dp[i][j] = A[i][j] ? 0 : (min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1);
    }

    ll ans = 0;
    reps(i,H) reps(j,W) ans += dp[i][j];
    cout << ans << endl;
}
