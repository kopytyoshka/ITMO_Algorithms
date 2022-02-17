#include <iostream>
#include <algorithm>
#include <vector>
#define rep(x, y, z) for (ll x = y; x < z; x++)
#define ll long long
 
using namespace std;
 
const ll MD = 1e9;
ll n;
vector<ll> g;
vector<vector<ll>> dp;
 
int main() {
    cin >> n;
    g.resize(n);
    dp.resize(n, vector<ll> (n, 0));
    rep(i, 0, n) {
        dp[i][i] = 1;
        cin >> g[i];
    }
    rep(u, 0, 40) {
        rep(k, 1, n) {
            for (ll i = 0; i + k < n; i++) {
                ll j = i + k;
                if (g[i] != g[j]) {
                    dp[i][j] = (dp[i][j - 1] - dp[i + 1][j - 1] + MD) % MD + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                }
                dp[i][j] %= MD;
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
