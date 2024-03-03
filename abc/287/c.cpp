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

ll N, M, u, v;
vector<int> path[200001];
bool seen[200001];

// 点, 距離
pair<ll,ll> dfs(ll v) {
    seen[v] = true;
    pair<ll,ll> ans;
    ans.first = v;
    ans.second = 0LL;

    for (auto next: path[v]) {
        if (seen[next]) continue;
        pair<ll,ll> temp;
        temp = dfs(next);
        temp.second++;
        if (temp.second >= ans.second) ans = temp;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    reps(i,M) {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    pair<ll,ll> s,a;
    s = dfs(1);
    // cout << s.first  << "," << s.second << endl;
    reps(i,N) seen[i] = false;
    a = dfs(s.first);
    // cout << a.second << endl;

    if (N - 1 != M) cout << "No" << endl;
    else cout << Yes(a.second == M) << endl;
}