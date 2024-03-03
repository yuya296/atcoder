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

int H, W, S[3001][3001]; //S[i][j]は(1,1)から(i,j)までの穴の数
bool A[3001][3001];
ll N;
int main() {
    cin >> H >> W >> N;
    reps(i,N) {
        int a,b;
        cin >> a >> b;
        A[a][b] = true;
    }
    
    int ans = 0;
    S[1][1] = A[1][1] ? 1 : 0;
    for (int h = 0; h <= H; h++) {
        if (h > 0) S[h][0] = S[h-1][0] + (A[h][0] ? 1 : 0);
        for (int w = 1; w <= W; w++) {
            S[h][w] = S[h][w-1] + (A[h][w] ? 1 : 0);
        }
    }


    reps(i,H) {
        reps(j,W) {
            int n = 1;
            while (i + n - 1 <= H && j + n - 1 <= W) {
                int temp = 0;
                temp += S[i+n-1][j+n-1];
                temp -= S[i-1][j+n-1];
                temp -= S[i+n-1][j-1];
                temp += S[i-1][j-1];
                if (temp == 0) ans ++;
                n ++;
            }
        }
    }
    cout << ans << endl;
}