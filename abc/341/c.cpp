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

int H, W, N;
string T, S[501];
int main() {
    cin >> H >> W >> N;
    cin >> T;
    reps(i,H) cin >> S[i];

    set<P> st;
    P c = P(0,0);
    st.insert(P(c.first, c.second));
    rep(i,N) {
        if (T[i] == 'L') c = P(c.first    , c.second - 1);
        if (T[i] == 'R') c = P(c.first    , c.second + 1);
        if (T[i] == 'U') c = P(c.first - 1, c.second    );
        if (T[i] == 'D') c = P(c.first + 1, c.second    );
        st.insert(P{c.first, c.second});
    }

    ll ans = 0;
    rep(h,H) {
        rep(w,W) {
            if (S[h][w] == '#') continue;
            bool success = true;
            for (auto itr = st.begin(); itr != st.end(); ++itr) {
                ll ih = h + (*itr).first;
                ll iw = w + (*itr).second;
                if (ih < 0 || iw < 0 || ih >= H || iw >= W) {
                    success = false;
                    break;
                }
                if (S[ih][iw] == '#') {
                    success = false;
                    break;
                }
            }
            if (success) ans ++;
        }
    }
    
    cout << ans << endl;
}
