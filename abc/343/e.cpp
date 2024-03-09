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

int v1,v2,v3;

int dist(int n1, int n2, int n3) {
    return max(0, min({n1,n2,n3}) - max({n1,n2,n3}) + 7);
} 

int dist(int n1, int n2) {
    return max(0, min(n1,n2) - max(n1,n2) + 7);
}

int calcV3(int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) {
    int ans = 1;
    ans *= dist(a1,a2,a3);
    ans *= dist(b1,b2,b3);
    ans *= dist(c1,c2,c3);
    return ans;
}

int calcV2(int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3, int v3) {
    int vt1 = dist(a1,a2) * dist(b1,b2) * dist(c1,c2);
    int vt2 = dist(a2,a3) * dist(b2,b3) * dist(c2,c3);
    int vt3 = dist(a3,a1) * dist(b3,b1) * dist(c3,c1);

    return vt1 + vt2 + vt3 - 3 * v3;
}

int calcV1(int v3, int v2) {
    return 3*7*7*7 - 2*v2 - 3*v3;
}


int main() {
    cin >> v1 >> v2 >> v3;

    for_(a1, -7, 8) {
        for_(b1, -7, 8) {
            for_(c1, -7, 8) {
                for_(a2, -7, 8) {
                    for_(b2, -7, 8) {
                        for_(c2, -7, 8) {

                            // V3 の計算
                            if (v3 != calcV3(0,0,0,a1,b1,c1,a2,b2,c2)) continue;

                            // V2 の計算
                            if (v2 != calcV2(0,0,0,a1,b1,c1,a2,b2,c2,v3)) continue;

                            // V1 の計算
                            if (v1 != calcV1(v3,v2)) continue;

                            cout << "Yes" << endl;
                            printf("%d %d %d %d %d %d %d %d %d\n",0,0,0,a1,b1,c1,a2,b2,c2);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}
