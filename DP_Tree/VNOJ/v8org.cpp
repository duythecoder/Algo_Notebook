#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ln "\n"
#define sp " "
#define fpp(a, b, c) for (int a = b; a <= c; a++)
#define fmm(a, b, c) for (int a = b; a >= c; a--)
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define printarr(arr, st, en) fpp(i, st, en) cout << arr[i] << sp;

#define vt vector
#define pb push_back
#define sz(A) A.size()

#define ll long long
#define ull unsigned long long

const int mod = 1e9 + 7;
const int mxn = 1e4 + 1;

int n, k, c = 0;
ll dp[mxn];
vt<int> g[mxn];

void dfs(int u, int parent){
    // Initialisation
    dp[u] = 1;
    // Traverse through children of u
    for (int child : g[u]){
        // Leaves (undirected graph, g[i].pb(u) and g[u].pb(i))
        if (child == parent) continue;
        dfs(child, u);
        dp[u] += dp[child];
    }
    if (dp[u] >= k) {
        c++;
        dp[u] = 0;
    }
}

void solve(){
    c = 0;
    dfs(1, 0);
    cout << c << ln;
}

void input(){
    int u;
    cin >> k >> n;
    fpp (i, 2, n){
        cin >> u;
        g[i].pb(u);
        g[u].pb(i);
    }
    solve();
}

int main(){
    fastio;
    input();
}
