#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define for_(i, a, b) for (int i = (a); i < (b); i++)
#define Yes(b) ((b) ? "Yes" : "No")
#define YES(b) ((b) ? "YES" : "NO")
template <typename T> inline bool chmin(T &a, const T &b){bool c = a > b; if (a > b) a = b; return c;}
template <typename T> inline bool chmax(T &a, const T &b){ bool c = a < b; if (a < b) a = b; return c;}
template <typename T> inline T gcd(T a, T b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) { return (a * b) / gcd(a, b); }
template <typename T>
inline T ceil(T a, T b) { return (a + (b - 1)) / b; }
template <typename T>
inline T floor(T a, T b) { return a / b; }
template <typename itr>
inline void print(itr b, itr e)
{
    for (itr p = begin; p < end; p++)
        cout << *p << ' ';
    cout << endl;
}
inline int sign(ll i) { return i / abs(i); }

int N, M;
string S[201];
int A[201][201];
deque<P> dq;

void run(P now, int dy, int dx) {
    while (A[now.first][now.second] != -1) {
        P next = {now.first + dy, now.second + dx};

        switch (A[now.first][now.second]) {
            case -1:
                // printf("  case -1: A[%lld][%lld] = %d\n", now.first, now.second, A[now.first][now.second]);
                return;
            case 2:
                // printf("  case 2: A[%lld][%lld] = %d\n", now.first, now.second, A[now.first][now.second]);
                break;
            default:
                // printf("  default: A[%lld][%lld] = %d\n", now.first, now.second, A[now.first][now.second]);
                if (A[next.first][next.second] == -1) {
                    // 次が壁のとき
                    A[now.first][now.second] = 2;
                    dq.push_back({now.first,now.second});
                } else {
                    A[now.first][now.second] = 1;
                }
                break;
        }
        now = next;
    }
}

int main()
{
    cin >> N >> M;
    rep(i, N) cin >> S[i];

    rep(i, N) rep(j, M)
    {
        if (S[i][j] == '#')
            A[i][j] = -1;
        else
            A[i][j] = 0;
    }

    A[1][1] = 2;
    dq.push_back({1, 1});

    while (!dq.empty())
    {
        P p = dq.front();
        dq.pop_front();

        // printf("now(%lld,%lld) ==========\n",p.first,p.second);

        run({p.first,p.second}, 0, 1);
        run({p.first,p.second}, 0, -1);
        run({p.first,p.second}, 1, 0);
        run({p.first,p.second}, -1, 0);
    }

    int ans = 0;
    rep(i,N) rep(j,M) if (A[i][j] > 0) ans++;
    cout << ans << endl;
}