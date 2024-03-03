#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for (int i=0; i<(n); i++)
#define repe(i,n) for (int i=1; i<=(n); i++)
#define for_(i,a,b) for (int i=(a); i<(b); i++)
#define Yes(b) ((b)?"Yes":"No")

int N, M;
bool visited[101];
vector<int> paths[101];

void dfs(int c) {
    visited[c] = 1;
    for (auto p : paths[c]) {
        if (!visited[p]) dfs(p);
    }
}

int main() {
    cin >> N >> M;
    repe(i,M) {
        int u,v;
        cin >> u >> v;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }

    int count = 0;
    repe(i,N) {
        if (!visited[i]) {
            count ++;
            dfs(i);
        }
    }

    cout << count << endl;

}