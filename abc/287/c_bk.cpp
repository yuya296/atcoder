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

bool run() {

    reps(i,M) {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    if (N - 1 != M) return false;

    int cnt1 = 0;
    int cnt2 = 0;
    reps(i,N) {
        switch(path[i].size()) {
            case 1: cnt1++; break;
            case 2: cnt2++; break;
            default: return false;
        }
    }


    if (N == 1) return true;
    if (N == 2) return true;
    return (cnt1 == 2) && (cnt1 + cnt2 == N);
}

int main() {
    cin >> N >> M;

    cout << Yes(run()) << endl;
}