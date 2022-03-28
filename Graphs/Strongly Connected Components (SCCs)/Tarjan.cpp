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

#define UNVISITED -1

const int mod = 1e9 + 7;
const int mxv = 1e4 + 1;
const int mxe = 1e5 + 1;

int n, m, id = 0, S = 0, ids[mxv], low[mxv];
bool onStack[mxv];
stack<int> st;
vi g[mxv];

void dfs(int u) {
    st.push(u);
    onStack[u] = true;
    ids[u] = low[u] = id++;

    // Visit all neighbours & min low-link on callback
    if (sz(g[u]) > 0) {
        fpp (i, 0, sz(g[u]) - 1) {
            if (ids[g[u][i]] == UNVISITED) dfs(g[u][i]);
            if (onStack[g[u][i]]) low[u] = min(low[u], low[g[u][i]]);
        }
    }

    // After visiting all neighbours of u if we're at the start of an SCC, empty the stack until we're back to the start of the SCC
    if (ids[u] == low[u]) {
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            low[v] = ids[u];
            if (v == u) break;
        }
        S++;
    }
}

void solve(){
   memset(ids, UNVISITED, sizeof(ids));
   fpp (i, 1, n) {
       if (ids[i] == UNVISITED) dfs(i);
   }
   cout << S << ln;
}

void input(){
    cin >> n >> m;
    fpp (i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    solve();
}

int main(){
    fastio;
    input();
}
