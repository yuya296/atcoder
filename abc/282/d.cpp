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
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return gcd(b, a % b);}
template <typename T> inline T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename T> inline T ceil(T a,T b) {return (a+(b-1))/b;}
template <typename T> inline T floor(T a,T b) {return a/b;}

ll N, M;
vector<int> G[200001];
int color[200001];

// @param v dfs対象の頂点
// @param p 直前の頂点(チェック量を減らすため？)
// @param c 色 {訪問済:±1 | 未訪問:0}
// @return 同じ木に所属する頂点の(色1,色2)の個数を返す, 二部グラフでない場合は(-1,-1)
P dfs(int v, int p, int c) {
    P ret = P(0, 0);
    color[v] = c;

    if (c == 1) ret.first++;
    else ret.second++;

    for (auto u : G[v]) {                       // 隣接する頂点全てに対して
        if (u == p || color[u] == -c) continue; //  | 訪問済みかつ色が違う -> continue
        if (color[u] == c) return P(-1,-1);     //  | 訪問済みかつ色が同じ -> 二部グラフでないのでreturn(-1,-1)
        P res = dfs(u, v, -c);                  //  | dfs再帰
        if (res.first == -1) return P(-1, -1);  //  | -> その結果、(-1,-1)=二部グラフでないならreturn(-1,-1)
        ret.first += res.first;
        ret.second += res.second;               //  dfs再帰で得られた結果を加えて終了
    }
    return ret;
}

int main() {
    cin >> N >> M;

    int u,v;
    reps(i,M) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    ll Ans = N*(N-1)/2 - M;
    
    reps(i,N) {
        if (!color[i]) {
            P res = dfs(i, -1, 1);
            if (res.first == -1) {
                cout << 0 << endl;
                return 0;
            }
            Ans -= res.first * (res.first-1) / 2;
            Ans -= res.second * (res.second-1) / 2;
        }
    }

    cout << Ans << endl;
    return 0;
}