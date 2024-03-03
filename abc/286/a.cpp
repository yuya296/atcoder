#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using Pair=pair<ll,ll>;
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

int N, P, Q, R, S, A[101];
int main() {
    cin >> N >> P >> Q >> R >> S;
    reps(i,N) cin >> A[i];

    reps(i,N) {
        if (i > 1) cout << " ";
        if (P <= i && i <= Q) cout << A[R + i - P];
        else if (R <= i && i <= S) cout << A[P + i - R];
        else cout << A[i];
    }
    cout << endl;
}