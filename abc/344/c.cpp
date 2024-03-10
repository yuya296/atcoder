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
ll LL_MAX = __LONG_LONG_MAX__;

ll N,M,L,Q,A[101],B[101],C[101];
int main() {
    unordered_map<ll,bool> amp; //answer_map

    cin >> N;
    reps(i,N) cin >> A[i];
    cin >> M;
    reps(i,M) cin >> B[i];
    cin >> L;
    reps(i,L) cin >> C[i];
    cin >> Q;

    reps(in,N) {
        reps(im,M) {
            reps(il,L) {
                amp[A[in]+B[im]+C[il]] = true;
            }
        }
    }

    reps(i,Q) {
        ll q;
        cin >> q;
        cout << Yes(amp[q]) << endl;
    }
}