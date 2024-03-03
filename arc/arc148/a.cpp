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
template <typename T> T gcd(T a, T b) {if (b==0)return a; else return gcd(b,a%b);}
template <typename T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template <typename T> inline T ceil(T a,T b) {return (a+(b-1))/b;}
template <typename T> inline T floor(T a,T b) {return a/b;}
template <typename T> void printvec(vector<T> v) {cout<<"vector[";rep(i,v.size()-1)cout<<v[i]<<", ";cout<<v[v.size()-1]<<"]"<<endl;}
template <typename T> inline void printarr(T a[], int f, int t) {cout<<"array[";for(int i=f;i<t;i++)cout<<a[i]<<", ";cout<<a[t]<<"]"<<endl;}

ll N, A[200001];
ll INF=1000000001;

P mins(ll min1, ll min2, ll newl) {
    if (min1 == newl || min2 == newl) return P(min1,min2);
    if (newl < min1) return P(newl,min1);
    if (newl < min2) return P(min1,newl);
    return P(min1,min2);
}

int main() {
    cin >> N;
    reps(i,N) cin>>A[i];

    // 1. 最小値と2番目に小さい値を探索する
    ll min1=INF,min2=INF;
    reps(i,N) {
        P newmin = mins(min1,min2,A[i]);
        min1 = newmin.first;
        min2 = newmin.second;
    }

    // 2. Aの全要素から最小値を引く (最小値の更新を忘れずに)
    reps(i,N) A[i] -= min1;
    min2 -= min1;

    // 3. Aの全ての最大公約数gを求める
    ll g = gcd(A[1],A[2]);
    for (int i=3; i<=N; i++) g = gcd(g,A[i]);

    // 4. g==1なら共通素因数を持たないので、2で割ったあまり(2種類)が正解
    //    g>1なら、gで割ればAはすべて0になるので答えは1
    if (g == 1) cout << 2 << endl;
    else cout << 1 << endl;
    




}