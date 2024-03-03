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

int N, A[200001], M, B[200001];
bool visited[200001];
deque<int> q;

int run() {
    reps(i,N) {
        if (visited[i]) continue;
        vector<bool> curVisited(N+1, false);
        int now = i;
        int nxt = A[i];
        while (true) {
            if (curVisited[nxt]) return now;
            curVisited[nxt] = true;
            now = nxt;
            nxt = A[nxt];
        }
    }
    return -1;
}

int main() {
    cin >> N;
    reps(i,N) cin >> A[i];
    int st = run();

    if (st == -1) cout << "err" << endl;
    else {
        vector<int> ans;
        ans.push_back(st);
        int c = A[st];
        while (c != st) {
            ans.push_back(c);
            c = A[c];
        }

        cout << ans.size() << endl;
        for (int i : ans) printf("%d ",i);
        printf("\n");
    }
}