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

int t, n, q, x, y, a[mxn], st[4 * mxn];

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

// Update tree of root id in [l, r]
void update(int l, int r, int id, int i, int val){
    // i doesn't belong to [l, r], skip
    if (i < l || i > r) return;
    // Segment contains only 1 element, no children
    if (l == r){
        st[id] = val;
        return;
    }

    int m = (l + r) / 2;
    update(l, m, id * 2, i, val);
    update(m + 1, r, id * 2 + 1, i, val);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

// Find max on [u, v]
int maxx(int l, int r, int id, int u, int v){
    if (v < l || u > r){
        // [u, v] doesn't intersect with [l, r], skip
        return INT_MIN;
    }
    if (u <= l && v >= r){
        // [l, r] lies in [u, v], return st[id]
        return st[id];
    }

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
            update(1, n, 1, x, y);
        }else{
            cout << maxx(1, n, 1, x, y) << ln;
        }
    }
}
int main(){
    fastio;
    input();
}
