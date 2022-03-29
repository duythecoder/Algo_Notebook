#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fmm(a, b, c) for (int a = b; a >= c; a--)
#define printarr(arr, st, en) fpp(i, st, en) cout << arr[i] << sp; cout << ln;

#define vt vector
#define pb push_back
#define sz(A) A.size()
#define uid uniform_int_distribution<int>
#define vi vector<int>

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxv = 1e4 + 1;
const int mxe = 1e5 + 1;

int n, m, S = 0;
vi g[mxv], g2[mxv];
stack<int> st;
bool v[mxv], v2[mxv];

void dfs(int u) {
    v[u] = true;
    if (sz(g[u]) > 0) {
        fpp (i, 0, sz(g[u]) - 1) {
            if (!v[g[u][i]]) dfs(g[u][i]);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    v2[u] = true;
    if (sz(g2[u]) > 0) {
        fpp (i, 0, sz(g2[u]) - 1) {
            if (!v2[g2[u][i]]) dfs2(g2[u][i]);
        }
    }
}

void solve(){
    // First DFS
    fpp (i, 1, n) {
        if (!v[i]) dfs(i);
    }

    // Second DFS
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!v2[u]){
            dfs2(u);
            S++;
        }
    }

    cout << S << ln;
}

void input(){
    cin >> n >> m;
    fpp (i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g2[v].pb(u); // reversal right in input process but requires more memory
    }
    solve();
}

int main(){
    fastio;
    input();
}
