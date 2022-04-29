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
const int mxn = 1e5 + 5;

int n, k;
ll a[mxn];

void solve(){
    ll dp[mxn], ans = 0;
    deque<int> q(k);
    fpp (i, 1, n) {
        while (!q.empty() && q.front() < i - k) q.pop_front();
        ll mx = q.empty() ? 0 : dp[q.front()];
        dp[i] = max(mx, 0LL) + a[i];
        ans = max(ans, dp[i]);
        while (!q.empty() && dp[i] >= dp[q.back()]) q.pop_back();
        q.pb(i);
    }
    cout << ans << ln;
}

void input(){
    cin >> n >> k;
    fpp (i, 1, n) cin >> a[i];
    solve();
}

int main(){
    fastio;
    input();
}
