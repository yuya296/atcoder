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

int N, L = -1, R;
string S;
bool bit[5001];

// a>bなら1, a=bなら0, a<bなら-1
int strcomp(string a, string b) {
    ll len = min(a.size(),b.size());
    for (int i = 0; i < len; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return sign(b.size() - a.size());
}

string f(string s) {
    string res = "";
    cout << s << endl;
    for (int i = s.size()-1; i >= 0; i--) res += (s[i] == 'p') ? 'd' : 'p'; 
    return res;
}

int main() {
    cin >> N >> S;
    reps(i,N) bit[i] = (S[i-1] == 'd') ? 1 : 0;

    // 1. 左から走査して最初の p が L の場所
    rep(i,N) if (S[i]=='p') {L=i; break;}

    // reps(i,N) if (!bit[i]) { L = i; break; }
    if (L == -1) { cout<<S<<endl; return 0; } // 操作しなくてOK

    for (int i = L; i < N; i++) {
        cout << i << ": ";
        cout << S.substr(L,R-L+1) << endl;
        string fs = f(S.substr(L,R-L+1));
        string s = S.substr(0,L) + fs + S.substr(R+1,N-R-1);
        cout << fs << endl;
        cout << s << endl;
    }



    // 2. Lから右に探索 -> 0が最大個連続する部分の一番右の0がRになる
    // int maxcount = 1;
    // int nowcount = 1;
    // for (int i=L+1; i<N; i++) {
    //     if (S[i]=='p') {
    //         nowcount++;
    //         if (nowcount >= maxcount) {
    //             maxcount = nowcount;
    //             R = i;
    //         }
    //     } else {
    //         nowcount = 0;
    //     }
    // }

    // rep(i,N) {
    //     if (L <= i && i <= R) {
    //         char c = S[L+R-i];
    //         if (c == 'p') cout << 'd';
    //         else cout << 'p';
    //     } else {
    //         cout << S[i];
    //     }
    // }
    // cout << endl;
}