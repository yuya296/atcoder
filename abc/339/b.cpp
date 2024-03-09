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

ll H,W,N,h,w;
bool board[101][101];

void move(ll dh, ll dw) {
    h += dh;
    w += dw;
    if (h <= 0) h = H;
    if (w <= 0) w = W;
    if (h > H) h = 1;
    if (w > W) w = 1;
}

int main() {
    cin >> H >> W >> N;

    P dims[] = {{-1,0},{0,1},{1,0},{0,-1}};
    int idx = 0;

    // 白:false, 黒:true
    h = 1, w = 1;
    reps(i,N) {
        if (/* 白のとき */ !board[h][w]) {
            board[h][w] = true;
            idx = (idx+4+1)%4;
        } else {
            board[h][w] = false;
            idx = (idx+4-1)%4;
        }
        move(dims[idx].first, dims[idx].second);
    }

    reps(ih,H) {
        reps(iw,W) {
            cout << (board[ih][iw]?'#':'.');
        }
        cout << endl;
    }
}