#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
#define pcms1
 
using namespace std;
 
ll n, m;
 
bool check(ll i, ll j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
 
ll knight(ll i, ll j, vector<vector<ll>> & g) {
    if (!check(i, j)) {
        return 0;
    } else {
        if (g[i][j] == -1) {
            g[i][j] = knight(i + 1, j - 2, g) + knight(i - 1, j - 2, g) +
                      knight(i - 2, j - 1, g) + knight(i - 2, j + 1, g);
        }
        return g[i][j];
    }
}
 
int main() {
#ifdef pcms1
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll> (m, -1));
    g[0][0] = 1;
    knight(n - 1, m - 1, g);
    if (g[n - 1][m - 1] == -1) {
        g[n - 1][m - 1]++;
    }
    cout << g[n - 1][m - 1];
    return 0;
}
