
// Lazy Propagation on Segment Tree

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
const int mxn = 1e5 + 1;

int t, n, q, x, y, v, a[mxn];
ll st[4 * mxn], lazy[4 * mxn]; // lazy[i] is the pending value for node i

void buildTree(int l, int r, int id){
    if (l == r){
        st[id] = a[l];
        return;
    }

    int m = (l + r) / 2;
    buildTree(l, m, id * 2);
    buildTree(m + 1, r, id * 2 + 1);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

// Push lazy propagation onto children of id
void lazyUpdate(int l, int r, int id){
    if (lazy[id] > 0){
        st[id] += lazy[id];
        if (l < r){
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void update(int l, int r, int id, int u, int v, int val){
    lazyUpdate(l, r, id);
    if (v < l || u > r) return;
    if (u <= l && v >= r){
        st[id] += val;
        if (l < r){
            lazy[id * 2] += val;
            lazy[id * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update(l, m, id * 2, u, v, val);
    update(m + 1, r, id * 2 + 1, u, v, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

// Find max on [u, v]
ll maxx(int l, int r, int id, int u, int v){
   lazyUpdate(l, r, id);
    if (v < l || u > r) return LLONG_MIN;
    if (u <= l && v >= r) return st[id];

    int m = (l + r) / 2;
    return max(maxx(l, m, id * 2, u, v), maxx(m + 1, r, id * 2 + 1, u, v));
}

void input(){
    cin >> n;
    fpp (i, 1, n) cin >> a[i];

    buildTree(1, n, 1);

    cin >> t;
    while (t--){
        cin >> q >> x >> y;
        if (q == 1){
            cin >> v;
            update(1, n, 1, x, y, v);
        }else{
            cout << maxx(1, n, 1, x, y) << ln;
        }
    }
}
int main(){
    fastio;
    input();
}
