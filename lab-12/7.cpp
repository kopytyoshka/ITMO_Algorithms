#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(x, y, z) for (ll x = y; x < z; x++)
#define ll long long
#define pcms1
 
using namespace std;
 
ll sum, n;
 
int main() {
#ifdef pcms1
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
    cin >> sum >> n;
    vector<ll> g(n + 1);
    rep(i, 1, n + 1) {
        cin >> g[i];
    }
    vector<vector<ll>> a(n + 1, vector<ll> (sum + 2, 0));
    rep(k, 1, n + 1) {
        rep(e, 1, sum + 1) {
            if (e >= g[k]) {
                a[k][e] = max(a[k - 1][e], a[k - 1][e - g[k]] + g[k]);
            } else {
                a[k][e] = a[k - 1][e];
            }
        }
    }
    cout << a[n][sum];
    return 0;
}
