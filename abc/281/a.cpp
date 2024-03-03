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

int N;
int main() {
    cin >> N;
    for (int i = N; i >= 0; i--) cout << i << endl;

}