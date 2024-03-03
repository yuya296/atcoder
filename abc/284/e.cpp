#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define pb push_back
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return gcd(b, a % b);}
template <typename T> inline T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename T> inline T ceil(T a,T b) {return (a+(b-1))/b;}
template <typename T> inline T floor(T a,T b) {return a/b;}

int N, M;
int Ans;
bool visited[200001];
vector<int> path[200001];
int lim = 1000000;

void dfs(int s) {
    visited[s] = 1;
    if (Ans == lim) return;
    Ans++;
    for (auto v:path[s]) if (!visited[v]) dfs(v);
    visited[s] = 0;
}

int main() {
    cin >> N >> M;
    reps(i,M) {
        int u,v;
        cin >> u >> v;
        path[u].pb(v);
        path[v].pb(u);
    }

    dfs(1);
    cout << Ans << endl;
}