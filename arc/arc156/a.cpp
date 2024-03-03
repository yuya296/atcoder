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

ll T, N;
string S;

char sw(char c) {
    return (c - '0' + 1) % 2 + '0';
}
bool check(string s, ll n) {
    return s[n-2] == '0' && s[n-1] == '0';
}

int main() {
    cin >> T;

    vector<ll> Ans;


    // Alg 3
    rep(t,T) {
        cin >> N >> S;
        deque<int> que;
        rep(i,N) if (S[i] == '1') que.push_back(i);

        bool result = true;
        int cnt = 0;

        while(que.size() > 1) {
            int first = que.front();
            que.pop_front();
            int second = que.front();
            que.pop_front();

            if (que.empty()) {
                result = second - first >= 2;
                cnt ++;
                break;
            }

            que.pop_front();
            cnt ++;
            que.push_front(second);
        }
        result &= que.empty();

        Ans.push_back(result?cnt:-1);
    }



    for (auto v : Ans) {
        cout << v << endl;
    }
}