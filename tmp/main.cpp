#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(void)
{
    int n, q;
    cin >> n >> q;
    dsu U(n);
    int t, u, v;
    while(q--){
        cin >> t >> u >> v;
        if(t){
            cout << (U.same(u, v) ? 1 : 0) << endl;
        }
        else{
            U.merge(u, v);
        }
    }
}