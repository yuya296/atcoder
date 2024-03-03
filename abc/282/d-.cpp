#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
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

int N, M;
vector<int> path[100001];
int color[100001];
int g1,g2;
bool isBipartite(int s, int c) {
    // 二部グラフ以外を弾く条件チェック
    if (color[s] == -c) {
        cout << "false" << endl;
        return false;
    }

    // 色の振り分け
    color[s] = c;
    // グループ数のカウントを++
    if (c == 1) g1++;
    else g2++;

    // 再帰でdfs
    bool result = true;
    for (auto p : path[s]) {
        if (color[p]==c) return false;
        if (color[p]==0) result &= isBipartite(p,-c);
    }

    return result;
}


int main() {
    cin >> N >> M;
    reps(i,M) {
        int u,v;
        cin >> u >> v;
        path[u].pb(v);
        path[v].pb(u);
    }
    
    bool result = true;
    int samecnt = 0;
    reps(i,N) if (color[i]==0) {
        g1=0; g2=0; //カウントを初期化
        result &= isBipartite(1,1);

        if (g1>1) samecnt += g1 * (g1-1) / 2;
        if (g2>1) samecnt += g2 * (g2-1) / 2;
    }

    
    if (result) {
        int a = (int)(N * (N-1) / 2) - samecnt - M;
        cout << a << endl;
    } else {
        cout << 0 << endl;
    }



}