#include <iostream>
#include <algorithm>
#include <vector>
#define rep(x, y, z) for (ll x = y; x < z; x++)
#define sz(x) (ll)x.size()
#define ll long long
#define pb push_back
 
using namespace std;
 
ll n, vt;
vector<vector<ll>> g, dp;
 
void algo(ll v) {
    for (auto e : g[v]) {
        algo(e);
    }
    if (!sz(g[v])) {
        dp[v][0] = 0,
                dp[v][1] = 1;
    } else {
        ll sum = 0, sum0 = 0;
        for (auto e : g[v]) {
            sum += max(dp[e][0], dp[e][1]);
            sum0 += dp[e][0];
        }
        dp[v][0] = sum;
        dp[v][1] = sum0 + 1;
    }
}
 
int main() {
    cin >> n;
    g.resize(n + 2);
    dp.resize(n + 2, vector<ll> (3, 0));
    rep(i, 1, n + 1) {
        ll x;
        cin >> x;
        if (!x) {
            vt = i;
        }
        else {
            g[x].pb(i);
        }
    }
    algo(vt);
    cout << max(dp[vt][0], dp[vt][1]);
    return 0;
}
