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

/* 
    MEMO========================

    N: グラフの頂点数            500 <= N <= 1000
    M: グラフの辺陬              500 <= M <= 3000
    D: 日数                     5 <= D <= 30
    K: 一日に工事可能な辺陬の上限   ceil(M/D) < K < 2*ceil(M/D)

    (u_i, v_i, w_i) := i番目の辺が頂点 u_i と v_i を重み w_i で結んでいる (1 <= u_i < v_i <= N, 1 <= w_i <= 10^6)
    (x_i, y_i) := i番目の頂点の座標 (0 <= x_i, y_i <= 1000)
    
    ============================ 
*/

ll N, M, D, K, u[3001], v[3001], w[3001], x[1001], y[1001], r[3001];
ll path[1001][1001], d[1001][1001];
ll parent[1001];
bool visited[1001];
ll UNREACHABLE = 1000000000LL; // 10^9



// 1日あたりの工事箇所を最小にする & 1〜順番に実行
void case1() {
    reps(i,M) r[i] = i / (M/D+1) + 1; 
}
// 1日あたりの工事箇所を最小にする & 剰余で順番に実行
void case2() {
    reps(i,M) r[i] = i % D + 1;
}
// 工事を行う日数を最小限に留める
void case3() {
    ll t = ceil(M/K)+1;
    reps(i,M) r[i] = i % t + 1;
}

// Union-Find木でグループ分け
// グループから
int color[3001];
void case4() {
    vector<vector<int>> groups;


    // vector<int> pathv[N+1];
    vector<int> pathp[M+1];
    // reps(i,M) {
    //     pathv[u[i]].push_back(v[i]);
    //     pathv[v[i]].push_back(u[i]);
    // }

    reps(i,M) {
        reps(j,M) {
            if (u[i] == u[j] || u[i] == v[j] || v[i] == u[j] || v[i] == v[j]) 
                pathp[i].push_back(j);
        }
    }

    color[1] = 1;
    int max_color = 1;
    for (int i = 2; i <= M; i++) {
        bool x[100];
        rep(ix,100) x[ix]=1;

        for (int v : pathp[i]) {
            x[color[v]] = 0;
        }

        int c = 1;
        for (c = 1; c < 100; c++) if (x[c]) break;
        color[i] = c; 
        chmax(max_color,c);
    }


    int cnt[100];
    rep(i,100) cnt[i] = 0;

    reps(i,M) {
        int p = color[i];
        while (cnt[p] >= K || p > D) {
            // p += max_color;
            p = (p + max_color) % K + 1;
        }
        r[i] = p;
        cnt[p] += 1;
    }
}





void run(int c) {
    switch(c) {
        case 1: case1(); break; //  46153160539
        case 2: case2(); break; //  47705877230 
        case 3: case3(); break; // 105150064892
        case 4: case4(); break;
    }
}

int main() {
    cin >> N >> M >> D >> K;
    reps(i,M) cin >> u[i] >> v[i] >> w[i];
    reps(i,N) cin >> x[i] >> y[i];
    // reps(i,M) {
    //     path[u[i]][v[i]] = w[i];
    //     path[v[i]][u[i]] = w[i];
    // }

    // reps(i,N) reps(j,N) d[i][j] = UNREACHABLE;

    // 実行するアルゴリズムを選択
    run(4);

    // 出力
    reps(i,M-1) cout << r[i] << " ";
    cout << r[M] << endl;
}