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

int T, IN[2001];
string IS[2001];

bool compare(int n1, int n2, char* s1, char* s2) {
    if (n1 == 0 && n2 == 0) return false; 
    if (n1 == 0) return true;
    if (n2 == 0) return false;
    if (*s1 < *s2) return true;
    if (*s1 > *s2) return false;
    return compare(n1-1, n2-1, ++s1, ++s2);
}

int main() {
    cin >> T;
    reps(t,T) cin >> IN[t] >> IS[t];

    reps(t,T) {
        string S = IS[t];
        int N = IN[t];
        char c = S[0];
        bool b = false;
        for (int i = 1; i < N; i++) {
            if (!compare(i, N-i, &S[0], &S[i])) continue;
            b = true;
            break;
        }
        cout << Yes(b) << endl;
    }
}