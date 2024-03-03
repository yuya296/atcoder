#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for (int i=(int)(s); i<(int)(n); i++)
#define repe(i,s,n) for (int i=(int)(s); i<=(int)(n); i++)

int N, M, E, U[500001], V[500001], Q, X[500001];
int parent[200001];
bool isDisconnected[500001];

int root(int x) {
    if (parent[x] == x) return x;
    else return root(parent[x]);
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx != ry) parent[rx] = ry;
}

bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}

int count() {
    int cnt = 0;
    repe(i,1,N) if(same(i,N+1)) cnt++;
    return cnt;
}


int main() {
    // 1.入力
    cin >> N >> M >> E;
    int u,v;
    repe(i,1,E) {
        cin >> u >> v;
        U[i] = min(u,N+1); // 発電所はすべてN+1として扱う
        V[i] = min(v,N+1);
    }
    cin >> Q;
    int x;
    repe(i,1,Q) {
        cin >> x;
        X[i] = x;
        isDisconnected[x] = true;
    }

    // 2. Union-Find木をつくる (parent配列)
    repe(i,1,N+1) parent[i] = i;
    repe(i,1,E) if (!isDisconnected[i]) unite(U[i],V[i]);


    // 3. Xを逆順で処理してunite->sameを行っていく
    int result[Q+1];
    for (int i = Q; i >= 1; i--) {
        result[i] = count();
        unite(U[X[i]],V[X[i]]);
    }

    // 4. 出力
    repe(i,1,Q) cout << result[i] << endl;



}